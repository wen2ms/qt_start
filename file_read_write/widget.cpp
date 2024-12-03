#include "widget.h"

#include <QFile>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>

#include "file_read_write_config.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {    
    QWidget* widget = new QWidget(this);
    
    QLineEdit* line_edit = new QLineEdit(this);
    QPushButton* pushbutton = new QPushButton("Open File With...", this);
    
    QHBoxLayout* horizontal_layout = new QHBoxLayout();
    horizontal_layout->addWidget(line_edit);
    horizontal_layout->addWidget(pushbutton);
    
    widget->setLayout(horizontal_layout);
    
    QWidget* text_read = new QWidget(this);
    
    QTextEdit* textedit_readall = new QTextEdit(this);
    QTextEdit* textedit_readline = new QTextEdit(this);
    
    QHBoxLayout* read_text_layout = new QHBoxLayout();
    read_text_layout->addWidget(textedit_readall);
    read_text_layout->addWidget(textedit_readline);
    
    text_read->setLayout(read_text_layout);
    
    QVBoxLayout* vertical_layout = new QVBoxLayout();
    vertical_layout->addWidget(widget);
    vertical_layout->addWidget(text_read);
    
    this->setLayout(vertical_layout);
    this->resize(800, 600);
    
    connect(pushbutton, &QPushButton::clicked, this, [=]() {
        const QString kFilename = QFileDialog::getOpenFileName(this);
        line_edit->setText(kFilename);
        
        QFile infile(kFilename);
        if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }
        
        textedit_readall->setText(infile.readAll());
        
        infile.reset();
        
        QByteArray text_array;
        while (!infile.atEnd()) {
            text_array.push_back(infile.readLine());
        }
        
        textedit_readline->setText(text_array);
        
        infile.close();
        
        QFile outfile(QString(PROJECT_TEXT_DIR) + "/text.txt");
        if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        
        outfile.write(textedit_readall->toPlainText().toUtf8());
        outfile.close();
    });
    
    
}

Widget::~Widget() {}
