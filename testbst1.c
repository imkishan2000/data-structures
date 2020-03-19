#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


// Both are My search functions
//void search(struct node *root,int item)
//{
//	bool flag=false;
//	if(root==NULL)
//	{
//		printf("tree is empty");
//		return;
//	}
//	else
//	{
//		while(root!=NULL)
//		{
//		if(item==root->data)
//		{
//			printf("item found");
//			flag=true;
//			return;
//		}
//		else if(item<root->data)
//			root=root->left;
//		else
//			root=root->right;	
//		}
//		if(!flag)
//			printf("Searched item not found");
//	}
//}

//bool search(struct node* root,int item,bool flag)
//{
//	if(root==NULL)
//		return;
//	else
//	{
//		if(item==root->data)
//		{
//			printf("Item found");
//			flag=true;
//		}
//		else if(item<root->data)
//		{
//			root=root->left;
//			flag=search(root,item,flag);
//		}
//		else if(item>root->data)
//		{
//			root=root->right;
//			flag=search(root,item,flag);
//		}
//	return flag;
//	}
//	
//}

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

struct node* insertion(struct node *root,int item)
{
	if(root==NULL)
		return create(item);
	if(item<root->data)
		root->left=insertion(root->left,item);
	else
		root->right=insertion(root->right,item);
		
	return root;			
}

//struct node* findMinimum(struct node)
//{
//	
//}

void delete(struct node* root,int item)
{
	if(root==NULL)
		return;
	
	struct node *parent=NULL;
	struct node *curr=root;
	
	while(curr!=NULL && curr->data!=item)
	{
		parent=curr;
		if(item<curr->data)
			curr=curr->left;
		else
			curr=curr->right;		
	}

	if(curr!=NULL && curr->left==NULL && curr->right==NULL)
	{
		if(parent->left==curr)
			parent->left=NULL;
		else
			parent->right=NULL;	
		printf("\n %d is deleted",curr->data);
		free(curr);
			
	}
	else if(curr!=NULL && curr->left && curr->right==NULL)
	{
		if(parent->left==curr)
			parent->left=curr->left;
		else
			parent->right=curr->left;
		printf("\n %d is deleted",curr->data);
		free(curr);	
					
	}	
	
		
}




int main()
{
	struct node *root=NULL;
	int i,keys[8];
//	bool z;
	
	for(i=0;i<8;i++)
	{
		printf("Enter the number to insert: ");
		scanf("%d",&keys[i]);
			root=insertion(root,keys[i]);
	}
	inorder(root);
	delete(root,25);
	inorder(root);
	
//	z=search(root,40,false);
//	if(z)
//		printf("\nitem found");
//	else
//		printf("item not found");	
//	search(root,40);
}
