//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//radix_sort.cpp         radix_sort algorithm
#include <iostream>
#include "radix_sort.h"
using namespace std;
void count_sort(int *a,int s,int e);
void radix_array(int* a, int s)
{
	for(int e=1;100/e>0;e*=10)
	{
		count_sort(a,s,e);
	}
}
void count_sort(int *a,int s,int e)
{
	int out[s];
    int i; 
    int count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < s; i++)
        count[ (a[i]/e)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in out[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the out array
    for (i = s - 1; i >= 0; i--)
    {
        out[count[ (a[i]/e)%10 ] - 1] = a[i];
        count[ (a[i]/e)%10 ]--;
    }
 
    // Copy the out array to a[], so that a[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < s; i++)
        a[i] = out[i];
}
void radix_link(node* root,int s)
{
    node* t=root;
    int a[s];
    for(int i=0;i<s;i++)
    {
        a[i]=t->x;
        t=t->rptr;
    }
    radix_array(a,s);
    t=root;
    for(int i=0;i<s;i++)
    {
        t->x=a[i];
        t=t->rptr;
    }
}
