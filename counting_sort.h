//Group ID 14114069-14114022    Tejal Singh & Deepanshu Singhal
//Date: 7 Feb 2016
//counting_sort.h         counting_sort algorithm header file
struct node
{	
	int x;
	node *lptr;
	node *rptr;
};
void counting_array(int* a,int s);
void counting_link(node * root, int s);