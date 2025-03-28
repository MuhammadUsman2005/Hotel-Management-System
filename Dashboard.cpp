#include "Dashboard.h"
#include "BookRooms.h"
#include "ViewDetails.h"
#include "CheckAvailability.h"
#include "GenerateBills.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HOTELMANAGEMENTSYSTEM;

void Dashboard::BookRoomsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Book Rooms Button Clicked");
	this->Hide();
    BookRooms^ bookRooms = gcnew BookRooms();
    bookRooms->Show();
}

void Dashboard::ViewDetailsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("View Details Button Clicked");
    this->Hide();
    ViewDetails^ viewDetails = gcnew ViewDetails();
    viewDetails->Show();
}

void Dashboard::CheckAvailabilityButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Check Availability Button Clicked");
    this->Hide();
    CheckAvailability^ checkAvailability = gcnew CheckAvailability();
    checkAvailability->Show();
}

void Dashboard::GenerateBillsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Generate Bills Button Clicked");
    this->Hide();
    GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
}

void Dashboard::LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
   // MessageBox::Show("Are you sure you want to Logout?");
	MessageBoxIcon icon = MessageBoxIcon::Question;
	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
	if (MessageBox::Show("Are you sure you want to Logout?", "Logout", buttons, icon) == System::Windows::Forms::DialogResult::Yes)
	
    {
        // is se current form close ho jaye ga aur login wala form open ho jaye ga
        // current form hide ho jaye ga

        this->Hide();
        Login^ login = gcnew Login();
        login->ShowDialog();
        this->Close();  // login form open hone k baad ye wala form close ho jaye ga

	}

	else
	{
		MessageBox::Show("Logout Cancelled");
	}

    
    // is se current form close ho jaye ga aur login wala form open ho jaye ga
    // current form hide ho jaye ga
    
    /*this->Hide();  
    Login^ login = gcnew Login();
    login->ShowDialog();
	this->Close();*/  // login form open hone k baad ye wala form close ho jaye ga
}


