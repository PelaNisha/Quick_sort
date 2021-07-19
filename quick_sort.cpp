// quick sort

#include<iostream>

using namespace std;

int lb, ub;
int swap(int *x, int *y)
{
	int temp = *x;
	*x= *y;
	*y= temp;
}

int partition(int a[], int lb, int ub)
{
	int pivot = a[lb];
	int start = lb;
	int end = ub;
	while(start<end)
	{
		while(a[start]<=pivot&& start<end)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(a[start],a[end]);
		}
	}
	swap(a[lb], a[end]);
	return (end);
}

int Quicksort(int a[], int lb,int  ub)
{
	int loc;
	if(lb<ub)
	{
	
		loc = partition(a, lb, ub);
		Quicksort(a,lb, loc-1);
		Quicksort(a, loc+1,ub);	
	}
	
}

void printArray(int a[], int s)
{
    int i;
    for (i=0; i < s; i++)
        printf("%d ", a[i]);
    printf("\n");
}

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
//	partition(a,lb,ub );
	Quicksort(a,lb,ub );
	printArray(a, size);
	
}
