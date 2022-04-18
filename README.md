# Linked List 

# Background 
By definition, linked list is a linear collection of elements of a specific type whose order is not given by their physical placement in memory. 
Instead, each element has a next pointer, pointing to the next element in the sequence. An application of a linked list could be a music library app where 
the songs resulted from user input could be stored in a linked list that is sorted alphabetically or based on the year it was produced. 

# Overview 

I have implemented this linked list in C Programming Language using structs and pointers. The logic behind it is that there is a struct containing the head and a node struct that stores 2 things, data and a next pointer which is pointing to the next element in the sequence. 

```C
typedef struct NODE {int data; struct NODE* next;} NODE; // nodes of the linked list
typedef struct LINKED_LIST {struct NODE *head;} LINKED_LIST; // struct to act as the head of the list
```

# Methods 
  This Linked list has the following methods. 
  ```C
  1) int Size(LINKED_LIST list) //Returns an integer that represents the number of elements in the linked list
  2) void Push_Front(LINKED_LIST *list, int data)  //This function adds an element to the front of the list
  3) void Push_Back(LINKED_LIST *list, int data) //this function adds an element to the end of the linked list 
  4) int Pop_Front(LINKED_LIST *list, int *data) // returns 0 if the list is empty otherwise returns 1
  5) int Pop_Back(LINKED_LIST *list, int *data)  //returns 0 if the list is empty otherwise returns 1
  6) int Count_If(LINKED_LIST list, int data) // returns the number of times that the value of the parameter data appears in the list
  7) int Delete(LINKED_LIST *list, int data) //return 1 if something was deleted otherwise 0
  8) int Is_Empty(LINKED_LIST list)  // return 1 if the list is empty otherwise returns 0
  9) void Clear(LINKED_LIST *list) //delete all elements of the list
  10) void Remove_Duplicates(LINKED_LIST *list) //Filtering the linked list by deleting repeated elements.
  ```
  
  





