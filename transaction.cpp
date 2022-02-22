/*  
 * 
 * --------------------------------transaction.cpp ---------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * ----------------------------------------------------------------------------------------
 * The purpose of this class to get and set transaction type 
 * ----------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#include "transaction.h"

// ------------------------------------constructor------------------------------------------------
// constructor 
// -------------------------------------------------------------------------------------------
Transaction::Transaction() 
{

}


// ------------------------------------destructor------------------------------------------------
// destructor 
// -------------------------------------------------------------------------------------------
Transaction::~Transaction() 
{

}

// ------------------------------------getTransactionType------------------------------------------------
// returns transaction type
// -------------------------------------------------------------------------------------------
char Transaction::getTransactionType() const 
{
  return transactionType;
}

// ------------------------------------setTransactionType------------------------------------------------
// change transction type
// -------------------------------------------------------------------------------------------
void Transaction::setTransactionType(char type) 
{
  transactionType = type;
}

// ------------------------------------getMovieType------------------------------------------------
// returns movie type
// -------------------------------------------------------------------------------------------
char Transaction::getMovieType() const 
{
  return movieType;
}

// ------------------------------------setMovieType------------------------------------------------
// change movie type
// -------------------------------------------------------------------------------------------
void Transaction::setMovieType(char type) 
{
  movieType = type;
}

// ------------------------------------setData------------------------------------------------
// virtual function to add transacion history to costomer record
// -------------------------------------------------------------------------------------------
bool Transaction::setData(string, Customer *&ct) 
{
  return false;
}
