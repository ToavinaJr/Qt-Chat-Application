/********************************************************************************
** Form generated from reading UI file 'chatclient.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCLIENT_H
#define UI_CHATCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatClient
{
public:

    void setupUi(QWidget *ChatClient)
    {
        if (ChatClient->objectName().isEmpty())
            ChatClient->setObjectName("ChatClient");
        ChatClient->resize(800, 600);

        retranslateUi(ChatClient);

        QMetaObject::connectSlotsByName(ChatClient);
    } // setupUi

    void retranslateUi(QWidget *ChatClient)
    {
        ChatClient->setWindowTitle(QCoreApplication::translate("ChatClient", "ChatClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatClient: public Ui_ChatClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
