// do not include other libraries
#include <stdio.h>
#include <stdlib.h>

// ***************************************
// *** struct definitions ****************
// *** do not change these ***************
// ***************************************
typedef struct NODE {int data; struct NODE* next;} NODE; // nodes of the linked list
typedef struct LINKED_LIST {struct NODE *head;} LINKED_LIST; // struct to act as the head of the list


// ***************************************
// *** provided functions  ****************
// ***************************************

// this function returns a LINKED_LIST struct to
// act as the head of the linked list.
// do not change this function
LINKED_LIST Create_List(void) {LINKED_LIST list = {NULL}; return list;}

// call this function to verify malloc worked when you create new nodes
void Verify_Malloc(NODE *node) {if (node == NULL) {printf("Malloc Failed\n"); exit(1);} return;}

// do not change this function
// this function prints out all of the nodes in the linked list
void Print_List(FILE *out, LINKED_LIST list) {
    if (list.head == NULL) {printf("\n"); return;} //empty list
    NODE *current = list.head;
    while (current->next != NULL) {
        fprintf(out, "%d -> ",current->data);
        current = current->next;
    }
    fprintf(out, "%d\n",current->data);
    return;
}

// ******************************************************
// *** Complete the following functions  ****************
// ******************************************************

// this function returns the number 
// of elements in the linked list
int Size(LINKED_LIST list){
    int size = 0;
    NODE *current = list.head;
    while(current != NULL){
	    size += 1;
	    current = current->next;
    }
    return size;
}
// this function adds an element to
// the front of the list
void Push_Front(LINKED_LIST *list, int data){
    NODE *node  = malloc(sizeof(NODE)); Verify_Malloc(node);
    node->data = data;
    if(list->head == NULL){ //Base case: Check if Linked List is empty
	    list->head = node;
    }
    else{
        node->next = list->head; //Step 1 next pointer of new node points to current head
        list->head = node; //Step 2 update the head of the new linked list
    }
}

// this function adds an element 
// to the end of the linked list 
void Push_Back(LINKED_LIST *list, int data) {
	
    NODE *node  = malloc(sizeof(NODE)); Verify_Malloc(node);
    node->data = data;
    NODE *current = list->head;
    if(current == NULL){ // Base case: Check if Linked List is empty
	    list->head = node;
    }
    else{
        while(current->next != NULL){ // While loop to check the last node of the linked list
	     current = current->next; 
    }
    current->next = node;
    }
    node->next = NULL;
}


// if the list is not empty
// the value of the first element of the list is returned by reference in the parameter data
// the first element of the list is deleted
// returns 0 if the list is empty otherwise returns 1
// remember to free the deleted node
int Pop_Front(LINKED_LIST *list, int *data) {
	NODE *current = list->head;
	if(current == NULL){ //Base case: Check if linked list is empty
		return 0;
	}
	*data = current->data;
	list->head = current->next;
	free(current);
	return 1;
}


// if the list is not empty
// the value of the last element of the list is returned by reference in the parameter data
// the last element of the list is deleted
// returns 0 if the list is empty otherwise returns 1
// remember to free the deleted node
int Pop_Back(LINKED_LIST *list, int *data) {
	NODE *current = list->head;
	NODE *previous;
	if(current == NULL){ // Base case: Check if linked list is empty
		return 0;
	} 
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	*data = current->data;
	free(current);
	previous->next = NULL;
	return 1;
}

// this function returns the number 
// of times that the value of the parameter 
// data appears in the list
int Count_If(LINKED_LIST list, int data) {
   int duplicate = 0;
   NODE *current = list.head;
   while(current != NULL){
	   if(current->data == data){
		   duplicate += 1;
	   }
	   current = current->next;
   }
   return duplicate;
}

// delete the first node containing the data value
// return 1 if something was deleted otherwise 0
// remember to free the deleted node
int Delete(LINKED_LIST *list, int data) {
    // if node is head then follow delete procedures and return 1
    // if node is somewhere in the middle, follow procedures and return 1
    // else return 0
    NODE *current = list->head;
    if(current != NULL && current->data == data){ // if node is head
	    list->head = current->next;
	    free(current);
	    return 1;  
    }
    NODE *previous;
    while(current != NULL && current->data != data){ // Find the node with the data value that matches the input
	    previous = current;
	    current = current->next;
    }
    if(current != NULL){
	    previous->next = current->next; // Make a new link for the linked list
	    free(current); // Free Memory
	    return 1;
    }
    return 0; 
}

// return 1 if the list is empty otherwise returns 0
int Is_Empty(LINKED_LIST list) {
    NODE *head = list.head;
    if(head == NULL){
	    return 1;
    }
    return 0;
}

// delete all elements of the list
// remember to free the nodes
void Clear(LINKED_LIST *list) {
    NODE *current = list->head;
    NODE *next;
    while(current != NULL){
	    next = current->next;
	    free(current);
	    current = next;
    }
    list->head = NULL;
}


// if an element appears in the list 
// retain the first occurance but
// remove all other nodes with the same 
// data value
void Remove_Duplicates(LINKED_LIST *list) {
    NODE *pt2; // Pointer 2 that starts at one position more from Pointer 2
    NODE *pt3; // Previous pointer of pointer 2
    NODE *dup;
    NODE *pt1 = list->head; // Pointer 1 that starts at the head of the linked list
       
    while (pt1 != NULL && pt1->next != NULL) { 
        pt3 = pt1;
        pt2 = pt1->next;
        while (pt2 != NULL) {  
            if (pt1->data == pt2->data) {
                dup = pt2;
                pt3->next = pt2->next; // Make the new link for the linked list
                free(dup);
		pt2 = pt3->next; // Update the second pointer after making the new link
            }
            else{
		pt3 = pt2; // Increment pointer 3
                pt2 = pt2->next; // Increment pointer 2
        }
    }
    pt1 = pt1->next; // Increment pointer 1
}
}

// modify main to completely test your functions 
int main() {
    // create a linked list
    printf("creating linked list\n");
    LINKED_LIST list = Create_List();
   
   
    printf("hardcoding some data\n");
    NODE *first  = malloc(sizeof(NODE)); Verify_Malloc(first);
    NODE *second = malloc(sizeof(NODE)); Verify_Malloc(second);
    NODE *third = malloc(sizeof(NODE)); Verify_Malloc(third);
    NODE *fourth = malloc(sizeof(NODE));Verify_Malloc(fourth);
    NODE *fifth = malloc(sizeof(NODE));Verify_Malloc(fifth);
    NODE *sixth = malloc(sizeof(NODE));Verify_Malloc(sixth);
    NODE *seventh = malloc(sizeof(NODE)); Verify_Malloc(seventh);
    first->data  = 1;
    second->data = 2;
    third->data = 4;
    fourth->data = 5;
    fifth->data = 6;
    sixth->data = 7;
    seventh->data = 8;
    list.head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

   printf("========================\n");
   // print the list
   printf("Testing Print_List\n");
   Print_List(stdout, list);

   printf("========================\n");
   // write a better test for Size
   printf("Testing Size\n");
   printf("size = %d\n",Size(list));

   printf("========================\n");
   //write a better test for Push_Front
   printf("Testing Push_Front\n");
   Push_Front(&list, 7);
   Push_Front(&list, 6);
   Push_Front(&list, 8);
   Push_Front(&list, 9);
   Print_List(stdout, list);

   printf("========================\n");
   //write a better test for Push_Back
   printf("Testing Push_Back\n");
   Push_Back(&list, 8);
   Push_Back(&list, 9);
   Push_Back(&list, 10);
   Push_Back(&list, 11);
   Push_Back(&list, 12);
   Print_List(stdout, list);

   printf("========================\n");
   //write a better test for Pop_Front
    printf("Testing Pop_Front\n");
    {
         int x; 
         int not_empty = Pop_Front(&list, &x);
         if (not_empty) {
            printf("Element popped was %d\n",x);
            Print_List(stdout,list);
            printf("size = %d\n",Size(list));
         }
         else 
            printf("List was empty\n");
    }

   printf("========================\n");
   //write a better test for Pop_Back
   printf("Testing Pop_Back\n");
    {
        int x; 
        int not_empty = Pop_Back(&list, &x);
        if (not_empty) {
            printf("Element popped was %d\n",x);
            Print_List(stdout,list);
            printf("size = %d\n",Size(list));
        }
        else 
            printf("List was empty\n");
    }

     printf("========================\n");
     printf("Testing Push Front\n");
     //write a beter test for Count_If
     Push_Front(&list, 5);
     Push_Front(&list, 5);
     Push_Front(&list, 5);
     Push_Front(&list, 7);
     Push_Front(&list, 89);
     Push_Back(&list, 5);
     Push_Front(&list, 5);
     Print_List(stdout, list);
     printf("5 count = %d\n",Count_If(list, 5));

     printf("========================\n");
     //write a test for Delete 
     printf("Testing Delete\n");
     Print_List(stdout, list);
     Delete(&list, 2);
     Delete(&list, 6);
     Delete(&list,5);
     Delete(&list, 89);
     Print_List(stdout, list);

     printf("========================\n");
     // write a better test for Is_Empty
     printf("Testing Is_Empty\n");
     if(Is_Empty(list)) printf("List is Empty\n"); else printf("List is not empty\n");

     printf("========================\n");
     printf("Testing Clear\n");    
     //write a better test for Clear
     Clear(&list);
     if (Is_Empty(list)) printf("List is Empty\n"); else printf("List is not empty\n");
        
     printf("========================\n");
//    // write a better test for Remove_Duplicates
      Push_Back(&list, 1);
      Push_Back(&list, 1);
      Push_Back(&list, 1);
      Push_Back(&list, 2);
      Push_Back(&list, 2);
      Push_Back(&list, 4);
      Push_Back(&list, 5);
      Push_Back(&list, 4);
      Push_Back(&list, 6);
      Push_Back(&list, 5);
      Push_Back(&list, 5);
      Push_Back(&list, 5);
      Push_Back(&list, 6);
      Remove_Duplicates(&list);
      Print_List(stdout, list);
    return 0;
}
