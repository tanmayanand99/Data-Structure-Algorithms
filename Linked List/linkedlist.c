#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodes;
int main()
{
    nodes *p=NULL,*left=NULL,*right=NULL,*k=NULL;
    int n,ans;
    do{
        scanf("%d",&n);
        p=(nodes *)malloc(sizeof(nodes));
        if(p!=NULL)
        {
            p->data=n;
            if(left==NULL)
            {
                left=right=p;
            }
            else
            {
                right->next=p;
                right=p;
            }
            right->next=NULL;            
        }
        printf("Do you want to continue(1/0)?");
        scanf("%d",&ans);

    }while (ans==1);

    printf("Linked List is\n");
    p=left;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

    do{
        p=(nodes *)malloc(sizeof(nodes));
        scanf("%d",&p->data);

        p->next=left;
        left=p;
        printf("Do you want to continue and want ot insert elements at the beginning??");
        scanf("%d",&ans);
    }while(ans==1);
    p=left;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}