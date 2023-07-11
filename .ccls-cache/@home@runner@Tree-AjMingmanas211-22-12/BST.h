#include "node.h"
#include <iostream>
#include <iomanip>
using namespace std;

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 0);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr,int);
};

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
    /*First Node*/
    if (!rootPtr) {// if(size==0)
      //if its a root node, let new node = root node
      rootPtr=new_node; 
    }
    else{
      t=rootPtr;
      while(inserted==0){
        if(value <= t->get_value()){
          //left side
          if(t->move_left()!=NULL){
            t=t->move_left();
          }
          else{
            t->set_left(new_node);
            inserted++;
          }
        }else{
          //right side
          if(t->move_right()!=NULL){
            t=t->move_right();
          }
          else{
            t->set_right(new_node);
            inserted++;
          }
        }
      }
    }
    ++size;
  }
}
BST::BST() {
  rootPtr=NULL;
  
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    kill(rootPtr);
}

void BST::inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function
void BST::printTree(TreeNodePtr treePtr,int l) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    printTree(treePtr->move_right(),l+1);
    cout<< setw(3) << treePtr->get_value()<<endl;

    printTree(treePtr->move_left(),l+1);
  }                                 // end if
} // end function


void BST::postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout<< setw(3)<< treePtr->get_value();
  }                                          // end if
} // end function

void BST::kill(TreeNodePtr treePtr) {
  // TreeNodePtr 
    if(treePtr){
      kill(treePtr->move_left());
      kill(treePtr->move_right());
      delete treePtr; //delete everything
      
    }                                        // end if
} // end function
void BST::preOrder(TreeNodePtr treePtr) {
  if(treePtr){
  // TreeNodePtr treePtr=rootPtr;
    cout<< setw(3)<< treePtr->get_value();
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }                                          // end if
} // end function


void BST::print_all(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  default:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr,0);
    cout << endl;
  }
}