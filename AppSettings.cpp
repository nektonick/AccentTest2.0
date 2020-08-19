#include "AppSettings.h"
#include "ui_AppSettings.h"

AppSettings::AppSettings(QWidget *parent) : ui(new Ui::AppSettings), mainMenu(parent)
{
    ui->setupUi(this);
    settingsFile.setFileName(fileName);
    readSettingsFromFile();
    showSettings();
}

AppSettings::~AppSettings()
{
    delete ui;
}

void AppSettings::showSettings()
{
    ui->wordsInputModeCheckBox->setChecked(bool(wordsInputType));
    ui->horizontalSlider->setValue(rightAnswersInARow);
}

void AppSettings::readSettingsFromFile()
{
    if (settingsFile.exists()){
        readFromExistFile();
    }
    else{
        createDefaultFile();
        readFromExistFile();
    }
}

void AppSettings::readFromExistFile()
{
    if (settingsFile.isOpen()){
        QMessageBox::information(0, "Ошибка", "Внутренняя ошибка. Файл со словами уже открыт");
        settingsFile.close();
    }
    if (settingsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream inStream(&settingsFile);
        inStream>>wordsInputType >> rightAnswersInARow;
        settingsFile.close();
    }
}

void AppSettings::createDefaultFile()
{
    if (settingsFile.isOpen()){
        QMessageBox::information(0, "Ошибка", "Внутренняя ошибка. Файл со словами уже открыт");
        settingsFile.close();
    }
    if (settingsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream outStream(&settingsFile);
        //format: "wordsInputType rightAnswersInARow"
        outStream<< QString::fromUtf8("1 4");
        settingsFile.close();
    }
}

void AppSettings::saveSettings()
{
    wordsInputType = ui->wordsInputModeCheckBox->isChecked();
    rightAnswersInARow = ui->horizontalSlider->value();
    if (settingsFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream outStream(&settingsFile);
        outStream<<wordsInputType<<' '<<rightAnswersInARow<<endl;
        settingsFile.close();
    }
}

void AppSettings::restoreSettings()
{
    createDefaultFile();
}

void AppSettings::on_resetButton_clicked()
{
    createDefaultFile();
    readFromExistFile();
    showSettings();
}

void AppSettings::on_saveButton_clicked()
{
    saveSettings();
}

int AppSettings::getWordsInputType()
{
    return  wordsInputType;
}

int AppSettings::getRightAnswersInARow()
{
    return  rightAnswersInARow;
}

void AppSettings::on_horizontalSlider_valueChanged(int value)
{
    ui->currentValue->setText(QString::number(value));
}

void AppSettings::on_returnButton_clicked()
{
    mainMenu->show();
    this->close();
    this->destroy();
}
