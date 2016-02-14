//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//heap_sort.h         heap_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void heap_array(int* a,int s);
void heap_link(node* root,int s);