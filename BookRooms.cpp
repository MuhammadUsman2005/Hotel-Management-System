#include "BookRooms.h"
#include "ViewDetails.h"
#include "Login.h"
#include "GenerateBills.h"
#include "CheckAvailability.h"
#include "Dashboard.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HOTELMANAGEMENTSYSTEM;


 //DONE BY MUHAMMAD USMAN MASOOD
 //CT-24239
 //SECTION: E

/*ADD wale button ka event handler initialize kiya hai, agar ADD wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void BookRooms::AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Data Added Successfully");
	/* this->Hide();
	ViewDetails^ viewDetails = gcnew ViewDetails();
	viewDetails->Show();*/
}

/*DELETE wale button ka event handler initialize kiya hai, agar DELETE wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void BookRooms::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Data Deleted Successfully");
	this->Hide();
	Login^ login = gcnew Login();
	login->Show();
}

/*HOME wale button ka event handler initialize kiya hai, agar HOME wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void BookRooms::HomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Home Button Clicked");
	this->Hide();
	Dashboard^ dashboard = gcnew Dashboard();
	dashboard->Show();
}

/*NEXT wale button ka event handler initialize kiya hai, agar NEXT wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void BookRooms::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("View Details!");
	this->Hide();
	ViewDetails^ viewDetails = gcnew ViewDetails();
	viewDetails->Show();
}


