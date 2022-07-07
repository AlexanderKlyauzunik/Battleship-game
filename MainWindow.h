#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "ship.h"
#include "myfield.h"
#include "enemyfield.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButton_ForOneDeck_clicked();

    void on_radioButton_ForTwoDecks_clicked();

    void on_radioButton_ForThreeDecks_clicked();

    void on_radioButton_ForFourDecks_clicked();

    void on_myField_cellClicked(int row, int column);

    void on_enemyField_cellClicked(int row, int column);

    void on_radioButton_Vertical_clicked();

    void on_radioButton_Horizontal_clicked();

    void on_randomButton_clicked();

    void on_newGamebutton_clicked();

private:
    Ui::MainWindow *ui;
    MyField myFieldObj;
    EnemyField enemyFieldObj;
};

#endif // MAINWINDOW_H
