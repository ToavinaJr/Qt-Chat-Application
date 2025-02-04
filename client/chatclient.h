#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QApplication>
#include <QTcpSocket>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ChatClient;
}
QT_END_NAMESPACE

class ChatClient : public QWidget
{
    Q_OBJECT

public:
    ChatClient(QWidget *parent = nullptr);
    ~ChatClient();

private slots:
    void sendMessage();
    void receiveMessage();
private:
    Ui::ChatClient *ui;

    QTcpSocket *socket;
    QTextEdit *chatBox;
    QLineEdit *messageInput;
    QPushButton *sendButton;
};
#endif // CHATCLIENT_H
