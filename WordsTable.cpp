#include "WordsTable.h"
#include "ui_WordsTable.h"

WordsTable::WordsTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordsTable)
{
    ui->setupUi(this);
    showWords();
}

WordsTable::~WordsTable()
{
    delete ui;
}

void WordsTable::on_addNewWordButton_clicked()
{
    AddNewWordDialog *dialog= new AddNewWordDialog;
    dialog->show();
}

void WordsTable::on_deleteWordButton_clicked()
{
    //TODO - сделать всплывающее окно "вы действительно хотите удалить @wordsToDelete слов?"

    //костыль. не смог придумать хорошего удаления из вектора в цикле.
    //Использованием итераторов проблему решить не удалось
    int wordsToDelete=0;
    for (int i=0; i<checkBoxesWithWords.size(); ++i){
        if (checkBoxesWithWords[i].isChecked())
            ++wordsToDelete;
    }
    while (wordsToDelete > 0){
        for (int j=0; j<checkBoxesWithWords.size(); ++j){
            if (checkBoxesWithWords[j].isChecked()){
                checkBoxesWithWords.checkBoxesVector[j]->close();
                checkBoxesWithWords.checkBoxesVector.erase(checkBoxesWithWords.checkBoxesVector.begin()+j);
                --wordsToDelete;
                break;
            }
        }
    }
}

void WordsTable::showWords()
{
    checkBoxesWithWords.generateCheckBoxes();
    for (int i=0; i<checkBoxesWithWords.size(); ++i){
        ui->wordsArea->addWidget(&checkBoxesWithWords[i]);
    }
}
