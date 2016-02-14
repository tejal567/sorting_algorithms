//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//radix_sort.h         radix_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void radix_array(int*a ,int s);
void radix_link(node* root,int s);