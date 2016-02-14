#include <iostream>
#include "quick_sort.h"
void quickSort(node* start,int a,int b);
void quickSort_array(int *x,int a,int b);
void quick_array(int* a, int s)
{
	quickSort_array(a,0,s-1);
}
void quickSort_array(int *x,int a,int b)
{
	if(b<=a)return;
	int pivot=x[a];
	int i=a+1,j=b;
	int hold;
	while(j>i)
	{
		while(x[i]<=pivot && i<b)
		{
			i++;
	//		cout<<"a"<<endl;
		}
		while(x[j]>pivot && j>(a))
		{
			j--;
	//		cout<<"b"<<endl;
		}
	//	cout<<i<<" "<<j<<endl;
		if(i<j)
		{
			hold=x[i];
			x[i]=x[j];
			x[j]=hold;
		}
		
	}
	if(i>j || (i==j && x[i]<pivot)){
		hold=pivot;
		x[a]=x[j];
		x[j]=hold;
	}
	
	quickSort_array(x,a,j-1);
	quickSort_array(x,j+1,b);
}

void quick_link(node* head,int s)
{
	quickSort(head,0,s-1);
}
void quickSort(node* start,int a,int b)
{
	if(b<=a)
		return;
	int pivot=start->x;
	node *x=start->rptr;
	node *y=start;
	for(int i=a;i<b;i++)
	{
		y=y->rptr;
	}
	int i=a+1,j=b,hold;
	while(j>i)
	{
		while(x->x<=pivot && i<b)
		{
			x=x->rptr;
			i++;
		}
		while(y->x>pivot && j>(a))
		{
			y=y->lptr;
			j--;
		}
		if(i<j)
		{
			hold=x->x;
			x->x=y->x;
			y->x=hold;
		}
		
	}
	if(i>j || (i==j && x->x<pivot))
	{
		hold=pivot;
		start->x=y->x;
		y->x=hold;
	}
	if(j==a)
	{
		y=start;
	}
	quickSort(start,a,j-1);
	quickSort(y->rptr,j+1,b);
}