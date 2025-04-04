#pragma once
#include "ViewDetails.h"
#include "BookRooms.h"
#include "CheckAvailability.h"

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ViewDetails
	/// </summary>
	public ref class ViewDetails : public System::Windows::Forms::Form
	{
	public:
		ViewDetails(void)
		{
			InitializeComponent();

	/* LoadData() function call kiya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein */

			LoadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewDetails()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

		void LoadData();









	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DataGridView^ dataGridView1;












	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ BackButton;
	private: System::Windows::Forms::Button^ NextButton;
    










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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->NextButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 39, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label10->Location = System::Drawing::Point(73, 118);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(1201, 64);
			this->label10->TabIndex = 47;
			this->label10->Text = L"DETAILS OF CUSTOMERS STAYING IN OUR HOTEL";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(73, 215);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1335, 558);
			this->dataGridView1->TabIndex = 46;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1604, 81);
			this->panel1->TabIndex = 61;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(676, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(265, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"THE GALAXY HOTEL";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(723, 44);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(220, 26);
			this->label4->TabIndex = 1;
			this->label4->Text = L"CUSTOMERS DETAILS";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// BackButton
			// 
			this->BackButton->BackColor = System::Drawing::Color::Crimson;
			this->BackButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BackButton->ForeColor = System::Drawing::SystemColors::Control;
			this->BackButton->Location = System::Drawing::Point(1423, 588);
			this->BackButton->Margin = System::Windows::Forms::Padding(2);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(159, 75);
			this->BackButton->TabIndex = 62;
			this->BackButton->Text = L"BACK";
			this->BackButton->UseVisualStyleBackColor = false;
			// 
			// NextButton
			// 
			this->NextButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->NextButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextButton->ForeColor = System::Drawing::SystemColors::Control;
			this->NextButton->Location = System::Drawing::Point(1423, 698);
			this->NextButton->Margin = System::Windows::Forms::Padding(2);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(159, 75);
			this->NextButton->TabIndex = 63;
			this->NextButton->Text = L"NEXT";
			this->NextButton->UseVisualStyleBackColor = false;
			// 
			// ViewDetails
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1604, 881);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"ViewDetails";
			this->Text = L"ViewDetails";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
