#include "doctorview.h"
#include "ui_doctorview.h"
#include "idatabase.h"

DoctorView::DoctorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initDoctorModel()) {
        qDebug() << "查询到了病人数据，即将展示";
        ui->tableView->setModel(iDatabase.DoctorTabModel);
        ui->tableView->setSelectionModel(iDatabase.theDoctorSelection);
    }
}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::on_btSearch_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchDoctor(filter);
}


void DoctorView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewDoctor();
        emit goDoctorEditView(currow);
}


void DoctorView::on_btDelete_clicked()
{
     IDatabase::getInstance().deleteCurrentDoctor();
}


void DoctorView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance()
                               .theDoctorSelection->currentIndex(); //获取当前选择单元格的模型索引
    emit goDoctorEditView(curIndex.row());
}

