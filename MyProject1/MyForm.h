#pragma once
#include "chessboard.h"

namespace MyProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: Pos pos1 = NONE_POS, pos2 = NONE_POS;
	private: Fill mode = Fill::EMPTY;
	private: Chessboard^ chess = gcnew Chessboard(mode);
	private: int counter = 0;
	private: System::Windows::Forms::Label^ label3;


	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Location = System::Drawing::Point(10, 10);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(654, 654);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(853, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 69);
			this->label1->TabIndex = 1;
			this->label1->Text = L"PC Chess";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::SandyBrown;
			this->panel2->Location = System::Drawing::Point(865, 76);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(265, 5);
			this->panel2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(700, 213);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(259, 47);
			this->label2->TabIndex = 1;
			this->label2->Text = L"choose mode:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->Checked = true;
			this->radioButton1->FlatAppearance->BorderSize = 2;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Montserrat", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButton1->ForeColor = System::Drawing::Color::SandyBrown;
			this->radioButton1->Location = System::Drawing::Point(708, 258);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(187, 50);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"CLASSIC";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->FlatAppearance->BorderSize = 2;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Montserrat", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButton2->ForeColor = System::Drawing::Color::SandyBrown;
			this->radioButton2->Location = System::Drawing::Point(708, 302);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(288, 50);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"KNIGHT FIGHT";
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SandyBrown;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->Location = System::Drawing::Point(708, 564);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 80);
			this->button1->TabIndex = 4;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatAppearance->BorderSize = 6;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::SandyBrown;
			this->button2->Location = System::Drawing::Point(978, 564);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(250, 80);
			this->button2->TabIndex = 4;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->FlatAppearance->BorderSize = 2;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Montserrat", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButton3->ForeColor = System::Drawing::Color::SandyBrown;
			this->radioButton3->Location = System::Drawing::Point(708, 348);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(278, 50);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Text = L"PAWNS ONLY";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat Light", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(701, 503);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 46);
			this->label3->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1261, 673);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		for (int counter = 1; counter < 65; counter++)
		{
			Graphics^ g = e->Graphics;
			Image^ newImage;

			int row = ((Pos)counter - 1) / 8;
			int column = (Pos)counter - row * 8;

			if ((Pos)counter == pos1)
			{
				if (chess[(Pos)counter]->getColor() == chess->m_currentMoveColor) newImage = Image::FromFile("select.png");
				else newImage = Image::FromFile("select2.png");
				g->DrawImage(newImage, (column - 1) * 61, 448 - row * 61);
			}
			if (pos1 != Pos::NONE_POS && (chess->movePossible(pos1, (Pos)counter)))
			{
				newImage = Image::FromFile("select.png");
				g->DrawImage(newImage, (column - 1) * 61, 448 - row * 61);
			}
			switch (chess[(Pos)counter]->getId())
			{
			case NONE:
				newImage = Image::FromFile("en.png");
				break;
			case PAWN:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("pw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("pb.png");
					break;
				}
				break;
			case ROOK:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("rw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("rb.png");
					break;
				}
				break;
			case KNIGHT:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("nw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("nb.png");
					break;
				}
				break;
			case BISHOP:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("bw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("bb.png");
					break;
				}
				break;
			case QUEEN:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("qw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("qb.png");
					break;
				}
				break;
			case KING:
				switch (chess[(Pos)counter]->getColor())
				{
				case WHITE:
					newImage = Image::FromFile("kw.png");
					break;
				case BLACK:
					newImage = Image::FromFile("kb.png");
					break;
				}
				break;
			}

			g->DrawImage(newImage, (column - 1) * 61, 448 - row * 61);
		}
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		// Create image.
		Image^ newImage = Image::FromFile("board.jpg");;

		//g->DrawImage(newImage, 10, 10, 500, 500);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked)
		{
			radioButton2->Checked = false;
			radioButton3->Checked = false;
		}
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton2->Checked)
		{
			radioButton1->Checked = false;
			radioButton3->Checked = false;
		}
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton3->Checked)
		{
			radioButton1->Checked = false;
			radioButton2->Checked = false;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		draw(e);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked) mode = Fill::CLASSIC;
		else if (radioButton2->Checked) mode = Fill::KNIGHT_FIGHT;
		else if (radioButton3->Checked) mode = Fill::PAWS_ONLY;
		button1->Text = "RESTART";
		delete chess;
		chess = gcnew Chessboard(mode);
		pos1 = NONE_POS;
		label3->Text = "WHITE MOVE";
		Invalidate();
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int column = (e->X / 61) + 1;
		int row = (8 - (e->Y + 28) / 61);
		if (pos1 == Pos::NONE_POS)
		{
			pos1 = (Pos)(row * 8 + column);
			Invalidate();
		}
		else
		{
			pos2 = (Pos)(row * 8 + column);
			if (chess->movePossible(pos1, pos2))
			{
				chess->move(pos1, pos2);
				if (chess->m_currentMoveColor == WHITE) label3->Text = "WHITE MOVE";
				else label3->Text = "BLACK MOVE";
			}
			pos1 = Pos::NONE_POS;
			pos2 = Pos::NONE_POS;
			Invalidate();
		}
	}
	};
}
