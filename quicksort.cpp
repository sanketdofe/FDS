#include<iostream>
using namespace std;
int part(int arr[] ,int beg ,int end)
{
	int left = beg;
	int right = end;
	int pivot = beg;
	int flag = 0;
	while (flag==0)
	{
		while (arr[pivot]<=arr[right] && pivot!=right)
		{	right--;
		}
		
		if(pivot==right)
		{	flag=1;
		}
		else if (arr[pivot]>arr[right])
		{
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
			pivot = right;
		}
		
		if (flag==0)
		{
			while (arr[pivot]>=arr[left] && pivot!=left)
			{	left++;
			}
			if (pivot==left)
			{	flag = 1;
			}
			else if(arr[pivot]<arr[left])
			{
				int temp = arr[pivot];
				arr[pivot] = arr[left];
				arr[left] = temp;
				pivot = left;
			}
		}
	}
	return pivot;
}

void quicksort(int arr[] ,int beg ,int end)
{
	int pivot;
	if  (beg<end)
	{
		pivot = part(arr ,beg ,end);
		quicksort(arr , beg ,pivot-1);
		quicksort(arr ,pivot+1 ,end);
	}
}


int main()
{
	int n;
	cout<<"Enter the no of elements:";
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cout<<"\nEnter the element:";
		cin>>arr[i];
	}
	cout<<"The array contains:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	
	quicksort(arr ,0 ,n-1);
	cout<<"The array after sorting contains:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
