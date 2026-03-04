#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

bool search_element(node *head, int target){
    while (head!=NULL)
    {
        if (head->data==target)
        {
            return true;
        }

        head = head->next;
        
    }
    return false;
    
}

void print_list(node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void Insertfirst(node *&head, int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void Insertlast(node *&head, int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->next=nullptr;

    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void Insertafter(node *&head,int target, int data){

    node* temp = head;

    while (temp!=nullptr&&temp->data!=target)
    {
        temp=temp->next;
    }
    if (temp==nullptr)
    {
        cout<<"Not found "<<target<<endl;
        return;
    }
    node *newnode = new node;
    newnode->data = data;
    newnode->next=temp->next;
    temp->next=newnode;
}

void Delete_element(node *&head,int target){

    if(head->data==target){
        node *todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    node *temp = head;
    while (temp->next!=nullptr)
    {
        if (temp->next->data==target)
        {
            node *todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
            return;
        }
        temp = temp->next;
        
    }
    cout<<"NOT FOUND"<<endl;
    
}



int main(){
    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    first->data=10;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=forth;
    forth->data=40;
    forth->next=fifth;
    fifth->data=50;
    fifth->next=nullptr;

    node *head = first;

    if (search_element(head,50))
    {
        cout<<"found"<<endl;
    }
    else{
        cout<<" not found "<<endl;
    }

    Insertfirst(head,0);
    print_list(head);
    Insertlast(head,60);
    print_list(head);
    Insertafter(head,30,35);
    print_list(head);
    Delete_element(head,35);
    print_list(head);
    
}

