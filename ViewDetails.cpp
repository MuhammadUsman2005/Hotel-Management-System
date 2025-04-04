#include "ViewDetails.h"
#include <string>
#include "BookRooms.h"
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

void ViewDetails::LoadData()
{

    try {

		/* Yahan hum ne DataGridView ko database se data load karne ka code likha hai.
		 Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */
     

        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT b.bookingID, b.checkinDate, c.firstName, c.lastName, c.address, c.mobile, b.roomNo, c.gender, "
                "c.email, c.nationality, r.roomType "
                "FROM ((bookings b INNER JOIN customers c ON c.bookingID = b.bookingID) "
                "INNER JOIN details d ON (d.bookingID = b.bookingID AND d.roomNo = b.roomNo))"
                "INNER JOIN rooms r ON r.roomNo = b.roomNo;", conn);
        

        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dataGridView1->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }



}

void ViewDetails::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
    BookRooms^ bookRooms = gcnew BookRooms();
    bookRooms->Show();
    this->Hide();
}

void ViewDetails::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
    GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
    this->Hide();
}