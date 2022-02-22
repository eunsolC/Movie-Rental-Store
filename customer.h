/*  
 * 
 * --------------------------------cusotmer.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class to store customer and to print 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#ifndef ASSIGNMENT_4_CUSTOMER_H
#define ASSIGNMENT_4_CUSTOMER_H


#include <iostream>
#include <vector>

using namespace std;

#include "history.h"

class Customer
{
public:
  Customer(); // constructor
  Customer(int id, string firstname, string lastname); // copy constructor
  ~Customer(); // destructor 
  int getCustomerID() const; // getter for customerID
  string getFirstName() const; // getter for fistname
  string getLastName() const; // getter for lastname
  void addHistory(History h); // add history transaction to history 
  friend ostream& operator<<(ostream& out, const Customer& rha);  //overloading assignment operator
  Customer& operator=(const Customer& ); //overloading assignment operator
private:
  int customerID; 
  string lastName;
  string firstName;
  std::vector<History> history; //vector for stores user's transaction records
};

#endif 
