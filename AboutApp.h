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

private slots:
    void on_returnButton_clicked();

private:
    Ui::AboutApp *ui;
    QWidget *mainWidget;
};

#endif // ABOUTAPP_H
