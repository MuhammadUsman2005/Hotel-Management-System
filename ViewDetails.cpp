#include "ViewDetails.h"
#include <string>
#include "BookRooms.h"
#include "CheckAvailability.h"


using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;

// DONE BY MUHAMMAD USMAN MASOOD
// CT-24239
// SECTION: E

/* LoadData() function banaya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein */

void ViewDetails::LoadData()
{

    try {
        /* Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */

        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        //OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT bookingsTable.bookingID, bookingsTable.customerID, customers.firstName, customers.lastName, bookingsTable.roomNO, rooms.roomType, rooms.price, bookingsTable.checkinDate, bookingsTable.checkoutDate FROM (bookings AS bookingsTable INNER JOIN customers ON customers.customerID = bookingsTable.customerID) INNER JOIN rooms ON rooms.roomNo = bookingsTable.roomNo;", conn);
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT bookings.bookingID, customers.customerID, customers.FirstName, customers.LastName, customers.address, customers.mobile, customers.gender, customers.email, customers.nationality, "
            + "bookings.roomNo, rooms.roomType, rooms.price, bookings.checkinDate "
            + "FROM (bookings "
            + "INNER JOIN customers ON bookings.CustomerID = customers.customerID) "
            + "INNER JOIN rooms ON bookings.roomNo = rooms.roomNo;", conn);
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dataGridView1->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }


}