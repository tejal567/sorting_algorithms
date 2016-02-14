//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//bucket_sort.h         bucket_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void bucket_array(int* a, int s);
void bucket_link(node* root,int s);