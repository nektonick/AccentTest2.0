#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QWidget>

namespace Ui {
class AppSettings;
}

class AppSettings : public QWidget
{
    Q_OBJECT

public:
    explicit AppSettings(QWidget *parent = nullptr);
    ~AppSettings();

private:
    Ui::AppSettings *ui;
    //TODO - альтернативный ввод слова (с одной большой буквой)
    bool alternativeWordsInput = false;
    int rightAnswersInARow = 4; //пока не используется
};

#endif // APPSETTINGS_H
