#include "mainwindow.h"
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("双缓冲绘图");
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);//将创建对象作为主窗口的中心窗体
    CreateToolBar();         //创建工具条
    setMinimumSize(600,400); //设置窗口最小宽度
    displayStyle();
    drawWidget->setWidth(spinboxLabelWidth->value());//初始化线条的宽度
    drawWidget->setColor(Qt::blue);//初始化线条颜色
}

MainWindow::~MainWindow()
{
}
//创建工具条
void MainWindow::CreateToolBar()
{
    QToolBar * toolBar = addToolBar("Tool");
    labelStyle = new QLabel("线型风格");
    //设置下拉列表选择线条类型
    comboxLabelStyle = new QComboBox;
    comboxLabelStyle->addItem("SolidLine",static_cast<int>(Qt::SolidLine));
    comboxLabelStyle->addItem("DotLine",static_cast<int>(Qt::DotLine));
    comboxLabelStyle->addItem("DashLine",static_cast<int>(Qt::DashLine));
    comboxLabelStyle->addItem("DashDotLine",static_cast<int>(Qt::DashDotLine));

    connect(comboxLabelStyle,&QComboBox::activated,this,&MainWindow::displayStyle);
    //设置线条宽度
    labelWidth = new QLabel("线型宽度");
    spinboxLabelWidth = new QSpinBox;
    connect(spinboxLabelWidth,&QSpinBox::valueChanged,drawWidget,&DrawWidget::setWidth);

    //填充颜色
    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,&QToolButton::clicked,this,&MainWindow::displayColor);
    //清除绘制的图画
    clearBtn = new QToolButton;
    clearBtn->setText("清除绘制");
    connect(clearBtn,&QToolButton::clicked,drawWidget,&DrawWidget::clearFunc);

    toolBar->addWidget(labelStyle);
    toolBar->addWidget(comboxLabelStyle);
    toolBar->addWidget(labelWidth);
    toolBar->addWidget(spinboxLabelWidth);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
}

void MainWindow::displayStyle()
{
    drawWidget->setStyle(comboxLabelStyle->itemData(comboxLabelStyle->currentIndex(),Qt::UserRole).toInt());
}

void MainWindow::displayColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black),this);
    if(color.isValid()){
        drawWidget->setColor(color);
        QPixmap ps(20,20);
        ps.fill(color);
    }
}

