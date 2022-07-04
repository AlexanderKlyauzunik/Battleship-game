#include "MainWindow.h"

MainWidget::MainWidget(QWidget *parent)
{
    this->pPlayersField = new Field();
    this->pCPUsField = new Field();
    this->pStartButton = new QPushButton("Start game");

    this->pSettingsLayout = new QVBoxLayout();
    this->pHorizLayout = new QHBoxLayout();

   // pSettingsLayout->addWidget(pStartButton); - widget with ships?
    pSettingsLayout->addWidget(pStartButton);
    pHorizLayout->addWidget(pPlayersField);
    pHorizLayout->addLayout(pSettingsLayout);
    pHorizLayout->addWidget(pCPUsField);

    this->setLayout(pHorizLayout);
}
