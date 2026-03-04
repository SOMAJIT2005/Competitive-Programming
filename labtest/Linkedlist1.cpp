#include<iostream>
#include<vector>
using namespace std;

struct node
{
  node *prev;
  int data;
  node *next;
};

void print_list(node *head){
  node *temp = head;
  while (temp!=nullptr)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
  
}

void insert(vector<int> &arr,node *&head,int data){
  node *newnode = new node;
  newnode->data = data;

  arr.push_back(data);

  if (head==nullptr)
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
      node* todelete = temp;
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
  cout<<"NOT FOUND"<<endl;
  
}

void undo(vector<int>arr,node *head){
  int i = 0;
  node *temp = head; 
  while (temp != nullptr)
  {
    if (temp->data!=arr[i])
    {
      node* newnode = new node;
      newnode->data = arr[i];
       
      temp->prev->prev = newnode;
      newnode->prev = temp->prev->prev;

      newnode->next = temp;
      temp->prev = newnode;
      
    }
    i++;
    temp = temp->next;
    
  }
  
}



int main(){

  node *head = new node;
  head->prev = nullptr;
  head->next = nullptr;

  vector<int>arr;

  insert(arr,head,1);
  insert(arr,head,2);
  insert(arr,head,3);
  insert(arr,head,4);
  insert(arr,head,5);
  print_list(head);

  Delete_element(head,2);
  print_list(head);

  Delete_element(head,4);
  print_list(head);

  undo(arr,head);
  print_list(head);
  undo(arr,head);
  print_list(head);

}