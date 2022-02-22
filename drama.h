/*  
 * 
 * --------------------------------drama.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate drama type of movies 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#ifndef ASSIGNMENT_4_DRAMA_H
#define ASSIGNMENT_4_DRAMA_H
#include "movie.h"
class Drama : public Movie {
public:

  Drama(); // constructor 
  virtual ~Drama(); // destructor
  bool isEqual(const Drama &mov) const; //whether two classic movies is equal to each other or not 
  bool isGreater(const Drama &mov) const; //whether two classic movies is greater to the other one 
  virtual MovieType getMovieType() const; //get movie type
  void print() const; // print movie information 
 
  // Compare operators 
  bool operator==(const Drama &rhs)const;
  bool operator!=(const Drama &rh)const;
  bool operator<(const Drama &rh) const;
  bool operator>(const Drama &rh) const;
};

#endif 