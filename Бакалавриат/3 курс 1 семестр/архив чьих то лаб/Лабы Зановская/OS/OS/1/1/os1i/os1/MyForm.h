#pragma once
#include <windows.h>
//#include <iostream.h>

namespace os1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::Label^  label59;
	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::Label^  label63;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::Label^  label66;
	private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::TabPage^  tabPage5;



















private: System::Windows::Forms::Label^  label96;









private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Label^  label91;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Label^  label105;
private: System::Windows::Forms::Label^  label104;
private: System::Windows::Forms::Label^  label103;
private: System::Windows::Forms::Label^  label102;
private: System::Windows::Forms::Label^  label101;
private: System::Windows::Forms::Label^  label100;
private: System::Windows::Forms::Label^  label99;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::Label^  label95;
private: System::Windows::Forms::Label^  label94;
private: System::Windows::Forms::Label^  label93;
private: System::Windows::Forms::Label^  label92;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label98;
private: System::Windows::Forms::Label^  label97;
private: System::Windows::Forms::Label^  label107;
private: System::Windows::Forms::Label^  label106;
private: System::Windows::Forms::Label^  label109;
private: System::Windows::Forms::Label^  label108;
private: System::Windows::Forms::Label^  label111;
private: System::Windows::Forms::Label^  label110;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Location = System::Drawing::Point(3, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(444, 379);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(436, 353);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Системная информация";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(213, 314);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(41, 13);
			this->label18->TabIndex = 19;
			this->label18->Text = L"label18";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 314);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(66, 13);
			this->label17->TabIndex = 18;
			this->label17->Text = L"Платформа";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(213, 276);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(41, 13);
			this->label16->TabIndex = 17;
			this->label16->Text = L"label16";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 276);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(83, 13);
			this->label15->TabIndex = 16;
			this->label15->Text = L"Версия сборки";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(213, 238);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(41, 13);
			this->label14->TabIndex = 15;
			this->label14->Text = L"label14";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 238);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(150, 13);
			this->label13->TabIndex = 14;
			this->label13->Text = L"Дополнительная версия ОС";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(213, 202);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 13;
			this->label12->Text = L"label12";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 202);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(114, 13);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Основная версия ОС";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(213, 164);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"label8";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 164);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(158, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Путь к каталогу врем.файлов";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(213, 127);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"label9";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 127);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(153, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Путь к системному каталогу";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(213, 90);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 90);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Путь к каталогу Windows";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 53);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Имя пользователя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(213, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"label3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Имя компьютера";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(436, 353);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Метрики 1-18";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label36);
			this->groupBox2->Controls->Add(this->label35);
			this->groupBox2->Controls->Add(this->label34);
			this->groupBox2->Controls->Add(this->label33);
			this->groupBox2->Controls->Add(this->label32);
			this->groupBox2->Controls->Add(this->label31);
			this->groupBox2->Controls->Add(this->label30);
			this->groupBox2->Controls->Add(this->label29);
			this->groupBox2->Controls->Add(this->label28);
			this->groupBox2->Controls->Add(this->label27);
			this->groupBox2->Controls->Add(this->label26);
			this->groupBox2->Controls->Add(this->label25);
			this->groupBox2->Controls->Add(this->label23);
			this->groupBox2->Controls->Add(this->label24);
			this->groupBox2->Location = System::Drawing::Point(5, 104);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(424, 244);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Размеры окон";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(322, 220);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(41, 13);
			this->label36->TabIndex = 15;
			this->label36->Text = L"label36";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(7, 220);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(156, 13);
			this->label35->TabIndex = 14;
			this->label35->Text = L"Минимальные размеры окна";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(322, 188);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(41, 13);
			this->label34->TabIndex = 13;
			this->label34->Text = L"label34";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(6, 188);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(115, 13);
			this->label33->TabIndex = 12;
			this->label33->Text = L"Толщина рамки окна";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(322, 153);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(41, 13);
			this->label32->TabIndex = 11;
			this->label32->Text = L"label32";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 153);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(196, 13);
			this->label31->TabIndex = 10;
			this->label31->Text = L"Размеры ячейки для свёрнутых окон";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(322, 121);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(41, 13);
			this->label30->TabIndex = 9;
			this->label30->Text = L"label30";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(6, 121);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(141, 13);
			this->label29->TabIndex = 8;
			this->label29->Text = L"Размеры свёрнутого окна";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(322, 87);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(41, 13);
			this->label28->TabIndex = 7;
			this->label28->Text = L"label28";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(6, 87);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(153, 13);
			this->label27->TabIndex = 6;
			this->label27->Text = L"Размеры развернутого окна";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(322, 52);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(41, 13);
			this->label26->TabIndex = 5;
			this->label26->Text = L"label26";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(6, 52);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(167, 13);
			this->label25->TabIndex = 4;
			this->label25->Text = L"Размеры полноэкранного окна";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(322, 20);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(41, 13);
			this->label23->TabIndex = 3;
			this->label23->Text = L"label23";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 20);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(168, 13);
			this->label24->TabIndex = 1;
			this->label24->Text = L"Ширина и высота границы окна";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->label20);
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Location = System::Drawing::Point(6, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(424, 95);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Мышь";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(228, 16);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(41, 13);
			this->label22->TabIndex = 3;
			this->label22->Text = L"label22";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 16);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(41, 13);
			this->label20->TabIndex = 1;
			this->label20->Text = L"label20";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(228, 61);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(41, 13);
			this->label21->TabIndex = 2;
			this->label21->Text = L"label21";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 61);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(41, 13);
			this->label19->TabIndex = 0;
			this->label19->Text = L"label19";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(436, 353);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Метрики 19-34";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label53);
			this->groupBox5->Controls->Add(this->label54);
			this->groupBox5->Controls->Add(this->label55);
			this->groupBox5->Controls->Add(this->label56);
			this->groupBox5->Location = System::Drawing::Point(5, 259);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(423, 84);
			this->groupBox5->TabIndex = 10;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Заголовок";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(318, 57);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(41, 13);
			this->label53->TabIndex = 3;
			this->label53->Text = L"label53";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(7, 57);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(41, 13);
			this->label54->TabIndex = 2;
			this->label54->Text = L"label54";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(318, 22);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(41, 13);
			this->label55->TabIndex = 1;
			this->label55->Text = L"label55";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(7, 22);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(41, 13);
			this->label56->TabIndex = 0;
			this->label56->Text = L"label56";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label47);
			this->groupBox4->Controls->Add(this->label48);
			this->groupBox4->Controls->Add(this->label49);
			this->groupBox4->Controls->Add(this->label50);
			this->groupBox4->Controls->Add(this->label51);
			this->groupBox4->Controls->Add(this->label52);
			this->groupBox4->Location = System::Drawing::Point(3, 147);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(423, 106);
			this->groupBox4->TabIndex = 9;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Иконки";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(318, 86);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(41, 13);
			this->label47->TabIndex = 5;
			this->label47->Text = L"label47";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(7, 86);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(41, 13);
			this->label48->TabIndex = 4;
			this->label48->Text = L"label48";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(318, 53);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(41, 13);
			this->label49->TabIndex = 3;
			this->label49->Text = L"label49";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(7, 53);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(41, 13);
			this->label50->TabIndex = 2;
			this->label50->Text = L"label50";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(318, 22);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(41, 13);
			this->label51->TabIndex = 1;
			this->label51->Text = L"label51";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(7, 22);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(41, 13);
			this->label52->TabIndex = 0;
			this->label52->Text = L"label52";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label43);
			this->groupBox3->Controls->Add(this->label44);
			this->groupBox3->Controls->Add(this->label42);
			this->groupBox3->Controls->Add(this->label41);
			this->groupBox3->Controls->Add(this->label40);
			this->groupBox3->Controls->Add(this->label39);
			this->groupBox3->Controls->Add(this->label38);
			this->groupBox3->Controls->Add(this->label37);
			this->groupBox3->Location = System::Drawing::Point(7, 7);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(423, 134);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Слайдер";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(7, 106);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(41, 13);
			this->label43->TabIndex = 8;
			this->label43->Text = L"label43";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(318, 106);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(41, 13);
			this->label44->TabIndex = 7;
			this->label44->Text = L"label44";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(318, 76);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(41, 13);
			this->label42->TabIndex = 5;
			this->label42->Text = L"label42";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(7, 76);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(41, 13);
			this->label41->TabIndex = 4;
			this->label41->Text = L"label41";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(318, 47);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(41, 13);
			this->label40->TabIndex = 3;
			this->label40->Text = L"label40";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(7, 47);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(41, 13);
			this->label39->TabIndex = 2;
			this->label39->Text = L"label39";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(318, 20);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(41, 13);
			this->label38->TabIndex = 1;
			this->label38->Text = L"label38";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(7, 20);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(41, 13);
			this->label37->TabIndex = 0;
			this->label37->Text = L"label37";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label77);
			this->tabPage4->Controls->Add(this->label76);
			this->tabPage4->Controls->Add(this->label75);
			this->tabPage4->Controls->Add(this->label74);
			this->tabPage4->Controls->Add(this->label73);
			this->tabPage4->Controls->Add(this->label72);
			this->tabPage4->Controls->Add(this->label71);
			this->tabPage4->Controls->Add(this->label70);
			this->tabPage4->Controls->Add(this->label69);
			this->tabPage4->Controls->Add(this->label68);
			this->tabPage4->Controls->Add(this->label67);
			this->tabPage4->Controls->Add(this->label66);
			this->tabPage4->Controls->Add(this->label65);
			this->tabPage4->Controls->Add(this->label64);
			this->tabPage4->Controls->Add(this->label63);
			this->tabPage4->Controls->Add(this->label62);
			this->tabPage4->Controls->Add(this->label61);
			this->tabPage4->Controls->Add(this->label60);
			this->tabPage4->Controls->Add(this->label59);
			this->tabPage4->Controls->Add(this->label58);
			this->tabPage4->Controls->Add(this->label57);
			this->tabPage4->Controls->Add(this->label46);
			this->tabPage4->Controls->Add(this->label45);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(436, 353);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Метрики 35-50";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(3, 333);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(41, 13);
			this->label77->TabIndex = 22;
			this->label77->Text = L"label77";
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(227, 320);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(41, 13);
			this->label76->TabIndex = 21;
			this->label76->Text = L"label76";
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(3, 320);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(41, 13);
			this->label75->TabIndex = 20;
			this->label75->Text = L"label75";
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(227, 289);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(41, 13);
			this->label74->TabIndex = 19;
			this->label74->Text = L"label74";
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(3, 289);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(41, 13);
			this->label73->TabIndex = 18;
			this->label73->Text = L"label73";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(227, 257);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(41, 13);
			this->label72->TabIndex = 17;
			this->label72->Text = L"label72";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(3, 257);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(41, 13);
			this->label71->TabIndex = 16;
			this->label71->Text = L"label71";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(319, 224);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(41, 13);
			this->label70->TabIndex = 15;
			this->label70->Text = L"label70";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(3, 224);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(41, 13);
			this->label69->TabIndex = 14;
			this->label69->Text = L"label69";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(227, 192);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(41, 13);
			this->label68->TabIndex = 13;
			this->label68->Text = L"label68";
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(3, 192);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(41, 13);
			this->label67->TabIndex = 12;
			this->label67->Text = L"label67";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(227, 159);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(41, 13);
			this->label66->TabIndex = 11;
			this->label66->Text = L"label66";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(3, 159);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(41, 13);
			this->label65->TabIndex = 10;
			this->label65->Text = L"label65";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(227, 128);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(41, 13);
			this->label64->TabIndex = 9;
			this->label64->Text = L"label64";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(3, 128);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(41, 13);
			this->label63->TabIndex = 8;
			this->label63->Text = L"label63";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(227, 97);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(41, 13);
			this->label62->TabIndex = 7;
			this->label62->Text = L"label62";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(3, 97);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(41, 13);
			this->label61->TabIndex = 6;
			this->label61->Text = L"label61";
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(227, 65);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(41, 13);
			this->label60->TabIndex = 5;
			this->label60->Text = L"label60";
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(3, 65);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(41, 13);
			this->label59->TabIndex = 4;
			this->label59->Text = L"label59";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(227, 35);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(41, 13);
			this->label58->TabIndex = 3;
			this->label58->Text = L"label58";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(3, 35);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(41, 13);
			this->label57->TabIndex = 2;
			this->label57->Text = L"label57";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(227, 3);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(41, 13);
			this->label46->TabIndex = 1;
			this->label46->Text = L"label46";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(3, 3);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(41, 13);
			this->label45->TabIndex = 0;
			this->label45->Text = L"label45";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->groupBox7);
			this->tabPage5->Controls->Add(this->groupBox6);
			this->tabPage5->Controls->Add(this->label96);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(436, 353);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Системные параметры";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label91);
			this->groupBox7->Controls->Add(this->label90);
			this->groupBox7->Controls->Add(this->label87);
			this->groupBox7->Controls->Add(this->label86);
			this->groupBox7->Controls->Add(this->label85);
			this->groupBox7->Controls->Add(this->label84);
			this->groupBox7->Location = System::Drawing::Point(9, 168);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(424, 100);
			this->groupBox7->TabIndex = 20;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"GET";
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Location = System::Drawing::Point(250, 69);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(41, 13);
			this->label91->TabIndex = 19;
			this->label91->Text = L"label91";
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Location = System::Drawing::Point(6, 69);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(41, 13);
			this->label90->TabIndex = 18;
			this->label90->Text = L"label90";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(250, 46);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(41, 13);
			this->label87->TabIndex = 17;
			this->label87->Text = L"label87";
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(6, 46);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(41, 13);
			this->label86->TabIndex = 16;
			this->label86->Text = L"label86";
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Location = System::Drawing::Point(250, 23);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(41, 13);
			this->label85->TabIndex = 15;
			this->label85->Text = L"label85";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Location = System::Drawing::Point(6, 23);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(41, 13);
			this->label84->TabIndex = 14;
			this->label84->Text = L"label84";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label83);
			this->groupBox6->Controls->Add(this->label82);
			this->groupBox6->Controls->Add(this->label81);
			this->groupBox6->Controls->Add(this->label80);
			this->groupBox6->Controls->Add(this->label79);
			this->groupBox6->Controls->Add(this->label78);
			this->groupBox6->Location = System::Drawing::Point(9, 31);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(424, 100);
			this->groupBox6->TabIndex = 19;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"SET";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Location = System::Drawing::Point(250, 70);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(41, 13);
			this->label83->TabIndex = 11;
			this->label83->Text = L"label83";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Location = System::Drawing::Point(6, 70);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(41, 13);
			this->label82->TabIndex = 10;
			this->label82->Text = L"label82";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Location = System::Drawing::Point(250, 47);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(41, 13);
			this->label81->TabIndex = 9;
			this->label81->Text = L"label81";
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(6, 47);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(41, 13);
			this->label80->TabIndex = 8;
			this->label80->Text = L"label80";
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(6, 23);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(41, 13);
			this->label79->TabIndex = 7;
			this->label79->Text = L"label79";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Location = System::Drawing::Point(250, 23);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(41, 13);
			this->label78->TabIndex = 6;
			this->label78->Text = L"label78";
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Location = System::Drawing::Point(108, 3);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(183, 13);
			this->label96->TabIndex = 18;
			this->label96->Text = L"Системные параметры (SET, GET)";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->label111);
			this->tabPage6->Controls->Add(this->label110);
			this->tabPage6->Controls->Add(this->label109);
			this->tabPage6->Controls->Add(this->label108);
			this->tabPage6->Controls->Add(this->label107);
			this->tabPage6->Controls->Add(this->label106);
			this->tabPage6->Controls->Add(this->label98);
			this->tabPage6->Controls->Add(this->label97);
			this->tabPage6->Controls->Add(this->groupBox9);
			this->tabPage6->Controls->Add(this->groupBox8);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(436, 353);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Прочее";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->Location = System::Drawing::Point(257, 306);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(47, 13);
			this->label109->TabIndex = 50;
			this->label109->Text = L"label109";
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->Location = System::Drawing::Point(13, 306);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(47, 13);
			this->label108->TabIndex = 49;
			this->label108->Text = L"label108";
			// 
			// label107
			// 
			this->label107->AutoSize = true;
			this->label107->Location = System::Drawing::Point(257, 284);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(47, 13);
			this->label107->TabIndex = 48;
			this->label107->Text = L"label107";
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->Location = System::Drawing::Point(13, 284);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(47, 13);
			this->label106->TabIndex = 47;
			this->label106->Text = L"label106";
			// 
			// label98
			// 
			this->label98->AutoSize = true;
			this->label98->Location = System::Drawing::Point(257, 261);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(41, 13);
			this->label98->TabIndex = 46;
			this->label98->Text = L"label98";
			// 
			// label97
			// 
			this->label97->AutoSize = true;
			this->label97->Location = System::Drawing::Point(13, 261);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(41, 13);
			this->label97->TabIndex = 45;
			this->label97->Text = L"label97";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->label105);
			this->groupBox9->Controls->Add(this->label104);
			this->groupBox9->Controls->Add(this->label103);
			this->groupBox9->Controls->Add(this->label102);
			this->groupBox9->Controls->Add(this->label101);
			this->groupBox9->Controls->Add(this->label100);
			this->groupBox9->Controls->Add(this->label99);
			this->groupBox9->Location = System::Drawing::Point(7, 122);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(423, 123);
			this->groupBox9->TabIndex = 44;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Время";
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->Location = System::Drawing::Point(250, 95);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(47, 13);
			this->label105->TabIndex = 49;
			this->label105->Text = L"label105";
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->Location = System::Drawing::Point(6, 95);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(47, 13);
			this->label104->TabIndex = 48;
			this->label104->Text = L"label104";
			// 
			// label103
			// 
			this->label103->AutoSize = true;
			this->label103->Location = System::Drawing::Point(250, 66);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(47, 13);
			this->label103->TabIndex = 47;
			this->label103->Text = L"label103";
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->Location = System::Drawing::Point(6, 66);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(47, 13);
			this->label102->TabIndex = 46;
			this->label102->Text = L"label102";
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Location = System::Drawing::Point(250, 45);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(47, 13);
			this->label101->TabIndex = 45;
			this->label101->Text = L"label101";
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->Location = System::Drawing::Point(250, 32);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(47, 13);
			this->label100->TabIndex = 44;
			this->label100->Text = L"label100";
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->Location = System::Drawing::Point(6, 32);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(41, 13);
			this->label99->TabIndex = 43;
			this->label99->Text = L"label99";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label95);
			this->groupBox8->Controls->Add(this->label94);
			this->groupBox8->Controls->Add(this->label93);
			this->groupBox8->Controls->Add(this->label92);
			this->groupBox8->Controls->Add(this->label89);
			this->groupBox8->Controls->Add(this->label88);
			this->groupBox8->Location = System::Drawing::Point(7, 4);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(423, 111);
			this->groupBox8->TabIndex = 43;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Цвета";
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->Location = System::Drawing::Point(250, 80);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(41, 13);
			this->label95->TabIndex = 39;
			this->label95->Text = L"label95";
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Location = System::Drawing::Point(6, 80);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(41, 13);
			this->label94->TabIndex = 38;
			this->label94->Text = L"label94";
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Location = System::Drawing::Point(250, 52);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(41, 13);
			this->label93->TabIndex = 37;
			this->label93->Text = L"label93";
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Location = System::Drawing::Point(6, 52);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(41, 13);
			this->label92->TabIndex = 36;
			this->label92->Text = L"label92";
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Location = System::Drawing::Point(250, 27);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(41, 13);
			this->label89->TabIndex = 35;
			this->label89->Text = L"label89";
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Location = System::Drawing::Point(6, 27);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(41, 13);
			this->label88->TabIndex = 34;
			this->label88->Text = L"label88";
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Location = System::Drawing::Point(13, 328);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(47, 13);
			this->label110->TabIndex = 51;
			this->label110->Text = L"label110";
			// 
			// label111
			// 
			this->label111->AutoSize = true;
			this->label111->Location = System::Drawing::Point(257, 328);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(47, 13);
			this->label111->TabIndex = 52;
			this->label111->Text = L"label111";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 473);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"ОС-1, Братковой И.О., ПВ-31";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {		

		WCHAR buff[ComputerNameMax + 50];
		DWORD size = sizeof(buff) / 2 - 1;
		GetComputerName(buff, &size);
		label2->Text = gcnew String(buff);					//Имя комп
		label3->Text = SystemInformation::UserName;		//Имя пользователя
		size = MAX_COMPUTERNAME_LENGTH + 1;
		//GetUserName(buff, &size);
		//label3->Text = gcnew String(buff);

		size = sizeof(buff) / 2 - 1;
		GetSystemDirectory(buff, size);
		label9->Text = gcnew String(buff);				//Путь к системному каталогу
		GetWindowsDirectory(buff, size);
		label6->Text = gcnew String(buff);				//Путь к каталогу виндовс
		GetTempPath(size, buff);
		label8->Text = gcnew String(buff);				//Путь к каталогу временных файлов

		OSVERSIONINFO wind;
		wind.dwOSVersionInfoSize = sizeof(wind);
		GetVersionEx(&wind);
		label12->Text = wind.dwMajorVersion.ToString();				//основная версия системы
		label14->Text = wind.dwMinorVersion.ToString();				//дополнительная версия ос
		label16->Text = wind.dwBuildNumber.ToString();				//версия сборки
		
		
		switch (wind.dwPlatformId)									//платформа
		{
		case 0: {
			label18->Text = L"Win32s, работающая на Windows";
			break;
		}
		case 1: {
			label18->Text = L"Win32, работающая на Windows 95 или Windows 98";
			break;
		}
		case 2: {
			label18->Text = L"Win32, работающая на Windows NT";
			break;
		}
		default:
			break;
		}

		//-----------------метрики-------------------------
		//1
		label19->Text = L"Количество клавиш мыши - " + GetSystemMetrics(SM_CMOUSEBUTTONS).ToString();
		
		//2
		label20->Text = (GetSystemMetrics(SM_MOUSEPRESENT)) ? L"Мышь установлена" : L"Мышь не установлена";

		//3
		label21->Text = (GetSystemMetrics(SM_MOUSEWHEELPRESENT)) ? L"Мышь с колёсиком установлена" : L"Мышь с колёсиком не установлена";

		//4
		label22->Text = (GetSystemMetrics(SM_SWAPBUTTON)) ? L"Клавиши можно поменять местами" : L"Клавиши нельзя поменять местами";

		//5, 6 высота и ширина окна
		label24->Text = SM_CXBORDER.ToString() + L", " + SM_CYBORDER.ToString() + L"      Ширина и высота границы окна";
		label23->Text = GetSystemMetrics(SM_CXBORDER).ToString()
			+ L" x " + GetSystemMetrics(SM_CYBORDER).ToString();

		//7, 8 полноэкранное окно (размеры)
		label25->Text = SM_CXFULLSCREEN.ToString() + L", " + SM_CYFULLSCREEN.ToString() + L"  Размеры полноэкранного окна";
		label26->Text = GetSystemMetrics(SM_CXFULLSCREEN).ToString()
			+ L" x " + GetSystemMetrics(SM_CYFULLSCREEN).ToString();

		//9, 10 развёрнутое (размеры)
		label27->Text = SM_CXMAXIMIZED.ToString() + L", " + SM_CYMAXIMIZED.ToString() + L"  Размеры развернутого окна верхнего уровня";
		label28->Text = GetSystemMetrics(SM_CXMAXIMIZED).ToString()
			+ L" x " + GetSystemMetrics(SM_CYMAXIMIZED).ToString();

		//11, 12 свёрнутое размеры
		label29->Text = SM_CXMINIMIZED.ToString() + L", " + SM_CYMINIMIZED.ToString() + L"  Размеры свернутого окна";
		label30->Text = GetSystemMetrics(SM_CXMINIMIZED).ToString()
			+ L" x " + GetSystemMetrics(SM_CYMINIMIZED).ToString();

		//13, 14 резмеры ячейки для свёрнутых окон
		label31->Text = SM_CXMINSPACING.ToString() + L", " + SM_CYMINSPACING.ToString() + L"  Размеры ячейки сетки для свернутых окон";
		label32->Text = GetSystemMetrics(SM_CXMINSPACING).ToString()
			+ L" x " + GetSystemMetrics(SM_CYMINSPACING).ToString();

		//15, 16 толщина рамки окна
		label33->Text = SM_CXSIZEFRAME.ToString() + L", " + SM_CYSIZEFRAME.ToString() + L"  Толщина рамки окна";
		label34->Text = GetSystemMetrics(SM_CXSIZEFRAME).ToString()
			+ L" x " + GetSystemMetrics(SM_CYSIZEFRAME).ToString();

		//17, 18 минимальные размеры окна 
		label35->Text = SM_CXMIN.ToString() + L", " + SM_CYMIN.ToString() + L"  Минимальные размеры окна";
		label36->Text = GetSystemMetrics(SM_CXMIN).ToString()
			+ L" x " + GetSystemMetrics(SM_CYMIN).ToString();

		//19, 20
		label37->Text = SM_CXHSCROLL.ToString() + L", " + SM_CYHSCROLL.ToString() + L"    Размеры стрелки горизонтального слайдера";
		label38->Text = GetSystemMetrics(SM_CXHSCROLL).ToString()
			+ L" x " + GetSystemMetrics(SM_CYHSCROLL).ToString();

		//21
		label39->Text = SM_CXHTHUMB.ToString() + L"        Минимальная длина горизонтального слайдера";
		label40->Text = GetSystemMetrics(SM_CXHTHUMB).ToString();

		//22, 23
		label41->Text = SM_CXVSCROLL.ToString() + L", " + SM_CYVSCROLL.ToString() + L"    Размеры стрелки вертикального слайдера";
		label42->Text = GetSystemMetrics(SM_CXVSCROLL).ToString()
			+ L" x " + GetSystemMetrics(SM_CYVSCROLL).ToString();

		//24
		label43->Text = SM_CYVTHUMB.ToString() + L"          Минимальная длина вертикального слайдера";
		label44->Text = GetSystemMetrics(SM_CYVTHUMB).ToString();

		//25, 26
		label52->Text = SM_CXICON.ToString() + L", " + SM_CYICON.ToString() + L"  Размеры иконок";
		label51->Text = GetSystemMetrics(SM_CXICON).ToString()
			+ L" x " + GetSystemMetrics(SM_CYICON).ToString();

		//27, 28
		label50->Text = SM_CXICONSPACING.ToString() + L", " + SM_CYICONSPACING.ToString() + L"  Размеры больших иконок";
		label49->Text = GetSystemMetrics(SM_CXICONSPACING).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYICONSPACING).ToString();

		//29, 30
		label48->Text = SM_CXSMICON.ToString() + L", " + SM_CYSMICON.ToString() + L"  Рекомендуемый размер маленькой иконки";
		label47->Text = GetSystemMetrics(SM_CXSMICON).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYSMICON).ToString();

		//31, 32
		label56->Text = SM_CXSIZE.ToString() + L", " + SM_CYSIZE.ToString() + L"  Размеры области заголовка";
		label55->Text = GetSystemMetrics(SM_CXSIZE).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYSIZE).ToString();

		//33, 34
		label54->Text = SM_CXSMSIZE.ToString() + L", " + SM_CYSMSIZE.ToString() + L"  Размеры маленьких кнопок заголовка";
		label53->Text = GetSystemMetrics(SM_CXSMSIZE).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYSMSIZE).ToString();

		//35
		label45->Text = SM_CLEANBOOT.ToString() + L"        Тип загрузки Windows";
		int rez = GetSystemMetrics(SM_CLEANBOOT);
		if (rez == 0)
			label46->Text = L"Нормальная загрузка";
		else if (rez == 1)
			label46->Text = L"Отказовустойчивая загрузка";
		else
			label46->Text = L"Отказовустойчивая загрузка с сетевой поддержкой";

		//36
		label57->Text = SM_SLOWMACHINE.ToString() + L"        Скорость процессора";
		label58->Text = (GetSystemMetrics(SM_SLOWMACHINE)) ? L"Компьютер имеет медленный процессор" : L"Компьютер имеет быстрый процессор";

		//37
		label59->Text = SM_MIDEASTENABLED.ToString() + L"        Еврейский и арабский языки";
		label60->Text = (GetSystemMetrics(SM_MIDEASTENABLED)) ? L"Допускаются" : L"Не допускаются";

		//38, 39
		label65->Text = SM_CXSCREEN.ToString() + L", " + SM_CYSCREEN.ToString() + L"      Размеры экрана в пикселях";
		label66->Text = GetSystemMetrics(SM_CXSCREEN).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYSCREEN).ToString();

		//40, 41
		label67->Text = SM_CXMENUCHECK.ToString() + L", " + SM_CYMENUCHECK.ToString() + L"  Размеры рисунка меню";
		label68->Text = GetSystemMetrics(SM_CXMENUCHECK).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYMENUCHECK).ToString();

		//42, 43
		label61->Text = SM_CXCURSOR.ToString() + L", " + SM_CYCURSOR.ToString() + L"  Размеры курсора";
		label62->Text = GetSystemMetrics(SM_CXCURSOR).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYCURSOR).ToString();

		//44, 45
		label63->Text = SM_CXDOUBLECLK.ToString() + L", " + SM_CYDOUBLECLK.ToString() + L"  Размеры области двойного клика";
		label64->Text = GetSystemMetrics(SM_CXDOUBLECLK).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYDOUBLECLK).ToString();

		//46, 47
		label69->Text = SM_CXDRAG.ToString() + L", " + SM_CYDRAG.ToString() + L"  Размеры области до нач. перетаскивания";
		label70->Text = GetSystemMetrics(SM_CXDRAG).ToString() 
			+ L" x " + GetSystemMetrics(SM_CYDRAG).ToString();

		//48
		label71->Text = SM_SECURE.ToString() + L"    Наличие защиты";
		label72->Text = (GetSystemMetrics(SM_SECURE)) ? L"Защита присутствует" : L"Защита отсуствует";

		//49 
		label73->Text = SM_DEBUG.ToString() + L"    Верия user.exe";
		label74->Text = (GetSystemMetrics(SM_SECURE)) ? L"Установлена отладочная версия" : L"Отладочная версия не установлена";

		//50
		label75->Text = SM_SHOWSOUNDS.ToString() + L"    Необходимость визуализации";
		label77->Text = L"звуковой информации для пользователя";
		label76->Text = (GetSystemMetrics(SM_SHOWSOUNDS)) ? L"Пользователь нуждается" : L"Пользователь не нуждается";

		//-------------------системные параметры------------------------
		//--------SET
		int a = 1;
		//SystemParametersInfo(SPI_GETBORDER, sizeof(a), &a, 0);
		SystemParametersInfo(SPI_SETBORDER, sizeof(a), &a, SPIF_SENDCHANGE);
		label79->Text = L"Толщина границы";
		label78->Text = a.ToString();
		
		int b = 400;
		//SystemParametersInfo(SPI_GETMOUSEHOVERTIME, sizeof(b), &b, 0);
		SystemParametersInfo(SPI_SETMOUSEHOVERTIME, sizeof(b), &b, SPIF_SENDCHANGE);
		label80->Text = L"Чувствительность мыши";
		label81->Text = b.ToString();

		HIGHCONTRAST hc;
		SystemParametersInfo(SPI_GETHIGHCONTRAST, 0, &hc, 0);
		//hc.dwFlags = HCF_HIGHCONTRASTON;
		SystemParametersInfo(SPI_SETHIGHCONTRAST, 0, &hc, SPIF_SENDCHANGE);
		label82->Text = L"Контрастность ";
		label83->Text = (hc.dwFlags & HCF_HIGHCONTRASTON) != 0 ? L"Оn" : L"Оff";


		//---------GET
		BOOL lol;
		SystemParametersInfo(SPI_GETMENUDROPALIGNMENT, sizeof(lol), &lol, 0);
		label84->Text = L"Расположение меню";
		label85->Text = lol ? L"Справа" : L"Слева";

		BOOL kek;
		SystemParametersInfo(SPI_GETSHOWSOUNDS, sizeof(kek), &kek, 0);
		label86->Text = L"Визуализация звуковой информации";
		label87->Text = kek ? L"On" : L"Off";

		BOOL bee;
		SystemParametersInfo(SPI_GETBEEP, 0, &bee, 0);
		label90->Text = L"Звуковые сигналы";
		label91->Text = bee ? L"On" : L"Off";
		

		//-------------------системные цвета--------------------------
		DWORD color;
		int r = COLOR_3DHIGHLIGHT;
		color = GetSysColor(r);
		color = 16777215;  //65280
		SetSysColors(1, &r, &color);
		label88->Text = L"Цвет трёхмерного изображения:";
		label89->Text = color.ToString();


		r = COLOR_WINDOWTEXT;
		//color = GetSysColor(r);
		color = 0;  // 16777215
		SetSysColors(1, &r, &color);
		label92->Text = L"Виндовс текст:";
		label93->Text = color.ToString();

		r = COLOR_HIGHLIGHTTEXT;
		color = GetSysColor(r);
		//color = 16777215;
		SetSysColors(1, &r, &color);
		label94->Text = L"Цвет выделения:";
		label95->Text = color.ToString();
		
		//----------------------время---------------------
		SYSTEMTIME time;
		GetSystemTime(&time);
		label99->Text = L"Системное время: ";
		label100->Text = time.wDay.ToString() + L"." + time.wMonth.ToString() + L"." + time.wYear.ToString()
			+ L"        " + time.wHour.ToString()
			+ L":" + time.wMinute.ToString() + L":" + time.wSecond.ToString()
			+ L":" + time.wMilliseconds.ToString();
		switch (time.wDayOfWeek)
		{
		case 0: {			label101->Text = L"Воскресенье";			break;		}
		case 1: {			label101->Text = L"Понедеьник";			break;		}
		case 2: {			label101->Text = L"Вторник";			break;		}
		case 3: {			label101->Text = L"Среда";			break;		}
		case 4: {			label101->Text = L"Четверг";			break;		}
		case 5: {			label101->Text = L"Пятница";			break;		}
		case 6: {			label101->Text = L"Суббота";			break;		}
		default:			break;
		}

		TIME_ZONE_INFORMATION l;
		DWORD time2;
		time2 = GetTimeZoneInformation(&l);
		label102->Text = L"Текущие параметры часового пояса:";
		if (time2 == 0)
			label103->Text = L"Летнее время не используется";
		else
			label103->Text = L"Летнее время используется";

		DWORD tmp1, tmp2;
		BOOL tmp3;
		GetSystemTimeAdjustment(&tmp1, &tmp2, &tmp3);
		label104->Text = L"Периодическая корректировка времени:";
		label105->Text = tmp3 ? L"Off" : L"On";

		//-----------------дополнительно
		//CreateCaret, GetEnvironmentStrings, GetQueueStatus, SetCursorPos
		

		label97->Text = L"Указатель на переменные среды";
		label98->Text = gcnew String(GetEnvironmentStrings());


		//HWND handle = FindWindowW(NULL, this->Name);
		//CreateCaret((HWND)handle, 0, 6, 13);

		//?????????????????????????????????????
		UINT f = QS_KEY;
		DWORD tmp = GetQueueStatus(f);
		label106->Text = L"Состояние очереди: ";
		label107->Text = tmp.ToString();


		POINT cursor;
		SetCursorPos(80, 80);
		label110->Text = L"Установлено положение курсора: ";
		label111->Text = cursor.x.ToString() + L", " + cursor.y.ToString();
		/* Sleep(100);
		 * SetCursorPos(380, 80);
		 * Sleep(100);
		 * SetCursorPos(380, 380);
		 * Sleep(100);
		 * SetCursorPos(80, 380);
		 * Sleep(100);
		 * SetCursorPos(80, 80);
		 */

		GetCursorPos(&cursor);
		label108->Text = L"Положение курсора: ";
		label109->Text = cursor.x.ToString() + L", " + cursor.y.ToString();

		
		
	
	}
};
}

/*QS_ALLEVENTS

Сообщение ввода, WM_TIMER, WM_PAINT, WM_HOTKEY или помещенное в очередь сообщение.

QS_ALLINPUT

Любое сообщение ввода.

QS_HOTKEY

Сообщение WM_HOTKEY .

QS_INPUT

Сообщение ввода.

QS_KEY

Сообщение WM_KEYUP, WM_KEYDOWN, WM_SYSKEYUP или WM_SYSKEYDOWN в очереди.

QS_MOUSE

Сообщение WM_MOUSEMOVE или сообщение клавиши мыши ( WM_LBUTTONUP, WM_RBUTTONDOWN и т. п.).

QS_MOUSEBUTTON

Сообщение клавиши мыши ( WM_LBUTTONUP, WM_RBUTTONDOWN и т. п.).

QS_MOUSEMOVE

Сообщение WM_MOUSEMOVE.

QS_PAINT

Сообщение WM_PAINT .

QS_OSTMESSAGE

Помещенное сообщение, отличное от перечисленных выше, находится в очереди.

QS_ENDMESSAGE

Сообщение, отправленное другим потоком или приложением, находится в очереди.

QS_TIMER

Сообщение WM_TIMER .*/