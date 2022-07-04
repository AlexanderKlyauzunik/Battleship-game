#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include<QPushButton>
#include <QLayout>

#include "field.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
 MainWidget(QWidget *parent = nullptr);

private:

Field* pPlayersField;
Field* pCPUsField;
QPushButton* pStartButton;

QVBoxLayout* pSettingsLayout;
QHBoxLayout* pHorizLayout;
signals:

};

#endif // MAINWINDOW_H
