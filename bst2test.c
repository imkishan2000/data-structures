#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create(int item)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Memory Overflow");
		return;
	}
	else
	{
		ptr->data=item;
		ptr->left=ptr->right=NULL;
	}
	
	return ptr;
	
}

struct node* insertion(struct node* root,int item)
{
	if(root==NULL)
	{
		return create(item);
	}
	else
	{
		if(item<root->data)
			root->left=insertion(root->left,item);
		else
			root->right=insertion(root->right,item);
		
		return root;		
	}
}

void inorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}

int main()
{
	struct node *root=NULL;
	int i,keys[8];
	for(i=0;i<8;i++)
	{
		printf("Enter no to insert: ");
		scanf("%d",&keys[i]);
			root=insertion(root,keys[i]);
	}
	
	inorder(root);
}
