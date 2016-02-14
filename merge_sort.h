struct node
{
	int x;
	node* rptr;
    node* lptr;
};
void merge_array(int* a, int s);
void merge_link(node* root,int s);