//UTSAB OJHA
//119CS0145
//g++ compiler


#include<iostream>
#include <cstring>
using namespace std;
typedef struct ArrayStack Stack;
struct ArrayStack{
	int top;
	int *array;
	unsigned int length;
};
Stack* createStack(unsigned int lent){
	Stack *stack;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->length = lent;
	stack->top = -1;
	stack->array = (int*)malloc(sizeof(int)*stack->length);
	return(stack);
}
int isFull(Stack *stack){
	if(stack->top ==stack->length-1)
		return 1;
	else
		return 0;
}
int isEmpty(Stack *stack){
	if(stack->top==-1)
		return 1;
	else
		return 0;
}

void push(Stack *stack,int value){
	if(!isFull(stack)){
		stack->top++;
		stack->array[stack->top] = value;
	}else{
		cout << "stack Full\n";
	}
}
void pop(Stack *stack){
	if(!isEmpty(stack)){
		printf("top value of stack = %d\n",stack->array[stack->top]);
		stack->array[stack->top] = 0;
		stack->top--;
	}else{
		cout << "Empty\n";
	}
}
void display(Stack *stack){
	while(stack->top!=-1){
		if(!isEmpty(stack)){
		printf("%d  ",stack->array[stack->top]);
		stack->array[stack->top] = 0;
		stack->top--;
		}
	}
	cout << "\n";
}
int main(){
	Stack *stack;
	stack = createStack(10);
	int choice,value;
	while(1){
		cout << "1. Push\n 2. Pop\n 3. Display\n 4. Exit\n" ;
		
		cin >> choice;
		switch(choice){
			case 1:{
				cout << "\nEnter a value(int) : ";
				cin >> value;
				push(stack,value);
				break;
			}
			case 2:{
				pop(stack);
				break;
			}
			case 3:{
				display(stack);
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			default:{
				cin >> "Wrong Inpunt From System I\n";
				break;
			}
		}
	}
}