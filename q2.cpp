//119CS0145
//Visual Studio C++
//Question2

#include <iostream> 
using namespace std; 

int main()
{
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

    int min=*(arr+0);
	for(int i=1;i<n;i++)
	{
		if(*(arr+i)<min)
			min=*(arr+i);
	}
		



	cout<<"The minimum element is: "<<min;

	
}