#include "widget.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include "file_read_write_config.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {    
    QWidget* widget = new QWidget(this);
    
    QLineEdit* line_edit = new QLineEdit(this);
    line_edit->setReadOnly(true);
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
        const QString kFilename = QFileDialog::getOpenFileName(this, QString(), PROJECT_SOURCE_DIR);
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
        
        const QString kOutFilename = QString(PROJECT_SOURCE_DIR) + "/text.txt";
        
        QFile outfile(kOutFilename);
        if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        
        outfile.write(textedit_readall->toPlainText().toUtf8());
        outfile.close();
        
        QFileInfo infile_info(infile);
        
        qDebug() << "Size:" << infile_info.size() << "Extension:" << infile_info.suffix() << "Filename:" << infile_info.fileName();
        qDebug() << "Created time" << infile_info.birthTime().toString();
    });
    
    
}

Widget::~Widget() {}
