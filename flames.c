#include<stdio.h>
#include<string.h>
struct node{
    char ch;
    struct node*next;
};
void removespaces(char *str)
{
    int j=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}
int main()
{
    int l1,l2,max,i,min,j,count=0,number;
    char name1[20],name2[20],rel;
    printf("enter 1st name\n");
    fgets(name1,20,stdin);
    name1[strcspn(name1,"\n")]='\0';
    removespaces(name1);
    l1=strlen(name1);
    printf("enter 2nd name\n");
    fgets(name2,20,stdin);
    name2[strcspn(name2,"\n")]='\0';
    removespaces(name2);
    l2=strlen(name2);
    if(l1>l2)
    {
    max=l1;
    min=l2;
    }
    else
    {
    max=l2;
    min=l1;
    }
    for(i=0;i<min;i++)
    {
        for(j=0;j<max;j++)
        {
            if(name1[i]==name2[j])
            {
                count++;
                name1[i]='*';
                name2[j]='*';
                break;
            }
        }
    }
    number=l1+l2-2*count;
    struct node f,l,a,m,e,s;
    f.next=&l;
    f.ch='f';
    l.next=&a;
    l.ch='l';
    a.next=&m;
    a.ch='a';
    m.next=&e;
    m.ch='m';
    e.next=&s;
    e.ch='e';
    s.next=&f;
    s.ch='s';
    struct node *prev,*p=&f,*r;
    while(p->next!=p)
    {
        for(i=0;i<number;i++)
        {
            if(i==number-1)
            {
                r=p->next;
                prev->next=r;
                p->next=NULL;
                p=r;
                
            }
            else
            {
                prev=p;
                p=p->next;
            }
        }
        rel=p->ch;
    }
    if(rel=='f')
        printf("You are nice friends  :)\n");
        else if(rel=='l')
        printf("You are great lovers \n");
        else if(rel=='a')
        printf("You have an affair ;)\n");
        else if(rel=='m')
            printf("You will marry your lover soon!");
       else if(rel=='e')
        printf("You both are enemies\n");
        else
        printf("You both are siblings\n");
    return 0;
}