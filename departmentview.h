#ifndef DEPARTMENTVIEW_H
#define DEPARTMENTVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
namespace Ui {
class DepartmentView;
}

class DepartmentView : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentView(QWidget *parent = nullptr);
    ~DepartmentView();

private slots:
    void on_btSearch_clicked();

    void on_btAdd_clicked();

    void on_btDelete_clicked();

    void on_btEdit_clicked();

signals:
    void goDepartmentEditView(int idx);

private:
    Ui::DepartmentView *ui;
    QDataWidgetMapper *dataMapper;//数据映射
};

#endif // DEPARTMENTVIEW_H
