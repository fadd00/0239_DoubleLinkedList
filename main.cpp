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
}


int main(){

}