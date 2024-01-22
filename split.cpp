/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


// WRITE YOUR CODE HERE
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */

  // If original list is empty
  if (in == nullptr){
    return;
  }

  // If value is even
  if ((in->value % 2) == 0){
    // If evens list is empty / first pointer is nullptr
    if (evens == nullptr){
      // Assign evens node to current node from "in" list
      evens = in; 

      // Assign current "in" pointer to the next value in the "in" list
      in = in->next; 

      // Assign the next value of the current node to nullptr
      evens->next = nullptr;

      // Call split
      split(in, odds, evens); 
    }


    // If evens list is not empty / first pointer is not nullptr 
    else if (evens != nullptr){
      // Assign next value of the current node of evens to the current "in" node 
      evens->next = in;

      // Assign current "in" pointer ot the next value in the "in" list 
      in = in->next;

      // Assign the next value of the current node to nullptr
      evens->next->next = nullptr;

      // Call split on the next node - 
      // this makes sure we aren't repeatedly calling on the first node over and over again
      split(in, odds, evens->next); 
    }
  }

  // If the value is odd 
  else if ((in->value % 2) != 0){
    // If odds list is empty / first pointer is nullptr
    if (odds == nullptr){
      // Assign odds node to current node from "in" list
      odds = in;

      // Assign current "in" pointer to the next value in the "in" list
      in = in->next;

      // Assign the next value of the current node to nullptr
      odds->next = nullptr;

      // Call split
      split(in, odds, evens); 
    }

    // If odds list is not empty / first pointer is not nullptr 
    else if (odds != nullptr){
      // Assign next value of the current node of odds to the current "in" node 
      odds->next = in;

      // Assign current "in" pointer ot the next value in the "in" list 
      in = in->next;

      // Assign the next value of the current node to nullptr
      odds->next->next = nullptr;

      // Call split on the next node - 
      // this makes sure we aren't repeatedly calling on the first node over and over again
      split(in, odds->next, evens); 
    }
  }
  
}

/* If you needed a helper function, write it here */