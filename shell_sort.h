//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//shell_sort.h         shell_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void shell_array(int *a, int s);
void shell_link(node* root,int s);