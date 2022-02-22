/*
 * 
 * --------------------------------history.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is to get and set transaciton and their movie type.  
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#include "history.h"
#include <iostream>
using namespace std;

// ------------------------------------constructor------------------------------------------------
// returns media type
// -------------------------------------------------------------------------------------------
History::History() 
{
  
}


// ------------------------------------getMovieType------------------------------------------------
// return movie type type
// -------------------------------------------------------------------------------------------
char History::getMovieType() const 
{
  return movieType;
}

// ------------------------------------getMovie------------------------------------------------
// return movie
// -------------------------------------------------------------------------------------------
string History::getMovie() const 
{
  return movie;
}

// ------------------------------------getTransType------------------------------------------------
// return to transaciton type
// -------------------------------------------------------------------------------------------
char History::getTransType() const 
{
  return transType;
}

// ------------------------------------setMediaType------------------------------------------------
// changes media type
// -------------------------------------------------------------------------------------------
void History::setMovieType(char type)  
{
  movieType = type;
}

// ------------------------------------setMovie------------------------------------------------
// changes movie
// -------------------------------------------------------------------------------------------
void History::setMovie(string type)  
{
  movie = type;
}

// ------------------------------------setTransType------------------------------------------------
// changes transaction type
// -------------------------------------------------------------------------------------------
void History::setTransType(char type) 
{
  transType = type;
}