#include "AccentTest.h"
#include "ui_AccentTest.h"


AccentTest::AccentTest(QWidget *parent) : QWidget(parent), ui(new Ui::AccentTest){
    ui->setupUi(this);
    wordsVector.getWordsByReadingFromFileOrCreatingDefaultFile();
    this->showRandomWord();
}


AccentTest::~AccentTest(){
    delete ui;
}

void AccentTest::showRandomWord(){
    word = wordsVector.getGoodRandomWord();
    buttons.generateButtonsFor(word);
    int vowels = 0;
    for (int i=0; i<buttons.size(); ++i){
        ui->buttonsLayout->addWidget(&buttons[i]);
        if (ButtonsWithLetter::isVowel(buttons[i].text()[0])){
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
void AccentTest::wrongAnswerTextAdd()
{
    QString s = word.getText();
    s[userAnswer.toInt()] = ButtonsWithLetter::makeLetterBig(s[userAnswer.toInt()]);
    s.insert(userAnswer.toInt()+1, " ́"); //символ ударения
    wrongAnswerLabel.setText("<s> "+ s + "</s");
    setRedLableStyleSheet(wrongAnswerLabel);
    ui->wrongAnswerTextLayout->addWidget(&wrongAnswerLabel);
    wrongAnswerLabel.show();
}

void AccentTest::setGreenButtonStyleSheet(QPushButton &b)
{
    b.setStyleSheet(
                "color:green; font-size:24px;"
                "font-weight:bold; border-radius:10%;"
                "padding: 5px;"
                "margin:3px; border:3px solid green;"
                );
}

void AccentTest::setRedLableStyleSheet(QLabel &l)
{
    l.setAlignment(Qt::AlignHCenter);
    l.setStyleSheet(
                "color:red; font-size: 18px;"
                "font-weight: normal;"
                "padding: 1px;"
                "margin:0px; border:0px"
                );
}

void AccentTest::rightVowelClick()
{
    buttons.deleteAllButtons();
    buttons.generateAnswer(word);
    //кнопка только одна, имеет индекс [0]
    setGreenButtonStyleSheet(buttons[0]);
    ui->buttonsLayout->addWidget(&buttons[0]);
    connect(&buttons[0], SIGNAL(clicked()), this, SLOT(nextWordClick()));
}

void AccentTest::wrongVowelClick()
{
    userAnswer=this->sender()->objectName();

    buttons.deleteAllButtons();
    buttons.generateAnswer(word);
    wrongAnswerTextAdd();
    //кнопка только одна, имеет индекс [0]
    setGreenButtonStyleSheet(buttons[0]);
    ui->buttonsLayout->addWidget(&buttons[0]);
    connect(&buttons[0], SIGNAL(clicked()), this, SLOT(nextWordClick()));
}

void AccentTest::nextWordClick()
{
    buttons.deleteAllButtons();
    if (wrongAnswerLabel.text() !="" && wrongAnswerLabel.text() !="TextLabel"){
        wrongAnswerLabel.hide();
    }
    this->showRandomWord();
}
