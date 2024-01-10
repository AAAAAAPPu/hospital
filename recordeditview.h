#ifndef RECORDEDITVIEW_H
#define RECORDEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
namespace Ui {
class RecordEditView;
}

class RecordEditView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEditView(QWidget *parent = nullptr,int index=0);
    ~RecordEditView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RecordEditView *ui;
    QDataWidgetMapper *dataMapper; //数据映射
signals:
        void goPreviousView();

};

#endif // RECORDEDITVIEW_H
