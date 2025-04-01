//#include "BookRooms.h"
//#include "ViewDetails.h"
//#include "Login.h"
//#include "GenerateBills.h"
//#include "CheckAvailability.h"
//#include "Dashboard.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//using namespace HOTELMANAGEMENTSYSTEM;
//
//
// //DONE BY MUHAMMAD USMAN MASOOD
// //CT-24239
// //SECTION: E
//
///*ADD wale button ka event handler initialize kiya hai, agar ADD wala button click hoga,
//tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/
//
//void BookRooms::AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
//	MessageBox::Show("Data Added Successfully");
//	/* this->Hide();
//	ViewDetails^ viewDetails = gcnew ViewDetails();
//	viewDetails->Show();*/
//}
//
///*DELETE wale button ka event handler initialize kiya hai, agar DELETE wala button click hoga,
//tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/
//
//void BookRooms::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
//	MessageBox::Show("Data Deleted Successfully");
//	this->Hide();
//	Login^ login = gcnew Login();
//	login->Show();
//}
//
///*HOME wale button ka event handler initialize kiya hai, agar HOME wala button click hoga,
//tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/
//
//void BookRooms::HomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
//	MessageBox::Show("Home Button Clicked");
//	this->Hide();
//	Dashboard^ dashboard = gcnew Dashboard();
//	dashboard->Show();
//}
//
///*NEXT wale button ka event handler initialize kiya hai, agar NEXT wala button click hoga,
//tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/
//
//void BookRooms::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
//	MessageBox::Show("View Details!");
//	this->Hide();
//	ViewDetails^ viewDetails = gcnew ViewDetails();
//	viewDetails->Show();
//}
//
//

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

// DONE BY MUHAMMAD USMAN MASOOD
// CT-24239
// SECTION: E

    void BookRooms::LoadData() {
        // Your data loading implementation here
    }
    
    /*ADD wale button ka event handler initialize kiya hai, agar ADD wala button click hoga,
     tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

    void BookRooms::AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

            // 1. First validate all inputs
            if (comboBox5->SelectedItem == nullptr || comboBox4->SelectedItem == nullptr) {
                MessageBox::Show("Please select Customer ID and Room Number", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            // 2. Use TryParse instead of Convert for safer conversion
            int customerID, roomNo;
            if (!Int32::TryParse(comboBox5->SelectedItem->ToString(), customerID)) {
                MessageBox::Show("Invalid Customer ID format", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            String^ roomNoStr = comboBox4->SelectedItem->ToString()->Split('-')[0]->Trim();
            if (!Int32::TryParse(roomNoStr, roomNo)) {
                MessageBox::Show("Invalid Room Number format", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            // 3. Insert into customers table
            String^ customerQuery = "INSERT INTO customers (customerID, FirstName, LastName, Address, mobile, gender, email, nationality) " +
                "VALUES (@customerID, @FirstName, @LastName, @Address, @mobile, @gender, @email, @nationality)";

            OleDbCommand^ customerCommand = gcnew OleDbCommand(customerQuery, connection);

            // 4. Use proper parameter types
            customerCommand->Parameters->AddWithValue("@customerID", customerID);
            customerCommand->Parameters->AddWithValue("@FirstName", textBox5->Text);
            customerCommand->Parameters->AddWithValue("@LastName", textBox6->Text);
            customerCommand->Parameters->AddWithValue("@Address", textBox4->Text);
            customerCommand->Parameters->AddWithValue("@mobile", textBox2->Text);
            customerCommand->Parameters->AddWithValue("@gender", comboBox2->SelectedItem->ToString());
            customerCommand->Parameters->AddWithValue("@email", textBox7->Text);
            customerCommand->Parameters->AddWithValue("@nationality", comboBox1->SelectedItem->ToString());

            // 5. Insert into bookings table
            String^ bookingQuery = "INSERT INTO bookings (CustomerID, roomNo, checkinDate) " +
                "VALUES (@CustomerID, @roomNo, @checkinDate)";

            OleDbCommand^ bookingCommand = gcnew OleDbCommand(bookingQuery, connection);

            // 6. Use proper parameter types
            bookingCommand->Parameters->AddWithValue("@CustomerID", customerID);
            bookingCommand->Parameters->AddWithValue("@roomNo", roomNo);
            bookingCommand->Parameters->AddWithValue("@checkinDate", dateTimePicker1->Value.Date.ToString("yyyy-MM-dd"));

            connection->Open();
            OleDbTransaction^ transaction = connection->BeginTransaction();

            try {
                customerCommand->Transaction = transaction;
                customerCommand->ExecuteNonQuery();

                bookingCommand->Transaction = transaction;
                bookingCommand->ExecuteNonQuery();

                transaction->Commit();
                MessageBox::Show("Booking added successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Refresh DataGridView
                String^ selectQuery = "SELECT bookings.bookingID, customers.customerID, customers.FirstName, customers.LastName, customers.address, customers.mobile, customers.gender, customers.email, customers.nationality, "
                    + "bookings.roomNo, rooms.roomType, rooms.price, bookings.checkinDate "
                    + "FROM (bookings "
                    + "INNER JOIN customers ON bookings.CustomerID = customers.customerID) "
                    + "INNER JOIN rooms ON bookings.roomNo = rooms.roomNo";


                OleDbCommand^ selectCommand = gcnew OleDbCommand(selectQuery, connection);
                OleDbDataAdapter^ dataAdapter = gcnew OleDbDataAdapter(selectCommand);
                DataTable^ dataTable = gcnew DataTable();
                dataAdapter->Fill(dataTable);
                dataGridView1->DataSource = dataTable;
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                MessageBox::Show("Error adding booking: " + ex->Message, "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                connection->Close();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    /*DELETE wale button ka event handler initialize kiya hai, agar DELETE wala button click hoga,
     tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

    void BookRooms::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a booking to delete.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }

        try {
            String^ bookingID = dataGridView1->SelectedRows[0]->Cells["bookingID"]->Value->ToString();
            String^ roomNo = dataGridView1->SelectedRows[0]->Cells["roomNo"]->Value->ToString();

            MessageBoxIcon icon = MessageBoxIcon::Question;
            MessageBoxButtons buttons = MessageBoxButtons::YesNo;
            if (MessageBox::Show("Are you sure you want to delete this booking?", "Confirm Delete", buttons, icon) == System::Windows::Forms::DialogResult::Yes) {
                String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

                // Rest of your Delete button implementation...

                {
                    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";
                    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

                    // Delete from bookings table
                    String^ deleteBookingQuery = "DELETE FROM bookings WHERE bookingID = @bookingID";
                    OleDbCommand^ deleteBookingCommand = gcnew OleDbCommand(deleteBookingQuery, connection);
                    deleteBookingCommand->Parameters->AddWithValue("@bookingID", bookingID);

                    // Delete from details table
                    String^ deleteDetailsQuery = "DELETE FROM details WHERE bookingID = @bookingID";
                    OleDbCommand^ deleteDetailsCommand = gcnew OleDbCommand(deleteDetailsQuery, connection);
                    deleteDetailsCommand->Parameters->AddWithValue("@bookingID", bookingID);

                    // Update room availability
                    String^ updateRoomQuery = "UPDATE rooms SET availability = 'Yes' WHERE roomNo = @roomNo";
                    OleDbCommand^ updateRoomCommand = gcnew OleDbCommand(updateRoomQuery, connection);
                    updateRoomCommand->Parameters->AddWithValue("@roomNo", roomNo);

                    connection->Open();
                    OleDbTransaction^ transaction = connection->BeginTransaction();

                    try {
                        deleteBookingCommand->Transaction = transaction;
                        deleteBookingCommand->ExecuteNonQuery();

                        deleteDetailsCommand->Transaction = transaction;
                        deleteDetailsCommand->ExecuteNonQuery();

                        updateRoomCommand->Transaction = transaction;
                        updateRoomCommand->ExecuteNonQuery();

                        transaction->Commit();
                        MessageBox::Show("Booking deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);


                        // Refresh the DataGridView
                        
                        String^ selectQuery = "SELECT bookings.bookingID, customers.customerID, customers.FirstName, customers.LastName, customers.address, customers.mobile, customers.gender, customers.email, customers.nationality, "
                            + "bookings.roomNo, rooms.roomType, rooms.price, bookings.checkinDate "
                            + "FROM (bookings "
                            + "INNER JOIN customers ON bookings.CustomerID = customers.customerID) "
                            + "INNER JOIN rooms ON bookings.roomNo = rooms.roomNo";



                        OleDbCommand^ selectCommand = gcnew OleDbCommand(selectQuery, connection);
                        OleDbDataAdapter^ dataAdapter = gcnew OleDbDataAdapter(selectCommand);
                        DataTable^ dataTable = gcnew DataTable();
                        dataAdapter->Fill(dataTable);
                        dataGridView1->DataSource = dataTable;
                    }

                    catch (Exception^ ex) {
                        transaction->Rollback();
                        MessageBox::Show("Error deleting booking: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                    finally {
                        connection->Close();
                    }
                }
            }
        }

        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    } 

    /*HOME wale button ka event handler initialize kiya hai, agar HOME wala button click hoga,
     tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/
    
    void BookRooms::HomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBoxIcon icon = MessageBoxIcon::Question;
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        if (MessageBox::Show("Are you sure you want to go back to dashboard?", "Confirm", buttons, icon) == System::Windows::Forms::DialogResult::Yes) {
            Dashboard^ dashboard = gcnew Dashboard();
            dashboard->Show();
            this->Close();
        }
    }

    /*NEXT wale button ka event handler initialize kiya hai, agar NEXT wala button click hoga,
     tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

    void BookRooms::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show("Go to View Details", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
        ViewDetails^ viewDetails = gcnew ViewDetails();
        viewDetails->Show();
        this->Hide();
    }
}
