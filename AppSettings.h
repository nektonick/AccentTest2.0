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
private:
    Ui::AppSettings *ui;
    QWidget *mainMenu = nullptr;
    int wordsInputType;
    int rightAnswersInARow;
    QFile settingsFile;
    QString fileName = "settings";
    void readFromExistFile();
    void createDefaultFile();
private slots:
    void on_resetButton_clicked();
    void on_saveButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_returnButton_clicked();
};

#endif // APPSETTINGS_H
