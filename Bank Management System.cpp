#include <iostream>	//Library file for input/output statements like cin and cout.
#include<cctype> //Offers character manipulation functions
#include <iomanip>// Allows formatting output, such as aligning text in tables
#include <cstdlib> //clear the screen
#include <windows.h> //For coloring
#include<vector> // is uesd for handling dymanic arrays
using namespace std;
//***************
//***   Coloring Functions   ****
//***************

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //Syntax used to color the text.
void whitecolor();          //Making White Color Function.
void bluecolor();           //Making Blue Color Function.
void Aquacolor();           //Making Aqua color function.
void greencolor();          //Green color Function.
void redcolor();            //Red Color Function.
void lightAqua();           //Light color function.
void solidred();            //Solid Red color Function.
class Account {
protected:
    int account_number;
    string name;
    double deposit;
    char type;

public:
    Account(int acc_number, const string acc_name, double acc_deposit, char acc_type) :
        account_number(acc_number), name(acc_name), deposit(acc_deposit), type(acc_type) {}

    void program_title();
    virtual void create_account() = 0;
    virtual void show_account() const = 0;
     virtual void modify() = 0;
    virtual void dep(double amount) = 0;
    virtual void draw(double amount) = 0;
    virtual void report() const = 0;
//The Account class is an abstract base class because it contains pure virtual functions. An abstract class cannot be instantiated on its own; it's meant to be a base for derived classes.
//The CreateAccount class provides concrete implementations for the pure virtual functions, making it a concrete class that can be instantiated.
    int retacno() const {
        return account_number;
    }

    double retdeposit() const {
        return deposit;
    }
//The member variables (account_number, deposit, and type) in the Account class are declared as protected, which means they are not directly accessible from outside the class. This encapsulation helps in hiding the internal details of the class and prevents unauthorized access or modification.
    char rettype() const {
        return type;
    }
};

void Account::program_title() {
    cout << "\n\t\t\t##########################################################################";
    cout << "\n\t\t\t######################### Citizen Unity Bank. Inc ########################";
    cout << "\n\t\t\t##########################################################################\n\n";
}

class CreateAccount : public Account {
public:
CreateAccount() : Account(0,"",0, ' ') {}

    void create_account() ;
    void show_account() const ;
    void modify() ;
    void dep(double amount) ;
    void draw(double amount) ;
    void report() const ;
};

void CreateAccount::create_account() {
    program_title();
	bluecolor();
    cout << "\n\t\t\t---------------- Register Your Account ---------------\n\n";
	Aquacolor();
    cout << "\n\t\t\tEnter The account No: ";
    lightAqua();
    cin >> account_number;
    Aquacolor();
    cout << "\t\t\tEnter Account Holder Name : ";
    lightAqua();
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\tEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);
    	Aquacolor();
    while (type != 'C' && type != 'S') {
        cout << "\t\t\tInvalid account type. Please enter 'C' for Current or 'S' for Savings: ";
        cin >> type;
        type = toupper(type);
    }

    cout << "\t\t\tEnter Amount >= 500 for Saving and amount >= 1000 for current : ";
    	lightAqua();
    cin >> deposit;
    while (deposit < 500.0 && type == 'S' || deposit < 1000.0 && type == 'C') {
        cout << "\t\t\tInvalid deposit amount. Please enter a valid amount: ";
        cin >> deposit;
    }
	bluecolor();
    cout << "\n\n\n\t\t\t---------------- User Details ---------------\n\n";
lightAqua();
    cout << "\n\t\t\tUser Account No. : " << account_number;
    cout << "\n\t\t\tAccount Holder Name : " << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
greencolor();
    cout << "\n\n\n\t\t\t\t\t----------------------------------";
    cout << "\n\t\t\t\t\t Account Successfully Created..";
    cout << "\n\t\t\t\t\t----------------------------------";
 
    cin.ignore();
    cin.get();

}

void CreateAccount::show_account() const {
		lightAqua();
				int num;
	 cout << "\n\n\t\t\tEnter The account No. : ";
                cin >> num;
	if(num!=account_number)
	 {
        
        redcolor();
        cout << "\n\n\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t   Account number does not match!";
        cout << "\n\t\t\t\t\t------------------------------";
        return;
    }
    cout << "\n\t\t\tAccount No. : " << account_number;
    cout << "\n\t\t\tAccount Holder Name : " << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
}

void CreateAccount::modify() {
		Aquacolor();
			int num;
	 cout << "\n\n\t\t\tEnter The account No. : ";
                cin >> num;
	if(num!=account_number)
	 {
        
        redcolor();
        cout << "\n\n\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t   Account number does not match!";
        cout << "\n\t\t\t\t\t------------------------------";
        return;
    }
    cout << "\n\t\t\tAccount No. : " << account_number;
    cout << "\n\t\t\tModify Account Holder Name : ";
    lightAqua();
    cin.ignore();
    getline(cin, name);
	Aquacolor();
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    lightAqua();
    type = toupper(type);
	Aquacolor();
    cout << "\n\t\t\tModify Balance amount : ";
    lightAqua();
    cin >> deposit;
     greencolor();
       	cout<<"\n\n\t\t\t\t\t--------------------------------";
			cout<<"\n\t\t\t\t\t Record Updated Successfully!";
			cout<<"\n\t\t\t\t\t--------------------------------";
}


void CreateAccount::dep(double amount) {

			int num;
	 cout << "\n\n\t\t\tEnter The account No. : ";
                cin >> num;
	if(num!=account_number)
	 {
        
        redcolor();
        cout << "\n\n\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t   Account number does not match!";
        cout << "\n\t\t\t\t\t------------------------------";
        return;
    }
	cout<<"\n\t\t\t Enter The Amount You Want To Deposit";
	cin>>amount;
    deposit += amount;
      greencolor();
    	cout<<"\n\n\t\t\t\t\t--------------------------------";
			cout<<"\n\t\t\t\t\t Record Updated Successfully!";
			cout<<"\n\t\t\t\t\t--------------------------------";
}

void CreateAccount::draw(double amount) {
			int num;
	 cout << "\n\n\t\t\tEnter The account No. : ";
                cin >> num;
	if(num!=account_number)
	 {
        
        redcolor();
        cout << "\n\n\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t   Account number does not match!";
        cout << "\n\t\t\t\t\t------------------------------";
        return;
    }
    else if (amount > deposit) {
        	redcolor();
				cout<<"\n\n\t\t\t\t\t------------------------------";
					cout<<"\n\t\t\t\t\t   Insufficience balance!";
					cout<<"\n\t\t\t\t\t------------------------------";
    } else {
        deposit -= amount;
        greencolor();
       	cout<<"\n\n\t\t\t\t\t--------------------------------";
			cout<<"\n\t\t\t\t\t Record Updated Successfully!";
			cout<<"\n\t\t\t\t\t--------------------------------";
    }
}


void CreateAccount::report() const {
	lightAqua();
	if(account_number==0)
	{
		cout<<" ";
	}
	else
    cout << "\t\t\t" << account_number << setw(10) << " " << name << setw(10) << " " << type <<"\t " << setw(6)<< deposit << endl;
}

void intro();
int main() {
    char ch;
    int num;
    vector<CreateAccount*> accounts;  // Using a vector to store multiple account objects CreateAccount* account = NULL;
    intro();

    do {
        system("cls");
        CreateAccount* ac = new CreateAccount();  // Create a new account object for each iteration
        accounts.push_back(ac);  // Store the pointer to the new account object in the vector

        ac->program_title();
        bluecolor();
        cout << "\n\n\t\t\t\t\t----------------- MAIN MENU -----------------";
        lightAqua();
        cout << "\n\n\n\t\t\t\t\t01. NEW ACCOUNT";
        cout << "\n\t\t\t\t\t02. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t\t03. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t\t04. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t\t05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t\t\t\t\t06. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t\t\t07. EXIT";
        Aquacolor();
        cout << "\n\n\t\t\t\t\tSelect Your Option (1-7) ";
        cin >> ch;
        system("cls");

        switch (ch) {
            case '1':
                ac->create_account();
                break;
            case '2':
                ac->program_title();
                ac->dep(num);
                break;
            case '3':
                ac->program_title();
                ac->draw(num);
                break;
            case '4':
                ac->program_title();
                ac->show_account();
                break;
            case '5':
                ac->program_title();
                cout << "\t\t\t====================================================\n";
                cout << "\t\t\tA/c no.      NAME           Type  Balance\n";
                cout << "\t\t\t====================================================\n";
                lightAqua();
                for (CreateAccount* account : accounts) {
                    account->report();
                }
                break;
            case '6':
                ac->program_title();
                ac->modify();
                break;
            case '7':
                ac->program_title();
                greencolor();
                cout << "\n\n\t\t\t\t\tThanks for using the bank management system";
                bluecolor();
                // Deallocate memory before exiting
                for (CreateAccount* account : accounts) {
                    delete account;
                }
                accounts.clear();
                break;
            default:
                cout << "\a";
        }

        cin.ignore();
        cin.get();
    } while (ch != '7');

    return 0;
}
void intro()
{	
Aquacolor();
	cout<<"\n\n\n\n\t\t\t\t########################################################";
	cout<<"\n\t\t\t\t   Final Subject Project  (Object Oriented Programming)";
	cout<<"\n\t\t\t\t########################################################";
	cout<<"\n\n\n\t\t\t\tProject: ";lightAqua();  cout<<"Bank Management Systam: ";
Aquacolor();	cout<<"\n\n\t\t\t\tProject Name:  "; lightAqua(); cout<<"Citizen Unity Bank Inc. \n";
Aquacolor();	cout<<"\n\t\t\t\tCreated By : "; lightAqua();
	cout<<"\n\t\t\t\t\tATTA UL ASAD\n";
	Aquacolor(); cout<<"\n\t\t\t\tLanguage : ";lightAqua(); cout<<"C++(Object Oriented Programming)";
	cin.get();
	  system("cls");
}

//************************
//********  COLORS FUNCTION  *********
//************************

void redcolor()
{
	SetConsoleTextAttribute(color,12);
	                                     //displaying red color on screen syntax.
}
	
void lightAqua()
{
	SetConsoleTextAttribute(color,11);            	                                     //displaying light Aqua color on screen syntax.
}

void solidred()
{
	SetConsoleTextAttribute(color,4);             	                                     //displaying solid red color on screen syntax.
}

void bluecolor()
{
	SetConsoleTextAttribute(color,9);             	                                     //displaying blue color on screen syntax.
}

void Aquacolor()
{
	SetConsoleTextAttribute(color,3);             	                                     //displaying Aqua color on screen syntax.
}

void whitecolor()
{
	SetConsoleTextAttribute(color,8);              	                                     //displaying white color on screen syntax.
}

void greencolor()
{
	SetConsoleTextAttribute(color,10);           	                                     //displaying green  color on screen syntax.
}



//*********************
//    			END OF PROJECT
//*********************




