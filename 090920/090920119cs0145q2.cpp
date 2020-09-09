
//UTSAB OJHA
//119CS0145
//g++ compiler


#include <iostream> 
using namespace std; 
  

class Node  
{  
    public: 
    char data;  
    Node* next;  
    Node* prev;  
};  

void InsertAtBegining(Node** head_ref, char new_data)  
{  
  
    Node* new_node = new Node();  
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  
  
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  

    (*head_ref) = new_node;  
}  

  
void printList(Node* node)  
{  
    Node* last;  
    cout<<"\nForward direction \n";  
    while (node != NULL)  
    {  
        cout<<" "<<node->data<<" ";  
        last = node;  
        node = node->next;  
    }  
  
    cout<<"\nReverse direction \n";  
    while (last != NULL)  
    {  
        cout<<" "<<last->data<<" ";  
        last = last->prev;  
    }  
}  
Node* search(Node** head,char data) {
   
   if(*head==NULL) {
      printf("Linked List not found");
      return NULL;
   } 

   Node* current = *head;
   while(current!=NULL) {
    
      if(current->data == data) {
         return current;
      }

      if(current->next != NULL)
         current = current->next;
      else
         break;
   }
   return NULL;
}
void DeleteFirstOccurrence(Node** head_ref, char value )
{  

    Node *del = search(head_ref,value);
    if (*head_ref == NULL || del == NULL)  
        return;  

    if (*head_ref == del)  
        *head_ref = del->next;  
  
    if (del->next != NULL)  
        del->next->prev = del->prev;  
  

    if (del->prev != NULL)  
        del->prev->next = del->next;  

    free(del);  
    return;  
} 

int main() 
{ 
    
    Node* head = NULL; 
    char value;
    int k,i;
    cout<<"How many value you want to enter?\n";
    cin >> k;
    for(i=0;i<k;i++){

        cout << "Enter value to insert:\n";
        cin >> value;
        InsertAtBegining(&head,value);
    }
 

  
    cout << "Result: "; 
    printList(head); 
    cout << "\nInsert value to delete: "; 
    cin>>value;
    DeleteFirstOccurrence(&head, value); 
  
    cout << "\nList After Deletion: "; 
    printList(head); 
  
    return 0; 
} 