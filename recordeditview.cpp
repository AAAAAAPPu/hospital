#include "recordeditview.h"
#include "ui_recordeditview.h"
#include "idatabase.h"
#include "qdatawidgetmapper.h"

RecordEditView::RecordEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::RecordEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().RecordTabModel;
    dataMapper->setModel(IDatabase::getInstance().RecordTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditPatientName, tabModel->fieldIndex("PATIENT_NAME"));
    dataMapper->addMapping(ui->dbEditDoctorName, tabModel->fieldIndex("DOCTOR_NAME"));
    dataMapper->addMapping(ui->dbEditStartDate, tabModel->fieldIndex("STARTDATE"));
    dataMapper->addMapping(ui->dbEditResult, tabModel->fieldIndex("RESULT"));
    dataMapper->addMapping(ui->dbEditMedicine, tabModel->fieldIndex("MEDICINE"));

    dataMapper->setCurrentIndex(index);
}

RecordEditView::~RecordEditView()
{
    delete ui;
}

void RecordEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitRecordEdit();
    emit goPreviousView();
}


void RecordEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertRecordEdit();
    emit goPreviousView();
}

