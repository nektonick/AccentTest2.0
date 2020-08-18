#include "AccentTest.h"
#include "ui_AccentTest.h"


AccentTest::AccentTest(QWidget *parent) : ui(new Ui::AccentTest) {
    ui->setupUi(this);
    mainWidget = parent;
    ui->buttonsLayout->setSpacing(0);
    this->showRandomWord();
}

AccentTest::~AccentTest(){
    delete ui;
}

void AccentTest::showRandomWord(){
    currentWordNum = getGoodRandomWordNum();
    if (currentWordNum == -1){
        allWordsAreLearned();
    }
    else{
        currentWord = wordsVector[currentWordNum];
        buttons.generateButtonsFor(currentWord);
        int numberOfReadedVowels = 0;
        for (int i=0; i<buttons.size(); ++i){
            ui->buttonsLayout->addWidget(&buttons[i]);
            if (WordWithAccentAndStatistic::isVowel(buttons[i].text()[0])){
                numberOfReadedVowels++;
                if (numberOfReadedVowels == currentWord.getRightAccent()){
                    connect(&buttons[i], SIGNAL(clicked()), this, SLOT(rightVowelClick()));
                }
                else{
                    connect(&buttons[i], SIGNAL(clicked()), this, SLOT(wrongVowelClick()));
                }
            }
        }
    }
}

int AccentTest::getGoodRandomWordNum()
{
    int id = rand()%(wordsVector.size());
    unsigned int numOfTry = 0;
    while (wordsVector[id].getNumOfRightAnswers() >= appSettings.getRightAnswersInARow() && numOfTry < wordsVector.size()*5){
        id = rand()%wordsVector.size();
        ++numOfTry;
    }
    if(numOfTry >= wordsVector.size()*5){
        for (unsigned int i=0; i<wordsVector.size(); ++i){
            if (wordsVector[i].getNumOfRightAnswers() < appSettings.getRightAnswersInARow()){
                return wordsVector[i].getId();
            }
        }
        id = -1;
    }
    return id;
}
void AccentTest::rightVowelClick()
{
    wordsVector[currentWordNum].setNumOfRightAnswers(currentWord.getNumOfRightAnswers()+1);
    saveWordsStatistic();
    buttons.deleteAllButtons();
    showRightAnswer();
}

void AccentTest::setGreenButtonStyleSheet(QPushButton &b)
{
    b.setStyleSheet("color:green; font-size:24px; font-weight:bold; border-radius:10%; padding: 5px; margin:3px; border:3px solid green;");
}

void AccentTest::wrongVowelClick()
{
    wordsVector[currentWordNum].setNumOfRightAnswers(0);
    saveWordsStatistic();
    inputAccent = this->sender()->objectName(); //objectName содержит номер глассной
    buttons.deleteAllButtons();
    showUserWrongAnswer();
    showRightAnswer();
}

void AccentTest::setRedLableStyleSheet(QLabel &l)
{
    l.setAlignment(Qt::AlignHCenter);
    l.setStyleSheet("color:red; font-size: 18px; font-weight: normal; padding: 1px; margin:0px; border:0px");
}

void AccentTest::showUserWrongAnswer()
{
    QString s = currentWord.getText();
    //буква, которую нажал пользователь, становится большой
    s[inputAccent.toInt()] = WordWithAccentAndStatistic::makeLetterBig(s[inputAccent.toInt()]);
    s.insert(inputAccent.toInt()+1, " ́"); //символ ударения
    wrongAnswerLabel.setText("<s> "+ s + "</s"); //получается зачёркнутый текст
    setRedLableStyleSheet(wrongAnswerLabel);
    ui->wrongAnswerTextLayout->addWidget(&wrongAnswerLabel);
    wrongAnswerLabel.show();
}

void AccentTest::showRightAnswer()
{
    buttons.generateButtonWithRightAnswer(currentWord);
    setGreenButtonStyleSheet(buttons[0]); //кнопка только одна, имеет индекс [0]
    ui->buttonsLayout->addWidget(&buttons[0]);
    connect(&buttons[0], SIGNAL(clicked()), this, SLOT(nextWordClick()));
}

void AccentTest::saveWordsStatistic()
{
    wordsVector.saveWords();
}

void AccentTest::nextWordClick()
{
    buttons.deleteAllButtons();
    if (!wrongAnswerLabel.isHidden()){
        wrongAnswerLabel.hide();
    }
    this->showRandomWord();
}

void AccentTest::allWordsAreLearned()
{
    QLabel *label = new QLabel();
    label->setText("Все слова выучены. Добавьте новые или удалите статистику.");
    label->setStyleSheet("font-size: 18px;");
    ui->buttonsLayout->addWidget(label);
}

void AccentTest::on_returnButton_clicked()
{
    mainWidget->show();
    this->close();
}
