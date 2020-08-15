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
    if(getInputAccent()==-1){
        this->reject();
    }
    else{
        inputText = ui->wordLineEdit->text();
        inputAccent = getInputAccent();
    }
}

int AddNewWordDialogAlternative::getInputAccent()
{
    QString vowels ="аеиоуыэюя";
    QString upperVowels = "АЕИОУЫЭЮЯ";
    int ans=0;
    int i=0;
    for (auto n: inputText){
        if (vowels.contains(n)){
            ++ans;
            qDebug()<<n;
        }
        if (upperVowels.contains(n)){
            ++ans;
            inputText[i]=vowels[upperVowels.indexOf(n)];
            return ans;
        }
        ++i;
    }
    return -1;
}
