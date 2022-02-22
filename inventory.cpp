/*
 * 
 * --------------------------------inventory.cpp --------------------------------------------
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

#include "inventory.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
using  namespace std;

// ------------------------------------constructor------------------------------------------------
// constructor
// -------------------------------------------------------------------------------------------
Inventory::Inventory()
{

}
// -------------------------------------destructor-----------------------------------------------
// destructor
// -------------------------------------------------------------------------------------------
Inventory::~Inventory()
{

}


// ------------------------------------readMovieFile-----------------------------------------
// read from input file and create BSTree
// ------------------------------------------------------------------------------------------
void Inventory::readMovieFile(string name) 
{
  fstream infile(name, ios_base::in);

  if (infile.fail())
  {
    cout << "Can't find movie file: " << endl; // print error message 
    return;
  }

  while(!infile.eof())
  {
    Movie* movie;
    if (!Inventory::Create(infile, movie))
    continue;

    if (movie)
    {
      switch (movie->getMovieType())
      {
        case MovieType ::ComedyType:
          ComedyTree.insert(dynamic_cast<Comedy *>(movie));  // add to the BSTree
          break;
        case MovieType::DramaType:
          DramaTree.insert(dynamic_cast<Drama *>(movie));   // add to the BSTree
          //DramaTree.print();
          break;
        case MovieType::ClassicType:
          ClassicTree.insert(dynamic_cast<Classic *>(movie));  // add to the BSTree
          //ClassicsTree.print();
          break;
          
        default:
          throw new logic_error("Unexpected type");

      }
    }
  }
}

// ------------------------------------create-------------------------------------------------
// After read file and create movie information 
// -------------------------------------------------------------------------------------------
bool Inventory::Create(istream &stream, Movie*& movie) 
{
  char movieType;
  int movieStock;
  string movieDirector;
  string movieTitle;

  stream >> movieType;
  if (stream.fail())
  {
    return false;
  }
  stream.ignore();
  stream >> movieStock;
  stream.ignore();
  getline(stream >> ws, movieDirector, ',');
  stream.ignore();
  getline(stream >> ws, movieTitle, ',');

  switch (movieType)
  {
    case 'F':
      movie = CreateComedy(stream);
      break;
    case 'C':
      movie = CreateClassic(stream);
      break;
    case 'D':
      movie = CreateDrama(stream);
      break;
    case 'Z':
      stream.ignore();
    default:
      cout << "Invalid movie type: " << movieType << endl;
      stream.ignore(512, '\n');
      return false;
      break;
    }

  movie->setDirector(movieDirector);
  movie->setTitle(movieTitle);
  movie->setStock(movieStock);

  return true;
}

// ------------------------------------Create Comedy-------------------------------------------
// helper method to create comedy movie
// -------------------------------------------------------------------------------------------
Comedy* Inventory::CreateComedy(istream &stream)
{
  int movieYear;
  stream >> movieYear;
  Comedy *comedy = new Comedy();
  comedy->setYear(movieYear);

  return comedy;
}

// ------------------------------------Create Drama-------------------------------------------
// helper method to create drama movie
// -------------------------------------------------------------------------------------------
Drama * Inventory::CreateDrama(istream &stream)
{
  int movieYear;
  stream >> movieYear;
  Drama *drama = new Drama();
  drama-> setYear(movieYear);

  return drama;
}

// ------------------------------------CreateClassics -------------------------------------------
// helper method to create classics  movie
// -------------------------------------------------------------------------------------------
Classic* Inventory::CreateClassic(istream &stream)
{
  int movieMonth;
  int movieYear;
  string movieMajorActorName;
  string movieMajorActorLastname;

  stream >> movieMajorActorName;
  stream >> movieMajorActorLastname;
  stream >> movieMonth;
  stream >> movieYear;

  Classic *classic = new Classic();

  classic->setMajorActor(movieMajorActorName + " " + movieMajorActorLastname);
  classic->setReleaseMonth(movieMonth);
  classic->setYear(movieYear);

  return classic;
}

// -------------------------------------getComedyTree()--------------------------------------
// returns the three that holds comedy movies
// ------------------------------------------------------------------------------------------

const BSTree<Comedy> & Inventory::getComedyTree() const
{
  return ComedyTree;
}

// -------------------------------------getDramaTree()---------------------------------------
// returns the three that holds drama movies
// ------------------------------------------------------------------------------------------
const BSTree<Drama> & Inventory::getDramaTree() const
{
  return DramaTree;
}

// -------------------------------------getClassicsTree()------------------------------------
// returns the three that holds classics movies
// ------------------------------------------------------------------------------------------
const BSTree<Classic> & Inventory::getClassicTree() const
{
  return ClassicTree;
}

// -------------------------------------printAllMovies------------------------------------
// print all movie type 
// ------------------------------------------------------------------------------------------
void Inventory::printAllMovies() const
{
  getComedyTree().print();
  getDramaTree().print();
  getClassicTree().print();
}