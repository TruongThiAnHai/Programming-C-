#include<iostream>
#include<string>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
class Student
{
    public:
        char *name;
        int age;
        int number;
        int score;

};
class node
{
    private:
        Student *info;
        node *next;
    public:
        node* create(student* g);
        student* create();
        void Insert(node*& head, student* g);
        void Show(node* head);
        void Find(node* phead);
        void Delete(node* head);

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
student* node::create()
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
    getInt(&st->number);
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
    printf ("Added");
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
void node:: Find(node* phead)
{
    system("cls");
    char *x;
    int i=0;
    printf("Enter name of student: ");
    fflush(stdin);
    x=getstring();
    for (node* p = phead; p != NULL; p = p->next)
        if ((strcmp(p->info->name, x) == 0))
        {
            printf ("%s\t\t%s\t%s\t\t%s\n","Name","Age","Number of student's record-book","Score of exam");
            printf("%s\t\t%d\t%d\t\t\t\t\t%d\n", p->info->name,p->info->age,p->info->number,p->info->score);
            i=1;
            break;
        }
    if (i==0) printf ("This name of student don't exist!");
    getch();
}
void node:: Delete(node* head)
{
    system("cls");
	node *p1, *p2;
	char *name;
	printf("Enter name of student you want to delete: ");
	fflush(stdin);
	name=getstring();
	p1 = head;
	while((p1!= NULL) && (strcmpi(p1->info->name,name)))
    {
		p2 = p1;
		p1 = p1->next;
	}
	if(p1 == NULL)
		printf("This name of student don't exist!\n");
	else{
		if(p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		free(p1);
		printf("Deleted!\n");
	}
	getch();
}
int main()
{
    int a;
    student* g;
    node T;
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
                g = T.create();
                T.Insert(head,g);
                break;
            }
            case 2: T.Show(head);break;
            case 3: T.Find(head);break;
            case 4: T.Delete(head);break;
            case 0:break;
        };
    } while (a!=0);

    printf ("----------------------------------------That's all--------------------------------------");
    getch();
    return 0;
}
