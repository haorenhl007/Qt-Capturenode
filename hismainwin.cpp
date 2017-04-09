#include "hismainwin.h"
#include "ui_hismainwin.h"
#include "mainwindow.h"
//#include "curvwidget.h"
#include "datathread.h"
#include "QMessageBox"
#include "QProgressDialog"
#include "QFile"

HisMainWin::HisMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HisMainWin)
{
    ui->setupUi(this);

    this->setWindowTitle("历史数据查询窗口");

    model = new QSqlTableModel(this);
    model->setTable("table_information");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setHeaderData(0,Qt::Horizontal,tr("包序号"));
    model->setHeaderData(1,Qt::Horizontal,tr("加速度X"));
    model->setHeaderData(2,Qt::Horizontal,tr("加速度Y"));
    model->setHeaderData(3,Qt::Horizontal,tr("加速度Z"));
    model->setHeaderData(4,Qt::Horizontal,tr("角速度X"));
    model->setHeaderData(5,Qt::Horizontal,tr("角速度Y"));
    model->setHeaderData(6,Qt::Horizontal,tr("角速度Z"));
    model->setHeaderData(7,Qt::Horizontal,tr("地磁X"));
    model->setHeaderData(8,Qt::Horizontal,tr("地磁Y"));
    model->setHeaderData(9,Qt::Horizontal,tr("地磁Z"));

    ui->tableView->setModel(model);

    ui->tableView->verticalHeader();
    ui->tableView->horizontalHeader();
    ui->tableView->resizeColumnsToContents();

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);"
        "alternate-background-color: rgb(141, 163, 215);}" );
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setShowGrid(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    QFont serifFont;
    serifFont.setBold(true);
    ui->tableView->setFont(serifFont);

    status = new QLabel;//设置状态条
    ui->statusbar->addWidget(status);

}

HisMainWin::~HisMainWin()
{
    delete ui;
}

void HisMainWin::on_btnReturn_his_clicked()//有数据库界面返回至主界面，启动一次数据保存
{
    this->hide();
    mainwin->show();
    datathread->stopped = true;//开启submit提交数据库线程
    datathread->start();
}

void HisMainWin::on_btnCurve_his_clicked()//跳转至曲线图界面
{
//    this->hide();
//    curvewgt->show();
}
//以下为保存成excel数据代码，是否加入断开串口连接功能需要进一步考虑
void HisMainWin::on_btnPrint_his_clicked()//此部分保存成excel语句耗时较大，可以考虑加入进度条
{
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save File"),".",tr("Microsoft Office Excel (*.xls *.xlsx)"));
    if(!filepath.isEmpty()){
        //界面弹出进度条
        QProgressDialog dialog(tr("Excel数据保存进度"), tr("取消"), 0, model->rowCount(), this);
        dialog.setWindowTitle(tr("进度条"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        //开启excel保存功能
        QAxObject *excel = new QAxObject(this);
        excel->setControl("Excel.Application");//连接Excel控件
        excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
        excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

        QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
        workbooks->dynamicCall("Add");//新建一个工作簿
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
        QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
        QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
        QAxObject *cell1,*cell2,*cell3,*cell4,*cell5,*cell6,*cell7,*cell8,*cell9,*cell10;

        for(int i=0;i<model->rowCount();i++)
        {
            //以下为进度条显示
            dialog.setValue(i);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
                break;
            //以下为实际保存语句
            QString X1="A"+QString::number(i+1);//设置要操作的单元格，如A1
            QString X2="B"+QString::number(i+1);
            QString X3="C"+QString::number(i+1);//设置要操作的单元格，如A1
            QString X4="D"+QString::number(i+1);
            QString X5="E"+QString::number(i+1);//设置要操作的单元格，如A1
            QString X6="F"+QString::number(i+1);
            QString X7="G"+QString::number(i+1);//设置要操作的单元格，如A1
            QString X8="H"+QString::number(i+1);
            QString X9="I"+QString::number(i+1);
            QString X10="J"+QString::number(i+1);


            cell1 = worksheet->querySubObject("Range(QVariant, QVariant)",X1);//获取单元格
            cell2 = worksheet->querySubObject("Range(QVariant, QVariant)",X2);
            cell3 = worksheet->querySubObject("Range(QVariant, QVariant)",X3);//获取单元格
            cell4 = worksheet->querySubObject("Range(QVariant, QVariant)",X4);
            cell5 = worksheet->querySubObject("Range(QVariant, QVariant)",X5);//获取单元格
            cell6 = worksheet->querySubObject("Range(QVariant, QVariant)",X6);
            cell7 = worksheet->querySubObject("Range(QVariant, QVariant)",X7);//获取单元格
            cell8 = worksheet->querySubObject("Range(QVariant, QVariant)",X8);
            cell9 = worksheet->querySubObject("Range(QVariant, QVariant)",X9);//获取单元格
            cell10 = worksheet->querySubObject("Range(QVariant, QVariant)",X10);

            cell1->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,0))));//设置单元格的值
            cell2->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,1))));
            cell3->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,2))));//设置单元格的值
            cell4->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,3))));
            cell5->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,4))));//设置单元格的值
            cell6->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,5))));
            cell7->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,6))));//设置单元格的值
            cell8->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,7))));
            cell9->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,8))));//设置单元格的值
            cell10->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,9))));

        }
        dialog.setValue(model->rowCount());//设置进度条为满值

        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;
    }

}

//void HisMainWin::on_btnExit_his_clicked()
//{
//    datathread->stopped = true;
//    this->close();

//}

static qint64 countrev;
void HisMainWin::insAndupdatetblview()
{

    QSqlRecord record;

    QDateTime dt;
    QTime time;
    QDate date;
    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy:MM:dd:hh:mm:ss"); //采用一定的格式保存时间日期

    QSqlField f1("ch1", QVariant::Int);
    QSqlField f2("ch2", QVariant::Int);
    QSqlField f9("datetime", QVariant::DateTime);

    f1.setValue(mainwin->ReofRecv);
    f2.setValue(mainwin->ImofRecv);


    f9.setValue(QVariant(currentDate));
    record.append(f1);
    record.append(f2);
    record.append(f9);

    model->insertRecord(-1, record);
    ui->tableView->scrollToBottom();//tableview自动滚动到表底部

    countrev++;

    showStatusMessage(tr("共计接收到: %1 个数据").arg(countrev));  

}

void HisMainWin::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void HisMainWin::on_btnClear_his_clicked()
{
    model->removeRows(0,model->rowCount());
}

void HisMainWin::on_btnOpen_clicked()
{


    QFile file("H:/liulong.txt");
    QByteArray array;

    QSqlRecord record;
    QSqlField f1("number", QVariant::Int);
    QSqlField f2("accx", QVariant::Double);
    QSqlField f3("accy", QVariant::Double);
    QSqlField f4("accz", QVariant::Double);
    QSqlField f5("angx", QVariant::Double);
    QSqlField f6("angy", QVariant::Double);
    QSqlField f7("angz", QVariant::Double);
    QSqlField f8("magx", QVariant::Double);
    QSqlField f9("magy", QVariant::Double);
    QSqlField f10("magz", QVariant::Double);

    qDebug()<<file.size();
    if(file.open(QIODevice::ReadOnly))
    {
        QProgressDialog dialog(tr("数据读取进度"), tr("取消"), 0, 5000, this);
        dialog.setWindowTitle(tr("进度条"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();


        for(int i = 1; i<5000/20;i++)
        {
            dialog.setValue(i);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
                break;

            file.seek(i*20);
            array = file.read(20);

            int a = (array.at(1)<<8) | array.at(0);
            f1.setValue(a);

            float b = (float)(array.at(3)*256+array.at(2))/32768*16;
            f2.setValue(b);
            float c = (float)(array.at(5)*256+array.at(4))/32768*16;
            f3.setValue(c);
            float d = (float)(array.at(7)*256+array.at(6))/32768*16;
            f4.setValue(d);

            double e = (float)((array.at(9)<<8) | array.at(8))/32768*2000;
            f5.setValue(e);
            double f = (float)((array.at(11)<<8) | array.at(10))/32768*2000;
            f6.setValue(f);
            double g = (float)((array.at(13)<<8) | array.at(12))/32768*2000;
            f7.setValue(g);

            double h = (float)((array.at(15)<<8) | array.at(14));
            f8.setValue(h);
            double j = (float)((array.at(17)<<8) | array.at(16));
            f9.setValue(j);
            double k = (float)((array.at(19)<<8) | array.at(18));
            f10.setValue(k);
            record.append(f1);
            record.append(f2);
            record.append(f3);
            record.append(f4);
            record.append(f5);
            record.append(f6);
            record.append(f7);
            record.append(f8);
            record.append(f9);
            record.append(f10);

            model->insertRecord(-1, record);

//            qDebug()<<a;
//            qDebug("acc x is %f,acc y is %f,acc z is %f",b,c,d);
//            qDebug("ang x is %f,ang y is %f,ang z is %f",e,f,g);
//            qDebug("mag x is %f,mag y is %f,mag z is %f",h,j,k);

        }
        ui->tableView->scrollToBottom();//tableview自动滚动到表底部
        qDebug()<<array.size();
        qDebug()<<file.pos();
    }

}
