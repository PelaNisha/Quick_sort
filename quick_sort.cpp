// quick sort

#include<iostream>

using namespace std;

int lb, ub;

//swap function
int swap(int *x, int *y)
{
	int temp = *x;
	*x= *y;
	*y= temp;
}

//partition function
int partition(int a[], int lb, int ub)
{
	int pivot = a[lb];//seting the pivot value by the left bound 
	int start = lb;//intialising left bound as start and right bound as end
	int end = ub;
	while(start<end)// condtion
	{
		while(a[start]<=pivot&& start<end)//if element is less than or equal to pivot and start <end then increment start
		{
			start++;
		}
		while(a[end]>pivot)//if a[end]>pivot then decrement end
		{
			end--;
		}
		if(start<end)// after the above statements, swap the start and end elements since a[start]>a[end] and greter element are placed in right side
		{
			swap(a[start],a[end]);
		}
	}
	swap(a[lb], a[end]);// when the end<start then swap the a[lb] and a[end]
	return (end);//return the end
}

//quickSort function
int Quicksort(int a[], int lb,int  ub)
{
	int loc;
	if(lb<ub)
	{
	
		loc = partition(a, lb, ub);//calling partition function
		Quicksort(a,lb, loc-1);//calling the quicksort fucntion recursively for the left sort
		Quicksort(a, loc+1,ub);	//calling the quicksort fucntion recursively for right sort
	}
	
}
//printArray function
void printArray(int a[], int s)
{
    int i;
    for (i=0; i < s; i++)//display the array
        printf("%d ", a[i]);
    printf("\n");
}
//main function
int main()
{
	int size;
	cout<<"Enter the size od array"<<endl;
	cin>>size;
	int a[size], lb, ub;
	cout<<"Enter the array"<<endl;
	for(int i = 0; i<size; i++)
	{
		cin>>a[i];
	}
	lb = 0;
	ub = size-1;
	Quicksort(a,lb,ub );
	printArray(a, size);
	
}
