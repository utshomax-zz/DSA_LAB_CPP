#include <iostream>
using namespace std;


void insert(int arr[],int element,int position){
        int i;
        arr[position]=element;
        printf("\nDone!");
        cout<< "\nThe new arry is:";  
    
        for (i = 0; i < position+1; i++){
            cout << arr[i]<< " ";
        }
}

int search(int arr[],int position,int element){
    int i ;
    if(position>50){
        cout<<"\nPossition is not valid!";
    }
    for(i=0;i<50;i++){
        if(arr[i]!=element){
            insert(arr,element,position);
            return 1;
        }
    }
    return 0;
}

void read(int arr[] ){
    int position,i;
    int element;
    printf("\nEnter the position: ");
	cin>>position;
    printf("\nEnter the Element: ");
	cin>>element;
    search(arr,position,element);

}

int main(){
    int arr[50]={};
    int i;
    bool a=true;
    char t;
    cout<<"\nEnter a position and element to insent in array \nType 'q' for Exit:";
    while(a==true)
    {   
        read(arr);
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