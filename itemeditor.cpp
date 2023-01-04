#include "itemeditor.h"
#include "ui_itemeditor.h"

ItemEditor::ItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditor)
{
    ui->setupUi(this);
}

ItemEditor::~ItemEditor()
{
    delete ui;
}
