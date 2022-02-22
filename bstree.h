/*  
 * 
 * --------------------------------bstree.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate correct order by name, year or director 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#include <stdio.h>

template <class item_type> class BSTree
{
public :
  // ------------------------------------constructor-------------------------------------------- 
  //  create an BSTree 
  // -------------------------------------------------------------------------------------------
  BSTree()
  {
    root = NULL;
    size = 0;
  }

  // ------------------------------------BSTree destructor--------------------------------------
  // make BSTree empty 
  // -------------------------------------------------------------------------------------------
  ~BSTree()
  {
    makeEmpty();
  }

  // ------------------------------------isEmpty------------------------------------------------
  // boolean type for checking of BSTree is empty or not 
  // -------------------------------------------------------------------------------------------
  bool isEmpty() const
  {
    return (root == NULL);
  }

  // ------------------------------------makeEmpty----------------------------------------------
  // call function named makeEmptyHelper to delete all the nodes 
  // -------------------------------------------------------------------------------------------
  void makeEmpty()
  {
    makeEmptyHelper(root);
  }

  // ------------------------------------insert-------------------------------------------------
  // insert the new data to the node 
  // -------------------------------------------------------------------------------------------
  bool insert(item_type* ptr)
  {
    // create a new node 
    Node *insertNode = new Node;
    if (ptr != NULL)
    {
      // insert data to pointer 
      insertNode->data = ptr;
    }
    insertNode->left = NULL;
    insertNode->right = NULL;

    if(root == NULL)
    {
      root= insertNode;
      size++;
    }
    else
    {
      // track for position 
      Node *currentPtr = root; 
      bool inserted = false;

      while(!inserted)
      {
        if(insertNode->data->isEqual(*currentPtr->data)) // for duplicate case 
        {
          delete insertNode;
          insertNode = NULL;
          return false;
        }
        else if (currentPtr->data->isGreater(*insertNode->data)) // data is less than current data, insert to the left
        {
          if(currentPtr->left == NULL) // insert left
          {
            currentPtr->left = insertNode;
            inserted = true;
            size++;
          }
          else
          {
            currentPtr = currentPtr->left; // move current to one step left
          }

        }
        else 
        {
          if (currentPtr->right == NULL) // insert to the right 
          {
            currentPtr->right = insertNode;
            inserted = true;
            size++;
          }
          else
          {
            currentPtr = currentPtr->right;
          }
        }
      }
    }
    return true;
  }
  // ------------------------------------retrieve-----------------------------------------------
  // search for data in the bst. Returns boolean
  // -------------------------------------------------------------------------------------------
  bool retrieve(const item_type &dataItem, item_type* & found) const
  {
    retrieveHelper(root, dataItem, found); // calling retrieveHelper funtion 
    if (found != NULL) // check for if data is changed
    {
      return true;
    }
    else
    {
      return false; //If found was not found 
    }
  }
  // ------------------------------------remove-------------------------------------------------
  // remove the item from tree
  // -------------------------------------------------------------------------------------------
  bool remove(const item_type &dataItem)
  {
    return false;
  }
  // -----------------------------------print --------------------------------------------------
  // calling helper funtion to print the BSTree 
  // -------------------------------------------------------------------------------------------
  void print() const
  {
    printHelper(root);
  }

private:
  struct Node
  {
    // set the node 
    Node()
    {
      data =NULL;
      left = NULL;
      right = NULL;
    }
    item_type* data; // pointer to data object
    Node* left; // left subtree pointer
    Node* right; // right subtree pointer
  };
  Node* root;	// root of the tree
  int size;

  // ------------------------------------makeEmptyHelper ---------------------------------------
  // helper funtion for make empty in BSTree 
  // -------------------------------------------------------------------------------------------
  void makeEmptyHelper(Node *& treePtr)
  {
    // postorder traversal
    if (treePtr != NULL)
    {
      makeEmptyHelper(treePtr->left);
      makeEmptyHelper(treePtr->right);

      delete treePtr->data;
      treePtr->data= NULL;

      delete treePtr;
      treePtr = NULL;

    }
  }

  // ------------------------------------isEqual------------------------------------------------
  // check for compare if left pointer and right pointer are equal 
  // -------------------------------------------------------------------------------------------
  bool isEqual(Node *leftPtr, Node *rightPtr) const
  {
    // check for equal 
    if ((leftPtr != NULL && rightPtr != NULL) && (leftPtr->data->isEqual(*rightPtr->data)))
    {
      return true;
    }
    // reach to the end 
    if ((leftPtr == NULL) || (rightPtr == NULL))
    {
      return false;
    }
    return isEqual(leftPtr->left,  rightPtr->left ) && isEqual (leftPtr->right, rightPtr->right);
  }

  // ------------------------------------retrieveHelper------------------------------------------
  // helper method to retrieve the node in tree 
  // -------------------------------------------------------------------------------------------
  void retrieveHelper(Node *current , const item_type &item, item_type *&found) const
  {
    if (current == NULL) 
    found = NULL;

    else if (item.isEqual(*current->data)) // item found 
    {
      found = current->data;
    }
    else if(current->data->isGreater(item)) // check for data left 
    {
      retrieveHelper(current->left, item, found);
    }
    else // check for data right 
    {
      retrieveHelper(current->right, item, found);
    }
  }
  // ------------------------------------print-------------------------------------------------
  // helper method to print out the tree
  // -------------------------------------------------------------------------------------------
  void printHelper(Node *current) const
  {
    if (current == NULL) // if current pointer is null 
    {
      return;
    }
    printHelper(current->left);
    current->data->print();
    printHelper(current->right);
  }
};