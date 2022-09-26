#include <iostream>

using namespace std;
int checkpin()
{

}
void statement(int x)
{
    cout<<"Choose option 1 or 2 only"<<endl;
    cout<<"1. 30 days statement"<<endl;
    cout<<"2. 90 days statement"<<endl;
    cin>>x;
    switch(x)
    {
    case 1:
        cout<<"30 days statement sent to your E-mail."<<endl;
        break;
    case 2:
        cout<<"90 days statement sent to your E-mail."<<endl;
    default:
        cout<<"You have made an incorrect choice"<<endl;
    }
}

int changepin(int newpin,int currentpin,int a)
{
    cout<<"Enter current pin :";
    cin>>newpin;
    while(newpin!=currentpin)
    {
        a--;
        cout<<"Wrong, enter PIN again :";
        cin>>newpin;
    }
    if(a>0)
    {
        cout<<"Enter new PIN: ";
        cin>>newpin;
        currentpin=newpin;
        cout<<"Enter PIN again: ";
        cin>>newpin;
        if(newpin==currentpin)
        {
            cout<<"Successfully changed your PIN."<<endl;
            return newpin;
        }
        else
        {
            cout<<"PINs do not match, exitting!"<<endl;
        }
    }
}
double sendcashf(double bal,double send,double num)
{
    cout<<"Enter number to send money to :";
    cin>>num;
    cout<<"Amount to be sent: R";
    cin>>send;
    while(send>bal)
    {
        cout<<"Insufficient funds, send less amount: R";
        cin>>send;
    }
    cout<<"Successfully sent R"<<send<<" to "<<num<<endl;
    return send;

}
double withdrawf(double bal,double wit)
{
    cout<<"Withdrawal amount: R";
    cin>>wit;
    while(wit>bal)
    {
        cout<<"Insufficient funds, withdraw less amount: R";
        cin>>wit;
    }
    cout<<"Successfully withdrawn."<<endl;
    return wit;

}
double depositf(double x)
{
    cout<<"Enter Amount you want to deposit: R";
    cin>>x;
    return x;
}
double balancef(double x)
{
    cout<<"Your balance is R"<<x<<endl;
}
void dots()
{
    cout<<"--------------------------------------------------"<<endl;
}
void menu()
{
    cout<<"1. View Balance"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Send cash"<<endl;
    cout<<"5. Change Pin"<<endl;
    cout<<"6. Send Statement"<<endl;
    cout<<"7. Exit"<<endl;
}
int ending(int x)
{
    if(x==0)
    {
        cout<<"Card blocked, visit nearest branch!!!"<<endl;
    }
    else
    {
        cout<<"Thank you for using VBS services."<<endl;
    }
}
int main()
{
    int dpin=12345,pin,block=2,option;
    char yesno;
    double balance=300.25,deposit,withdraw,number;

    cout<<"Please enter pin :";
    cin>>pin;
    while(pin!=dpin && block>0)
    {
        block--;
        cout<<"Please enter correct pin :";
        cin>>pin;
    }
    if(pin==dpin)
    {
        dots();
        cout<<"-----------Welcome to Capitech Bank---------------"<<endl;
        while(option!=-1)
        {
            dots();
            menu();
            dots();
            cin>>option;
            switch(option)
            {
            case 1:
                balancef(balance);
                break;
            case 2:
                balance+=depositf(deposit);
                cout<<"Balance is now R"<<balance<<endl;
                break;
            case 3:
                balance-=withdrawf(balance,withdraw);
                cout<<"Balance is now R"<<balance<<endl;
                break;
            case 4:
                balance-=sendcashf(balance,withdraw,number);
                cout<<"Balance is now R"<<balance<<endl;
                break;
            case 5:
                dpin=changepin(pin,dpin,block);
                break;
            case 6:
                statement(option);
                break;
            case 7:
                option=-1;
            }
        }
    }
    ending(block);

    return 0;
}
