//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//bubble_sort.cpp         bubble_sort algorithm
#include <iostream>
using namespace std;
#include "bubble_sort.h"
void bubble_array(int *a,int s)
{
	int temp;
	for(int i=0;i<s-1;i++)
	{
		for(int j=0;j<s-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

			}
		}
	}

}
void bubble_link(node *root,int s)
{
	int temp;
	node* pi=root;
	node* pj=root;
	for(int i=0;i<s-1;i++)
	{
		for(int j=0;j<s-1-i;j++)
		{
			if(pj->x>pj->rptr->x)
			{
				temp=pj->x;
				pj->x=pj->rptr->x;
				pj->rptr->x=temp;
			}
			pj=pj->rptr;
		}
		pj=root;
	}
}