#include "ViewDetails.h"
#include <string>


using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;


void ViewDetails::LoadData()
{

    try {
        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT bookingsTable.bookingID, bookingsTable.customerID, customers.firstName, customers.lastName, bookingsTable.roomNO, rooms.roomType, rooms.price, bookingsTable.checkinDate, bookingsTable.checkoutDate FROM (bookings AS bookingsTable INNER JOIN customers ON customers.customerID = bookingsTable.customerID) INNER JOIN rooms ON rooms.roomNo = bookingsTable.roomNo;", conn);
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dataGridView1->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }


}