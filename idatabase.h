#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    static IDatabase &getInstance()
    {
        static IDatabase instance;
        return instance;
    }

    QString userLogin(QString userName, QString password);


private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const &) = delete;
    void operator=(IDatabase const &) = delete;
    QSqlDatabase database;
    void initDatabase();


signals:
public:
    bool initPatientModel();
    int addNewPatient();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    void revertPatientEdit();

    bool initDoctorModel();
    int addNewDoctor();
    bool searchDoctor(QString filter);
    bool deleteCurrentDoctor();
    bool submitDoctorEdit();
    void reverDoctorEdit();

    bool initDepartmentModel();
    int addNewDepartment();
    bool searchDepartment(QString filter);
    bool deleteCurrentDepartment();
    bool submitDepartmentEdit();
    void revertDepartmentEdit();

    bool initRecordModel();
    int addNewRecord();
    bool searchRecord(QString filter);
    bool deleteCurrentRecord();
    bool submitRecordEdit();
    void revertRecordEdit();

    bool initMedicineModel();
    int addNewMedicine();
    bool searchMedicine(QString filter);
    bool deleteCurrentMedicine();
    bool submitMedicineEdit();
    void revertMedicineEdit();


    QSqlTableModel *patientTabModel; //数据模型
    QItemSelectionModel *thePatientSelection;//选择模型

    QSqlTableModel *DoctorTabModel; //数据模型
    QItemSelectionModel *theDoctorSelection;//选择模型

    QSqlTableModel *DepartmentTabModel; //数据模型
    QItemSelectionModel *theDepartmentSelection;//选择模型

    QSqlTableModel *RecordTabModel; //数据模型
    QItemSelectionModel *theRecordSelection;//选择模型

    QSqlTableModel *MedicineTabModel; //数据模型
    QItemSelectionModel *theMedicineSelection;//选择模型

};

#endif // IDATABASE_H
