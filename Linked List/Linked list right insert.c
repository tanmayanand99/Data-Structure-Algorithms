#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodes;
void print(struct node* head)
 {
   if(head == NULL)
     return;
    print(head->next);
   printf("%d",head->data);
}
int main()
{
    nodes *left=NULL,*right=NULL,*p=NULL;
    int n,ch;

    do
    {
        printf("Enter the number which you want to add to linked list\n");
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

        printf("Do you want to continue\n");
        scanf("%d",&ch);
    } while (ch==1);
    print(p);

    printf("dgdddddddddElements of linked list are\n");
    p=left;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}