#include <QApplication>
#include "chatserver.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ChatServer server;
    return a.exec();
}
