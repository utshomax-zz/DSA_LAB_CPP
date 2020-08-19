#include <iostream>
using namespace std;


void dlt(int arr[],int element,int position,int size){
    int i;
    for(i=position;i<size;i++){
		arr[position]=arr[position+1];
}
        for (i = 0; i < size; i++){
            cout << arr[i]<< " ";
        }
}

int search(int arr[],int element,int size){
    int i,position ;
    for(i=0;i<size;i++){
        if(arr[i]==element){
            position=i;
            dlt(arr,element,position,size);
            return 1;
        }
    }
    cout<<"Does not exist";
    return 0;
}

void read(int arr[],int size){
    int position,i;
    int element;
    printf("\nEnter the Element: ");
	cin>>element;
    search(arr,element,size);

}

int main(){
    int n;
    int* arr = new int[n];
	printf("Enter the length of array: ");
	cin>>n;
	int *p=arr;
	for(int i=0;i<n;i++)
		{
		    printf("Element %d:", i);
			scanf("%d", p);
			p++;
		}

    bool a=true;
    char t;
    cout<<"\nEnter a position and element to Delete in array \nType 'q' for Exit:";
    while(a==true)
    {   
        read(arr,n);
        char t;
        cout<<"\n'q' for quit or 'c' for continue:";
        cin>>t;
        if(t=='q'){
            a=false;
        }
        if(t=='c'){
            t='c';
        }
    }
    
    return 0;
}