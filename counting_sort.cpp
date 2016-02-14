//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//counting_sort.cpp         counting_sort algorithm
#include <iostream>
#include "counting_sort.h"
using namespace std;
void counting_array(int* a, int s)
{
	int count[1000];
	for(int i=0;i<1000;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<s;i++)
	{
		count[a[i]]++;
	}
	int index=0;
	for(int i=0;i<1000;i++)
	{
		while(count[i]!=0)
		{	
			a[index]=i;
			index++;
			count[i]--;
		}
	}
}
void counting_link(node* root,int s)
{
	int count[1000];
	for(int i=0;i<1000;i++)
	{
		count[i]=0;
	}
	node* p=root;
	while(p)
	{
		count[p->x]++;
		p=p->rptr;
	}
	p=root;
	for(int i=0;i<1000;i++)
	{
		while(count[i]!=0)
		{
			p->x=i;
			p=p->rptr;
			count[i]--;
		}
	}
}