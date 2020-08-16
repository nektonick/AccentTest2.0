#include "AppSettings.h"
#include "ui_AppSettings.h"

AppSettings::AppSettings(QWidget *parent) : ui(new Ui::AppSettings)
{
    mainMenu = parent;
    ui->setupUi(this);
    settings.setFileName(fileName);
    readSettingsFromFile();
    showSettings();
}

AppSettings::~AppSettings()
{
    delete ui;
}

void AppSettings::saveSettings()
{
    wordsInputType = ui->wordsInputModeCheckBox->isChecked();
    rightAnswersInARow = ui->horizontalSlider->value();
    if (settings.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream outStream(&settings);
        outStream<<wordsInputType<<' '<<rightAnswersInARow<<endl;
        settings.close();
    }
}

void AppSettings::readSettingsFromFile()
{
    if (settings.exists()){
        readFromExistFile();
    }
    else{
        createDefaultFile();
        readFromExistFile();
    }
}

void AppSettings::restoreSettings()
{
    createDefaultFile();
}

void AppSettings::showSettings()
{
    ui->wordsInputModeCheckBox->setChecked(bool(wordsInputType));
    ui->horizontalSlider->setValue(rightAnswersInARow);
}

int AppSettings::getWordsInputType()
{
    return  wordsInputType;
}

int AppSettings::getRightAnswersInARow()
{
    return  rightAnswersInARow;
}

void AppSettings::readFromExistFile()
{
    if (settings.isOpen()){
        qDebug()<<"file is already open!"<<endl;
        settings.close();
    }
    if (settings.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream inStream(&settings);
        inStream>>wordsInputType >> rightAnswersInARow;
        settings.close();
    }
}

void AppSettings::createDefaultFile()
{
    if (settings.isOpen()){
        qDebug()<<"file is already open!"<<endl;
        settings.close();
    }
    if (settings.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream outStream(&settings);
        //format: "wordsInputType rightAnswersInARow"
        outStream<< QString::fromUtf8("1 4");
        settings.close();
    }
}

void AppSettings::on_returnButton_clicked()
{
    mainMenu->show();
    this->close();
    this->destroy();
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

void AppSettings::on_horizontalSlider_valueChanged(int value)
{
    ui->currentValue->setText(QString::number(value));
}
