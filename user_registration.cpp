// m_boma housing project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "stdafx.h"
#include<mysql.h>
#include <iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
using namespace std;

// declaring the type of data structures
struct user_registration {
    /* data */
    string first_name;
    string second_name;
    string email;
    int phone_number;

};


int qstate;
 

int main()
{
   struct user_registration reg;

       cout << "PLEASE ENTER YOUR FIRST NAME?" << endl;
        cin >> reg.first_name;
        cout << "PLEASE ENTER YOUR SECOND NAME?" << endl;
        cin >> reg.second_name;
        cout << "PLEAE ENTER YOUR EMAIL ?" << endl;
        cin >> reg.email;
        cout << "PLEAESE ENTER PHONE NUMBER ?" << endl;
        cin >> reg.phone_number;
   
   
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








