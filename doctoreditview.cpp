#include "doctoreditview.h"
#include "ui_doctoreditview.h"
#include "idatabase.h"
#include "qdatawidgetmapper.h"

DoctorEditView::DoctorEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::DoctorEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().DoctorTabModel;
    dataMapper->setModel(IDatabase::getInstance().DoctorTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditNum, tabModel->fieldIndex("EMPLOYENO"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditAge, tabModel->fieldIndex("AGE"));
    dataMapper->addMapping(ui->dbEditICefiticate, tabModel->fieldIndex("CERTITICATENUM"));
    dataMapper->addMapping(ui->dbEditMobile, tabModel->fieldIndex("MOBILENUM"));
    dataMapper->addMapping(ui->dbcomboBoxRoom, tabModel->fieldIndex("DEPARTMENTNAME"));

    dataMapper->setCurrentIndex(index);
}

DoctorEditView::~DoctorEditView()
{
    delete ui;

}

void DoctorEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitDoctorEdit();
    emit goPreviousView();
}


void DoctorEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().reverDoctorEdit();
    emit goPreviousView();
}

