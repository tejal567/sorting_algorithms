//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//insertion_sort.cpp         insertion_sort algorithm
#include <iostream>
using namespace std;
#include "insertion_sort.h"
#define NEGATIVE_INFINITY -100000 
void insertion_array(int *a,int s)
{
	int key;
	for(int i=1;i<s;i++)
	{
		key=a[i];
		int j=i-1;
		while(key<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void insertion_link(node* root,int s)
{
	node* dummy=new node();
	dummy->x=NEGATIVE_INFINITY;
	dummy->rptr=root;
	root->lptr=dummy;
	int key;
	node* pi=root;
	node* pj=root;
	pi=pi->rptr;
	for(int i=1;i<s;i++)
	{
		key=pi->x;
		while(key<pj->x)
		{
			pj->rptr->x=pj->x;
			pj=pj->lptr;
		}
		pj->rptr->x=key;
		pj=pi;
		pi=pi->rptr;
	}
}