#ifndef ABOUTAPP_H
#define ABOUTAPP_H

#include <QWidget>

namespace Ui {
class AboutApp;
}

class AboutApp : public QWidget
{
    Q_OBJECT

public:
    explicit AboutApp(QWidget *parent = nullptr);
    ~AboutApp();
private:
    Ui::AboutApp *ui;
    QWidget *mainWidget;
private slots:
    void on_returnButton_clicked();
};

#endif // ABOUTAPP_H
