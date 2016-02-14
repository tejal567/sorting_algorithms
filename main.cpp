//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//main.cpp      Main file for calling all sorting algorithms
#include <iostream>
#include <ctime>
//#include "bubble_sort.h"
//#include "insertion_sort.h"
//#include "selection_sort.h"
//#include "shell_sort.h"
//#include "bucket_sort.h"
//#include "counting_sort.h"
//#include "radix_sort.h"
//#include "heap_sort.h"
//#include "merge_sort.h"
#include "quick_sort.h"
#include <cstdlib>
using namespace std;
int main()
{
	srand(time(0));
	cout<<"Enter size of numbers you want to sort"<<endl;
	int s;
	cin>>s;
	cout<<"Enter 0 to sort using array data structure or 1 to sort using linked lists\n";
	bool how;
	cin>>how;
	if(!how)
	{
		int a[s];
		for(int i=0;i<s;i++)
		{
			a[i]=rand()%1000;
		}
		cout<<"Here are "<<s<<" random generated numbers"<<endl;
		for(int i=0;i<s;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		clock_t begin = clock();
		//bubble_array(&a[0],s);                   //for bubble sort
		//insertion_array(a,s);                    //for insertion sort
		//selection_array(a,s);                    //for selection sort
		//shell_array(a,s);                        //for shell sort
		//bucket_array(a,s);                       //for bucket sort
		//counting_array(a,s);                     //for counting sort
		//radix_array(a,s);                        //for radix sort
		//heap_array(a,s);                         //for heap sort 
		//merge_array(a,s);                        //for merge sort
		quick_array(a,s);                        //for quick sort
		clock_t end = clock();
		cout<<"Sorted Numbers:\n";
		for(int i=0;i<s;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout<<"Elapsed time(in seconds): "<<elapsed_secs<<endl;	
	}
	else
	{
		node *root=new node();
		root->x=rand()%1000;
		node *temp=root;
		temp->lptr=NULL;
		for(int i=0;i<s-1;i++)
		{
			node *temp2=new node();
			temp->rptr=temp2;
			temp2->lptr=temp;
			temp2->x=rand()%1000;
			temp2->rptr=NULL;
			temp=temp2;
		}
		cout<<"Here are "<<s<<" random generated numbers"<<endl;
		temp=root;
		for(int i=0;i<s;i++)
		{
			cout<<temp->x<<" ";
			temp=temp->rptr;
		}
		cout<<endl;
		clock_t begin = clock();
		//bubble_link(root,s);                      //for bubble sort
		//insertion_link(root,s);                   //for insertion sort
		//selection_link(root,s);                   //for selection sort
		//shell_link(root,s);                       //for shell sort 
		//bucket_link(root,s);                      //for bucket sort
		//counting_link(root,s);                    //for counting sort
		//radix_link(root,s);                       //for radix sort
		//heap_link(root,s);                        //for heap sort
		//merge_link(root,s);                       //for merge sort
		quick_link(root,s);                       //for quick sort
		clock_t end = clock();
		cout<<"Sorted Numbers:\n";
		temp=root;
		for(int i=0;i<s;i++)
		{
			cout<<temp->x<<" ";
			temp=temp->rptr;
		}
		cout<<endl;
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout<<"Elapsed time(in seconds): "<<elapsed_secs<<endl;
	}
	
}