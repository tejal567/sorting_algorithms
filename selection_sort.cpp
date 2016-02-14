//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//selection_sort.cpp         selection_sort algorithm
#include <iostream>
#include "selection_sort.h"
using namespace std;
void selection_array(int *a,int s)
{
	int temp;
	for(int i=0;i<s-1;i++)
	{
		//find the min element in the unsorted array a[i...n-1]
		//assume the min is the first element
		int min=i;
		//test against elements after i to find the smallest
		for(int j=i+1;j<s;j++)
		{
			//if this element is less, then it is the new min
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
void selection_link(node* root,int s)
{
	int temp;
	node* pi=root;
	node* pj=root;
	pj=pj->rptr;
	node* min;
	for(int i=0;i<s-1;i++)
	{
		min=pi;
		for(int j=i+1;j<s;j++)
		{
			if(pj->x<min->x)
				min=pj;
			pj=pj->rptr;
		}
		if(min->x!=pi->x)
		{
			temp=pi->x;
			pi->x=min->x;
			min->x=temp;
		}
		pi=pi->rptr;
		pj=pi->rptr;
	}	
}