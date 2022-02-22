 /*
 * 
 * --------------------------------factory.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate read file, change stock, and display. 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#ifndef ASSIGNMENT_4_FACTORY_H
#define ASSIGNMENT_4_FACTORY_H
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "hashTable.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
using namespace std;
class Factory
{

public:
  Factory(); // constructor 
  ~Factory(); // destructor
  bool readCustomer(string file); // read customer file 
  bool readTransaction(string file); // read transaction file 
  bool processTransaction(istream&);
  void displayCList() const;
  bool readMovie(string file);
  void displayTHistory() const;
  void displayMList() const;

private:
  HashTable customer;
  Inventory movieInv;
  vector <string> transactionHistory;

  bool changeStock(int numOfStock, char type, istream& movie, string& mTitle); //change the number of stock for specific movie
};
#endif