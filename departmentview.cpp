#include "departmentview.h"
#include "ui_departmentview.h"
#include "idatabase.h"

DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initDepartmentModel()) {
        qDebug() << "查询到了科室数据，即将展示";
        ui->tableView->setModel(iDatabase.DepartmentTabModel);
        ui->tableView->setSelectionModel(iDatabase.theDepartmentSelection);
    }
}

DepartmentView::~DepartmentView()
{
    delete ui;
}

void DepartmentView::on_btSearch_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchDepartment(filter);
}


void DepartmentView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewDepartment();
    emit goDepartmentEditView(currow);
}


void DepartmentView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentDepartment();
}



void DepartmentView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance()
                               .theDepartmentSelection->currentIndex(); //获取当前选择单元格的模型索引
    emit goDepartmentEditView(curIndex.row());
}

