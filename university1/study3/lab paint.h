#pragma once

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;
	

	/// <summary>
	/// сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);


	protected:
		/// <summary>
		/// очистить все ресурсы
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ДействияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ВыходToolStripMenuItem;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ СохранитьКакToolStripMenuItem;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBoxToolbar;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSize;
	private: System::Windows::Forms::Button^ buttonCircle;
	private: System::Windows::Forms::Button^ buttonSquare;



	private: System::Windows::Forms::Button^ buttonLine;

	private: System::Windows::Forms::Button^ buttonApplySize;
	private: System::Windows::Forms::Button^ buttonClearCanvas;
	private: System::Windows::Forms::Button^ buttonColor;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;



	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ buttonRubber;
	private: System::Windows::Forms::Button^ buttonFillingCircle;
	private: System::Windows::Forms::Button^ buttonFillingSquare;








	private:
		
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ДействияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->СохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ВыходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxToolbar = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFillingSquare = (gcnew System::Windows::Forms::Button());
			this->buttonFillingCircle = (gcnew System::Windows::Forms::Button());
			this->buttonRubber = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonCircle = (gcnew System::Windows::Forms::Button());
			this->buttonSquare = (gcnew System::Windows::Forms::Button());
			this->buttonLine = (gcnew System::Windows::Forms::Button());
			this->buttonApplySize = (gcnew System::Windows::Forms::Button());
			this->buttonClearCanvas = (gcnew System::Windows::Forms::Button());
			this->buttonColor = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBoxToolbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ДействияToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(826, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ДействияToolStripMenuItem
			// 
			this->ДействияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->СохранитьКакToolStripMenuItem,
					this->ВыходToolStripMenuItem
			});
			this->ДействияToolStripMenuItem->Name = L"ДействияToolStripMenuItem";
			this->ДействияToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->ДействияToolStripMenuItem->Text = L"Действия";
			// 
			// СохранитьКакToolStripMenuItem
			// 
			this->СохранитьКакToolStripMenuItem->Name = L"СохранитьКакToolStripMenuItem";
			this->СохранитьКакToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->СохранитьКакToolStripMenuItem->Text = L"Сохранить как";
			this->СохранитьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::СохранитьКакToolStripMenuItem_Click);
			// 
			// ВыходToolStripMenuItem
			// 
			this->ВыходToolStripMenuItem->Name = L"ВыходToolStripMenuItem";
			this->ВыходToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->ВыходToolStripMenuItem->Text = L"Выход";
			this->ВыходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ВыходToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(826, 395);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &MyForm::pictureBox1_SizeChanged);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// groupBoxToolbar
			// 
			this->groupBoxToolbar->Controls->Add(this->buttonFillingSquare);
			this->groupBoxToolbar->Controls->Add(this->buttonFillingCircle);
			this->groupBoxToolbar->Controls->Add(this->buttonRubber);
			this->groupBoxToolbar->Controls->Add(this->numericUpDownSize);
			this->groupBoxToolbar->Controls->Add(this->buttonCircle);
			this->groupBoxToolbar->Controls->Add(this->buttonSquare);
			this->groupBoxToolbar->Controls->Add(this->buttonLine);
			this->groupBoxToolbar->Controls->Add(this->buttonApplySize);
			this->groupBoxToolbar->Controls->Add(this->buttonClearCanvas);
			this->groupBoxToolbar->Controls->Add(this->buttonColor);
			this->groupBoxToolbar->Controls->Add(this->label2);
			this->groupBoxToolbar->Location = System::Drawing::Point(12, 27);
			this->groupBoxToolbar->Name = L"groupBoxToolbar";
			this->groupBoxToolbar->Size = System::Drawing::Size(802, 89);
			this->groupBoxToolbar->TabIndex = 2;
			this->groupBoxToolbar->TabStop = false;
			this->groupBoxToolbar->Text = L"Панель элементов";
			// 
			// buttonFillingSquare
			// 
			this->buttonFillingSquare->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFillingSquare->Location = System::Drawing::Point(532, 51);
			this->buttonFillingSquare->Name = L"buttonFillingSquare";
			this->buttonFillingSquare->Size = System::Drawing::Size(137, 29);
			this->buttonFillingSquare->TabIndex = 12;
			this->buttonFillingSquare->Text = L"Заливка Квадрата";
			this->buttonFillingSquare->UseVisualStyleBackColor = true;
			this->buttonFillingSquare->Click += gcnew System::EventHandler(this, &MyForm::buttonFillingSquare_Click);
			// 
			// buttonFillingCircle
			// 
			this->buttonFillingCircle->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFillingCircle->Location = System::Drawing::Point(532, 20);
			this->buttonFillingCircle->Name = L"buttonFillingCircle";
			this->buttonFillingCircle->Size = System::Drawing::Size(137, 29);
			this->buttonFillingCircle->TabIndex = 11;
			this->buttonFillingCircle->Text = L"Заливка Круга";
			this->buttonFillingCircle->UseVisualStyleBackColor = true;
			this->buttonFillingCircle->Click += gcnew System::EventHandler(this, &MyForm::buttonFillingCircle_Click);
			// 
			// buttonRubber
			// 
			this->buttonRubber->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRubber->Location = System::Drawing::Point(428, 51);
			this->buttonRubber->Name = L"buttonRubber";
			this->buttonRubber->Size = System::Drawing::Size(98, 29);
			this->buttonRubber->TabIndex = 10;
			this->buttonRubber->Text = L"Ластик";
			this->buttonRubber->UseVisualStyleBackColor = true;
			this->buttonRubber->Click += gcnew System::EventHandler(this, &MyForm::buttonRubber_Click);
			// 
			// numericUpDownSize
			// 
			this->numericUpDownSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownSize->Location = System::Drawing::Point(27, 54);
			this->numericUpDownSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSize->Name = L"numericUpDownSize";
			this->numericUpDownSize->Size = System::Drawing::Size(71, 26);
			this->numericUpDownSize->TabIndex = 9;
			this->numericUpDownSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// buttonCircle
			// 
			this->buttonCircle->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCircle->Location = System::Drawing::Point(698, 19);
			this->buttonCircle->Name = L"buttonCircle";
			this->buttonCircle->Size = System::Drawing::Size(98, 29);
			this->buttonCircle->TabIndex = 7;
			this->buttonCircle->Text = L"Круг";
			this->buttonCircle->UseVisualStyleBackColor = true;
			this->buttonCircle->Click += gcnew System::EventHandler(this, &MyForm::buttonCircle_Click);
			// 
			// buttonSquare
			// 
			this->buttonSquare->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSquare->Location = System::Drawing::Point(698, 54);
			this->buttonSquare->Name = L"buttonSquare";
			this->buttonSquare->Size = System::Drawing::Size(98, 29);
			this->buttonSquare->TabIndex = 6;
			this->buttonSquare->Text = L"Квадрат";
			this->buttonSquare->UseVisualStyleBackColor = true;
			this->buttonSquare->Click += gcnew System::EventHandler(this, &MyForm::buttonSquare_Click);
			// 
			// buttonLine
			// 
			this->buttonLine->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLine->Location = System::Drawing::Point(428, 19);
			this->buttonLine->Name = L"buttonLine";
			this->buttonLine->Size = System::Drawing::Size(98, 29);
			this->buttonLine->TabIndex = 5;
			this->buttonLine->Text = L"Линия";
			this->buttonLine->UseVisualStyleBackColor = true;
			this->buttonLine->Click += gcnew System::EventHandler(this, &MyForm::buttonLine_Click);
			// 
			// buttonApplySize
			// 
			this->buttonApplySize->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonApplySize->Location = System::Drawing::Point(6, 19);
			this->buttonApplySize->Name = L"buttonApplySize";
			this->buttonApplySize->Size = System::Drawing::Size(151, 29);
			this->buttonApplySize->TabIndex = 4;
			this->buttonApplySize->Text = L"Применить размер";
			this->buttonApplySize->UseVisualStyleBackColor = true;
			this->buttonApplySize->Click += gcnew System::EventHandler(this, &MyForm::buttonApplySize_Click);
			// 
			// buttonClearCanvas
			// 
			this->buttonClearCanvas->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClearCanvas->Location = System::Drawing::Point(163, 19);
			this->buttonClearCanvas->Name = L"buttonClearCanvas";
			this->buttonClearCanvas->Size = System::Drawing::Size(147, 29);
			this->buttonClearCanvas->TabIndex = 3;
			this->buttonClearCanvas->Text = L"Очистить холст";
			this->buttonClearCanvas->UseVisualStyleBackColor = true;
			this->buttonClearCanvas->Click += gcnew System::EventHandler(this, &MyForm::buttonClearCanvas_Click);
			// 
			// buttonColor
			// 
			this->buttonColor->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonColor->Location = System::Drawing::Point(336, 19);
			this->buttonColor->Name = L"buttonColor";
			this->buttonColor->Size = System::Drawing::Size(75, 29);
			this->buttonColor->TabIndex = 2;
			this->buttonColor->Text = L"Цвет";
			this->buttonColor->UseVisualStyleBackColor = true;
			this->buttonColor->Click += gcnew System::EventHandler(this, &MyForm::buttonColor_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(600, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Фигуры";
			// 
			
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 419);
			this->Controls->Add(this->groupBoxToolbar);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LAB3 PAINT";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBoxToolbar->ResumeLayout(false);
			this->groupBoxToolbar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Graphics^ canvas;//полотно
		List <Point>^ points;//точки, по которой рисуем линию
		Pen^ pen;//перо
		Pen^ rubber;//ластик
		SolidBrush^ solidbrush;//заливка
		bool draw;//можно ли рисовать
		Bitmap^ background;//фон
		Color color;//цвет
		float size;
		bool clearAll;
		String^ filename;
		int statePen;//выбор рисования
		
		
		

	private: System::Void pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ВыходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void СохранитьКакToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonApplySize_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonClearCanvas_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonLine_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSquare_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void buttonCircle_Click(System::Object^ sender, System::EventArgs^ e);
	
	
	private: void DrawBackground();
	
	private: System::Void buttonRubber_Click(System::Object^ sender, System::EventArgs^ e);

		  

private: System::Void buttonFillingCircle_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonFillingSquare_Click(System::Object^ sender, System::EventArgs^ e);




};
}
