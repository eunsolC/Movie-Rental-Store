/*  
 * 
 * --------------------------------customer.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class to store customer and to print 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about
 this issue. 
 * -------------------------------------------------------------------------------------
 */

#include <sstream>
#include "customer.h"
#include <fstream>

// ------------------------------------constructor------------------------------------------------
// constructor 
// -------------------------------------------------------------------------------------------
Customer::Customer() 
{
  customerID = 0;
  firstName = "";
  lastName = "";
}

// ------------------------------------parametarized constructor-----------------------------------
// parametarized constructor 
// -------------------------------------------------------------------------------------------
Customer::Customer(int id, string firstname, string lastname) 
{
  this->customerID = id;
  this->firstName = firstname;
  this->lastName = lastname;
}

// ------------------------------------destructor------------------------------------------------
// destructor 
// -------------------------------------------------------------------------------------------
Customer::~Customer() {}

// ------------------------------------getCustomerID------------------------------------------------
// getter for customerID
// -------------------------------------------------------------------------------------------
int Customer::getCustomerID() const
{
  return this->customerID;
}

// ------------------------------------getFirstname------------------------------------------------
// getter for firstName
// -------------------------------------------------------------------------------------------
string Customer::getFirstName() const
{
  return this->firstName;
}

// ------------------------------------getLastname------------------------------------------------
// getter for lastName 
// -------------------------------------------------------------------------------------------
string Customer::getLastName() const
{
  return this->lastName;
}

// ------------------------------------operator = ------------------------------------------------
// overloading oprator for = 
// -------------------------------------------------------------------------------------------
Customer& Customer::operator=(const Customer &customer) 
{
  customerID = customer.getCustomerID();
  lastName = customer.getLastName();
  firstName = customer.getFirstName();
  return *this;
}

// ------------------------------------operator << ------------------------------------------------
// overloading oprator for <<
// -------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Customer& c)
{
  cout << endl;
  out << c.getCustomerID() << " " << c.getFirstName() << " " << c.getLastName() << endl;
  if (!c.history.empty())
  {
    out << "Transaction type   Movie type    Movie" << endl;
    for (int i = c.history.size() - 1; i >= 0; i--)
    {
      out << c.history.at(i).getTransType() << "                  " << c.history.at(i).getMovieType() << "             " << c.history.at(i).getMovie() << endl;
    }
  }
  return out;
}

// ------------------------------------ addHistory ------------------------------------------------
// adds history to the record
// -------------------------------------------------------------------------------------------
void Customer::addHistory(History h) 
{
  history.push_back(h);
}
