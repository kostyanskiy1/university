#include "MyForm.h"

#include <Windows.h>
#include <stdio.h>
#include <List>
#include <wingdi.h>

#include <dos.h>

#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab3::MyForm form;
	Application::Run(% form);
}

struct Vector2D {
	int X,
		Y,
		difX,
		difY;
};
Vector2D mousePosition;

Lab3::MyForm::MyForm(void)
{
	InitializeComponent();

	// фильтр для выбора файлов
	openFileDialog1->Filter = "Файлы (*.bmp, *.jpg, *.png)|*.bmp;*.jpg;*.png";
	saveFileDialog1->Filter = "Файлы (*.bmp, *.jpg, *.png)|*.bmp;*.jpg;*.png";
}

System::Void Lab3::MyForm::pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e)
{

	//если изменить размеры PictureBox
	if (pictureBox1->Image) { //если что-то нарисовано, скопировать через Bitmap и перерисовать картинку	

		if (background)
			background = gcnew Bitmap(background, pictureBox1->Width, pictureBox1->Height);
		else
			background = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);

		delete canvas;
		canvas = Graphics::FromImage(background);
		pictureBox1->Image = background;
		pictureBox1->Refresh();
		pictureBox1->Invalidate();
	}
}

System::Void Lab3::MyForm::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	//проверка пера или ластика
	if ((statePen == 1)|| (statePen == 4)) {
		
		points->Clear();//каждый раз рисуем заново, поэтому очищаем
		points->Add(e->Location);//çàïîìèíàåì òî÷êó
		draw = true;//разрешаем рисовать

		pictureBox1->SizeMode = PictureBoxSizeMode::Normal;
	}
	else {
		//запоминаем позицию мышки
		mousePosition.X = e->Location.X;
		mousePosition.Y = e->Location.Y;
	}

	pictureBox1->Invalidate();//перерисовываем 
}

System::Void Lab3::MyForm::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	//проверяем, можео ли рисовать
	if (draw && points->Contains(Point(e->X, e->Y)) == false) {
		//проверяем нажатие левой кнопки мыши
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			//добавляем точку
			points->Add(e->Location);
		}
	 
		pictureBox1->Invalidate();
	}
}

System::Void Lab3::MyForm::pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	mousePosition.difX= e->Location.X - mousePosition.X ;//считаем значение по Х и Y , на сколько мы переместили мышку, чтобы нарисовать прямоугольник и окружность
	mousePosition.difY = e->Location.Y - mousePosition.Y ;
	draw = false;//запрещаем рисовать
	pictureBox1->Invalidate();

	if (statePen==2)//рисукм прямоугольник
	{
		
			canvas->DrawRectangle(pen, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
	}

	if (statePen == 3)//рисуем окружность
	{
		
			canvas->DrawEllipse(pen, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
	}

	if (statePen == 5)//заливаем окружность
	{
		canvas->DrawEllipse(pen, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
		canvas->FillEllipse(solidbrush, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
	}
	
	if (statePen == 6)//заливаем прямоугольник
	{
		canvas->DrawRectangle(pen, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
		canvas->FillRectangle(solidbrush, mousePosition.X, mousePosition.Y, mousePosition.difX, mousePosition.difY);
	}


	mousePosition.X = -1;
	mousePosition.Y = -1;
}

System::Void Lab3::MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	
	//проверяем, чем рисуем
	switch (statePen)
	{
	case 1://карандаш
		if (points->Count > 1) {
			
			canvas->DrawLines(pen, points->ToArray());
		}
		break;



	case 4://ластик
		if (points->Count > 1) {
								
			canvas->DrawLines(rubber, points->ToArray());
		}
		break;
		

	default:
		break;
	}

	if (clearAll) {
		points->Clear();
		canvas->Clear(Color::White);
		clearAll = false;

		mousePosition.X = -1;
		mousePosition.Y = -1;

		
		DrawBackground();
	}
}

System::Void Lab3::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//инициализируем данные
	color = Color::Black;
	size = 1;

	rubber = gcnew Pen(Color::White, size);
	pen = gcnew Pen(color, size);

	//pen->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
	//HatchBrush^ hBrush = gcnew HatchBrush(HatchStyle::ZigZag, Color::White, Color::Blue);
	
	
	solidbrush = gcnew SolidBrush(Color::Black );

	points = gcnew List <Point>();
	draw = false;
	statePen = 1;

	buttonLine->BackColor = Color::Green;

	//меняем цвет кнопкам
	buttonCircle->BackColor = Color::LightGray;
	buttonSquare->BackColor = Color::LightGray;
	buttonFillingCircle->BackColor = Color::LightGray;
	buttonFillingSquare->BackColor = Color::LightGray;
	buttonRubber->BackColor = Color::LightGray;

	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);//создаем пустое изображение
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;
	

	clearAll = false;

	filename = "openFileDialog1";

	buttonColor->BackColor = color;

	return System::Void();
}


void Lab3::MyForm::DrawBackground()
{
	//Применяем фон
	if (filename != "openFileDialog1") {
		background = gcnew Bitmap(filename);
		background = gcnew Bitmap(background, pictureBox1->Width, pictureBox1->Height);
	}
	else
		background = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);

	delete canvas;
	canvas = Graphics::FromImage(background);
	pictureBox1->Image = background;
	pictureBox1->Refresh();
	pictureBox1->Invalidate();
}

System::Void Lab3::MyForm::ВыходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}





System::Void Lab3::MyForm::СохранитьКакToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ fname;
	saveFileDialog1->ShowDialog();//показываем диалог для сохпранения
	fname = saveFileDialog1->FileName;//запоминаем расположение сохранения

	//проверяем 
	if (fname == "")
		return;

	//запоминаем изображение
	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	img->Save(fname);//сохраняем

	MessageBox::Show("Изображение сохранено по адресу \"" + fname + "\".");

	return System::Void();
}



System::Void Lab3::MyForm::buttonApplySize_Click(System::Object^ sender, System::EventArgs^ e)
{
	size = Convert::ToSingle(numericUpDownSize->Value);//применяем размер карандаша и ластика
	pen = gcnew Pen(color, size);
	rubber = gcnew Pen(color.White, size);

	return System::Void();
}

System::Void Lab3::MyForm::buttonColor_Click(System::Object^ sender, System::EventArgs^ e)
{
	colorDialog1->ShowDialog();//выбиарем цвет
	color = colorDialog1->Color;

	buttonColor->BackColor = color;

	if (color == Color::Black) {
		buttonColor->ForeColor = Color::White;//если цвет черный, меняем цвет шрифта на кпопке на белый
	}
	else {
		buttonColor->ForeColor = Color::Black;
	}

	pen = gcnew Pen(color, size);
	solidbrush = gcnew SolidBrush(color);

	return System::Void();
}

System::Void Lab3::MyForm::buttonClearCanvas_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearAll = true;
	pictureBox1->Invalidate();

	return System::Void();
}

System::Void Lab3::MyForm::buttonLine_Click(System::Object^ sender, System::EventArgs^ e)
{
	//проверяем выбор пера
	if (statePen != 1) {

		
		statePen = 1;

		//менчем цвета кнопок

		buttonLine->BackColor = Color::Green;
		
		buttonCircle->BackColor = Color::LightGray;
		buttonSquare->BackColor = Color::LightGray;
		buttonRubber->BackColor = Color::LightGray;
		buttonFillingCircle->BackColor = Color::LightGray;
		buttonFillingSquare->BackColor = Color::LightGray;
	}

	return System::Void();
}

System::Void Lab3::MyForm::buttonSquare_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (statePen != 2) {
		
		statePen = 2;

		
		buttonSquare->BackColor = Color::Green;

		
		buttonCircle->BackColor = Color::LightGray;
		buttonRubber->BackColor = Color::LightGray;
		buttonLine->BackColor = Color::LightGray;
		buttonFillingCircle->BackColor = Color::LightGray;
		buttonFillingSquare->BackColor = Color::LightGray;
		
	}

	return System::Void();
}



System::Void Lab3::MyForm::buttonCircle_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (statePen != 3) {
		
		statePen = 3;
		
		buttonCircle->BackColor = Color::Green;

		buttonSquare->BackColor = Color::LightGray;
		buttonRubber->BackColor = Color::LightGray;
		buttonLine->BackColor = Color::LightGray;
		buttonFillingCircle->BackColor = Color::LightGray;
		buttonFillingSquare->BackColor = Color::LightGray;
		
	
	}
	
	return System::Void();
}







System::Void Lab3::MyForm::buttonRubber_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (statePen != 4) {


		statePen = 4;

	
		buttonRubber->BackColor = Color::Green;


		buttonCircle->BackColor = Color::LightGray;
		buttonSquare->BackColor = Color::LightGray;
		buttonLine->BackColor = Color::LightGray;
		buttonFillingCircle->BackColor = Color::LightGray;
		buttonFillingSquare->BackColor = Color::LightGray;
	}

	return System::Void();
}

System::Void Lab3::MyForm::buttonFillingCircle_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (statePen != 5) {

	
		statePen = 5;

	
		buttonFillingCircle->BackColor = Color::Green;

		buttonCircle->BackColor = Color::LightGray;
		buttonSquare->BackColor = Color::LightGray;
		buttonLine->BackColor = Color::LightGray;
		buttonRubber->BackColor = Color::LightGray;
		buttonFillingSquare->BackColor = Color::LightGray;

	}

	return System::Void();
}



System::Void Lab3::MyForm::buttonFillingSquare_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (statePen != 6) {

		statePen = 6;

		buttonFillingSquare->BackColor = Color::Green;

		buttonCircle->BackColor = Color::LightGray;
		buttonSquare->BackColor = Color::LightGray;
		buttonLine->BackColor = Color::LightGray;
		buttonRubber->BackColor = Color::LightGray;
		buttonFillingCircle->BackColor = Color::LightGray;
	}

	return System::Void();
}

