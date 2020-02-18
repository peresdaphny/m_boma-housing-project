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
