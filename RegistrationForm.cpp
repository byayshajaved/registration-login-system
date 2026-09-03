#include <iostream>
#include <fstream>
using namespace std;

class temp{
	string Username, Email, Password;
	string searchName, searchPass, searchEmail; //for login/forgot password search
	fstream file; //file object for reading/writing loginData.txt
	
	public:
		void login();
		void signUp();
		void forgot();
};

int main()
{
	temp obj;
	char choice;
	
	do
	{
		cout << "\n==========================" << endl;
		cout << "     REGISTRATION SYSTEM    " << endl;
		cout << "==========================" << endl;
		cout << "1. login" << endl;
	    cout << "2. Sign-Up" << endl;
	    cout << "3. Forgot Password"  << endl;
	    cout << "4. Exit" << endl;
    	cout << "Enter your choice: " << endl;
	    cin >> choice;
	
    	switch (choice)
    	{
    		case '1':
	    		obj.login();	
		        break;
    		case '2':
	    		obj.signUp();
	        	break;
	    	case '3':
	    		obj.forgot();
	        	break;
	    	case '4':
	    		cout << "\nExisting Program. GoodBye!" << endl;
			    break;
	    	default:
		    	cout << "\nInvalid Selection... Please try again!" <<endl;
   	   }
	}while (choice != '4');
	
	return 0;
}

void temp :: signUp ()
{
	cout << "\nEnter username: ";
	cin >> Username;
	
	//Duplicate username check
	file.open("loginData.txt", ios::in);
	if (file)
	{
		string checkUser, checkEmail, checkPass;
		bool userExists = false;
		while (getline(file, checkUser, '|') &&
		       getline(file, checkEmail, '|') &&
			   getline(file, checkPass, '\n'))
		{
			if(checkUser == Username)
			{
				userExists = true;
				break;
			}
		}
		file.close();
		
		if(userExists)
		{
			cout << "\nError:Username already exists! Please choose a different username." << endl;
			return;
		}
	}
	cout << "\nEnter email: ";
	cin >> Email ;
	cout << "\nEnter password: ";
	cin >> Password;	
	
	file.open("loginData.txt", ios :: out | ios :: app);
	file << Username << "|"<< Email << "|" << Password << endl;
	file.close();
	cout << "\nAccount Created Successfully...!"; 
}

void temp :: login()
{
	cout << "\n---------Login---------";
	cout << "\nEnter your username: ";
	cin>>  searchName;
	cout << "\nEnter your password: ";
	cin >> searchPass;
	
	file.open("loginData.txt", ios :: in);
	if(!file)
	{
		cout << "\nNo account data found!";
		return;
	}
	bool userFound = false;
	
	while(getline(file,Username,'|')&&
	getline(file,Email,'|')&&
	getline(file,Password,'\n'))
	{
	 if(Username == searchName) 
	 {
	 	userFound = true;
	 	if (Password == searchPass)
		{
	 	cout <<"\nLogin Successful...!";
	 	cout <<"\nUsername: " << Username;
	 	cout <<"\nEmail: " << Email;
	    }
	    else{
	 	cout << "\nPassword is incorrect...!" << endl;
	    }
	    break;
	 }
    }
    if(!userFound)
    {
    	cout << "\nUsername not found!" << endl;
	}
	 	file.close();
}
	
void temp :: forgot()
{
	cout << "\nEnter your Username: ";
	cin >> searchName;
	cout << "\nEnter your Email: ";
	cin >> searchEmail;
	
	file.open("loginData.txt", ios :: in);
	if(!file)
	{
		cout << "\nNo account data found!";
		return;
	}
	
	bool found = false;
	
	while(getline(file,Username,'|')&&
	getline(file,Email,'|')&&
	getline(file,Password,'\n'))
	{
		if(Username == searchName && Email == searchEmail)
		{
			cout << "\nAccount Found...!";
			cout << "\nYour Password: " << Password << endl;
			found = true;
			break;
		}
    }
	if(!found)
	{
		cout << "\nAccount not found...!";
    }
    
	file.close();
}









