#pragma once

namespace lab_1_vcpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	  	// ���� �������� ���������
		int angle;

	public:
		Form1(void)
		{
			InitializeComponent();
			
			// �������� ������� �����������
			this->SetStyle(ControlStyles::DoubleBuffer |
				 ControlStyles::UserPaint |
				 ControlStyles::AllPaintingInWmPaint | 
				 ControlStyles::ResizeRedraw, // �������������� ��� ��������� ������� ����
				 true);
			this->UpdateStyles();

			angle = 10;
			
		}
	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
		  	Graphics^ g = e->Graphics;

			RectangleF bounds = g->VisibleClipBounds;

			// ������ ������� ����������
			float radius;
			if (bounds.Width > bounds.Height)
				radius = (bounds.Height - 20) / 2; // ������ �� ���� - 10 ��������
			else radius = (bounds.Width - 20) / 2;

			// ���� ������� ���� ���������, ������ �� ��������
			if (bounds.Width < 30 || bounds.Height < 30)
				return;

			// ���������� ������ ����������
			PointF center = PointF(bounds.Width / 2, bounds.Height / 2);

			// ����� ������� ���������� �����
			RectangleF rect = RectangleF(center.X - radius, center.Y - radius, radius*2, radius*2);

			// ������ ����
			g->FillEllipse(Brushes::OrangeRed, rect);
			
			// ������ ��� ��� ����� �������� �������� � ������� �������
			float radiuses[3] = {radius*0.9f, radius*0.3f, radius*0.2f };
			array<Brush^>^ brushes = gcnew array<Brush^>(3); // = { Brushes::Black, Brushes.OrangeRed, Brushes.Black};
			brushes[0] = Brushes::Black;
			brushes[1] = Brushes::OrangeRed;
			brushes[2] = Brushes::Black;


			for (int i = 0; i < 3; i++) {
				rect = RectangleF(center.X - radiuses[i], center.Y - radiuses[i], radiuses[i] * 2, radiuses[i] * 2);
				g->FillEllipse(brushes[i], rect);
				// �������� ��������
				if (i == 1) {
					Rectangle rect2 = Rectangle((int)(center.X - radius*0.95), (int)(center.Y - radius*0.95), (int)(radius*0.95*2), (int)(radius*0.95*2));
			        g->FillPie(Brushes::OrangeRed, rect2, angle, 60);
					g->FillPie(Brushes::OrangeRed, rect2, angle + 120, 60);
					g->FillPie(Brushes::OrangeRed, rect2, angle + 240, 60);
				}
			}

			//base.OnPaint(e);
		}

		virtual void OnMouseWheel(MouseEventArgs^ e) override
		{
		  angle -= e->Delta / 60;
		  Invalidate(); // ��������� ����
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"������������ ������ �1 (������������ �������)";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}

