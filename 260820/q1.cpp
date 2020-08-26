//UTSAB OJHA
//119CS0145
// G++ compiler

#include <iostream>
using namespace std;

struct Node{
 char data;
 Node *link;
};

Node *head=NULL;


void InsertAtBeginning(char d)
{
 Node *ptr = new Node();
 ptr->data=d;
 ptr->link=head;
 head=ptr;
}

bool search(Node* head, char x)  
{  
    Node* current = head; 
    while (current != NULL)  
    {  
        if (current->data == x){
            cout<<current;
            return true;      
        }
        current = current->link;  
    } 
    return false;
} 

void PrintList()
{
 Node *temp=head;
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->link;
 }
 cout<<"\n";
}
int main()
{
    int k;
    int i;
    char v;
    char s;
    
    
    search(head,2);
    cout<<"How many value you want to enter?\n";
    cin >> k;
    for(i=0;i<k;i++){

        cout << "Enter value \n";
        cin >> v;
        InsertAtBeginning(v);
    }
    cout<<"Result: ";
    PrintList();
    cout<<"Search a data \n";
    cin>>s;
    if(search(head,s)==false){
        cout<< "NULL";
    };
}