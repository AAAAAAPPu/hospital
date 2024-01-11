#include "medicineview.h"
#include "ui_medicineview.h"
#include "idatabase.h"

MedicineView::MedicineView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicineView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initMedicineModel()) {
        qDebug() << "查询到了药品数据，即将展示";
        ui->tableView->setModel(iDatabase.MedicineTabModel);
        ui->tableView->setSelectionModel(iDatabase.theMedicineSelection);
    }
}

MedicineView::~MedicineView()
{
    delete ui;
}

void MedicineView::on_btSearch_clicked()
{
    QString filter = QString("drug_name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchMedicine(filter);
}


void MedicineView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewMedicine();
    emit goMedicineEditView(currow);
}


void MedicineView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentMedicine();
}



void MedicineView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance()
                               .theMedicineSelection->currentIndex(); //获取当前选择单元格的模型索引
    emit goMedicineEditView(curIndex.row());
}

