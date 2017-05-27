#pragma once

binaryTree A;
SearchTree B;
Node * AddHead; //���� ��� ��������� ������ ������������
Node * prevAdd; //���������� �����������
Node * prevFind;  //���������� ���������
Node * STprevFind;

namespace trees_Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::Button^  show_Tree;
	private: System::Windows::Forms::Button^  findKeyBut;
	private: System::Windows::Forms::TextBox^  textFindKey;
	private: System::Windows::Forms::Label^  labelFindNode;
	private: System::Windows::Forms::Button^  butDelete;
	private: System::Windows::Forms::TextBox^  textDelete;
	private: System::Windows::Forms::Label^  labelDelete;
	private: System::Windows::Forms::TextBox^  textObhod;
	private: System::Windows::Forms::Button^  obhodBut;
	private: System::Windows::Forms::Button^  sTreeBut;
	private: System::Windows::Forms::Button^  print_ST;
	private: System::Windows::Forms::Button^  find_ST_but;
	private: System::Windows::Forms::Button^  delete_ST_butt;






	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
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
			this->find_ST_but = (gcnew System::Windows::Forms::Button());
			this->print_ST = (gcnew System::Windows::Forms::Button());
			this->sTreeBut = (gcnew System::Windows::Forms::Button());
			this->obhodBut = (gcnew System::Windows::Forms::Button());
			this->textObhod = (gcnew System::Windows::Forms::TextBox());
			this->butDelete = (gcnew System::Windows::Forms::Button());
			this->textDelete = (gcnew System::Windows::Forms::TextBox());
			this->labelDelete = (gcnew System::Windows::Forms::Label());
			this->findKeyBut = (gcnew System::Windows::Forms::Button());
			this->textFindKey = (gcnew System::Windows::Forms::TextBox());
			this->labelFindNode = (gcnew System::Windows::Forms::Label());
			this->show_Tree = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->delete_ST_butt = (gcnew System::Windows::Forms::Button());
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
			this->groupBox1->Controls->Add(this->delete_ST_butt);
			this->groupBox1->Controls->Add(this->find_ST_but);
			this->groupBox1->Controls->Add(this->print_ST);
			this->groupBox1->Controls->Add(this->sTreeBut);
			this->groupBox1->Controls->Add(this->obhodBut);
			this->groupBox1->Controls->Add(this->textObhod);
			this->groupBox1->Controls->Add(this->butDelete);
			this->groupBox1->Controls->Add(this->textDelete);
			this->groupBox1->Controls->Add(this->labelDelete);
			this->groupBox1->Controls->Add(this->findKeyBut);
			this->groupBox1->Controls->Add(this->textFindKey);
			this->groupBox1->Controls->Add(this->labelFindNode);
			this->groupBox1->Controls->Add(this->show_Tree);
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
			// find_ST_but
			// 
			this->find_ST_but->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->find_ST_but->Location = System::Drawing::Point(883, 169);
			this->find_ST_but->Name = L"find_ST_but";
			this->find_ST_but->Size = System::Drawing::Size(75, 22);
			this->find_ST_but->TabIndex = 17;
			this->find_ST_but->Text = L"Find ST";
			this->find_ST_but->UseVisualStyleBackColor = true;
			this->find_ST_but->Click += gcnew System::EventHandler(this, &Form1::find_ST_but_Click);
			// 
			// print_ST
			// 
			this->print_ST->Location = System::Drawing::Point(372, 222);
			this->print_ST->Name = L"print_ST";
			this->print_ST->Size = System::Drawing::Size(75, 23);
			this->print_ST->TabIndex = 16;
			this->print_ST->Text = L"Show ST";
			this->print_ST->UseVisualStyleBackColor = true;
			this->print_ST->Click += gcnew System::EventHandler(this, &Form1::print_ST_Click);
			// 
			// sTreeBut
			// 
			this->sTreeBut->Location = System::Drawing::Point(187, 50);
			this->sTreeBut->Name = L"sTreeBut";
			this->sTreeBut->Size = System::Drawing::Size(75, 23);
			this->sTreeBut->TabIndex = 15;
			this->sTreeBut->Text = L"S. tree";
			this->sTreeBut->UseVisualStyleBackColor = true;
			this->sTreeBut->Click += gcnew System::EventHandler(this, &Form1::sTreeBut_Click);
			// 
			// obhodBut
			// 
			this->obhodBut->Location = System::Drawing::Point(463, 98);
			this->obhodBut->Name = L"obhodBut";
			this->obhodBut->Size = System::Drawing::Size(75, 46);
			this->obhodBut->TabIndex = 14;
			this->obhodBut->Text = L"Show elements";
			this->obhodBut->UseVisualStyleBackColor = true;
			this->obhodBut->Click += gcnew System::EventHandler(this, &Form1::obhodBut_Click);
			// 
			// textObhod
			// 
			this->textObhod->Location = System::Drawing::Point(299, 21);
			this->textObhod->Multiline = true;
			this->textObhod->Name = L"textObhod";
			this->textObhod->Size = System::Drawing::Size(454, 71);
			this->textObhod->TabIndex = 13;
			this->textObhod->TextChanged += gcnew System::EventHandler(this, &Form1::textObhod_TextChanged);
			// 
			// butDelete
			// 
			this->butDelete->Location = System::Drawing::Point(964, 75);
			this->butDelete->Name = L"butDelete";
			this->butDelete->Size = System::Drawing::Size(75, 23);
			this->butDelete->TabIndex = 12;
			this->butDelete->Text = L"Delete";
			this->butDelete->UseVisualStyleBackColor = true;
			this->butDelete->Click += gcnew System::EventHandler(this, &Form1::butDelete_Click);
			// 
			// textDelete
			// 
			this->textDelete->Location = System::Drawing::Point(858, 75);
			this->textDelete->Name = L"textDelete";
			this->textDelete->Size = System::Drawing::Size(100, 22);
			this->textDelete->TabIndex = 11;
			this->textDelete->TextChanged += gcnew System::EventHandler(this, &Form1::textDelete_TextChanged);
			// 
			// labelDelete
			// 
			this->labelDelete->AutoSize = true;
			this->labelDelete->Location = System::Drawing::Point(775, 75);
			this->labelDelete->Name = L"labelDelete";
			this->labelDelete->Size = System::Drawing::Size(79, 17);
			this->labelDelete->TabIndex = 10;
			this->labelDelete->Text = L"Delete key:";
			this->labelDelete->Click += gcnew System::EventHandler(this, &Form1::labelDelete_Click);
			// 
			// findKeyBut
			// 
			this->findKeyBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->findKeyBut->Location = System::Drawing::Point(964, 46);
			this->findKeyBut->Name = L"findKeyBut";
			this->findKeyBut->Size = System::Drawing::Size(75, 22);
			this->findKeyBut->TabIndex = 9;
			this->findKeyBut->Text = L"Find key\r\n\r\n";
			this->findKeyBut->UseVisualStyleBackColor = true;
			this->findKeyBut->Click += gcnew System::EventHandler(this, &Form1::findKeyBut_Click);
			// 
			// textFindKey
			// 
			this->textFindKey->Location = System::Drawing::Point(858, 46);
			this->textFindKey->Name = L"textFindKey";
			this->textFindKey->Size = System::Drawing::Size(100, 22);
			this->textFindKey->TabIndex = 8;
			this->textFindKey->TextChanged += gcnew System::EventHandler(this, &Form1::textFindKey_TextChanged);
			// 
			// labelFindNode
			// 
			this->labelFindNode->AutoSize = true;
			this->labelFindNode->Location = System::Drawing::Point(775, 45);
			this->labelFindNode->Name = L"labelFindNode";
			this->labelFindNode->Size = System::Drawing::Size(77, 17);
			this->labelFindNode->TabIndex = 7;
			this->labelFindNode->Text = L"Find Node:";
			this->labelFindNode->Click += gcnew System::EventHandler(this, &Form1::labelFindNode_Click);
			// 
			// show_Tree
			// 
			this->show_Tree->Location = System::Drawing::Point(463, 222);
			this->show_Tree->Name = L"show_Tree";
			this->show_Tree->Size = System::Drawing::Size(75, 23);
			this->show_Tree->TabIndex = 6;
			this->show_Tree->Text = L"Show";
			this->show_Tree->UseVisualStyleBackColor = true;
			this->show_Tree->Click += gcnew System::EventHandler(this, &Form1::show_Tree_Click);
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
			// delete_ST_butt
			// 
			this->delete_ST_butt->Location = System::Drawing::Point(883, 197);
			this->delete_ST_butt->Name = L"delete_ST_butt";
			this->delete_ST_butt->Size = System::Drawing::Size(75, 23);
			this->delete_ST_butt->TabIndex = 18;
			this->delete_ST_butt->Text = L"Del. ST";
			this->delete_ST_butt->UseVisualStyleBackColor = true;
			this->delete_ST_butt->Click += gcnew System::EventHandler(this, &Form1::delete_ST_butt_Click);
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
			
	private: System::Void justTree_Click(System::Object^  sender, System::EventArgs^  e) {


				int n = Convert::ToInt32(number->Text);  //����������� ������
				 binaryTree x (n, 100); //����� ������ 
				 A=x; //����������� �����������
				 
			 
			 }
	private: System::Void number_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void labelNumber_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Add_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt32(addNode->Text);
			 if (prevAdd) {
				 prevAdd -> status = 0; //�������� ������ ����� ��� �����������
			 }
			 Node *T = new Node ( n, NULL, NULL, 1); //������� ����� ���� ��� ����������
			 AddHead = A.add_Node ( A.getRoot(), T ); //���������
			 prevAdd = T; //��������� ����������� ���� � ����������
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, A.getRoot(),0,this->panel1->Width-26,5,-1);
			 
		 }
private: System::Void addNode_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void show_Tree_Click(System::Object^  sender, System::EventArgs^  e) {
			Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, A.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
private: System::Void labelFindNode_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textFindKey_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void findKeyBut_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt32(textFindKey->Text);
			 if (prevFind) {
				 prevFind -> status = 0; //�������� ������ ����� ��� ����������� ����������
			 }
			 Node *T; 
			 T = A.findKey ( A.getRoot(), n); //������� ����� ���� ��� ����������
			 if ( T != NULL ) {
				T -> status = 2; 
			 }
			 prevFind = T; //��������� ��������� ���� � ����������
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, A.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
private: System::Void labelDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textDelete_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void butDelete_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt32(textDelete->Text);
			 A.deleteKey ( n );
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, A.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
private: System::Void textObhod_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void obhodBut_Click(System::Object^  sender, System::EventArgs^  e) {
			 textObhod -> Text = "\0";
			 System::String^ a;
			 A.obhod ( A.getRoot(), a);
			 textObhod -> Text = a;
		 }
private: System::Void sTreeBut_Click(System::Object^  sender, System::EventArgs^  e) {
			     int n = Convert::ToInt32(number->Text);  //����������� ������
				 SearchTree x (n, 100); //����� ������ 
				 B=x; //����������� �����������
		 }
private: System::Void print_ST_Click(System::Object^  sender, System::EventArgs^  e) {
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, B.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
private: System::Void find_ST_but_Click(System::Object^  sender, System::EventArgs^  e) {
			  int n = Convert::ToInt32(textFindKey->Text);
			 if (STprevFind) {
				 STprevFind -> status = 0; //�������� ������ ����� ��� ����������� ����������
			 }
			 Node *T; 
			 T = B.findKey ( B.getRoot(), n); //������� ����� ���� ��� ����������
			 if ( T != NULL ) {
				T -> status = 2; 
			 }
			 STprevFind = T; //��������� ��������� ���� � ����������
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, B.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
private: System::Void delete_ST_butt_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt32(textDelete->Text);
			 B.deleteKey ( n );
			 Graphics^ gr = this -> panel1 -> CreateGraphics();
			gr ->  Clear( Color::White );
			PrintT(gr, B.getRoot(),0,this->panel1->Width-26,5,-1);
		 }
};
}

