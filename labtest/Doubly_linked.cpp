#include<iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};

void print_list(node *head){
    while (head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void Insertfirst(node *&head,int data){
    node *newnode = new node;
    newnode->data= data;
    newnode->prev = nullptr;
    newnode->next = head;

    if (head != nullptr)
    {
        head->prev = newnode;
    }
    
    head = newnode;
}

void Insertafter(node *&head,int target, int data){

    node *temp = head;
    
    while (temp!=nullptr)
    {
        if (temp->data==target)
        {
            node *newnode = new node;
            newnode->data = data;

            newnode->prev = temp;
            newnode->next = temp->next;

            if (temp->next!=nullptr)
            {
                temp->next->prev = newnode;
            }
            temp->next=newnode;

            return;
            
        }
        temp = temp->next;
    }
    cout<<"NOT FOUND"<<endl;
    
}

void Insertlast(node *&head,int data){
    node *newnode = new node;
    newnode->data = data;

    if (head == nullptr)
    {
        newnode->prev = nullptr;
        head = newnode;
        return;
    }
    

    node *temp = head;

    while (temp->next!=nullptr)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = nullptr;
    
}

void Delete_element(node *&head,int target){
    node *temp = head;
    while (temp!=nullptr)
    {
        if (temp->data==target)
        {
            node * todelete = temp;
            if (temp->prev!=nullptr)
            {
                temp->prev->next = temp->next;
            }
            
            if (temp->next!=nullptr)
            {
                temp->next->prev = temp->prev;
            }

            delete temp;

            return;
        }
        temp = temp->next;
        
    }
    cout<<"NOT FOUND\n";
    
}

void InsertInEmpty(node *&chead, int data) {
    node *newnode = new node;
    newnode->data = data;
    
    chead = newnode;
    
    // The magic of circularity: It points to itself!
    chead->next = chead;
    chead->prev = chead;
}

void InsertEnd(node *&chead, int data) {
    // If the list is empty, use our other function
    if (chead == nullptr) {
        InsertInEmpty(chead, data);
        return;
    }

    node *newnode = new node;
    newnode->data = data;

    // Instantly jump to the last node
    node *tail = chead->prev;

    // 1. Connect newnode to its neighbors (the old tail and the head)
    newnode->next = chead;
    newnode->prev = tail;

    // 2. Break the old loop and connect neighbors to the new node
    tail->next = newnode;
    chead->prev = newnode;
}

void print_circular_list(node *chead) {
    if (chead == nullptr) return;

    node *temp = chead;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != chead); // Stop when we get back to the start!
    
    cout << "(loops back to " << chead->data << ")" << endl;
}


int main(){
    node *dnode = new node;
    node *cnode = new node;

    dnode->prev = nullptr;
    dnode->data = 10;
    dnode->next = nullptr;

    node *head = dnode;
    node *chead = cnode;

    Insertfirst(head,0);
    print_list(head);
    Insertafter(head,0,5);
    Insertafter(head,10,15);
    print_list(head);
    Insertlast(head,20);
    print_list(head);
    Delete_element(head,10);
    print_list(head);

    InsertInEmpty(chead,1);
    InsertEnd(chead,3);
    InsertEnd(chead,5);
    InsertEnd(chead,7);
    InsertEnd(chead,9);

    print_circular_list(chead);
}