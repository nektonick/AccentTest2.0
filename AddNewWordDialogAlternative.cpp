#include "AddNewWordDialogAlternative.h"
#include "ui_AddNewWordDialogAlternative.h"

AddNewWordDialogAlternative::AddNewWordDialogAlternative(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewWordDialogAlternative)
{
    ui->setupUi(this);
}

AddNewWordDialogAlternative::~AddNewWordDialogAlternative()
{
    delete ui;
}

void AddNewWordDialogAlternative::on_buttonBox_accepted()
{
    //TODO - выводить предупреждение, а не просто закрывать
    inputText = ui->wordLineEdit->text();
    int tempAccent = getInputAccent();
    if(tempAccent == -1){
        this->reject();
    }
    else{
        inputAccent = tempAccent;
    }
}

int AddNewWordDialogAlternative::getInputAccent()
{
    QString vowels ="аеиоуыэюя";
    QString upperVowels = "АЕИОУЫЭЮЯ";
    int ans=0;
    int i=0;
    //bool isWordCorrect = false;
    for (auto n: inputText){
        if (vowels.contains(n)){
            ++ans;
        }
        if (upperVowels.contains(n)){
            ++ans;
            inputText[i]=vowels[upperVowels.indexOf(n)];
            //isWordCorrect = true;
            break;
        }
        ++i;
    }
    return i<inputText.size() ? ans : -1;
}
