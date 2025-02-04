#include "chatclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ChatClient client;
    client.setWindowTitle("Chat en temps réel");
    client.resize(400, 300);
    client.show();
    return app.exec();
}
