#include "WordsTable.h"
#include "ui_WordsTable.h"

WordsTable::WordsTable(QWidget *parent)
{
    mainWidget = parent;
    ui = new Ui::WordsTable;
    ui->setupUi(this);
    showWords();
}

WordsTable::~WordsTable()
{
    delete ui;
}

void WordsTable::showWords()
{
    checkBoxesWithWords.generateCheckBoxes();
    for (int i=0; i<checkBoxesWithWords.size(); ++i){
        ui->wordsArea->addWidget(&checkBoxesWithWords[i]);
    }
}

void WordsTable::on_addNewWordButton_clicked()
{
    if (appSettings.getWordsInputType() == 0){
        showRegularAddWordDialog();
    }
    else
        if(appSettings.getWordsInputType() == 1){
            showAlternativeAddWordDialog();
        }
}

void WordsTable::addNewWord()
{
    checkBoxesWithWords.wordsVector.words.push_back(newWord);
    wordsUpdate();
}

void WordsTable::wordsUpdate()
{
    checkBoxesWithWords.clear();
    checkBoxesWithWords.generateCheckBoxes();
    for (int i=0; i<checkBoxesWithWords.size(); ++i){
        ui->wordsArea->addWidget(&checkBoxesWithWords[i]);
    }
}
void WordsTable::on_deleteWordButton_clicked()
{
    int wordsToDelete=0;
    for (int i=0; i<checkBoxesWithWords.size(); ++i){
        if (checkBoxesWithWords[i].isChecked())
            ++wordsToDelete;
    }

    if (showWarningAndReturnExecCode(wordsToDelete) == 1){
        //костыль. не смог придумать хорошего удаления из вектора в цикле.
        //Использованием итераторов проблему решить не удалось
        while (wordsToDelete > 0){
            for (int j=0; j<checkBoxesWithWords.size(); ++j){
                if (checkBoxesWithWords[j].isChecked()){
                    checkBoxesWithWords.checkBoxesVector[j]->close();
                    checkBoxesWithWords.wordsVector.words.erase(checkBoxesWithWords.wordsVector.words.begin()+j);
                    checkBoxesWithWords.checkBoxesVector.erase(checkBoxesWithWords.checkBoxesVector.begin()+j);
                    --wordsToDelete;
                    break;
                }
            }
        }
    }

}

void WordsTable::saveWords()
{
    checkBoxesWithWords.wordsVector.saveWords();
}

void WordsTable::showRegularAddWordDialog()
{
    AddNewWordDialog *dialog= new AddNewWordDialog;
    dialog->show();
    if (dialog->exec() == 1){
        newWord.setText(dialog->inputText);
        newWord.setAccent(dialog->inputAccent);
        newWord.setId(checkBoxesWithWords.getLastWordId()+1);
        newWord.setNumOfRightAnswers(0);
        addNewWord();
    }
}

void WordsTable::showAlternativeAddWordDialog()
{
    AddNewWordDialogAlternative *dialog= new AddNewWordDialogAlternative;
    dialog->show();
    if (dialog->exec() == 1){
        //qDebug()<<dialog->inputAccent;
        newWord.setText(dialog->inputText);
        newWord.setAccent(dialog->inputAccent);
        newWord.setId(checkBoxesWithWords.getLastWordId()+1);
        newWord.setNumOfRightAnswers(0);
        addNewWord();
    }
}

int WordsTable::showWarningAndReturnExecCode(int howManyWordsWillBeDelete)
{
    DeleteWordsWarning *warningDialog = new DeleteWordsWarning;
    QString text = "Вы уверенны, что хотите удалить "
            + QString::number(howManyWordsWillBeDelete) + " слов?";
    warningDialog->setWarningText(text);
    warningDialog->show();
    return warningDialog->exec();
}

void WordsTable::on_returnButton_clicked()
{
    saveWords();
    mainWidget->show();
    this->close();
}


void WordsTable::on_clearStatisticButton_clicked()
{
    for(int i=0; i<checkBoxesWithWords.wordsVector.size(); ++i){
        checkBoxesWithWords.wordsVector[i].setNumOfRightAnswers(0);
    }
    saveWords();
    wordsUpdate();
}
