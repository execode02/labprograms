#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST * NODE;
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct BST));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
void insert(NODE root,NODE newnode)
{
    if(newnode->data<root->data)
    {
        if(root->lchild==NULL)
            root->lchild=newnode;
        else
            insert(root->lchild,newnode);
    }
    if(newnode->data>root->data)
    {
        if(root->rchild==NULL)
            root->rchild=newnode;
        else
            insert(root->rchild,newnode);
    }
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}
void search(NODE root,int key)
{
    NODE cur;
    if(root==NULL)
    {
        printf("BST is empty!!!");
        return;
    }
    cur=root;
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            printf("\nKey element %d is present in BST",cur->data);
            return;
        }
        if(key<cur->data)
            cur=cur->lchild;
        else
            cur=cur->rchild;
    }
    printf("Key element %d is not found in BST",key);
}
void main()
{
    int ch,key,val,ans;
    NODE root=NULL,newnode;
    while(1)
    {
        printf("\n________BST MENU__________\n1.create a BST\n2.BST traversal\n3.search\n4.exit\n________________________\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                newnode=getnode();
                printf("Enter the value:");
                scanf("%d",&val);
                newnode->data=val;
                if(root==NULL)
                    root=newnode;
                else
                    insert(root,newnode);
                printf("\npress 1 to insert next node:");
                scanf("%d",&ans);
            }
            while(ans==1);
            break;
        case 2:
            if(root==NULL)
                printf("\nTree is not created!!!");
            else
            {
                printf("\nPreorder display:\n");
                preorder(root);
                printf("\nInorder display:\n");
                inorder(root);
                printf("\nPostorder display:\n");
                postorder(root);
            }
            break;
        case 3:
            printf("Enter element to be searched:");
            scanf("%d",&key);
            search(root,key);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input!!!");
            break;
        }
    }
}
