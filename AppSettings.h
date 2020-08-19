#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class AppSettings;
}

class AppSettings : public QWidget
{
    Q_OBJECT

public:
    explicit AppSettings(QWidget *parent = nullptr);
    ~AppSettings();
    void saveSettings();
    void readSettingsFromFile();
    void restoreSettings();
    void showSettings();
    int getWordsInputType();
    int getRightAnswersInARow();

private slots:
    void on_returnButton_clicked();
    void on_resetButton_clicked();
    void on_saveButton_clicked();
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::AppSettings *ui;
    int wordsInputType;
    int rightAnswersInARow; //пока не используется
    QFile settings;
    QString fileName = "settings";
    void readFromExistFile();
    void createDefaultFile();
    QWidget *mainMenu = nullptr;
};

#endif // APPSETTINGS_H
