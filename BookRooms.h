#pragma once
#include "BookRooms.h"
#include "ViewDetails.h"
#include "Login.h"
#include "GenerateBills.h"
#include "CheckAvailability.h"
#include "Dashboard.h"

using namespace System::Data;
using namespace System::Data::OleDb;

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookRooms
	/// <summary>
	public ref class BookRooms : public System::Windows::Forms::Form
	{
	public:
		BookRooms(void)
		{
			InitializeComponent();

			//TODO: Add the constructor code here
			/* LoadData() function call kiya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein */

			LoadData();

			/* Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */

			String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
			OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

			String^ selectQuery = "SELECT bookings.bookingID, customers.customerID, customers.FirstName, customers.LastName, customers.address, customers.mobile, customers.gender, customers.email, customers.nationality, "
				+ "bookings.roomNo, rooms.roomType, rooms.price, bookings.checkinDate "
				+ "FROM (bookings "
				+ "INNER JOIN customers ON bookings.CustomerID = customers.customerID) "
				+ "INNER JOIN rooms ON bookings.roomNo = rooms.roomNo";
			
			OleDbCommand^ selectCommand = gcnew OleDbCommand(selectQuery, connection);
			OleDbDataAdapter^ dataAdapter = gcnew OleDbDataAdapter(selectCommand);
			DataTable^ dataTable = gcnew DataTable();

			try {
				connection->Open();
				dataAdapter->Fill(dataTable);
				dataGridView1->DataSource = dataTable;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (connection->State == ConnectionState::Open) {
					connection->Close();
				}
			}

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookRooms()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
		void LoadData();

		// Line number 34 se 80 tak samajh lena.

	private: System::Windows::Forms::TextBox^ textBox4;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ NextButton;


	private: System::Windows::Forms::Button^ DeleteButton;

	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ HomeButton;





	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label3;




	private: System::Windows::Forms::TextBox^ textBox5;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->HomeButton = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(217, 527);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(262, 31);
			this->textBox4->TabIndex = 49;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(217, 662);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(262, 31);
			this->textBox2->TabIndex = 48;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label12->Location = System::Drawing::Point(39, 525);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(136, 56);
			this->label12->TabIndex = 47;
			this->label12->Text = L"RESIDENTIAL ADDRESS";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label11->Location = System::Drawing::Point(28, 662);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(177, 26);
			this->label11->TabIndex = 46;
			this->label11->Text = L"PHONE NUMBER";
			// 
			// NextButton
			// 
			this->NextButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->NextButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextButton->ForeColor = System::Drawing::SystemColors::Control;
			this->NextButton->Location = System::Drawing::Point(1376, 673);
			this->NextButton->Margin = System::Windows::Forms::Padding(2);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(205, 75);
			this->NextButton->TabIndex = 44;
			this->NextButton->Text = L"NEXT";
			this->NextButton->UseVisualStyleBackColor = false;
			this->NextButton->Click += gcnew System::EventHandler(this, &BookRooms::NextButton_Click_1);
			// 
			// DeleteButton
			// 
			this->DeleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteButton->ForeColor = System::Drawing::SystemColors::Control;
			this->DeleteButton->Location = System::Drawing::Point(784, 673);
			this->DeleteButton->Margin = System::Windows::Forms::Padding(2);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(205, 75);
			this->DeleteButton->TabIndex = 43;
			this->DeleteButton->Text = L"DELETE";
			this->DeleteButton->UseVisualStyleBackColor = false;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &BookRooms::DeleteButton_Click_1);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->AddButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddButton->ForeColor = System::Drawing::SystemColors::Control;
			this->AddButton->Location = System::Drawing::Point(500, 673);
			this->AddButton->Margin = System::Windows::Forms::Padding(2);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(205, 75);
			this->AddButton->TabIndex = 42;
			this->AddButton->Text = L"ADD";
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &BookRooms::AddButton_Click_1);
			// 
			// HomeButton
			// 
			this->HomeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->HomeButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HomeButton->ForeColor = System::Drawing::SystemColors::Control;
			this->HomeButton->Location = System::Drawing::Point(1076, 673);
			this->HomeButton->Margin = System::Windows::Forms::Padding(2);
			this->HomeButton->Name = L"HomeButton";
			this->HomeButton->Size = System::Drawing::Size(205, 75);
			this->HomeButton->TabIndex = 41;
			this->HomeButton->Text = L"HOME";
			this->HomeButton->UseVisualStyleBackColor = false;
			this->HomeButton->Click += gcnew System::EventHandler(this, &BookRooms::HomeButton_Click_1);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(217, 598);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(262, 31);
			this->textBox7->TabIndex = 37;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label9->Location = System::Drawing::Point(68, 598);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 42);
			this->label9->TabIndex = 36;
			this->label9->Text = L"EMAIL";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label7->Location = System::Drawing::Point(59, 341);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 26);
			this->label7->TabIndex = 34;
			this->label7->Text = L"GENDER";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label6->Location = System::Drawing::Point(37, 275);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(148, 26);
			this->label6->TabIndex = 33;
			this->label6->Text = L"NATIONALITY";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label4->Location = System::Drawing::Point(44, 151);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 26);
			this->label4->TabIndex = 30;
			this->label4->Text = L"FIRST NAME";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label3->Location = System::Drawing::Point(28, 100);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 26);
			this->label3->TabIndex = 28;
			this->label3->Text = L"CUSTOMER ID";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(217, 151);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(262, 32);
			this->textBox5->TabIndex = 30;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label1->Location = System::Drawing::Point(44, 402);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 32);
			this->label1->TabIndex = 54;
			this->label1->Text = L"ROOM TYPE";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label5->Location = System::Drawing::Point(37, 14);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(156, 26);
			this->label5->TabIndex = 31;
			this->label5->Text = L"ROLL NUMBER";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(217, 12);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(262, 31);
			this->textBox3->TabIndex = 32;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(744, 44);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(190, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ROOM BOOKING";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(676, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(265, 26);
			this->label8->TabIndex = 3;
			this->label8->Text = L"THE GALAXY HOTEL";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1604, 79);
			this->panel1->TabIndex = 51;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(217, 209);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(262, 32);
			this->textBox6->TabIndex = 56;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label10->Location = System::Drawing::Point(44, 209);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(127, 26);
			this->label10->TabIndex = 57;
			this->label10->Text = L"LAST NAME";
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label13->Location = System::Drawing::Point(44, 464);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(136, 32);
			this->label13->TabIndex = 59;
			this->label13->Text = L"ROOM NO";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label14->Location = System::Drawing::Point(19, 732);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(174, 26);
			this->label14->TabIndex = 61;
			this->label14->Text = L"CHECK-IN DATE";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(217, 729);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(262, 29);
			this->dateTimePicker1->TabIndex = 62;
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"101 - DELUXE", L"102 - DELUXE", L"103 - SUITE",
					L"104 - SUITE", L"105 - SUITE", L"106 - STANDARD", L"107 - STANDARD", L"108 - STANDARD"
			});
			this->comboBox4->Location = System::Drawing::Point(217, 464);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(262, 30);
			this->comboBox4->TabIndex = 60;
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"SUITE ($ 200.0)", L"DELUXE ($ 150.0)", L"STANDARD ($ 100.0)" });
			this->comboBox3->Location = System::Drawing::Point(217, 402);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(262, 30);
			this->comboBox3->TabIndex = 58;
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MALE", L"FEMALE" });
			this->comboBox2->Location = System::Drawing::Point(217, 337);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(262, 30);
			this->comboBox2->TabIndex = 39;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"PAKISTAN", L"INDIA", L"BANGLADESH", L"SRI LANKA",
					L"AFGHANISTAN", L"ENGLAND", L"CHINA", L"OTHER"
			});
			this->comboBox1->Location = System::Drawing::Point(217, 271);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(262, 30);
			this->comboBox1->TabIndex = 55;
			// 
			// comboBox5
			// 
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(50) {
				L"01  ", L"02  ", L"03  ", L"04  ", L"05  ", L"06  ",
					L"07  ", L"08  ", L"09  ", L"10  ", L"11  ", L"12  ", L"13  ", L"14  ", L"15  ", L"16  ", L"17  ", L"18  ", L"19  ", L"20  ",
					L"21  ", L"22  ", L"23  ", L"24  ", L"25  ", L"26  ", L"27  ", L"28  ", L"29  ", L"30  ", L"31  ", L"32  ", L"33  ", L"34  ",
					L"35  ", L"36  ", L"37  ", L"38  ", L"39  ", L"40  ", L"41  ", L"42  ", L"43  ", L"44  ", L"45  ", L"46  ", L"47  ", L"48  ",
					L"49  ", L"50  "
			});
			this->comboBox5->Location = System::Drawing::Point(217, 96);
			this->comboBox5->Margin = System::Windows::Forms::Padding(2);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(262, 30);
			this->comboBox5->TabIndex = 63;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(500, 96);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 90;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1081, 552);
			this->dataGridView1->TabIndex = 50;
			// 
			// BookRooms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1604, 881);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->HomeButton);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Name = L"BookRooms";
			this->Text = L"BookRooms";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/* Is file mein ooper top se (#pragma once) lekar neeche bottom (#pragma endregion) tak
		jo code likha hua hai, ye Microsoft Visual Studio ka Automatically generated code hota hai,
		yani jo UI hum tool-box se drag and drop k through design karte hain, usi ko Microsoft Visual
		Studio apne aap hee se automatically, code mein convert kar deta hai.

		Is liye #pragma once se lekar #pragma endregion tak ka code hamare samajhne k liye nahi hai, ye
		just UI form k design ko automatically coding ki language mein convert kar deta hai.*/



		// MUHAMMAD USMAN MASOOD
		// CT-24239
		// SECTION: E



		/* Yahan maine BookRooms.h wale forms par saare buttons k event handlers banaye hain.
		 In sab buttons ki implementation BookRooms.cpp file mein likhi hai */


		
		void AddButton_Click(System::Object^ sender, System::EventArgs^ e);

		void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e);

		void HomeButton_Click(System::Object^ sender, System::EventArgs^ e);

		void NextButton_Click(System::Object^ sender, System::EventArgs^ e);


	
		/*Yahan maine BookRooms.h wale forms par saare buttons k event handlers initialize kiye hain,
		aur har button k event handler ko initialize karte hue us button ka respective function call
		kiya hua hai, har button k functions BookRooms.cpp file mein banay hain, wahan se call kiye hain.*/

	private: System::Void AddButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		AddButton_Click(sender, e);
	}
	private: System::Void DeleteButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		DeleteButton_Click(sender, e);
	}

	private: System::Void HomeButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		HomeButton_Click(sender, e);
	}

	private: System::Void NextButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		NextButton_Click(sender, e);
	}
	
	


};
}