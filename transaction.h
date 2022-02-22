/*  
 * 
 * --------------------------------transaction.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * ----------------------------------------------------------------------------------------
 * The purpose of this class to store customer and to print 
 * ----------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#ifndef ASSIGNMENT_4_TRANSACTION_H
#define ASSIGNMENT_4_TRANSACTION_H

#include <iostream>
#include "customer.h"
using namespace std;


class Transaction {

public:
  Transaction(); // constructor
  ~Transaction(); // destructor
  char getTransactionType() const; // getter transaction type
  void setTransactionType(char type); // setter transaction type
  char getMovieType() const; // getter movie type
  void setMovieType(char type); // setter movie type
  virtual bool setData(string, Customer *&); // boolean for set data
   
private:
  char transactionType; 
  char movieType;
};

#endif 