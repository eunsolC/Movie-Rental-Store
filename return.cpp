/*
 * 
 * --------------------------------return.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is to return transaction history to related customer record
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#include "return.h"

// ------------------------------------constructor---------------------------------------------
// constructor
// -------------------------------------------------------------------------------------------
Return::Return() 
{

}


// ------------------------------------destructor---------------------------------------------
// destructor
// -------------------------------------------------------------------------------------------
Return::~Return() 
{

}

// ------------------------------------setData------------------------------------------------
// return transaction history to related customer record
// -------------------------------------------------------------------------------------------
bool Return::setData(string title, Customer *&cust) 
{
  if (title != "" && cust != NULL)
  {
    History h;
    h.setMovieType(getMovieType());
    h.setTransType('R');
    h.setMovie(title);
    cust->addHistory(h);
    return true;
  }
  return false;
}

