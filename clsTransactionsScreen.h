#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include <iomanip>
#include <conio.h>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfar = 4, eShowMainMenue = 5
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _GoBackToTransactionsMenue()
    {
      cout << "\n\nPress Any Key To Go Show Transactions Menue...";
      getch();
      ShowTransactionsMenue();
    }

static void _ShowTrnsfarScreen()
{
  clsTransferScreen::ShowTransferScreen();
}

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfar:
        {
            _ShowTrnsfarScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
        
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfar.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

