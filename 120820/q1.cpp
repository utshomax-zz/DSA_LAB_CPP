//119CS0145
//Visual Studio C++
//Question1

#include <iostream> 
using namespace std; 

int main()
{
	
	int n;
	char* arr = new char[n];

	printf("Enter the length of array elements: ");
	cin>>n;
	
	
	for(int i=0;i<n;i++){
		cout<<"Enter array element " << i << " :";
		cin>> arr+i;
	}

    cout<<"Processing...\n";

    cout<<"Result: ";

    for(int i=0;i<n;i+=2){
		cout <<*(arr+i);
    }

}