#include "readwritexml.h"
#include "ui_readwritexml.h"

ReadWriteXML::ReadWriteXML(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReadWriteXML)
{
    ui->setupUi(this);
    current_filepath_ = "./xmlfiles";
    current_filename_ = "/workers.xml";
    connect(ui->writeXMLBtn,&QPushButton::clicked,this,&ReadWriteXML::SlotWriteXML);
    connect(ui->readXMLBtn,&QPushButton::clicked,this,&ReadWriteXML::SlotReadXML);
}

ReadWriteXML::~ReadWriteXML()
{
    delete ui;
}

bool ReadWriteXML::openXMLFile(QString fileNamePath)
{
    files_.setFileName(current_filepath_ + fileNamePath);
    return files_.open(QIODevice::ReadWrite|QFile::Text);
}
///读取XML文件
void ReadWriteXML::readXMLFile()
{
    if(!openXMLFile(current_filename_)){
        qDebug() << "读取：打开XML文件失败";
        return;
    }
    qDebug() << "读取：打开XML文件成功，请认真操作。";
    QDomDocument docs;
    //xml格式必须正确
    if(!docs.setContent(&files_)){
        files_.close();
        qDebug() << "读取：操作setContent失败，请认真操作。";
        return;
    }
    qDebug() << "读取：操作setContent成功，请认真操作。";
    //读取根节点
    QDomElement root = docs.documentElement();
    //读取第一个父类节点
    QDomNode node = root.firstChild();
    while(!node.isNull()){
        QDomNodeList son_list = node.childNodes();     //读取子节点集合信息
        QString root_name = node.toElement().tagName();//读取父亲节点名称
        if(root_name.compare("worker") == 0){          //检查当前节点的名称是否为 "worker"，如果是，则调用 readRootXML 函数来读取该节点的子节点数据。
            //将子节点集合信息传递到读取子节点数据
            readRootXML(son_list);
        }
        node = node.nextSibling();//读取下一个父节点
    }
}

void ReadWriteXML::writeXMLFile()
{
    if(!openXMLFile(current_filename_)){
        qDebug() << "写入打开XML文件失败";
        return;
    }
    qDebug() << "打开XML文件成功。";
    QDomDocument dom_doc;
    QDomProcessingInstruction version;///写入xml文件头部
    version = dom_doc.createProcessingInstruction("xml","version = \"1.0\" encoding = \"UTF-8\"");
    dom_doc.appendChild(version);
    ///添加第一个子节点以及相关子元素
    QDomElement dom_root_elem = dom_doc.createElement("factory");
    dom_doc.appendChild(dom_root_elem);
    ///创建父节点
    QDomElement item_root_elem = dom_doc.createElement("worker");

    ///number
    QDomElement node_no = dom_doc.createElement("WNO");   ///创建子节点
    QDomText dom_text_1 = dom_doc.createTextNode("WNO");    ///创建文本节点
    dom_text_1.setData(ui->lineEditWEmployeeNumber->text());///设置子节点数据
    node_no.appendChild(dom_text_1);
    item_root_elem.appendChild(node_no);                  ///将子节点绑定到父节点上

    ///name
    QDomElement node_name = dom_doc.createElement("WNAME");   ///创建子节点
    QDomText dom_text_2 = dom_doc.createTextNode("WNAME");      ///创建文本节点
    dom_text_2.setData(ui->lineEditWEmployeeName->text());      ///设置子节点数据
    node_name.appendChild(dom_text_2);
    item_root_elem.appendChild(node_name);                    ///将子节点绑定到父节点上

    ///sex
    QDomElement node_sex = dom_doc.createElement("WSEX");   ///创建子节点
    QDomText dom_text_3 = dom_doc.createTextNode("WSEX");     ///创建文本节点
    dom_text_3.setData(ui->lineEditWEmployeeSex->text());     ///设置子节点数据
    node_sex.appendChild(dom_text_3);
    item_root_elem.appendChild(node_sex);                   ///将子节点绑定到父节点上

    ///academic
    QDomElement node_academic = dom_doc.createElement("WACADEMIC");   ///创建子节点
    QDomText dom_text_4 = dom_doc.createTextNode("WACADEMIC");          ///创建文本节点
    dom_text_4.setData(ui->lineEditWEmployeeAcademic->text());          ///设置子节点数据
    node_academic.appendChild(dom_text_4);
    item_root_elem.appendChild(node_academic);                          ///将子节点绑定到父节点上

    ///department
    QDomElement node_depart = dom_doc.createElement("WDEPARTMENT");   ///创建子节点
    QDomText dom_text_5 = dom_doc.createTextNode("WDEPARTMENT");        ///创建文本节点
    dom_text_5.setData(ui->lineEditWEmployeeDepartment->text());        ///设置子节点数据
    node_depart.appendChild(dom_text_5);
    item_root_elem.appendChild(node_depart);                          ///将子节点绑定到父节点上

    ///salary
    QDomElement node_salary = dom_doc.createElement("WSALARY");       ///创建子节点
    QDomText dom_text_6 = dom_doc.createTextNode("WSALARY");            ///创建文本节点
    dom_text_6.setData(ui->lineEditWEmployeeSalary->text());            ///设置子节点数据
    node_salary.appendChild(dom_text_6);
    item_root_elem.appendChild(node_salary);                          ///将子节点绑定到父节点上

    dom_root_elem.appendChild(item_root_elem);                            ///绑定到顶层节点
    files_.write(dom_doc.toString().toLocal8Bit().data());
    files_.close();
    QMessageBox::information(this,tr("提示"),tr("恭喜，写入XML文件数据成功。"),QMessageBox::Yes);
}
/// 读取子节点数据
void ReadWriteXML::readRootXML(QDomNodeList nodeList)
{
    for(int son_node = 0;son_node < nodeList.size();son_node++){
        //获取子节点
        QDomElement son_elem = nodeList.at(son_node).toElement();
        if(son_elem.toElement().tagName().compare("WNO") == 0){
            ui->lineEditREmployeeNumber_2->setText(son_elem.text());
        }
        else  if(son_elem.toElement().tagName().compare("WNAME") == 0){
            ui->lineEditREmployeeName_2->setText(son_elem.text());
        }
        else  if(son_elem.toElement().tagName().compare("WSEX") == 0){
            ui->lineEditREmployeeSex_2->setText(son_elem.text());
        }
        else  if(son_elem.toElement().tagName().compare("WACADEMIC") == 0){
            ui->lineEditREmployeeAcademic_2->setText(son_elem.text());
        }
        else  if(son_elem.toElement().tagName().compare("WDEPARTMENT") == 0){
            ui->lineEditREmployeeDepartment_2->setText(son_elem.text());
        }
        else  if(son_elem.toElement().tagName().compare("WSALARY") == 0){
            ui->lineEditREmployeeSalary_2->setText(son_elem.text());
        }
    }
}

void ReadWriteXML::SlotWriteXML()
{
    writeXMLFile();
}

void ReadWriteXML::SlotReadXML()
{
    readXMLFile();
}
