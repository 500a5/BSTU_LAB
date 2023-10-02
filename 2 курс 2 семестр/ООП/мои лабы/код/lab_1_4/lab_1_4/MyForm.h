#pragma once

namespace lab14 {

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

	protected:
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;


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
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(302, 459);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(121, 30);
			this->button10->TabIndex = 68;
			this->button10->Text = L"Свойства";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(180, 373);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(230, 17);
			this->label8->TabIndex = 67;
			this->label8->Text = L"Устройство работает нормально.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 385);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(84, 17);
			this->label7->TabIndex = 66;
			this->label7->Text = L"Соятояние:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(180, 346);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(189, 17);
			this->label6->TabIndex = 65;
			this->label6->Text = L"на USB - устройтсво ввода ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(35, 346);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 17);
			this->label5->TabIndex = 64;
			this->label5->Text = L"Размещение:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(180, 313);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 17);
			this->label4->TabIndex = 63;
			this->label4->Text = L"Microsoft";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 313);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 17);
			this->label3->TabIndex = 62;
			this->label3->Text = L"Изготовитель:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 17);
			this->label1->TabIndex = 61;
			this->label1->Text = L"Свойства устройства";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(362, 507);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(91, 30);
			this->button8->TabIndex = 60;
			this->button8->Text = L"Применить";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(266, 507);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(80, 30);
			this->button7->TabIndex = 59;
			this->button7->Text = L"Отмена";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(183, 507);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(77, 30);
			this->button6->TabIndex = 58;
			this->button6->Text = L"ОК";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 17);
			this->label2->TabIndex = 57;
			this->label2->Text = L"Устройства:";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(237, 43);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(186, 31);
			this->button9->TabIndex = 56;
			this->button9->Text = L"настройки ClickPad";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(237, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(186, 31);
			this->button5->TabIndex = 55;
			this->button5->Text = L"Параметры указателя ";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(129, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(102, 31);
			this->button4->TabIndex = 54;
			this->button4->Text = L"Указатели";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 31);
			this->button3->TabIndex = 53;
			this->button3->Text = L"Кнопки мыши";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(116, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 29);
			this->button2->TabIndex = 52;
			this->button2->Text = L"Оборудование";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 29);
			this->button1->TabIndex = 51;
			this->button1->Text = L"Колесико";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(29, 120);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(481, 105);
			this->listView1->TabIndex = 69;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(35, 158);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(160, 17);
			this->linkLabel1->TabIndex = 70;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"HID- совместимая мыш";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(51, 129);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 17);
			this->label9->TabIndex = 71;
			this->label9->Text = L"Имя";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(288, 129);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 17);
			this->label10->TabIndex = 72;
			this->label10->Text = L"Тип";
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(35, 186);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(73, 17);
			this->linkLabel2->TabIndex = 73;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"TouchPad";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(234, 158);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(260, 17);
			this->label12->TabIndex = 75;
			this->label12->Text = L"Мыши и иные совместимые устроства";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(234, 186);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(260, 17);
			this->label13->TabIndex = 76;
			this->label13->Text = L"Мыши и иные совместимые устроства";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 555);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
}
};
}
