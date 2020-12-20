
#pragma once

#include <iostream>
#include <algorithm>  // std::max

using namespace std;

template<typename TKey,typename TValue>
class binarysearchtree
{
private:
  struct NODE
  {
    TKey  Key;
	TValue Value;
    NODE* Left;
    NODE* Right;
  };

  NODE* Root;  // pointer to root node of tree (nullptr if empty)
  int   Size;  // # of nodes in the tree (0 if empty)
  // _inorder does the actual inorder traversal and output 
  // to console.  Each key is output to the console followed
  // by " ", including the last key.
  void _inorder(NODE* cur)
  {
     if (cur == nullptr)
       return;
     else
     {
        _inorder(cur->Left);
        cout << cur->Key << " ";
		cout<< cur->Value <<" ";
        _inorder(cur->Right);
     }
  }
   void copy_(NODE* cur){
  //if cur isnt null then insert key and value to coopy and 
  //else return
	  if(cur!=nullptr ){
		  insert(cur->Key,cur->Value);
		  copy_(cur->Left);
		  copy_(cur->Right);
		 }
		 else{return;}}  

public:
  
  // Creates an empty tree.
  //
  binarysearchtree()
  {
    Root = nullptr;
    Size = 0;
  }
  //copy contructor 
  binarysearchtree(binarysearchtree& other)
	{
	//newnode is the other tree use recursion to 
	//go thru tree and add data 
	struct NODE* newNode =  new struct NODE();
	Root=NULL;
	newNode=other.Root;
	Size=0;

	copy_(newNode);
	}

  int size()
  {
    return Size;
  }

  // Computes and returns height of tree; height of an empty tree is
  // defined as -1.
	int _height(NODE *cur){
     if (cur==NULL){
        return -1;
        }
      else {
       int leftHeight = _height(cur->Left);
       int  rightHeight = _height(cur->Right);
         if(leftHeight>rightHeight){
            return 1+leftHeight;
            }
            else{
               return 1+rightHeight;
               }
         }
     }
  int height()
  {
   
    return _height(Root);
  }

  // Searches the tree for the given key, returning true if found
  // and false if not.
 TValue*  search(TKey key)
  {
    NODE* cur = Root;

    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
        return&(cur->Value);

      if (key < cur->Key)  // search left:
      {
        cur = cur->Left;
      }
      else
      {
        cur = cur->Right;
      }
    }//while  
  // if get here, not found
    return NULL;
  }
  // Inserts the given key into the tree; if the key has already been insert then
  // the function returns without changing the tree.
  //
  void insert(TKey key,TValue value)
  {
    NODE* prev = nullptr;
    NODE* cur = Root;
    // 1. Search to see if tree already contains key:
    
    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
        return;

      if (key < cur->Key)  // search left:
      {
        prev = cur;
        cur = cur->Left;
      }
      else
      {
        prev = cur;
        cur = cur->Right;
      }
    }//while
    
    // TODO: allocate a new node, store key, initialize
    // pointer fields:
    //
    struct NODE* newNode =  new struct NODE();
     newNode->Key=key;
	 newNode->Value=value;
     newNode->Left=NULL;
     newNode->Right=NULL;
    // 3. link in the new node:
	if(prev==NULL){
	//if prev null add data
       Root=newNode;
       newNode->Right=NULL;
       newNode->Left=NULL;
      Size++;
       }
      else{
	 //prev not null so add data dependig on right or left
         if(newNode->Key < prev->Key){
			prev->Left=newNode;
            Size++;  
             }
            else{
                  prev->Right=newNode;
                  Size++;
             }
         newNode->Right=NULL;
         newNode->Left=NULL;
      }
   
  }
void printRootAddress(){
        cout << "Root Key Address : "<< &Root->Key << endl;
    }
  // Performs an inorder traversal of the tree, outputting
  // the keys to the console.
  void inorder()
  {
     cout << "Inorder: ";
      _inorder(Root);
     cout << endl;
  }
  

};

