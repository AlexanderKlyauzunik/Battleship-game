#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myFieldObj.gui = ui;
    enemyFieldObj.gui = ui;
    enemyFieldObj.playerField = &myFieldObj;
    myFieldObj.resetfield();
    enemyFieldObj.resetfield();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_ForOneDeck_clicked()
{
    this->myFieldObj.setOneDeck();
    this->ui->radioButton_ForOneDeck->setChecked(true);
}


void MainWindow::on_radioButton_ForTwoDecks_clicked()
{
    this->myFieldObj.setTwoDeck();
     this->ui->radioButton_ForTwoDecks->setChecked(true);
}


void MainWindow::on_radioButton_ForThreeDecks_clicked()
{
    this->myFieldObj.setThreeDeck();
     this->ui->radioButton_ForThreeDecks->setChecked(true);
}


void MainWindow::on_radioButton_ForFourDecks_clicked()
{
    this->myFieldObj.setFourDeck();
     this->ui->radioButton_ForFourDecks->setChecked(true);
}


void MainWindow::on_myField_cellClicked(int row, int column)
{
    if(!this->myFieldObj.put(column,row))
    {
        this->enemyFieldObj.aiPlacement();
    };
}


void MainWindow::on_enemyField_cellClicked(int row, int column)
{
    this->enemyFieldObj.strike(column,row);
}


void MainWindow::on_radioButton_Vertical_clicked()
{
    this->myFieldObj.setVert();
    this->ui->radioButton_Vertical->setChecked(true);
    this->ui->radioButton_Horizontal->setChecked(false);
}


void MainWindow::on_radioButton_Horizontal_clicked()
{
    this->myFieldObj.setHor();
    this->ui->radioButton_Vertical->setChecked(false);
    this->ui->radioButton_Horizontal->setChecked(true);
}


void MainWindow::on_randomButton_clicked()
{
    this->myFieldObj.aiPlacement();
    this->ui->randomButton->setEnabled(false);
    this->enemyFieldObj.aiPlacement();
}


void MainWindow::on_newGamebutton_clicked()
{
    myFieldObj.resetfield();
    enemyFieldObj.resetfield();

    this->ui->gui_decknum->setEnabled(true);
    this->ui->gui_shippos->setEnabled(true);
    this->ui->randomButton->setEnabled(true);
    this->ui->radioButton_ForFourDecks->setEnabled(true);
    this->ui->radioButton_ForThreeDecks->setEnabled(true);
    this->ui->radioButton_ForTwoDecks->setEnabled(true);
    this->ui->radioButton_ForOneDeck->setEnabled(true);
}

void MainWindow::grey_out_radioButton_ForFourDecks()
{
    this->ui->radioButton_ForFourDecks->setEnabled(false);
}

