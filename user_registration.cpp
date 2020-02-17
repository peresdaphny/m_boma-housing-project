// m_boma housing project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "stdafx.h"
#include<mysql.h>
#include <iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>

using namespace std;
int qstate;
 

int main()
{
   
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "Dennis001", "m_boma_project", 3306, NULL, 0);
    
    if (conn)
    { 
        puts("successful connection to database !*");
        string first_name, second_name, email, phone_number;
       
        cout << "PLEASE ENTER YOUR FIRST NAME?" << endl;
        cin >> first_name;
        cout << "PLEASE ENTER YOUR SECOND NAME?" << endl;
        cin >> second_name;
        cout << "PLEAE ENTER YOUR EMAIL ?" << endl;
        cin >> email;
        cout << "pLEAESE ENTER PHONE NUMBER ?" << endl;
        cin >> phone_number;

      
        if (!qstate)
        {
            
            string query = "INSERT INTO user_info(first_name,second_name,email,phone_number) VALUES ( '" + first_name + "','" + second_name + "','" + email + "','" + phone_number + "')";
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








