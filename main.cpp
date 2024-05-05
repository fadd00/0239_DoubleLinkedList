#include<iostream>
#include<string>
using namespace std;

struct Node{
    int noMhs; 
    string name;
    Node *next;
    Node *prev;
};

Node * START = NULL;

void addNode(){
    Node *newNode = new Node; //step 1: create a new node
    cout<<"\nEnter the roll number of students: ";
    cin>>newNode->noMhs; //Assign value to the data feild of new node
    cout<<"\nEnter the name of the student: ";
    cin>>newNode->name; // assign value to the data feild of new node

    // Insert the new node in the list
    if (START == NULL || newNode->noMhs <= START ->noMhs){

        if (START != NULL && newNode->noMhs <= START ->noMhs)
        {
            cout << "\033[31mDuplicate rull number not allowed\033[0m]"<<endl;
            return ;
        }
        // if the list is empty, make the new node point to the first node
        newNode->next = START; // step 3: make the new node point to the first node
        if (START!= NULL)
        {
            START->prev = newNode; // step 4: make the new node point to the new node
        }
        newNode->next = NULL; // step 5: make the new node point to null
        START = newNode; // step 6: make the new node the first node
    } else {
        // insert the new node in the midle or at the end
        Node *current = START; // step 1.a : start from the first node
        Node *previous = NULL; // step 1.b : previous node is NULL initially
    while (current != NULL && current->noMhs < newNode->noMhs) // step 1.c traverse the list to find the correct position
        {
            previous = current; // step 1.d : move the previous to the current node
            current = current->next; // step 1.e : move the currrent to the next node
        }
        newNode->next = previous; // step 4 : make the next field of the new node point to current
        newNode->prev = previous; // step 5 : make the previous field of the new node point to previous

         if (current != NULL)
        {
            current->prev = newNode; // step 6 : make the next previous field of the current node point ti the new world
        }
         if (previous != NULL)
        {
            previous->next =newNode; // step 7 : make the next field of the previous node point to the new node
        }
        else
        {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
    }
}
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = * current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}
void deletenode(){
    Node *previous, *current;
    int rollNo;

    cout <<"\nEnter the roll number of the student whose record is to be deleted : ";
    cin >> rollNo; // step 3 : get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    current = START; // step 1 : start from the first node
    previous = NULL;

        // Locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        cout << "\033[31mThe record wtih toll number " << rollNo << " not found\033[0m" << endl;
        return;
    }
    // Node to be deleted is the first node
    if (current == START)
    {
        START = START->next; // step 2 : update the START pointer
        if (START != NULL)
        {
           START->prev = NULL; 
        }
    }
    else
    { // Node to be deletd is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        { // if there's a succesor, update is prev pointer
            current->next->prev = previous;
        } 
    }
    
delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;

}

bool listEmpty()
{
    return (START == NULL);
}
int main(){

}