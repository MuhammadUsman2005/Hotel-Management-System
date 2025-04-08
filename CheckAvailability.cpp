#include "Dashboard.h"
#include "CheckAvailability.h"
#include "GenerateBills.h"

using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;


// LoadData() function banaya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein 

void CheckAvailability::LoadData()
{

    try {

        /* Yahan hum ne DataGridView ko database se data load karne ka code likha hai.
         Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */


        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT rooms, type, price, roomNo FROM rooms;", conn);

        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dataGridView1->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }



}


void CheckAvailability::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
    Dashboard^ dashboard = gcnew Dashboard();
    dashboard->Show();
    this->Hide();
}

void CheckAvailability::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
    this->Hide();
}