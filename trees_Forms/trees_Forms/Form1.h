#pragma once

namespace trees_Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  justTree;
	private: System::Windows::Forms::Label^  labelNumber;
	private: System::Windows::Forms::TextBox^  number;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  addNode;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  Add;





	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->justTree = (gcnew System::Windows::Forms::Button());
			this->labelNumber = (gcnew System::Windows::Forms::Label());
			this->number = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addNode = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Margin = System::Windows::Forms::Padding(200, 3, 3, 3);
			this->panel1->MaximumSize = System::Drawing::Size(1600, 900);
			this->panel1->MinimumSize = System::Drawing::Size(746, 544);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1045, 544);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// justTree
			// 
			this->justTree->Location = System::Drawing::Point(187, 21);
			this->justTree->Name = L"justTree";
			this->justTree->Size = System::Drawing::Size(75, 23);
			this->justTree->TabIndex = 0;
			this->justTree->Text = L"Just tree";
			this->justTree->UseVisualStyleBackColor = true;
			this->justTree->Click += gcnew System::EventHandler(this, &Form1::justTree_Click);
			// 
			// labelNumber
			// 
			this->labelNumber->AutoSize = true;
			this->labelNumber->Location = System::Drawing::Point(6, 21);
			this->labelNumber->Name = L"labelNumber";
			this->labelNumber->Size = System::Drawing::Size(62, 17);
			this->labelNumber->TabIndex = 1;
			this->labelNumber->Text = L"Number:";
			this->labelNumber->Click += gcnew System::EventHandler(this, &Form1::labelNumber_Click);
			// 
			// number
			// 
			this->number->Location = System::Drawing::Point(81, 21);
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(100, 22);
			this->number->TabIndex = 2;
			this->number->TextChanged += gcnew System::EventHandler(this, &Form1::number_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(779, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Add node:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// addNode
			// 
			this->addNode->Location = System::Drawing::Point(858, 18);
			this->addNode->Name = L"addNode";
			this->addNode->Size = System::Drawing::Size(100, 22);
			this->addNode->TabIndex = 4;
			this->addNode->TextChanged += gcnew System::EventHandler(this, &Form1::addNode_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->Add);
			this->groupBox1->Controls->Add(this->addNode);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->number);
			this->groupBox1->Controls->Add(this->labelNumber);
			this->groupBox1->Controls->Add(this->justTree);
			this->groupBox1->Location = System::Drawing::Point(3, 9);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1045, 251);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Make Tree";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(967, 15);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(75, 23);
			this->Add->TabIndex = 5;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Form1::Add_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1045, 568);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
			 binaryTree x( n, 100);
	private: System::Void justTree_Click(System::Object^  sender, System::EventArgs^  e) {


				//int n = Convert::ToInt32(number->Text);
				  
				
				 Graphics^ gr = this -> panel1 -> CreateGraphics();
				 gr ->  Clear( Color::Teal );
	
				 PrintT(gr,x.getRoot(),0,this->panel1->Width-26,5,-1);
			 
			 }
	private: System::Void number_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void labelNumber_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Add_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt32(addNode->Text);
			 x.addNode (x.getRoot(), n);
		 }
private: System::Void addNode_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

