#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QPushButton>
#include <QButtonGroup>
#include <QLCDNumber>
#include <QGridLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <random>
#include <unistd.h>
#include <QtGui>


using namespace std;



class FindDialog :public QDialog
{
        Q_OBJECT


public:
    FindDialog(QWidget	*parent	=nullptr); // Constructor of the main object

private slots:
            void buttoncheck(int current); // Checks what will be done to the butttons
            void trypaircheck(); // Updates the number of "Tries" and number of "Pairs" found
            void reseting(); // Resets the game

private:
    QPushButton  *reset;  // Reset button
    QLabel       *trylabel; // "Tries" label
    QLabel       *trylabelnumber; // number of tries
    QLabel       *pairlabel; // "Pairs" label
    QLabel       *pairlabelnumber; // number of pairs found
    QButtonGroup  *buttongroup ; // all buttons
    QPushButton  *button[24]  ;
    QGridLayout   *glayout ;
    QLCDNumber    *disp ;
    QString       *s ;
    vector<string> letters; // Hold the first 12 letters of the alphabet as pairs in random order
    int prevnum; // -1 if there is nothing needs to be stored. Otherwise hold the previous clicked button's location
    int trying; // number of tries
    int pair; // number of pairs found

};

#endif // FINDDIALOG_H
