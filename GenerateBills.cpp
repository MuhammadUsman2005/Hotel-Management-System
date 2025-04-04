#include "GenerateBills.h"
#include "ViewDetails.h"
#include "Dashboard.h"

using namespace System;
using namespace System::Windows::Forms;

namespace HOTELMANAGEMENTSYSTEM {

    Void GenerateBills::GenerateBillButton_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Calculate days stayed
            TimeSpan daysStayed = dateTimePicker2->Value - dateTimePicker1->Value;
            int days = daysStayed.Days;
            if (days < 0) days = 0; // Ensure days is not negative
            textBox2->Text = days.ToString();

            // Calculate total bill
            String^ roomPriceStr = comboBox1->Text;
            // Extract numeric value from room price string
            double roomPrice = 0;
            int dollarIndex = roomPriceStr->IndexOf("$");
            if (dollarIndex >= 0) {
                String^ priceStr = roomPriceStr->Substring(dollarIndex + 1)->Trim();
                int spaceIndex = priceStr->IndexOf(" ");
                if (spaceIndex > 0) {
                    priceStr = priceStr->Substring(0, spaceIndex);
                }
                roomPrice = Double::Parse(priceStr);
            }

            double totalBill = roomPrice * days;
            label10->Text = "YOUR TOTAL BILL : $" + totalBill.ToString("F2");
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error calculating bill: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    Void GenerateBills::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
        ViewDetails^ viewDetails = gcnew ViewDetails();
        viewDetails->Show();
        this->Hide();
    }

    Void GenerateBills::HomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Dashboard^ dashboard = gcnew Dashboard();
        dashboard->Show();
        this->Hide();
    }

    Void GenerateBills::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        // When booking ID is entered, populate other fields automatically
        // You would typically fetch this data from your database
        // This is just a simulation - replace with actual database code

        String^ bookingId = textBox1->Text;
        if (!String::IsNullOrEmpty(bookingId)) {
            // Simulate fetching data based on booking ID
            // In a real app, you would query your database here

            // For demo purposes, we'll just set some sample values
            comboBox3->Text = "DELUXE ($ 150.0)";
            comboBox4->Text = "102";
            dateTimePicker1->Value = DateTime::Now.AddDays(-5); // Sample check-in date
            comboBox1->Text = "$ 150.0 (DELUXE)";
        }
    }

    // Add this to your InitializeComponent method in GenerateBills.h
    // after the components are initialized
    /*
    this->GenerateBillButton->Click += gcnew System::EventHandler(this, &GenerateBills::GenerateBillButton_Click);
    this->BackButton->Click += gcnew System::EventHandler(this, &GenerateBills::BackButton_Click);
    this->HomeButton->Click += gcnew System::EventHandler(this, &GenerateBills::HomeButton_Click);
    this->textBox1->TextChanged += gcnew System::EventHandler(this, &GenerateBills::textBox1_TextChanged);
    */
}