#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
class student
{
    public:
        char *name;
        int age;
        int number;
        int score;

};
class teacher
{
    public:
        char *name;
        int number;
        int age;
};
class node
{
    private:
        student *info;
        node *next;
    public:
        node* create(student* g);
        student* create(node* head);
        void Insert(node*& head, student* g);
        void ShowFind(node* head);
        void Show(node* head);
        node* Find(node* phead,int x);
        void Delete(node*& head);

};
class node2
{
    private:
        teacher *info;
        node2 *next;
    public:
        node2* create2(teacher* g);
        teacher* create2(node2* head2);
        void Insert2(node2*& head2, teacher* g);
        void ShowFind2(node2* head2);
        void Show2(node2* head2);
        node2* Find2(node2* phead2,int x);
        void Delete2(node2*& head2);

};
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
node* node::create(student* g)
{
    node* p = new node;
    if (p == NULL)
        return 0;
    p->info = g;
    p->next = NULL;
    return p;
}
node2* node2::create2(teacher* g)
{
    node2* p = new node2;
    if (p == NULL)
        return 0;
    p->info = g;
    p->next = NULL;
    return p;
}
student* node::create(node *head)
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
teacher* node2::create2(node2 *head2)
{
    system("cls");
    teacher* st = new teacher;
    fflush(stdin);
    printf("Enter name of teacher: ");
    st->name=getstring();
    printf("Enter age: ");
    getInt(&st->age);
    printf ("Enter number of teacher:");
    while(1)
    {
        getInt(&st->number);
        if (Find2(head2,st->number)) printf ("Number was exist! Enter new number: ");
        else break;
    }
    return st;
}
void node:: Insert(node*& head, student* g)
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
    printf ("Added!");
    getch();
}
void node2:: Insert2(node2*& head2, teacher* g)
{
    node2* p = create2(g);
    if (head2 == NULL)
        head2 = p;
    else {
        node2* temp = head2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    printf ("Added!");
    getch();
}
void node:: Show(node* head)
{
    system("cls");
    printf ("%s\t\t%s\t%s\t\t%s\n","Name","Age","Number of student's record-book","Score of exam");
    for (node* p = head; p != NULL; p = p->next)
    {
        printf("%s\t\t%d\t%d\t\t\t\t\t%d\n", p->info->name,p->info->age,p->info->number,p->info->score);
    }
    getch();
}
void node2:: Show2(node2* head2)
{
    system("cls");
    printf ("%s\t%s\t%s\n","Name","Age","Number of teacher");
    for (node2* p = head2; p != NULL; p = p->next)
    {
        printf("%s\t%d\t%d\n", p->info->name,p->info->age,p->info->number);
    }
    getch();
}
node* node::Find(node* phead, int x)
{

    for (node* p = phead; p != NULL; p = p->next)
        if (p->info->number==x)
        {
            return p;
        }
    return NULL;
    getch();
}
node2* node2::Find2(node2* phead2, int x)
{

    for (node2* p = phead2; p != NULL; p = p->next)
        if (p->info->number==x)
        {
            return p;
        }
    return NULL;
    getch();
}
void node::Delete(node* &head)
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
    printf("This number of student don't exist!\n");
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
void node2::Delete2(node2* &head2)
{
    system("cls");
	node2 *p1=head2, *p2;
	int x;
    printf("Enter number of teacher: ");
    scanf("%d",&x);
	while((p1!= NULL) && (p1->info->number!=x))
    {
        p2 = p1;
        p1 = p1->next;
    }
    //p1=Find2(head2,x);
    if(p1 == NULL)
    printf("This number of teacher don't exist!\n");
    else
    {
        if(p1 == head2)
        head2 = p1->next;
        else
        p2->next = p1->next;
        free(p1);
        printf("Deleted!\n");
    }
    getch();
}
void node::ShowFind(node* phead)
{
    system("cls");
    int x;
    printf("Enter number of student: ");
    scanf("%d",&x);
    node *p=Find(phead,x);

    if (p==NULL)  printf ("This number of student don't exist!");
    else
    {
         printf ("%s\t\t%s\t%s\t\t%s\n","Name","Age","Number of student's record-book","Score of exam");
         printf("%s\t\t%d\t%d\t\t\t\t\t%d\n", p->info->name,p->info->age,p->info->number,p->info->score);
    }
    getch();
}
void node2::ShowFind2(node2* phead2)
{
    system("cls");
    int x;
    printf("Enter number of teacher: ");
    scanf("%d",&x);
    node2 *p=Find2(phead2,x);

    if (p==NULL)  printf ("This number of teacher don't exist!");
    else
    {
         printf ("%s\t%s\t%s\n","Name","Age","Number of teacher");
         printf("%s\t\t%d", p->info->name,p->info->age,p->info->number);
    }
    getch();
}
int main()
{
    int a,c;
    student* g;
    teacher*t;
    node T,*head=NULL;
    node2 T2,*head2=NULL;
    do{
        system("cls");
        printf ("Type of Elements \n");
        printf ("1. Student\n");
        printf ("2. Teacher\n");
        getInt(&c);
    }while (c!=2&&c!=1);
    do {
        system("cls");
        printf("\n------------------MENU---------------------------\n");
        printf("0. Quit\n");
        printf("1. Add \n");
        printf("2. Show\n");
        printf("3. Find\n");
        printf("4. Delete\n");
        printf ("Your chose:");
        getInt(&a);
        if (c==1)
         {
            switch (a)
            {
                case 1:
                {
                    g = T.create(head);
                    T.Insert(head,g);
                    break;
                }
                case 2: T.Show(head);break;
                case 3: T.ShowFind(head);break;
                case 4: T.Delete(head);break;
                case 0:break;
            }
        }
       if (c==2)
        {
            switch (a)
            {
                case 1:
                {
                    t = T2.create2(head2);
                    T2.Insert2(head2,t);
                    break;
                }
                case 2: T2.Show2(head2);break;
                case 3: T2.ShowFind2(head2);break;
                case 4: T2.Delete2(head2);break;
                case 0:break;
            }

        }
    } while (a!=0);

    printf ("----------------------------------------That's all--------------------------------------");
    getch();
    return 0;
}
