#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node *next;
    Node *prev;
};

Node * START = NULL;

void addNode(){
    Node *newNode = new Node;
    cout<<"\nEnter the roll number of students: ";
    cin>>newNode->noMhs;
    cout<<"\nEnter the name of the student: ";
    cin>>newNode->name;
    
    newNode->next = NULL;
    newNode->prev = NULL;

}

int main(){

}