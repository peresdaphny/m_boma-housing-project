// m_boma housing project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "boma.h"
#include<mysql.h>
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include "boma.h"

/*
#include<string>
#include<iostream>

*/

//#include "../../../Documents/GitHub/m_boma-housing-project/.vscode/boma.cpp"


using namespace std;

int qstate;
 

int main()
{
    char pass[20];
    char password[20];

      user_registration person;

    cout << "PLEASE ENTER YOUR FIRST NAME?" << endl;
    cin >> person.first_name;
    cout << "PLEASE ENTER YOUR SECOND NAME?" << endl;
    cin >> person.second_name;
    cout << "PLEAE ENTER YOUR EMAIL ?" << endl;
    cin >> person.email;
    cout << "PLEAESE ENTER PHONE NUMBER ?" << endl;
    cin >> person.phone_number;

    cout<<"PLease create new password To proceed"<<endl;
    cin>>pass;
    cout<<"PASSWORD SAVED!"<<endl;

    cout<<"Please input password again to preoceed"<<endl;
    cin>>password;
    
    pin_verification(pass,password);

    get_user_info(person);


   
   
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "Dennis001", "m_boma_project", 3306, NULL, 0);
    
    if (conn)
    { 
        puts("successful connection to database !*");       
      
        if (!qstate)
        {
            
            string query = "INSERT INTO user_info(first_name,second_name,email,phone_number) VALUES ( '" + reg.first_name + "','" + reg.second_name + "','" + reg.email + "','" + reg.phone_number + "')";
            const char* q = query.c_str();
            qstate = mysql_query(conn, q);
            if (qstate != 0)
            {
                cout << mysql_error(conn) << endl;
                return 1;
            }
        }
        else
        {
            cout << "Querry failed: " << mysql_error(conn) << endl;
        }

    }

    else
    {
        puts("connection to database has failed!*");
    }

    return 0;

}








