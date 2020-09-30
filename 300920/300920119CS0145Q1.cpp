
//UTSAB OJHA
//119CS0145
//g++ compiler

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node
{
	char info;
    int prn;
	struct node* link;
};
struct node* front = NULL;
struct node* r = NULL;

void enqueue(char d,int pr)
{ 	struct node* temp;
	struct node* n_node;
	n_node = (struct node*)malloc(sizeof(struct node));
	n_node->info = d;
	n_node->prn = pr;

	if((front==NULL)||(pr))
	{
		n_node->link = front;
		front = n_node;
	}
	else
	{
		temp = front;
		while((temp->link != NULL)&&((temp->link->prn) <= pr)) temp = temp->link;
		n_node->link = temp->link;
		temp->link = n_node;

	}
}
void display() 
{
	struct node* temp = front;
	while(temp != NULL) 
	{ 
		printf("\nData: %c\tPriority: %d ",temp->info,temp->prn);	 
		temp = temp->link; 
	} 

}
void dequeue() //Deletion of highest priority element from the Queue
{
	struct node* temp;
	if(front==NULL) //Check for Underflow condition
		printf("\nEmpty");
	else
	{
		temp = front;
		front = front->link;
		printf("\nDeleted element: %c\t Priority: %d",temp->info,temp->prn);
		free(temp);
	}
}
int main()
{
	int opt,n,i,pr;
    char info;
	printf("Enter Your Choice:-");
	do{
        cout << "\n1.Enqueue \n2.Dequeue \n3.Display\n";
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of info: ");
				scanf("%d",&n);
				i=0;
				for(i=0;i<n;i++){
					printf("Enter info: ");
					cin >> info;
					printf("Enter priority: ");
					cin >> pr;
					enqueue(info,pr);
				}
				break;
			case 2:
				dequeue();
				break;
			case 3:
                display();
				break;
			case 0:
				break;
			default:
				printf("\nError in Choice");

		}
	}while(opt!=0);
return 0;
}