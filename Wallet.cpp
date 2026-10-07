#include<iostream>
using namespace std ;
class Bankaccount 
{
    private :
        string user_name ;
        int user_phonenumber ;
        int user_accountnumber ;
        string user_passwordapp , confirm_user_passwordapp ;
        int user_passwordaccount , confirm_user_passwordaccount ;
        float balance = 0 ;

    public : 
        void creat_account()
        {
            // Name , Phone Number , Account Number , balance
            cout << "--------------------------------\n" ;
            cout << "Enter Your Name : " ;
            cin >> user_name ;
            cout << "--------------------------------\n" ;
            cout << "Enter Your Phone Number : " ;
            cin >> user_phonenumber ;
            cout << "--------------------------------\n" ;
            cout << "Enter Your Acount Number : " ;
            cin >> user_accountnumber ;

            // Password App
            cout << "--------------------------------\n" ;
            cout << "Enter Password App : " ;
            cin >> user_passwordapp ;
            do{
                cout << "--------------------------------\n" ;
                cout << "Confirm Password App : " ;
                cin >> confirm_user_passwordapp ;
                if (user_passwordapp != confirm_user_passwordapp)
                {
                    cout << "\n---------------------\n" ;
                    cout << "Passwords don't Match\n" ;
                    cout << "---------------------\n\n" ;
                }
            }while (user_passwordapp != confirm_user_passwordapp);

            // Password Acount
            cout << "--------------------------------\n" ;
            cout << "Enter Password Account : " ;
            cin >> user_passwordaccount ;
            do{
                cout << "--------------------------------\n" ;
                cout << "Confirm Password Account : " ;
                cin >> confirm_user_passwordaccount ;
                if (user_passwordaccount != confirm_user_passwordaccount)
                {
                    cout << "\n---------------------\n" ;
                    cout << "Passwords don't Match\n" ;
                    cout << "---------------------\n\n" ;
                }
            }while (user_passwordaccount != confirm_user_passwordaccount); 
            cout << "\n*************************************************************\n" ;
            cout << "Welcome! " << user_name << " You Acount has been Created Successfully.\n" ;
            balance += 100 ;
            cout << "Congratulations! " << user_name << " won 100 EGP for creating your account\n" ;
            cout << "Current Balance = "<< balance << endl ;
            cout << "*************************************************************\n" ;
        }

        void Depositmoney()
        {
            float depositmoney ;
            float Maxdeposit = 30000 ;
            int check_passwordaccount ;
            for ( int t = 1 ; t <= 5 ; t++ )
            {
                cout << "--------------------------------\n" ;
                cout << "Enter Your Password Account : ";
                cin >> check_passwordaccount ;
                if (check_passwordaccount == user_passwordaccount)
                {
                    do{
                        cout << endl ;
                        cout << "Enter the Deposit = " ;
                        cin >> depositmoney ; 
                        if (depositmoney <= 0)
                        {
                            cout << "Are you Joking with me?\n";
                        }
                        else if (depositmoney > Maxdeposit)
                        {
                            cout << "Transaction declined. Maximum limit exceeded.\n";
                        }
                    }while(depositmoney <= 0 || depositmoney > Maxdeposit);
                    balance += depositmoney ;
                    cout << "Deposit successful!\n" ;
                    cout << "Your Current Balance = " << balance << endl ;
                    break;
                }
                else
                {
                    cout << "Wrong Password! ,try Again.\n" ;
                }
                if (t == 5)
                {
                    cout << "Too many incorrect attempts.\n";
                }
            }
        }

        void Withdrawmoney()
        {
            float withdrawmoney ;
            float MaxWithdraw = 50000 ;
            int check_passwordaccount ;
            for ( int t = 1 ; t <= 5 ; t++ )
            {
                cout << "--------------------------------\n" ;
                cout << "Enter Your Password Acount : ";
                cin >> check_passwordaccount ;
                if (check_passwordaccount == user_passwordaccount)
                {
                    do{
                        cout << endl ;
                        cout << "Enter the Withdraw = " ;
                        cin >> withdrawmoney ; 
                        if (withdrawmoney <= 0)
                        {
                            cout << "Invalid withdrawal.\n";
                        }
                        else if (withdrawmoney > MaxWithdraw)
                        {
                            cout << "Transaction declined. Maximum limit exceeded.\n";
                        }
                        else if (withdrawmoney > balance)
                        {
                            cout << "Transaction declined. Insufficient balance.\n";
                        }
                    }while(withdrawmoney <=0 || withdrawmoney > balance || withdrawmoney > MaxWithdraw);
                    balance -= withdrawmoney ;
                    cout << "Withdraw successful!\n" ;
                    cout << "Your Current Balance = " << balance << endl ;
                    break;
                }
                else
                {
                    cout << "Wrong Password! ,try Again.\n" ;
                }
                if (t == 5)
                {
                    cout << "Too many incorrect attempts.\n";
                }
            }
        }

        void showinfo()
        {
            cout << "***** User Information *****\n\n" ;
            cout << "Name : " << user_name << endl ;
            cout << "--------------------------\n" ;
            cout << "Phone Number : " << user_phonenumber << endl ;
            cout << "--------------------------\n" ;
            cout << "Acount Number : " << user_accountnumber << endl ;
            cout << "--------------------------\n" ;
            cout << "Balance : " << balance << endl ;
            cout << "--------------------------\n" ;
        }
};

int main()
{
    Bankaccount acount ;
    cout << "!!! Creat Account !!!\n" ;
    acount.creat_account() ;
    int choice ;
    do{
        cout << "\n==========================\n" ;
        cout << "1.Deposit Money\n" ;
        cout << "2.Withdraw Money\n" ;
        cout << "3.View Account Information\n" ;
        cout << "0.Exit\n" ;
        cout << "==========================\n\n" ;

        cout << "Enter your choice (0,...,3) : " ;
        cin >> choice ;

        switch (choice)
        {
        case 1 :
            acount.Depositmoney() ;
            break;
        case 2 :
            acount.Withdrawmoney() ;
            break;
        case 3 :
            acount.showinfo() ;
            break;
        case 0 : 
            break;            
        default :
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }while(choice != 0 );
}
