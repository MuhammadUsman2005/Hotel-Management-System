#include "Login.h"
#include <string.h>
#include "MainPage.h"
#include <string>


using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;

  
     void main(array<String^>^ args)
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

    if (userName == "Admin" && password == "123")
    {
        MessageBox::Show("Login Successful");
        this->Hide();

        MainPage^ mainPage = gcnew MainPage();
        mainPage->Show();
    }

    else 
    {
        MessageBox::Show("Invalid Credentials");
    }


}
