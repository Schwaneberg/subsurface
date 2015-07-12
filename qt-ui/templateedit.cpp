#include "templateedit.h"
#include "printoptions.h"
#include "printer.h"
#include "ui_templateedit.h"

#include <QMessageBox>
#include <QColorDialog>

TemplateEdit::TemplateEdit(QWidget *parent, struct print_options *printOptions, struct template_options *templateOptions) :
	QDialog(parent),
	ui(new Ui::TemplateEdit)
{
	ui->setupUi(this);
	this->templateOptions = templateOptions;
	newTemplateOptions = *templateOptions;
	this->printOptions = printOptions;

	// restore the settings and init the UI
	ui->fontSelection->setCurrentIndex(templateOptions->font_index);
	ui->fontsize->setValue(templateOptions->font_size);
	ui->colorpalette->setCurrentIndex(templateOptions->color_palette_index);
	ui->linespacing->setValue(templateOptions->line_spacing);

	if (printOptions->p_template == print_options::ONE_DIVE) {
		grantlee_template = TemplateLayout::readTemplate("one_dive.html");
	} else if (printOptions->p_template == print_options::TWO_DIVE) {
		grantlee_template = TemplateLayout::readTemplate("two_dives.html");
	} else if (printOptions->p_template == print_options::CUSTOM) {
		grantlee_template = TemplateLayout::readTemplate("custom.html");
	}

	// gui
	btnGroup = new QButtonGroup;
	btnGroup->addButton(ui->editButton1, 1);
	btnGroup->addButton(ui->editButton2, 2);
	btnGroup->addButton(ui->editButton3, 3);
	btnGroup->addButton(ui->editButton4, 4);
	btnGroup->addButton(ui->editButton5, 5);
	connect(btnGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(colorSelect(QAbstractButton*)));

	ui->plainTextEdit->setPlainText(grantlee_template);
	updatePreview();
}

TemplateEdit::~TemplateEdit()
{
	delete btnGroup;
	delete ui;
}

void TemplateEdit::updatePreview()
{
	// update Qpixmap preview
	int width = ui->label->width();
	int height = ui->label->height();
	QPixmap map(width * 2, height * 2);
	map.fill(QColor::fromRgb(255, 255, 255));
	Printer printer(&map, printOptions, &newTemplateOptions, Printer::PREVIEW);
	printer.previewOnePage();
	ui->label->setPixmap(map.scaled(width, height, Qt::IgnoreAspectRatio));

	// update colors tab
	ui->colorLable1->setStyleSheet("QLabel { background-color : \"" + newTemplateOptions.color_palette.color1.name() + "\";}");
	ui->colorLable2->setStyleSheet("QLabel { background-color : \"" + newTemplateOptions.color_palette.color2.name() + "\";}");
	ui->colorLable3->setStyleSheet("QLabel { background-color : \"" + newTemplateOptions.color_palette.color3.name() + "\";}");
	ui->colorLable4->setStyleSheet("QLabel { background-color : \"" + newTemplateOptions.color_palette.color4.name() + "\";}");
	ui->colorLable5->setStyleSheet("QLabel { background-color : \"" + newTemplateOptions.color_palette.color5.name() + "\";}");

	ui->colorLable1->setText(newTemplateOptions.color_palette.color1.name());
	ui->colorLable2->setText(newTemplateOptions.color_palette.color2.name());
	ui->colorLable3->setText(newTemplateOptions.color_palette.color3.name());
	ui->colorLable4->setText(newTemplateOptions.color_palette.color4.name());
	ui->colorLable5->setText(newTemplateOptions.color_palette.color5.name());
}

void TemplateEdit::on_fontsize_valueChanged(int font_size)
{
	newTemplateOptions.font_size = font_size;
	updatePreview();
}

void TemplateEdit::on_linespacing_valueChanged(double line_spacing)
{
	newTemplateOptions.line_spacing = line_spacing;
	updatePreview();
}

void TemplateEdit::on_fontSelection_currentIndexChanged(int index)
{
	newTemplateOptions.font_index = index;
	updatePreview();
}

void TemplateEdit::on_colorpalette_currentIndexChanged(int index)
{
	newTemplateOptions.color_palette_index = index;
	updatePreview();
}

void TemplateEdit::saveSettings()
{
	if ((*templateOptions) != newTemplateOptions || grantlee_template.compare(ui->plainTextEdit->toPlainText())) {
		QMessageBox msgBox;
		msgBox.setText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
		msgBox.setDefaultButton(QMessageBox::Discard);
		if (msgBox.exec() == QMessageBox::Save) {
			memcpy(templateOptions, &newTemplateOptions, sizeof(struct template_options));
			if (grantlee_template.compare(ui->plainTextEdit->toPlainText())) {
				printOptions->p_template = print_options::CUSTOM;
				TemplateLayout::writeTemplate("custom.html", ui->plainTextEdit->toPlainText());
			}
		}
	}
}

void TemplateEdit::on_buttonBox_clicked(QAbstractButton *button)
{
	QDialogButtonBox::StandardButton standardButton = ui->buttonBox->standardButton(button);
	switch (standardButton) {
	case QDialogButtonBox::Ok:
		saveSettings();
		break;
	case QDialogButtonBox::Cancel:
		break;
	case QDialogButtonBox::Apply:
		saveSettings();
		updatePreview();
		break;
	}
}

void TemplateEdit::colorSelect(QAbstractButton *button)
{
	QColor color;
	switch (btnGroup->id(button)) {
	case 1:
		color = QColorDialog::getColor(newTemplateOptions.color_palette.color1, this);
		newTemplateOptions.color_palette.color1 = color;
		break;
	case 2:
		color = QColorDialog::getColor(newTemplateOptions.color_palette.color2, this);
		newTemplateOptions.color_palette.color2 = color;
		break;
	case 3:
		color = QColorDialog::getColor(newTemplateOptions.color_palette.color3, this);
		newTemplateOptions.color_palette.color3 = color;
		break;
	case 4:
		color = QColorDialog::getColor(newTemplateOptions.color_palette.color4, this);
		newTemplateOptions.color_palette.color4 = color;
		break;
	case 5:
		color = QColorDialog::getColor(newTemplateOptions.color_palette.color5, this);
		newTemplateOptions.color_palette.color5 = color;
		break;
	}
	updatePreview();
}
