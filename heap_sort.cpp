//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//heap_sort.cpp         heap_sort algorithm
#include <iostream>
#include "heap_sort.h"
#include <stdlib.h> 
using namespace std;
#define GETBIT(num,pos) (num >> pos & 1)
struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};
typedef struct tnode tnode;
 
int nodes;
tnode *first, *tmp, *current;
 
void addNode_link(tnode *,tnode *,int);
void swap_link(int *, int *);
void getRoot_link(tnode *, int);
void heapSort_link(tnode *);
void siftdown_array(int *a ,int i,int s)
{
	if(2*i+1<s)
	{
		if(a[i]<a[2*i+1])
		{
			int temp=a[i];
			a[i]=a[2*i+1];
			a[2*i+1]=temp;
			siftdown_array(a,2*i+1,s);
		}
	}
	if(2*i+2<s)
	{
		if(a[i]<a[2*i+2])
		{
			int temp=a[i];
			a[i]=a[2*i+2];
			a[2*i+2]=temp;
			siftdown_array(a,2*i+2,s);
		}
	}
}
void heapify_array(int* a,int s)
{
	for(int i=(s-2)/2;i>=0;i--)
	{
		siftdown_array(a,i,s);
	}
}
void heap_array(int *a , int s)
{
	heapify_array(a,s);
	int t=s-1;
	for(int i=0;i<s-1;i++)
	{
		int temp=a[0];
		a[0]=a[t];
		a[t]=temp;
		t--;
		siftdown_array(a,0,t+1);
	}
}
void heap_link(node* root,int s)
{
    int num;
    int cont,i,j;
	node* t=root; 
    for(int i1=0;i1<s;i1++)                                               
    {
        num=t->x;
        t=t->rptr;                                         
        current = new tnode();
        if(current ==  0)
        {
        	return;
        }
 
        current->data = num;
        nodes++;
 
        for(i=nodes,j=-1; i; i >>= 1,j++);
 
        if(first == 0)
        {
            first = current;
            first->left = 0;
            first->right = 0;
        }
        else
            addNode_link(first,first,j-1);
 
    }
 	t=root;
    while(nodes)
    {
        //cout<<first->data<<" ";                                        //prints the largest number in the heap
        t->x=first->data;
        t=t->rptr;
        for(i=nodes,j=-1; i; i >>= 1,j++);                                    //Updating the height of the tree
        getRoot_link(first,j-1);
        nodes--;
 
        heapSort_link(first);
    }       
 
}
 
void swap_link(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
 
void addNode_link(tnode *tmp1,tnode *parent, int pos)
{
    int dirxn = GETBIT(nodes,pos);                                   // 0 - go left, 1 - go right
 
    if(!pos)
    {
        if(dirxn)
            tmp1->right = current;
        else
            tmp1->left = current;
 
        current->left = 0;
        current->right = 0;
 
        if(current->data > tmp1->data)
            swap_link(&current->data, &tmp1->data);
    }
 
    else
        if(dirxn)
            addNode_link(tmp1->right,tmp1,pos-1);
        else
            addNode_link(tmp1->left,tmp1,pos-1);
 
    if(tmp1->data > parent->data)
        swap_link(&parent->data,&tmp1->data);
}
 
void getRoot_link(tnode *tmp,int pos)
{
    int dirxn;
 
    if(nodes == 1)
        return ;
 
    while(pos)
    {
        dirxn = GETBIT(nodes,pos);
 
        if(dirxn)
            tmp = tmp->right;
        else
            tmp = tmp->left;
        pos--;
    }
 
    dirxn = GETBIT(nodes,pos);
 
    if(dirxn)
    {
        first->data = tmp->right->data;
        free(tmp->right);
        tmp->right = 0;
    }
    else
    {
        first->data = tmp->left->data;
        free(tmp->left);
        tmp->left = 0;
    }
}
 
void heapSort_link(tnode *tmp)
{
    if(!tmp->right && !tmp->left)
        return;
 
    if(!tmp->right)
    {
        if(tmp->left->data > tmp->data)
            swap_link(&tmp->left->data, &tmp->data);
    }
    else
    {
        if(tmp->right->data > tmp->left->data)
        {
            if(tmp->right->data > tmp->data)
            {
                swap_link(&tmp->right->data, &tmp->data);
                heapSort_link(tmp->right);
            }
        }           
        else
        {
            if(tmp->left->data > tmp->data)
            {
                swap_link(&tmp->left->data, &tmp->data);
                heapSort_link(tmp->left);
            }
        }
    }
}