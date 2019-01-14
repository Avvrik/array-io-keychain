#include "keymanager_dialog.hpp"

keymanager_dialog::keymanager_dialog(QWidget * parent)
	: QDialog(parent) 
{
    //define common dialog properties
    QMetaObject::connectSlotsByName(this);
    setWindowTitle(QApplication::translate("keychain_gui_winClass", "keychain_gui_win", nullptr));
    resize(1100, 760);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("background-color:rgb(242,243,246);");
    //
    //define header properties
    header = new QLabel(this);
    header->setFixedSize(this->width(), 50);
    header->setStyleSheet("background-color:rgb(255,255,255);");
    //define logo picture
    QPixmap logo(":/keymanager/keychain_logo.png");
    logo = logo.scaled(100, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoLabel = new QLabel(this);
    logoLabel->setStyleSheet("background:transparent;");
    logoLabel->setPixmap(logo);
    logoLabel->move(811, 4);
    //create logo title "KeyManager
    logoTitle = new QLabel("KeyManager", this);
    logoTitle->move(884, 20);
    logoTitle->setStyleSheet("font:15px \"Segoe UI\";background:transparent;");
    //end dialog initialization

    keys_table = new keys_table_view(this);
    keys_table->setFixedSize(1040, 650);
    keys_table->move(32, 90);

    toolbar = new menu_toolbar(this);
    toolbar->setFixedSize(300, 35);
    toolbar->setStyleSheet("font:15px \"Segoe UI\";background:transparent;");
    toolbar->move(32, 15);
}