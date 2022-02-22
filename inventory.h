/*
 * 
 * --------------------------------inventory.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is to read file from input and create BSTree to set the movie information 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#ifndef ASSIGNMENT_4_INVENTORY_H
#define ASSIGNMENT_4_INVENTORY_H
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "bstree.h"


class Inventory {
public:

  static bool Create(istream &stream, Movie*&); // read input file 
  Inventory();
  virtual  ~Inventory();
  void readMovieFile(string name);              // read movie file 
  void printAllMovies() const;                  // print BSTree with all movie types in
  
  const BSTree<Comedy> &getComedyTree() const;  // store comedy
  const BSTree<Drama> &getDramaTree() const;    // store drama
  const BSTree<Classic> &getClassicTree() const;// store classic 

private:

  static Comedy* CreateComedy(istream &stream);
  static Drama* CreateDrama(istream &stream);
  static Classic* CreateClassic(istream &stream);
  // BSTrees depend on their type 
  BSTree<Comedy> ComedyTree;
  BSTree<Drama> DramaTree;
  BSTree<Classic> ClassicTree;
  BSTree<Movie> allMovies;

};

#endif