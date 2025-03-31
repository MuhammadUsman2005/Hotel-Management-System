#include "Dashboard.h"
#include "BookRooms.h"
#include "ViewDetails.h"
#include "CheckAvailability.h"
#include "GenerateBills.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HOTELMANAGEMENTSYSTEM;


// DONE BY MUHAMMAD USMAN MASOOD
// CT-24239
// SECTION: E

/*BookRooms wale button ka event handler initialize kiya hai, agar BookRooms wala button click hoga, 
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::BookRoomsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Book Rooms Button Clicked");
	this->Hide();
    BookRooms^ bookRooms = gcnew BookRooms();
    bookRooms->Show();
}

/*ViewDetails wale button ka event handler initialize kiya hai, agar ViewDetails wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::ViewDetailsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("View Details Button Clicked");
    this->Hide();
    ViewDetails^ viewDetails = gcnew ViewDetails();
    viewDetails->Show();
}

/*CheckAvailability wale button ka event handler initialize kiya hai, agar CheckAvailability wala button 
click hoga, tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::CheckAvailabilityButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Check Availability Button Clicked");
    this->Hide();
    CheckAvailability^ checkAvailability = gcnew CheckAvailability();
    checkAvailability->Show();
}

/*GenerateBills wale button ka event handler initialize kiya hai, agar GenerateBills wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::GenerateBillsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Generate Bills Button Clicked");
    this->Hide();
    GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
}

/*Logout wale button ka event handler initialize kiya hai, agar Logoout wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

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

}

