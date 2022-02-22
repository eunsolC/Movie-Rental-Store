/*
 * 
 * --------------------------------history.h --------------------------------------------
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
 
#ifndef ASSIGNMENT_4_HISTORY_H
#define ASSIGNMENT_4_HISTORY_H

#include <iostream>
using namespace std;

class History {
public:
  History(); // constructor 
  char getMovieType() const; // get movie movie type
  string getMovie() const; // get movie
  char getTransType() const; // get trans type
  void setMovieType(char); // set movie type 
  void setMovie(string); // set movie
  void setTransType(char); // set transaciton type

private:
  char movieType;
  string movie;
  char transType;
};

#endif 