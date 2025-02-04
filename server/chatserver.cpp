#include "chatserver.h"

ChatServer::ChatServer(QObject *parent) : QTcpServer(parent) {
    if (!listen(QHostAddress::Any, 12345)) {
        qWarning() << "Le serveur ne peut pas démarrer!";
    } else {
        qDebug() << "Le serveur écoute sur le port 12345";
    }
}


void ChatServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *clientSocket = new QTcpSocket(this);
    if (clientSocket->setSocketDescriptor(socketDescriptor)) {
        connect(clientSocket, &QTcpSocket::readyRead, this, &ChatServer::readMessage);
        connect(clientSocket, &QTcpSocket::disconnected, this, &ChatServer::clientDisconnected);
        clients.append(clientSocket);
        qDebug() << "Un nouveau client s'est connecté!";
    } else {
        delete clientSocket;
    }
}


void ChatServer::readMessage() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message = clientSocket->readAll();

    // Diffuse le message à tous les clients
    for (QTcpSocket *client : std::as_const(clients)) {
        if (client != clientSocket) {
            client->write(message);
        }
    }
}

void ChatServer::clientDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    clients.removeAll(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Un client s'est déconnecté.";
}
