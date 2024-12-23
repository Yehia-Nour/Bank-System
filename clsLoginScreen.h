#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

  private :
    static  void _Login()
    {
      bool LoginFaild = false;
      string Username, Password;
      short C = 2;
      do
      {

      if (LoginFaild)
      {
        cout << "\nInvlaid Username/Password!\n\n";
        cout << "You Have " << C << " Trials To Login\n";
        C--;
      }

      cout << "Enter Username? ";
      cin >> Username;

      cout << "Enter Password? ";
      cin >> Password;

      CurrentUser = clsUser::Find(Username, Password);

      LoginFaild = CurrentUser.IsEmpty();
      if (C == 0)
      {
        cout << "You Are Locked After 3 falid Trials";
        return;
      }
      

    } while (LoginFaild);
    CurrentUser.RegisterLogIn();
    clsMainScreen::ShowMainMenue();

    }

public:


    static void ShowLoginScreen()
    {
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

