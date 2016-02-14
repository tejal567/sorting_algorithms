//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//selection_sort.h         selection_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void selection_link(node* root,int s);
void selection_array(int *a,int s);