#include "boma.h"

#include<string>
#include<iostream>


using namespace std;

// declaring the type of data structures
struct user_registration {
    /* data */
    string first_name;
    string second_name;
    string email;
    int phone_number;

};

void get_user_info( user_registration person) {

    cout << "ACCOUNT RECORD:" << endl;
    cout << "Name: " << person.first_name <<""<<person.second_name<< endl;
    cout << "Email: " << person.email << endl;
    cout << "Phone_number: " << person.phone_number;
}


void pin_verification(char pass[20],char password[20])
{
     int i=0;
	while( i <3)
    {


	if(strcmp(pass, password)==0)
	     {
		cout<<"SUCCESFULYY LOGGED IN";
		//for now but will define later
        break;
	     }
	else
	   {
		cout<<"INCORRECT PASSWORD PLEASE TRY AGAIN";
       }
            i++;
    }

}


