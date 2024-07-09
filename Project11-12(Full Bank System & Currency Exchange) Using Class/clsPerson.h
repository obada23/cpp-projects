#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
    private:
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;

    public:
        clsPerson(string FirstName, string LastName, string Email, string Phone)
        {
            this->_FirstName = FirstName;
            this->_LastName = LastName;
            this->_Email = Email;
            this->_Phone = Phone;
        }

        void setFirstName(string FirstName)
        {
            this->_FirstName = FirstName;
        }

        string FirstName()
        {
            return this->_FirstName;
        }

        void setLastName(string LastName)
        {
            this->_LastName = LastName;
        } 

        string LastName()
        {
            return this->_LastName;
        }

        void setEmail(string Email)
        {
            this->_Email = Email;
        } 

        string Email()
        {
            return this->_Email;
        }

        void setPhone(string Phone)
        {
            this->_Phone = Phone;
        } 

        string Phone()
        {
            return this->_Phone;
        }

        string FullName()
        {
            return this->_FirstName + " " + this->_LastName;
        }
};