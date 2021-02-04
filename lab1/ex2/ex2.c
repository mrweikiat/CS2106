/*************************************
* Lab 1 Exercise 1
* Name: Goh wei kiat
* Matric No: A0204970H
* Lab Group: 6
*************************************/

#include <stdio.h>
#include <stdlib.h> //for malloc() and free()

//Declaration of a Linked List Node

typedef struct NODE{
    int data;
    struct NODE* next;
} node;

//Function Prototypes
node* insertAt(node*, int, int, int);

void printList(node*);
void destroyList(node*);



int main()
{
    node* myList = NULL;    //Empty List
    int position, newValue, copies;

    //Fill in code for input and processing
     while (scanf("%i %i %i",&position, &newValue, &copies ) != EOF){
        //Add to head
        
        for (int i = 0; i < copies; i++) {
            myList = insertAt(myList, position, copies, newValue);
        }
        //printf("1\n");
    } 

    //Output code coded for you
    printf("My List:\n");
    
    printList(myList);
    
    destroyList(myList);
    myList = NULL;

    
    printf("My List After Destroy:\n");
    printList(myList);
 
    return 0;
}

//Actual Function Implementations
node* insertAt(node* head, int position, int copies, int newValue)
{
    //Fill in your code here
    while(position >= 0) {
        
        if (position == 0) {
            node* temp = (node*)malloc(sizeof(node));
            temp->data = newValue;
            
            temp->next = head;
            
            head = temp;
        } else {
            head = &head->next;
        }
        position--;
    }
        
    
  
        
    return head;    //change this!
}
 
void printList(node* head)
//Purpose: Print out the linked list content
//Assumption: the list is properly null terminated
{
    //This function has been implemented for you
    node* ptr = head;

    while (ptr != NULL)  {    //or you can write while(ptr)
        printf("%i ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void destroyList(node* head)
{
     
    //Fill in your code here
    //You can use the same implementation as in exercise 1
    node* current = head;
    node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}



