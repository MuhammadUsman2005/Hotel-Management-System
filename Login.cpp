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




void Login::CheckLogin(System::Object^ sender, System::EventArgs^ e)
{
   
    String^ userName = textBoxUserName->Text;
    String^ password = textBoxPassword->Text;

    if (userName == "usman" && password == "123")
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


