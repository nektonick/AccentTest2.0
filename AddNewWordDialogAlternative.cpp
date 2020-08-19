#include "AddNewWordDialogAlternative.h"
#include "ui_AddNewWordDialogAlternative.h"

AddNewWordDialogAlternative::AddNewWordDialogAlternative(QWidget *parent) : QDialog(parent),
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

    switch (tempAccent) {
    case -1:
        QMessageBox::information(0, "Ошибка", "Неверный ввод. Возможно, вы не выделили ударение большой буквой");
        this->reject();
        break;
    case -2:
        QMessageBox::information(0, "Ошибка", "Неверный ввод. Возможно, вы ввели больше одной заглавной буквы");
        this->reject();
        break;
    default:
        inputAccent = tempAccent;
    }
}

int AddNewWordDialogAlternative::getInputAccent()
{
    //очень большая функция, которая к тому же делает больше одной вещи
    //кроме того, она делает неочевидную из названия вещь (превращает большую букву в малую)
    //конструккия из return выглядит уродливо
    //TODO - исправить code-style проблемы
    QString vowels ="аеиоуыэюя";
    QString upperVowels = "АЕИОУЫЭЮЯ";

    int numOfUpperVowels = 0;
    for (auto n: inputText){
        if (upperVowels.contains(n))
            ++numOfUpperVowels;
    }

    int numOfVowels = 0;
    int lettersIterator = 0;
    for (auto n: inputText){
        if (vowels.contains(n)){
            ++numOfVowels;
        }
        if (upperVowels.contains(n)){
            ++numOfVowels;
            inputText[lettersIterator]=vowels[upperVowels.indexOf(n)];
            break;
        }
        ++lettersIterator;
    }

    //если не найдена большая буква, возвращается -1,
    //если найдено больше одной возвращается -2, иначе - ударение
    if (numOfUpperVowels > 1){
        return -2;
    }
    if (lettersIterator >= inputText.size()){
        return -1;
    }
    return numOfVowels;
}
