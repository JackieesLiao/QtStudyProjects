#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    DockWidgetFunc();
}

MainWindow::~MainWindow()
{
}

void MainWindow::DockWidgetFunc()
{
    setWindowTitle("QDockWidget类停靠窗口测试");
    //主窗口加入textedit
    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->setAlignment(Qt::AlignHCenter);
    setCentralWidget(textEdit);//将编辑框控件设置为主窗口的中央窗体
    //1.创建停靠窗口1
    QDockWidget * dw1 = new QDockWidget("停靠窗口一",this);
    dw1->setFeatures(QDockWidget::DockWidgetMovable);//可移动
    //只能停靠在应用程序窗口的左侧或右侧
    dw1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    //加入文本输入
    QTextEdit * edit = new QTextEdit();
    edit->setText("清华大学（英语：Tsinghua University，缩写：THU），简称清华，旧称清华学堂、游美肄业馆、清华学校、国立清华大学，是一所位于中华人民共和国北京市海淀区清华园的公立大学。始建于1911年，因北京西北郊清华园而得名[20]，初为清政府利用美国退还的部分庚子赔款所建“游美学务处”及附设“肄业馆”，1925年始设大学部[21]。抗日战争爆发后，清华大学与北京大学、南开大学南迁长沙，组建国立长沙临时大学。1938年国立长沙临时大学内迁昆明，易名国立西南联合大学。1946年清华大学部分迁回北京清华园复校，拥有文、法、理、工、农等5个学院。1949年中华人民共和国成立后，国立清华大学归属中央人民政府教育部，更名“清华大学”；而国立清华大学则于1956年由原大陆时期校长梅贻琦，在台湾新竹复校，仍沿用原名。");
    dw1->setWidget(edit);
    //将dw1添加到指定的停靠区域，即右侧停靠区域。
    addDockWidget(Qt::RightDockWidgetArea,dw1);
    //2.创建停靠窗口2
    QDockWidget * dw2 = new QDockWidget("停靠窗口二",this);
    //关闭操作
    dw2->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit * edit2 = new QTextEdit();
    edit2->setText("北京大学（英语：Peking University，缩写：PKU）[注 1]，简称北大[注 2]，创建于1898年，初名京师大学堂，成立之初为中国最高学府，同时也是国家最高教育行政机关，行使教育部职能，统管全国教育。中华民国建立后，校名改为北京大学校，后又改名为国立北京大学。1916年—1927年，蔡元培任北京大学校长时期，“循思想自由原则、取兼容并包之义”，推行改革，把北大办成以文、理两科为重点的综合性大学，使北京大学成为新文化运动和五四运动的策源地。1937年中华民国政府在平津作战失守北平后，北大与清华、南开迁昆明组建新的国立西南联合大学，留守北京的学者于1939-1945年在北京成立沦陷区北京大学招收留守北京的贫寒学生，1946年北京大学由昆明回迁北平，接收了沦陷区北大学生。1952年院系调整后，北京大学聚集了原北大、清华、燕大三校的自然科学、人文学者，奠定了北大文理学科在中国高校中长期领先的地位。2000年，北京医科大学并入北京大学，成为北京大学医学部。");
    dw2->setWidget(edit2);
    addDockWidget(Qt::RightDockWidgetArea,dw2);
}

