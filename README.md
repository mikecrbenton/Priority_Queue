# Priority_Queue
CSC 300 Data Structures // C++ program using Selection Sort to maintain a Priority Queue

## Overview:


#### Assignment 1: 
Implement a priority queue that stores integers and gives highest priority to those
integers with the lowest value. The priority queue should be written using a C++ class,
named Priority_Queue, and the queue itself should be implemented as a linked list using
C‐style structs.

The following functions need to be implemented:

* Priority_Queue( void ) : Initialize private variables appropriately
* bool empty( void ) : Test whether queue is empty
* int size( void ) : Return size
* int front( void ) : Access next node
* int back( void ) : Access last node
* void enqueue( int ) : Insert node
* void dequeue( void ) : Remove node

#### Assignment 2:
Alter your priority queue so it maintains priority using a Selection Sort. The highest priority
should be given to nodes with larger values (ordered largest to smallest). Basically, sort your
Priority Queue using a Selection Sorting algorithm each time the enqueue function is called.
The priority queue should be written using a C++ class, named Priority_Queue, and the queue itself 
should be implemented as a linked list using C‐style structs.

The following public functions need to be implemented:

* Priority_Queue( void ) : Initialize private variables appropriately
* bool empty( void ) : Test whether queue is empty
* int size( void ) : Return size
* int front( void ) : Access next node
* int back( void ) : Access last node
* void enqueue( int ) : Insert node
* void dequeue( void ) : Remove node

The following private functions need to be implemented:

* void sort( void ) : Sort linked list using selection sorting algorithm
