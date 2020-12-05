#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
typedef struct student
{
    char *name;
    int age;
    int number;
    int score;
} student;
typedef struct teacher
{
    char *name;
    int number;
} teacher;
typedef struct node
{
    student* info;
    struct node* next;
}node;
typedef struct node2
{
    teacher* info;
    struct node* next;
}node2;
node* head=NULL;
node2* head2=NULL;
node* Find(node* phead, int x);
int getInt(int* a)
{
    int n;
    do {
        n=scanf("%d",a);
        if (n==0)
        {
            printf ("Error");
            scanf ("%*[^\n]");
            n=0;
        }

    }while (n==0);
    return 1;
}
char *getstring()
{
	int n, l;
	char buf[80];
	char *str = NULL, *p;
	str = (char *)malloc(sizeof(char));
	if (str == NULL) return NULL;
    strcpy(str,"");
	do{
		n = scanf("%79[^\n]",buf);
		if (n == -1)
        {
            free(str);
            return NULL;
        }
		if (n == 0) scanf("%*c");
        else
        {
            l = strlen(buf)+strlen(str)+1;
            p = (char *)realloc(str,l);
            if (p == NULL)
            {
                free(str); return NULL;
            }
            str = p;
            strcat(str, buf);
        }
       }while(n!=0);
	return str;
}

node* create(student* g)
{
    node* p = new node;
    if (p == NULL)
        return 0;
    p->info = g;
    p->next = NULL;
    return p;
}
student* create()
{
    system("cls");
    student* st = new student;
    fflush(stdin);
    printf("Enter name of student: ");
    st->name=getstring();
    printf("Enter age: ");
    getInt(&st->age);
    printf("Enter score of exam:  ");
    getInt(&st->score);
    printf ("Enter number of student's record-book:");
    while(1)
    {
        getInt(&st->number);
        if (Find(head,st->number)) printf ("Number was exist! Enter new number: ");
        else break;
    }
    return st;
}

void Insert(node*& head, student* g)
{
    node* p = create(g);
    if (head == NULL)
        head = p;
    else {
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    printf ("Added");
    getch();
}

void Show(node* head)
{
    system("cls");
    printf ("%s\t\t%s\t%s\t\t%s\n","Name","Age","Number of student's record-book","Score of exam");
    for (node* p = head; p != NULL; p = p->next)
    {
        printf("%s\t\t%d\t%d\t\t\t\t\t%d\n", p->info->name,p->info->age,p->info->number,p->info->score);
    }
    getch();
}

node* Find(node* phead, int x)
{

    for (node* p = phead; p != NULL; p = p->next)
        if (p->info->number==x)
        {
            return p;
        }
    return NULL;
    getch();
}

void Delete(node* &head)
{
    system("cls");
	node *p1=head, *p2;
	int x;
    printf("Enter number of student: ");
    scanf("%d",&x);
	while((p1!= NULL) && (p1->info->number!=x))
    {
        p2 = p1;
        p1 = p1->next;
    }
    //p1=Find(head,x);
    if(p1 == NULL)
    printf("This name of student don't exist!\n");
    else
    {
        if(p1 == head)
        head = p1->next;
        else
        p2->next = p1->next;
        free(p1);
        printf("Deleted!\n");
    }
    getch();
}
void ShowFind(node* phead)
{
    system("cls");
    int x;
    printf("Enter number of student: ");
    scanf("%d",&x);
    node *p=Find(phead,x);

    if (p==NULL)  printf ("This name of student don't exist!");
    else
    {
         printf ("%s\t\t%s\t%s\t\t%s\n","Name","Age","Number of student's record-book","Score of exam");
         printf("%s\t\t%d\t%d\t\t\t\t\t%d\n", p->info->name,p->info->age,p->info->number,p->info->score);
    }
    getch();
}
int main()
{
    int a;
    student* g;
    do {
        system("cls");
        printf("\n------------------MENU---------------------------\n");
        printf("0. Quit\n");
        printf("1. Add student\n");
        printf("2. Show\n");
        printf("3. Find\n");
        printf("4. Delete\n");
        printf ("Your chose:");
        getInt(&a);
        switch (a)
         {
            case 1:
            {
                g = create();
                Insert(head,g);
                break;
            }
            case 2: Show(head);break;
            case 3: ShowFind(head);break;
            case 4: Delete(head);break;
            case 0:break;
        };
    } while (a!=0);

    printf ("----------------------------------------That's all--------------------------------------");
    getch();
    return 0;
}
