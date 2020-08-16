#include "AddNewWordDialogAlternative.h"
#include "ui_AddNewWordDialogAlternative.h"

AddNewWordDialogAlternative::AddNewWordDialogAlternative(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewWordDialogAlternative)
{
    ui->setupUi(this);
    ui->wordLineEdit->setValidator(new QRegExpValidator(QRegExp(QString::fromUtf8("[а-яА-Я]+")), ui->wordLineEdit));
    ui->wordLineEdit->setFocus();
}

AddNewWordDialogAlternative::~AddNewWordDialogAlternative()
{
    delete ui;
}

void AddNewWordDialogAlternative::on_buttonBox_accepted()
{
    inputText = ui->wordLineEdit->text();
    int tempAccent = getInputAccent();
    if(tempAccent == -1){
        QMessageBox::information(0, "Ошибка", "Неверный ввод. Возможно вы не выделили ударение большой буквой");
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
    for (auto n: inputText){
        if (vowels.contains(n)){
            ++ans;
        }
        if (upperVowels.contains(n)){
            ++ans;
            inputText[i]=vowels[upperVowels.indexOf(n)];
            break;
        }
        ++i;
    }
    return i<inputText.size() ? ans : -1;
}
