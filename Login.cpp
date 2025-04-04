#include "Login.h"
#include "Dashboard.h"
#include <string>


using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;

  
     int main(array<String^>^ args)
     {
         Application::EnableVisualStyles();
         Application::SetCompatibleTextRenderingDefault(false);
         HOTELMANAGEMENTSYSTEM::Login form;
         Application::Run(% form);
     }


     // Yahan hum ne Login check karne ka function banaya hai

void Login::CheckLogin(System::Object^ sender, System::EventArgs^ e)
{
   
    // textboxes k andar username aur password ko input lega

    String^ userName = textBoxUserName->Text;
    String^ password = textBoxPassword->Text;

    if (userName == "admin" && password == "123")
    {
        MessageBox::Show("Login Successful");
        this->Hide();
        Dashboard^ dashboard = gcnew Dashboard();
        dashboard->Show();
    }

    else 
    {
        MessageBox::Show("Invalid Credentials");
    }


}


