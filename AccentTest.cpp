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
    int vowels = 0;
    for (int i=0; i<buttons.size(); ++i){
         ui->buttonsLayout->addWidget(&buttons[i]);
        if (isVowel( buttons[i].text())){
            vowels++;
            if (vowels == word.accentLetterNumber){
                connect(&buttons[i], SIGNAL(clicked()), this, SLOT(rightVowelClick()));
            }
            else{
                connect(&buttons[i], SIGNAL(clicked()), this, SLOT(wrongVowelClick()));
            }
        }
    }
}

bool AccentTest::isVowel(QString s)
{
    QString vowels ="аеёиоуыэюя";
    return vowels.contains(s);
}

void AccentTest::rightVowelClick()
{
    //qDebug()<<"rightAccent"<<endl;
    buttons.deleteAllButtons();
}

void AccentTest::wrongVowelClick()
{
    //qDebug()<<"wrongAccent"<<endl;
}
