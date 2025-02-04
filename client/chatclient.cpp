#include "chatclient.h"
#include "ui_chatclient.h"

ChatClient::ChatClient(QWidget *parent) : QWidget(parent) {
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 12345);  // Adresse du serveur

    chatBox = new QTextEdit();
    chatBox->setReadOnly(true);
    chatBox->setStyleSheet("background-color: #f0f0f0; color: #333; font-family: Arial; font-size: 14px; padding: 10px; border-radius: 5px;");

    messageInput = new QLineEdit();
    messageInput->setPlaceholderText("Tapez votre message...");
    messageInput->setStyleSheet("border: 2px solid #ccc; border-radius: 5px; padding: 5px; font-family: Arial; font-size: 14px;");

    sendButton = new QPushButton("Envoyer");
    sendButton->setIcon(QIcon(":/resources/send_icon.png"));
    sendButton->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 10px 20px; font-size: 14px; border-radius: 5px;");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(chatBox);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);

    mainLayout->addLayout(inputLayout);
    setLayout(mainLayout);

    connect(sendButton, &QPushButton::clicked, this, &ChatClient::sendMessage);
    connect(socket, &QTcpSocket::readyRead, this, &ChatClient::receiveMessage);
}

void ChatClient::sendMessage() {
    QString message = messageInput->text();
    if (!message.isEmpty()) {
        socket->write(message.toUtf8());  // Envoie du message au serveur
        messageInput->clear();
        chatBox->append("<b>Vous: </b>" + message);  // Affiche le message dans la chatBox
    }
}

void ChatClient::receiveMessage() {
    QByteArray data = socket->readAll();
    chatBox->append("<b>Serveur: </b>" + QString(data));  // Affiche les messages du serveur
}

ChatClient::~ChatClient() {
    delete socket;
}
