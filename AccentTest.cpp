#include "AccentTest.h"
#include "ui_AccentTest.h"


AccentTest::AccentTest(QWidget *parent) {
    ui = new Ui::AccentTest;
    ui->setupUi(this);
    mainWidget = parent;
    //mainWidget = myParent;
    ui->buttonsLayout->setSpacing(0);
    wordsVector.getWordsByReadingFromFileOrCreatingDefaultFile();
    this->showRandomWord();
}


AccentTest::~AccentTest(){
    delete ui;
}

void AccentTest::showRandomWord(){
    wordNum =wordsVector.getGoodRandomWordNum();
    if (wordNum == -1){
        allWordsAreLearned();
    }
    else{
        word = wordsVector[wordNum];
        buttons.generateButtonsFor(word);
        int vowels = 0;
        for (int i=0; i<buttons.size(); ++i){
            ui->buttonsLayout->addWidget(&buttons[i]);
            if (WordWithAccentAndStatistic::isVowel(buttons[i].text()[0])){
                vowels++;
                if (vowels == word.getRightAccent()){
                    connect(&buttons[i], SIGNAL(clicked()), this, SLOT(rightVowelClick()));
                }
                else{
                    connect(&buttons[i], SIGNAL(clicked()), this, SLOT(wrongVowelClick()));
                }
            }
        }
    }
}

void AccentTest::saveWordsStatistic()
{
    wordsVector.saveWords();
}

void AccentTest::wrongAnswerTextAdd()
{
    QString s = word.getText();
    s[userAnswer.toInt()] = WordWithAccentAndStatistic::makeLetterBig(s[userAnswer.toInt()]);
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

void AccentTest::allWordsAreLearned()
{
    QLabel *label = new QLabel();
    label->setText("Все слова выучены. Добавьте новые или удалите статистику.");
    label->setStyleSheet("font-size: 18px;");
    ui->buttonsLayout->addWidget(label);
}

void AccentTest::rightVowelClick()
{
    wordsVector[wordNum].setNumOfRightAnswers(word.getNumOfRightAnswers()+1);
    saveWordsStatistic();
    buttons.deleteAllButtons();
    buttons.generateAnswer(word);
    //кнопка только одна, имеет индекс [0]
    setGreenButtonStyleSheet(buttons[0]);
    ui->buttonsLayout->addWidget(&buttons[0]);
    connect(&buttons[0], SIGNAL(clicked()), this, SLOT(nextWordClick()));
}

void AccentTest::wrongVowelClick()
{
    wordsVector[wordNum].setNumOfRightAnswers(0);
    saveWordsStatistic();
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

void AccentTest::on_returnButton_clicked()
{
    mainWidget->show();
    this->close();
}
