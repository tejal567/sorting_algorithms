//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//shell_sort.cpp         shell_sort algorithm
#include <iostream>
#include "shell_sort.h" 
using namespace std;
void shell_array(int *a, int s)
{
	int j;
 
  	//Narrow the array by 2 everytime
  	for (int gap = s / 2; gap > 0; gap /= 2)
  	{
    	for (int i = gap; i < s; ++i)
    	{
      		int temp = a[i];
      		for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
      		{
        		a[j] = a[j - gap];
      		}
      		a[j] = temp;
    	} 
  	}
}
void shell_link(node* root,int s)
{
	if(root)
    {
        int step=0;
        int length=s;
        node *p=root;
        while(2*(3*step+1)<=length)
            step=3*step+1;
        for(step;step>0;step/=3)
            for(int i=step;i>0;i--)
                for(int j=step-i; j<length; j+=step)
                {
                    p=root;
                    int k;
                    for(k=0;k<j;k++)
                        p=p->rptr;
                    node* c=p;
                    int temp=k+step;
                    while(c)
                    {
                        for(k;k<temp;)
                            if(c)
                            {
                                k++;
                                c=c->rptr;
                            }
                            else break;
                            if(c)
                                if(p->x>c->x)
                                {
                                    int t=p->x;
                                    p->x=c->x;
                                    c->x=t;
                                }
                                temp+=step;
                    }
                }
    }
}