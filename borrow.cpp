/*  
 * 
 * --------------------------------borrow.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this to stock -1 for each item borrowed
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#include "borrow.h"

// ------------------------------------constructor-------------------------------------------- 
// 
// -------------------------------------------------------------------------------------------
Borrow::Borrow() 
{

}

// ------------------------------------constructor-------------------------------------------- 
//  
// -------------------------------------------------------------------------------------------
Borrow::~Borrow() 
{

}

// ------------------------------------setData------------------------------------------------
// add borrow to the customer history 
// -------------------------------------------------------------------------------------------
bool Borrow::setData(string title, Customer *&c) 
{
  if (title != "" && c != NULL)
  {
    History h;
    h.setMovieType('D');
    h.setTransType('B');
    h.setMovie(title);
    c->addHistory(h);
    return true;
  }
    return false;
}