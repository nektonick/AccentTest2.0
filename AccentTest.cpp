#include "AccentTest.h"
#include "ui_AccentTest.h"


AccentTest::AccentTest(QWidget *parent) : QWidget(parent), ui(new Ui::AccentTest){
    ui->setupUi(this);
    wordsVector.getWordsByReadingFromFileOrCreatingDefaultFile();
    this->showWord();
}


AccentTest::~AccentTest(){
    delete ui;
}

void AccentTest::showWord(){
    word = wordsVector.getGoodRandomWord();
    buttons.generateButtonsFor(word);
    for (int i=0; i<buttons.size(); ++i){
        ui->buttonsLayout->addWidget(&buttons[i]);
    }
}
