#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QTextStream>
#include <QCoreApplication>

class ChatServer : public QTcpServer {
    Q_OBJECT
public:
    ChatServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void readMessage();
    void clientDisconnected();

private:
    QList<QTcpSocket *> clients;
};
