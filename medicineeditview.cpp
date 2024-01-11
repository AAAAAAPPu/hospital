#include "medicineeditview.h"
#include "ui_medicineeditview.h"
#include "idatabase.h"
#include "qdatawidgetmapper.h"
MedicineEditView::MedicineEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::MedicineEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().MedicineTabModel;
    dataMapper->setModel(IDatabase::getInstance().MedicineTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditDrugName, tabModel->fieldIndex("DRUG_NAME"));
    dataMapper->addMapping(ui->dbEditDosage, tabModel->fieldIndex("DOSAGE"));
    dataMapper->addMapping(ui->dbEditQuantity, tabModel->fieldIndex("QUANTITY"));

    dataMapper->setCurrentIndex(index);
}

MedicineEditView::~MedicineEditView()
{
    delete ui;
}

void MedicineEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitMedicineEdit();
    emit goPreviousView();
}


void MedicineEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertMedicineEdit();
    emit goPreviousView();
}

