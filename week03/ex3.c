#include "stdio.h"
//Write a program that creates a linked list* containing integers
//and uses the next functions:
//a function print list() that will print out the value of each
//element
//a function insert node() which will insert a new element after
//some existing element
//a function delete node() which will delete a certain element
struct node {
    int data;
    struct node* next;
    struct node* previous;
};
void printList(struct node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
struct LinkedList {

};


int main() {

}
