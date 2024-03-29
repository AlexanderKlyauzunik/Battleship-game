#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "myfield.h"
#include "enemyfield.h"
#include <QThread>

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

    void grey_out_radioButton_ForFourDecks();

signals:

private:
    Ui::MainWindow *ui;
    MyField myFieldObj;
    EnemyField enemyFieldObj;
};

#endif // MAINWINDOW_H
