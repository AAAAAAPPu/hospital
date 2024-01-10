#include "recordview.h"
#include "ui_recordview.h"
#include "idatabase.h"

RecordView::RecordView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initRecordModel()) {
        qDebug() << "查询到了就诊记录数据，即将展示";
        ui->tableView->setModel(iDatabase.RecordTabModel);
        ui->tableView->setSelectionModel(iDatabase.theRecordSelection);
    }
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewRecord();
    emit goRecordEditView(currow);
}

void RecordView::on_btSearch_clicked()
{
    QString filter = QString("patient_name like '%%1%'").arg(ui->txtSearch->text());


    IDatabase::getInstance().searchRecord(filter);



}

void RecordView::on_btDelete_clicked()
{
     IDatabase::getInstance().deleteCurrentRecord();
}


void RecordView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance()
                               .theRecordSelection->currentIndex(); //获取当前选择单元格的模型索引
    emit goRecordEditView(curIndex.row());
}

