#include "WordsTable.h"
#include "ui_WordsTable.h"

WordsTable::WordsTable(QWidget *parent) : ui(new Ui::WordsTable)
{
    mainWidget = parent;
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

void WordsTable::showRegularAddWordDialog()
{
    AddNewWordDialog *dialog= new AddNewWordDialog;
    dialog->show();
    if (dialog->exec() == 1){
        newWord.wordText = dialog->inputText;
        newWord.rightAccent = dialog->inputAccent;
        newWord.id = checkBoxesWithWords.getLastWordId()+1;
        newWord.rightAnswersInARow = 0;
        addNewWord();
    }
}

void WordsTable::showAlternativeAddWordDialog()
{
    AddNewWordDialogAlternative *dialog= new AddNewWordDialogAlternative;
    dialog->show();
    if (dialog->exec() == 1){
        newWord.wordText = dialog->inputText;
        newWord.rightAccent = dialog->inputAccent;
        newWord.id = checkBoxesWithWords.getLastWordId()+1;
        newWord.rightAnswersInARow = 0;
        addNewWord();
    }
}

void WordsTable::addNewWord()
{
    checkBoxesWithWords.wordsVector.push_back(newWord);
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
                    checkBoxesWithWords.wordsVector.erase(checkBoxesWithWords.wordsVector.begin()+j);
                    checkBoxesWithWords.checkBoxesVector.erase(checkBoxesWithWords.checkBoxesVector.begin()+j);
                    --wordsToDelete;
                    break;
                }
            }
        }
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

void WordsTable::saveWords()
{
    checkBoxesWithWords.wordsVector.saveWords();
}

void WordsTable::on_clearStatisticButton_clicked()
{
    for(unsigned int i=0; i<checkBoxesWithWords.wordsVector.size(); ++i){
        checkBoxesWithWords.wordsVector[i].rightAnswersInARow = 0;
    }
    saveWords();
    wordsUpdate();
}

void WordsTable::on_returnButton_clicked()
{
    saveWords();
    mainWidget->show();
    this->close();
    this->destroy();
}
