#ifndef RECORDVIEW_H
#define RECORDVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
namespace Ui {
class RecordView;
}

class RecordView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordView(QWidget *parent = nullptr);
    ~RecordView();

private slots:
    void on_btSearch_clicked();

    void on_btAdd_clicked();

    void on_btDelete_clicked();

    void on_btEdit_clicked();

signals:
    void goRecordEditView(int idx);

private:
    Ui::RecordView *ui;
    QDataWidgetMapper *dataMapper;//数据映射
};

#endif // RECORDVIEW_H
