#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

int main(){
    
    node *head = new node;
    node *first = new node;
    node *second = new node;
    node *third = new node;
    head->data=10;
    head->next=first;
    first->data=20;
    first->next=second;
    second->data=30;
    second->next=third;
    third->data=40;
    third->next=nullptr;

    node *temp=head;

    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
