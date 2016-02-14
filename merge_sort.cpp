#include <iostream>
#include "merge_sort.h"
using namespace std;
node* Split(node* my_node);
node* MergeSort(node *my_node);
node* Merge(node* firstNode, node* secondNode);
void merge_it_array(int *a,int i,int j);
void merge_array(int* a, int s)
{
	merge_it_array(a,0,(s-1));
}

void merge_it_array(int *a,int i,int j)
{
	int n=j-i+1,g=n;
	if(n>2)
	{
		merge_it_array(a,i,i+(n/2)-1);
		merge_it_array(a,(n/2)+i,j);
	}n=n+(2*i);
	int *b=new int[g];
	int p=i,q=(n/2),l=0;
	for(int k=0;k<g;k++)
	{
		if(l==0)
		{
			if(a[p]>a[q])
			{
				b[k]=a[q];
				q++;
				if(q==j+1)
				{
					l=1;
					continue;
				}
			}
			else 
			{
				b[k]=a[p];
				p++;
				if(p==(n/2))
				{
					l=2;
					continue;
				}
			}
		}
		else if(l==1)
		{
			b[k]=a[p];
			p++;
		}
		else if(l==2)
		{
			b[k]=a[q];
			q++;
		}
	}
	for(int k=i;k<=j;k++)
	{
		a[k]=b[k-i];
	}
	delete[] b;
}
void merge_link(node* root,int s)
{
	node *root2=new node();
	root2->x=root->x;
	node *temp=root2;
	node *temp3=root->rptr;
	temp->lptr=NULL;
	for(int i=0;i<s-1;i++)
	{
		node *temp2=new node();
		temp->rptr=temp2;
		temp2->lptr=temp;
		temp2->x=temp3->x;
		temp3=temp3->rptr;
		temp2->rptr=NULL;
		temp=temp2;
	}
	*root=*MergeSort(root2); 
    //root=MergeSort(root2);      // This does not work!!!!  I know why!! :))
}
node* MergeSort(node *my_node)
{
    node *secondNode;

    if (my_node->rptr == NULL)
        return my_node;
    else
    {
        secondNode = Split(my_node);
        return Merge(MergeSort(my_node),MergeSort(secondNode));
    }
}

node* Merge(node* firstNode, node* secondNode)
{
    if (firstNode == NULL) return secondNode;
    else if (secondNode == NULL) return firstNode;
    else if (firstNode->x <= secondNode->x) 
    {
        firstNode->rptr = Merge(firstNode->rptr, secondNode);
        return firstNode;
    }
    else 
    {
        secondNode->rptr = Merge(firstNode, secondNode->rptr);
        return secondNode;
    }
}

node* Split(node* my_node)
{
    node* secondNode;

    if (my_node == NULL || my_node->rptr == NULL) return NULL;
    else 
    {
        secondNode = my_node->rptr;
        my_node->rptr = secondNode->rptr;
        secondNode->rptr = Split(secondNode->rptr);
        return secondNode;
    }
}