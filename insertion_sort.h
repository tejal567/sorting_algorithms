//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//insertion_sort.h         insertion_sort algorithm header file
struct node
{	
	int x;
	node *rptr;
	node *lptr;
};
void insertion_array(int *a,int s);
void insertion_link(node* root,int s);