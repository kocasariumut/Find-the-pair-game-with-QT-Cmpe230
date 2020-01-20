#include "finddialog.h"
using namespace std;

FindDialog::FindDialog(QWidget *parent):QDialog(parent)
{
    prevnum=-1;
    trying=0;
    pair=0;
    reset = new QPushButton("Reset"); // the reset button
    trylabel = new QLabel("Tries"); // "Tries" label
    trylabelnumber = new QLabel("0"); // initializes the number of tries
    pairlabel = new QLabel("Pairs"); // "Pairs" label
    pairlabelnumber = new QLabel("0"); //initializes the number of pairs found
    buttongroup = new QButtonGroup;
    disp = new QLCDNumber;
    disp->setSegmentStyle(QLCDNumber::Flat) ;
    glayout = new QGridLayout;
    glayout->addWidget(pairlabel,0,0);  // adding "Pairs" label to first line's first index
    glayout->addWidget(pairlabelnumber,0,1); // adding number of pairs found to first line's second index
    glayout->addWidget(trylabel,0,2); // adding "Tries" label to first line's third index
    glayout->addWidget(trylabelnumber,0,3); // adding number of tries to first line's fourth index
    glayout->addWidget(reset,0,4,1,2); // adding a "Reset" button to the first line's end with 1,2 size
    s = new QString;
    letters.resize(24); //resizes the vector into number of letters that will inserted
    letters = {"A","B","C","D","E","F","G","H","I","K","L","M","A","B","C","D","E","F","G","H","I","K","L","M"};
    random_shuffle ( letters.begin(), letters.end() ); // randomizes the letters

    for(int i=0 ; i < 4 ; i++) {
      for(int j=0 ; j < 6 ; j++) {
          *s = "x"; // makes all buttons to display "x"

         button[6*i+j] = new QPushButton(*s); //creates all buttons
         glayout->addWidget(button[6*i+j],i+1,j); // adds all buttons into the table
         buttongroup->addButton(button[6*i+j],6*i+j+1) ; // adds all buttons into button group
       }
    }
    // If user clicks any button in the buttongroup, it calls buttoncheck(int) function.
    QObject::connect(buttongroup, SIGNAL(buttonClicked(int)),
                     this, SLOT(buttoncheck(int)));
    // If user clicks any button in the buttongroup, it calls trypaircheck() function.
    QObject::connect(buttongroup,SIGNAL(buttonClicked(int)),
                     this, SLOT(trypaircheck()));
    // If user clicks reset button, it calls reseting() function.
    QObject::connect(reset,SIGNAL(clicked()),
                     this, SLOT(reseting()));


setLayout(glayout);

}

void FindDialog::buttoncheck(int current){



    if(current!=prevnum){ // Processes if the click is different than the previous click.
    if(this->prevnum==-1){ // Processes if the click is the first part of the try.
        prevnum = current;
        button[current-1]->setText(QString::fromStdString(letters[current-1]));



    }
    else{ // Processes if the click is the second part of the try.
        if(letters[prevnum-1]!=letters[current-1]){ // If the previous click is different than the current click.
         button[current-1]->setText(QString::fromStdString(letters[current-1]));
         trying+=1;
         qApp->processEvents();
         sleep(2);

         button[current-1]->setText("x");
         button[prevnum-1]->setText("x");
         prevnum=-1;

        }
        else{ // If the previous click is the same as the current click.
            button[current-1]->setText(QString::fromStdString(letters[current-1]));
            pair+=1;
            trying+=1;
            qApp->processEvents();
            sleep(2);
            button[current-1]->setText("");
            button[prevnum-1]->setText("");
            button[current-1]->setDisabled(true);
            button[prevnum-1]->setDisabled(true);
             prevnum=-1;


        }
    }
}



}
// Updates the number of tries and the number of pairs found.
void FindDialog::trypaircheck(){

    trylabelnumber->setText(QString::number(trying));
    pairlabelnumber->setText(QString::number(pair));



}
// Resets the game.
void FindDialog::reseting(){

    prevnum=-1;
    trying=0;
    pair=0;
    trylabelnumber->setText("0");
    pairlabelnumber->setText("0");
    random_shuffle ( letters.begin(), letters.end() );
    for(int i=0;i<24;i++){
        button[i]->setEnabled(true);
        button[i]->setText("x");

    }


}
