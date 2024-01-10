#include "departmenteditview.h"
#include "ui_departmenteditview.h"
#include "idatabase.h"
#include "qdatawidgetmapper.h"

DepartmentEditView::DepartmentEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::DepartmentEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().DepartmentTabModel;
    dataMapper->setModel(IDatabase::getInstance().DepartmentTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));

    dataMapper->setCurrentIndex(index);
}

DepartmentEditView::~DepartmentEditView()
{
    delete ui;
}

void DepartmentEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitDepartmentEdit();
    emit goPreviousView();
}


void DepartmentEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertDepartmentEdit();
    emit goPreviousView();
}

