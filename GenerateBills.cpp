#include "GenerateBills.h"
#include "Dashboard.h"
#include "ViewDetails.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;

namespace HOTELMANAGEMENTSYSTEM {

    
    void GenerateBills::LoadBookingDetails(String^ bookingID)
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";

        try {
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
            connection->Open();

            String^ query = "SELECT b.bookingID, b.checkinDate, b.roomNo, r.roomType, r.price "
                "FROM bookings b INNER JOIN rooms r ON b.roomNo = r.roomNo "
                "WHERE b.bookingID = @bookingID";

            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
            command->Parameters->AddWithValue("@bookingID", bookingID);

            OleDbDataReader^ reader = command->ExecuteReader();

            if (reader->Read())
            {
                bookingIDTextbox->Text = reader["bookingID"]->ToString();
                roomNumberComboBox->Text = reader["roomNo"]->ToString();
                roomTypeComboBox->Text = reader["roomType"]->ToString();

                String^ roomType = reader["roomType"]->ToString();
                if (roomType == "SUITE") {
                    roomPricePerNightComboBox->Text = "$ 200.0 (SUITE)";
                }
                else if (roomType == "DELUXE") {
                    roomPricePerNightComboBox->Text = "$ 150.0 (DELUXE)";
                }
                else {
                    roomPricePerNightComboBox->Text = "$ 100.0 (STANDARD)";
                }

                DateTime checkinDate;
                if (DateTime::TryParse(reader["checkinDate"]->ToString(), checkinDate)) {
                    checkInDatePicker->Value = checkinDate;
                }

                checkOutDatePicker->Value = DateTime::Now;
                CalculateDaysStayed();
            }
            else {
                MessageBox::Show("Booking ID not found!");
            }

            connection->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading booking details: " + ex->Message);
        }
    }

    void GenerateBills::CalculateDaysStayed()
    {
        DateTime checkinDate = checkInDatePicker->Value;
        DateTime checkoutDate = checkOutDatePicker->Value;

        if (checkoutDate < checkinDate) {
            MessageBox::Show("Check-out date cannot be before check-in date!");
            checkOutDatePicker->Value = checkinDate;
            return;
        }

        TimeSpan duration = checkoutDate - checkinDate;
        int daysStayed = duration.Days;
        if (daysStayed == 0) daysStayed = 1;

        daysStayedTextbox->Text = daysStayed.ToString();
        //CalculateTotalBill();
    }

    void GenerateBills::CalculateTotalBill()
    {
        try
        {
            // Check if required fields are empty
            if (daysStayedTextbox->Text->Length == 0 || roomPricePerNightComboBox->Text->Length == 0)
                return;

            // Get days stayed
            int daysStayed = Convert::ToInt32(daysStayedTextbox->Text);
            if (daysStayed <= 0) daysStayed = 1; // Minimum 1 day

            // Extract price from comboBox text (e.g., "$ 200.0 (SUITE)" -> 200.0)
            String^ priceText = roomPricePerNightComboBox->Text;

            // Find the dollar sign
            int dollarPos = priceText->IndexOf("$");
            if (dollarPos < 0)
            {
                MessageBox::Show("Invalid price format! Price should start with $");
                return;
            }

            // Extract the numeric part after $
            String^ numericPart = priceText->Substring(dollarPos + 1)->Trim();

            // Find where the numeric part ends
            int spacePos = numericPart->IndexOf(" ");
            if (spacePos > 0)
            {
                numericPart = numericPart->Substring(0, spacePos);
            }

            // Handle cases where there might be parentheses after number
            int parenPos = numericPart->IndexOf("(");
            if (parenPos > 0)
            {
                numericPart = numericPart->Substring(0, parenPos)->Trim();
            }

            // Convert to double using invariant culture
            double pricePerNight = Convert::ToDouble(numericPart, System::Globalization::CultureInfo::InvariantCulture);

            // Calculate and display total bill
            double totalBill = daysStayed * pricePerNight;
            label10->Text = "YOUR TOTAL BILL : $" + totalBill.ToString("F2");
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error calculating bill: " + ex->Message +
                "\nPlease check the room price format.",
                "Calculation Error",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error);
        }
    }

    void GenerateBills::SaveBillToDatabase()
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Hotel Management System\\HOTEL MANAGEMENT SYSTEM\\project resources\\database\\connection.accdb;";

        try {
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
            connection->Open();

            // Extract price using the same reliable method
            String^ priceText = roomPricePerNightComboBox->Text;
            int dollarPos = priceText->IndexOf("$");
            String^ numericPart = priceText->Substring(dollarPos + 1)->Trim();
            int spacePos = numericPart->IndexOf(" ");
            if (spacePos > 0)
            {
                numericPart = numericPart->Substring(0, spacePos);
            }
            double pricePerNight = Convert::ToDouble(numericPart, System::Globalization::CultureInfo::InvariantCulture);

            int daysStayed = Convert::ToInt32(daysStayedTextbox->Text);
            double totalAmount = daysStayed * pricePerNight;

            String^ query = "INSERT INTO bills (bookingID, roomNo, roomType, checkinDate, checkoutDate, daysStayed, pricePerNight, totalAmount) "
                "VALUES (@bookingID, @roomNo, @roomType, @checkinDate, @checkoutDate, @daysStayed, @pricePerNight, @totalAmount)";

            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
            command->Parameters->AddWithValue("@bookingID", bookingIDTextbox->Text);
            command->Parameters->AddWithValue("@roomNo", roomNumberComboBox->Text);
            command->Parameters->AddWithValue("@roomType", roomTypeComboBox->Text);
            command->Parameters->AddWithValue("@checkinDate", checkInDatePicker->Value.ToString("MM/dd/yyyy"));
            command->Parameters->AddWithValue("@checkoutDate", checkOutDatePicker->Value.ToString("MM/dd/yyyy"));
            command->Parameters->AddWithValue("@daysStayed", daysStayed);
            command->Parameters->AddWithValue("@pricePerNight", pricePerNight);
            command->Parameters->AddWithValue("@totalAmount", totalAmount);

            command->ExecuteNonQuery();
            connection->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error saving bill: " + ex->Message);
        }
    }

    // Event Handlers
    //Void GenerateBills::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
    //{
    //    // Only process if we have at least 1 character that's a digit
    //    if (bookingIDTextbox->Text->Length > 0 && Char::IsDigit(bookingIDTextbox->Text[0]))
    //    {
    //        LoadBookingDetails(bookingIDTextbox->Text);
    //    }
    //}
    Void GenerateBills::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
        // Clear any existing total
        label10->Text = "YOUR TOTAL BILL : $0.00";

        // Only process if we have at least 1 character that's a digit
        if (bookingIDTextbox->Text->Length > 0 && Char::IsDigit(bookingIDTextbox->Text[0]))
        {
            LoadBookingDetails(bookingIDTextbox->Text);
        }
    }

    Void GenerateBills::dateTimePicker2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
    {
        CalculateDaysStayed();
    }

    Void GenerateBills::GenerateBillButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (bookingIDTextbox->Text->Length == 0 || roomNumberComboBox->Text->Length == 0 ||
            roomTypeComboBox->Text->Length == 0 || checkInDatePicker->Text->Length == 0 ||
            checkOutDatePicker->Text->Length == 0 || daysStayedTextbox->Text->Length == 0) {
            MessageBox::Show("Please fill all fields!");
            return;
        }
        if (daysStayedTextbox->Text->Length == 0) {
            CalculateDaysStayed();
        }

        // Then calculate and display the total bill
        CalculateTotalBill();
        SaveBillToDatabase();
        MessageBox::Show("Bill generated successfully!");
    }

    Void GenerateBills::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ViewDetails^ viewDetails = gcnew ViewDetails();
        viewDetails->Show();
        this->Hide();
    }

    Void GenerateBills::HomeButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Dashboard^ dashboard = gcnew Dashboard();
        dashboard->Show();
        this->Hide();
    }
}