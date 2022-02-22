/*  
 * 
 * --------------------------------comedy.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate comedy type of movies 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#ifndef ASSIGNMENT_4_COMEDY_H
#define ASSIGNMENT_4_COMEDY_H
#include "movie.h"

class Comedy : public Movie 
{
  friend ostream &operator<<(ostream &outStream, const Comedy &rhs);

public:
  Comedy(); // constructor 
  Comedy(const Comedy &rhs); // copy constructor
  virtual ~Comedy(); // destructor
  void print() const; // print function for print the comedy movies
  bool isEqual(const Comedy &comedy) const; // compare two movies if they are equal
  bool isGreater(const Comedy &comedy) const; // compare two movies if one is greater 
  virtual MovieType getMovieType() const; // return movie type
  bool setData(istream&); // read file for comedy movies

  //--------------------Operator Overloading-----------------------------------
  bool operator==(const Comedy &rhs)const;
  bool operator!=(const Comedy &rhs)const;
  bool operator<(const Comedy &rhs) const;
  bool operator>(const Comedy &rhs) const;
};

#endif 