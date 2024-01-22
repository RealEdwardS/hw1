/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
    Node* in = nullptr; 

    Node* node1 = new Node(2, nullptr); 
    Node* node2 = new Node(2, nullptr);
    Node* node3 = new Node(3, nullptr); 
    Node* node4 = new Node(2, nullptr); 
    Node* node5 = new Node(2, nullptr); 
    Node* node6 = new Node(2, nullptr); 
    Node* node7 = new Node(2, nullptr); 
    Node* node8 = new Node(2, nullptr); 
    Node* node9 = new Node(2, nullptr); 
    Node* node10 = new Node(10, nullptr); 

    in = node1; 
    node1->next = node2; 
    node2->next = node3; 
    node3->next = node4; 
    node4->next = node5; 
    node5->next = node6; 
    node6->next = node7; 
    node7->next = node8; 
    node8->next = node9; 
    node9->next = node10;

    Node* evens = nullptr; 
    Node* odds = nullptr; 

    split(in, odds, evens);

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete node9;
    delete node10; 

    return 0;


}
