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
    }
}


int main(){

}