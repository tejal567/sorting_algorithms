//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//bubble_sort.h         bubble_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void bubble_array(int *a,int s);
void bubble_link(node* root,int s);