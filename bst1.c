#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create(int item)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node*));
	ptr->data=item;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
		
		
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);	
}

struct node* findMinimum(struct node* cur)
{
	while(cur->left!=NULL)
	{
		cur=cur->left;
	}
	return cur;
}

struct node* insertion(struct node* root,int item)
{
	if(root==NULL)
		return create(item);
	if(item<root->data)
		root->left = insertion(root->left,item);
	else
		root->right = insertion(root->right,item);
		

	return root;				
}

//struct node* search(struct node* cur,int item,struct node* parent)
//{
//	while(cur!=NULL && cur->data!=item)
//	{
//		parent=cur;
//		
//		if(item<cur->data)
//			cur=cur->left;
//		else
//			cur=cur->right;	
//	}
//}

void deletion(struct node* root,int item)
{
	struct node *parent=NULL;
	struct node *cur=root;
	// searching
	while(cur!=NULL && cur->data!=item)
	{
		parent=cur;
		
		if(item<cur->data)
			cur=cur->left;
		else
			cur=cur->right;	
	}
	
	
	if(cur == NULL)
		return;
	
	if(cur->left==NULL && cur->right==NULL)
	{
		if(cur!=root)
		{
			if(parent->left == cur)
				parent->left=NULL;
			else
				parent->right=NULL;	
		}
		else
			root=NULL;
		free(cur);	
	}
	else if(cur->left && cur->right)
	{
		struct node *succ = findMinimum(cur->right);
		int val=succ->data;
		deletion(root,succ->data);
		cur->data=val;
	}
	else
	{
		struct node* child=(cur->left)? cur->left: cur->right;
		
		if(cur!=root)
		{
			if(cur==parent->left)
				parent->left=child;
			else
				parent->right=child;	
		}
		else
			root=child;
		free(cur);	
	}
}


int main()
{
	struct node *root=NULL;
	int i,keys[8];
	for(i=0;i<8;i++)
	{
		printf("Enter value to be inserted");
		scanf("%d",&keys[i]);
			root = insertion(root,keys[i]);
	}
	
	inorder(root);
	deletion(root,10);
	printf("\n");
	inorder(root);
}


