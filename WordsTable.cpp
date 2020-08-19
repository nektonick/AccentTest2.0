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
    wordsWithCheckBoxVector.generateWordsCheckBoxes();
    for (unsigned int i = 0; i < wordsWithCheckBoxVector.size(); ++i){
        ui->wordsArea->addWidget(wordsWithCheckBoxVector[i]);
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
        newWord.id = wordsWithCheckBoxVector.getLastWordId() + 1;
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
        newWord.id = wordsWithCheckBoxVector.getLastWordId() + 1;
        newWord.rightAnswersInARow = 0;
        addNewWord();
    }
}

void WordsTable::addNewWord()
{
    wordsWithCheckBoxVector.wordsVector.push_back(newWord);
    wordsUpdate();
}

void WordsTable::wordsUpdate()
{
    for (auto i: wordsWithCheckBoxVector){
        delete i;
    }
    wordsWithCheckBoxVector.clear();
    wordsWithCheckBoxVector.generateWordsCheckBoxes();
    for (unsigned int i = 0; i < wordsWithCheckBoxVector.size(); ++i){
        ui->wordsArea->addWidget(wordsWithCheckBoxVector[i]);
    }
}
void WordsTable::on_deleteWordButton_clicked()
{
    int wordsToDelete=0;
    for (unsigned int i = 0; i < wordsWithCheckBoxVector.size(); ++i){
        if (wordsWithCheckBoxVector[i]->isChecked())
            ++wordsToDelete;
    }

    if (showWarningAndReturnExecCode(wordsToDelete) == 1){

        //костыль. не смог придумать хорошего удаления из вектора в цикле.
        //Использованием итераторов проблему решить не удалось
        while (wordsToDelete > 0){
            for (unsigned int j = 0; j < wordsWithCheckBoxVector.size(); ++j){
                if (wordsWithCheckBoxVector[j]->isChecked()){
                    wordsWithCheckBoxVector[j]->close();
                    wordsWithCheckBoxVector.wordsVector.erase(wordsWithCheckBoxVector.wordsVector.begin() + j);
                    wordsWithCheckBoxVector.erase(wordsWithCheckBoxVector.begin() + j);
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
    wordsWithCheckBoxVector.wordsVector.saveWords();
}

void WordsTable::on_clearStatisticButton_clicked()
{
    for(unsigned int i = 0; i < wordsWithCheckBoxVector.wordsVector.size(); ++i){
        wordsWithCheckBoxVector.wordsVector[i].rightAnswersInARow = 0;
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
