#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QThread>
#include "polling.hpp"

class Widget : public QWidget
{
    Q_OBJECT
    QThread pollingThread;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QLineEdit *ple;
    QTextEdit *pte;
    QLabel *caps, *num, *shift;
private:
    void interior();
    void closeEvent(QCloseEvent *);
    void parse(const std::string);
    bool passClearOnExit;
public slots:
    void found_pass();
    void send(std::string);
signals:
    void poll();
};
#endif // WIDGET_H
