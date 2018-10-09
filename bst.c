#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *CreateBST(struct node *, int);
void Inorder(struct node *);
void Preorder(struct node *);
void Postorder(struct node *);

struct node* search(struct node *root,int no){

   struct node *current = root;
   printf("Visited elements: \n");
	
   while(current->data != no){
	
      if(current != NULL) {
         printf("%d ",current->data);
			
         //go to left tree
         if(current->data > no){
            current = current->left;
         }//else go to right tree
         else {                
            current = current->right;
         }
			
         //not found
         if(current == NULL){
            return NULL;
         }
      }			
   }
   return current;
}

/*
struct node* delete(struct node* node, struct node* pnode, int target)
{
    struct node* rchild;
    struct node* rchildparent;
    if(node==NULL)
    {
        return(pnode);
    }
    else
    {
        if(target == node->data)
        {
            if(node->left == NULL && node->right == NULL) //leaf node
            {
                if(pnode == NULL) //special case deleting the root node
                {
                    free(node);
                    return(NULL);
                }
                if(pnode->left == node)
                {
                    pnode->left = NULL;
                }
                else
                {
                    pnode->right = NULL;
                }
                free(node);
                return(pnode);
            }
            if(node->left ==NULL ) //one child
            {
                if(pnode == NULL) //deleting root having no left child
                {
                    struct node* temp = node;
                    node = node->right;
                    free(temp);
                    return(node);
                }
                if(pnode->left == node)
                {
                    pnode->left = node->right;
                }
                else
                {
                    pnode->right = node->right;
                }   
                free(node);
                return(pnode);
            }
            if(node->right ==NULL ) //one child
            {
                if(pnode == NULL) //deleting root having no right child
                {
                    struct node* temp = node;
                    node = node->left;
                    free(temp);
                    return(node);
                }
                if(pnode->left == node)
                {
                    pnode->left = node->left;
                }
                else
                {
                    pnode->right = node->left;
                }   
                free(node);
                return(pnode);
            }

            //two children case
            rchild = node->right;
            rchildparent=node;
            while(rchild->left != NULL)
            {
                rchildparent=rchild;
                rchild = rchild->left;
            }
            node->data=rchild->data;
            if(rchildparent == node)
            {
                //rchildparent->right=rchild->right;
                node->right=rchild->right;
            }
            else
            {
                //rchildparent->left=NULL;
                rchildparent->left=rchild->right;
            }
            free(rchild);
            if(pnode ==NULL) //root node
            {
                return(node);
            }           
            return(pnode);
        }
        else
        {
            if(target < node->data)
            {
                delete(node->left,node,target);
                return(node);
            }
            else
            {
                delete(node->right,node,target);
                return(node);
            }
        }

    }

}
struct node* delete(struct node *root,int no){

   struct node *current = root;
   printf("Visited elements: \n");
	
   while(current->data != no){
	
      if(current != NULL) {
         printf("%d ",current->data);
			
         //go to left tree
         if(current->data > no){
            current = current->left;
            free(current);
         }//else go to right tree
         else {                
            current = current->right;
         free(current);
		 }
         
			
         //not found
         if(current == NULL){
            return NULL;
         }
      }			
   }
   return current;
}
*/

int main()
{
    struct node *root = NULL;
    int choice, item, n, i,no;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Search");
        printf("\n6. Delete");
        printf("\n7. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root = NULL;
            printf("\n\nBST for How Many Nodes ? ");
            scanf("%d",&n);
            for(i = 1; i <= n; i++)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d",&item);
                root = CreateBST(root,item);
            }
            printf("\nBST with %d nodes is ready to Use!!\n", n);
            break;
        case 2:
            printf("\nBST Traversal in INORDER \n");
            Inorder(root);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            Preorder(root);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            Postorder(root);
            break;
        case 5:
            printf("\nEnter the elementt to be Searched : \n");
            scanf("%d",&no);
             root=search(root,no);
             if(root!=NULL)
             printf("The Search Element is :%d",no);
             else
             printf("\nThe %d Not Found.......!!Sorry Bro",no);
            break;
            
        case 6:
            printf("\nEnter the elementt to beDeleted : \n");
            scanf("%d",&no);
       //      root=delete(root,no);
             if(root!=NULL)
             {
			 printf("The Deleted Element is :%d",no);
             
         }
			 else
             printf("\nThe %d Not Found.......!!Sorry Bro",no);
            break;
            
            
            
        case 7:
            printf("\n\n Terminating \n\n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while(choice != 5);
    return 0;
}
struct node *CreateBST(struct node *root, int item)
{
    if(root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");

        return(root);
    }
}

void Inorder(struct node *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}
