/*
 * 
 * --------------------------------store.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is for drive file. 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#include <iostream>
#include "hashTable.h"
#include "customer.h"
#include "factory.h"
#include "history.h"
#include "inventory.h"
#include <stdexcept>

#include <cassert>
using namespace std;

// ------------------------------------Case 1-----------------------------
//  Testing  Hash Table
// -----------------------------------------------------------------------

void Case1()
{
  cout << "------------------------- Case 1 ------------------------" << endl;
  HashTable ht;
  Customer c1(1010, "A", "Apple");
  Customer c3(9336, "B", "Banana");
  Customer c4(8933, "C", "Cat");
  Customer c5(9467, "D", "Dog");
  Customer c6(3287, "E", "Egg");
  Customer c7(7865, "F", "Fox");
  Customer c8(1839, "G", "Green");
  Customer c9(2346, "H", "Hat");
  Customer c10(6543, "I", "Ice");
  Customer c11(4523, "J", "Joker");
  ht.insert(c1);
  ht.insert(c3);
  ht.insert(c4);
  ht.insert(c5);
  ht.insert(c6);
  ht.display();
  ht.insert(c7);
  ht.insert(c8);
  ht.insert(c9);
  ht.insert(c10);
  ht.insert(c11);
  Customer* c2;
  ht.display();
  ht.get(1010, c2);
  cout << "\n---------------------------------------------------------" << endl;
}

// ------------------------------------Case 2--------------------------------
//  Testing  Hash Table using customer data
// --------------------------------------------------------------------------

void Case2()
{
  cout << "------------------------- Case 2 ------------------------" << endl;

  HashTable ht;
  ifstream inFile("data4customers.txt");

  if (inFile.is_open())
  {
    while (!inFile.eof())
    {
       ht.setData(inFile);
    }
  }
  else {
    cout << "ERROR! Fail to open file!" << endl;
  }
    ht.display();
    cout << "\n---------------------------------------------------------" << endl;

}
/*

// ------------------------------------Case 3--------------------------------
//  Testing Inventory class which stores movies
// ---------------------------------------------------------------------------
void Case3()
{
  cout << ""------------------------- Case 3 ------------------------"" << endl;
  Inventory inv;
  inv.readMovieFile("data4movies.txt");
  inv.printAllMovies();
  cout << "\n---------------------------------------------------------" << endl;
}

*/


// ------------------------------------Case 4-------------------------------
//  Testing the entire system inc. Customer, Movie, and Transaction
// -------------------------------------------------------------------------
void Case4()
{
  cout << "------------------------- Case 4 ------------------------" << endl;

  Factory fac;
  fac.readCustomer("data4customers.txt");
  fac.readMovie("data4movies.txt");
  fac.readTransaction("data4commands.txt");
  //fac.displayMList(); //duplicate with test3 for movie list section 
  fac.displayTHistory(); // duplicate with test3 for movie list section 
  fac.displayCList();
  cout << "\n---------------------------------------------------------" << endl;

}

int main() {

  Case1();
  Case2();
  //Case3(); // case 3 can be tested from case 4
  Case4();
  cout << endl << "Passed All Test Cases! " << endl;
  return 0;

}

