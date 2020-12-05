#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
class student
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
        student info;
        node *left;
        node *right;
        node *parent;
    public:
        int Insert(int number, char* name, int age, int score);
        int checkNumber(int number);
        void Add();
        node* Search(int number);
        void Find();
        void  LNR(node* root);
        void  NLR(node* root);
        void Show();
        void Show2();
        node* find_remove(node *root, int number);
        void Delete();

};
node *root=NULL;
class teacher
{
    public:
        char *name;
        int age;
        int number;
        int workdays;

};
class node2
{
    private:
        teacher info;
        node2 *left;
        node2 *right;
        node2 *parent;
    public:
        int Insert(int number, char* name, int age, int score);
        int checkNumber(int number);
        void Add();
        node2* Search(int number);
        void Find();
        void  LNR(node2* root);
        void  NLR(node2* root);
        void Show();
        void Show2();
        node2* find_remove(node2 *root, int number);
        void Delete();

};
node2 *root2=NULL;
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
int node::Insert(int number, char* name, int age, int score)
{
   node *tempNode = (node*) malloc(sizeof(node));
   node *current;
   node *pr;

   tempNode->info.number = number;
   tempNode->info.name=name;
   tempNode->info.age=age;
   tempNode->info.score=score;
   tempNode->parent=NULL;
   tempNode->left= NULL;
   tempNode->right= NULL;
   if(root == NULL)
    {
        root = tempNode;
        return 1;
    }
   else
    {
      current = root;
      pr = NULL;
      while(1)
      {
        pr = current;
        if (number==pr->info.number) return 0;
        else if(number < pr->info.number)
        {
            current->parent=current;
            current = current->left;
            if(current == NULL)
            {
               pr->left= tempNode;
               tempNode->parent=pr;
               return 1;
            }
         }
         else
        {
            current->parent=current;
            current = current->right;
            if(current == NULL)
            {
               pr->right = tempNode;
               tempNode->parent=pr;
               return 1;
            }
         }
      }
   }
   return 1;
}
int node2::Insert(int number, char* name, int age, int workdays)
{
   node2 *tempNode = (node2*) malloc(sizeof(node2));
   node2 *current;
   node2 *pr;

   tempNode->info.number = number;
   tempNode->info.name=name;
   tempNode->info.age=age;
   tempNode->info.workdays=workdays;
   tempNode->parent=NULL;
   tempNode->left= NULL;
   tempNode->right= NULL;
   if(root2 == NULL)
    {
        root2 = tempNode;
        return 1;
    }
   else
    {
      current = root2;
      pr = NULL;
      while(1)
      {
        pr = current;
        if (number==pr->info.number) return 0;
        else if(number < pr->info.number)
        {
            current->parent=current;
            current = current->left;
            if(current == NULL)
            {
               pr->left= tempNode;
               tempNode->parent=pr;
               return 1;
            }
         }
         else
        {
            current->parent=current;
            current = current->right;
            if(current == NULL)
            {
               pr->right = tempNode;
               tempNode->parent=pr;
               return 1;
            }
         }
      }
   }
   return 1;
}
int node::checkNumber(int number)
{
    node *current;
    current=root;
    while (current!=NULL)
    {
        if (current->info.number==number) return 0;
        if (current->info.number>number)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }
    return 1;
}
int node2::checkNumber(int number)
{
    node2 *current;
    current=root2;
    while (current!=NULL)
    {
        if (current->info.number==number) return 0;
        if (current->info.number>number)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }
    return 1;
}
void node::Add()
{
    system("cls");
    int number,age,score;
    char *name;
    printf("Enter number of student: ");
    getInt(&number);
    if (checkNumber(number)==0) printf ("Error! This number already exists!");
    else
    {
        fflush(stdin);
        printf("Enter name of student: ");
        name=getstring();
        printf("Enter age: ");
        getInt(&age);
        printf("Enter score of exam:  ");
        getInt(&score);
       Insert(number,name,age,score);
       printf("Added");
    }
    getch();
}
void node2::Add()
{
    system("cls");
    int number,age,workdays;
    char *name;
    printf("Enter number of teacher: ");
    getInt(&number);
    if (checkNumber(number)==0) printf ("Error! This number already exists!");
    else
    {
        fflush(stdin);
        printf("Enter name of teacher: ");
        name=getstring();
        printf("Enter age: ");
        getInt(&age);
        printf("Enter workdays:  ");
        getInt(&workdays);
       Insert(number,name,age,workdays);
       printf("Added");
    }
    getch();
}
node* node::Search(int number)
{
    node *current = root;
    while(current->info.number != number)
    {
      if(current->info.number > number)
      {
         current = current->left;
      }
      else
      {
         current = current->right;
      }
      if(current == NULL)
      {
         return NULL;
      }
   }

   return current;
}
node2* node2::Search(int number)
{
    node2 *current = root2;
    while(current->info.number != number)
    {
      if(current->info.number > number)
      {
         current = current->left;
      }
      else
      {
         current = current->right;
      }
      if(current == NULL)
      {
         return NULL;
      }
   }

   return current;
}
void node:: Find()
{
    int number;
    node *temp;
    system("cls");
    printf("Find number: ");
    getInt(&number);
    temp = Search(number);
    if (temp!=NULL)
    {
        printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
        printf("\t%d\t%s\t\t%d\t%d\n ",temp->info.number,temp->info.name,temp->info.age,temp->info.score);
    }
    else printf("This number don't exist");
    getch();
}
void node2:: Find()
{
    int number;
    node2 *temp;
    system("cls");
    printf("Find number: ");
    getInt(&number);
    temp = Search(number);
    if (temp!=NULL)
    {
        printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Workdays");
        printf("\t%d\t%s\t\t%d\t%d\n ",temp->info.number,temp->info.name,temp->info.age,temp->info.workdays);
    }
    else printf("This number don't exist");
    getch();
}

void node:: LNR(node* root)//Left->Root->Right
{
   if(root != NULL)
    {

      LNR(root->left);
      printf("\t%d\t%s\t\t%d\t%d\n ",root->info.number,root->info.name,root->info.age,root->info.score);
      LNR(root->right);
   }
}
void node::NLR(node* root)//Root->left->Right
{
   if(root!=NULL)
   {
      printf("\t%d\t%s\t\t%d\t%d\n ",root->info.number,root->info.name,root->info.age,root->info.score);
      NLR(root->left);
      NLR(root->right);
   }
}
void node:: Show()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
    LNR(root);
    getch();
}
void node::Show2()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
    NLR(root);
    getch();
}
void node2:: LNR(node2* root)//Left->Root->Right
{
   if(root != NULL)
    {

      LNR(root->left);
      printf("\t%d\t%s\t\t%d\t%d\n ",root->info.number,root->info.name,root->info.age,root->info.workdays);
      LNR(root->right);
   }
}
void node2::NLR(node2* root)//Root->left->Right
{
   if(root!=NULL)
   {
      printf("\t%d\t%s\t\t%d\t%d\n ",root->info.number,root->info.name,root->info.age,root->info.workdays);
      NLR(root->left);
      NLR(root->right);
   }
}
void node2:: Show()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Workdays");
    LNR(root2);
    getch();
}
void node2::Show2()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Workdays");
    NLR(root2);
    getch();
}
node* node::find_remove(node *root, int number)
{
    if (root == NULL)
        return NULL;
    if (root->info.number == number)
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left != NULL && root->right != NULL)
        {

            node *successor = root->right;
            while (successor->left != NULL)
            successor = successor->left;

            root->info.number = successor->info.number;
            find_remove(root->right, successor->info.number);
            return root;
        }
        if (root->left != NULL)
            return root->left;
        else
            return root->right;
    }
    if (number > root->info.number)
        root->right = find_remove(root->right, number);
    else
        root->left = find_remove(root->left, number);
    return root;
}
void node::Delete()
{
    system("cls");
    int number;
    printf ("Enter number of student you want to delete: ");
    getInt(&number);
    if (checkNumber(number)) printf ("This number does not exist");
    else
    {
        root=find_remove(root,number);
        printf("Deleted");
    }
    getch();
}
node2* node2::find_remove(node2 *root, int number)
{
    if (root == NULL)
        return NULL;
    if (root->info.number == number)
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left != NULL && root->right != NULL)
        {

            node2 *successor = root->right;
            while (successor->left != NULL)
            successor = successor->left;

            root->info.number = successor->info.number;
            find_remove(root->right, successor->info.number);
            return root;
        }
        if (root->left != NULL)
            return root->left;
        else
            return root->right;
    }
    if (number > root->info.number)
        root->right = find_remove(root->right, number);
    else
        root->left = find_remove(root->left, number);
    return root;
}
void node2::Delete()
{
    system("cls");
    int number;
    printf ("Enter number of teacher you want to delete: ");
    getInt(&number);
    if (checkNumber(number)) printf ("This number does not exist");
    else
    {
        root2=find_remove(root2,number);
        printf("Deleted");
    }
    getch();
}
int main()
{
	int a,c;
	node T;
	node2 T2;
	do{
        system("cls");
        printf ("Type of Elements \n");
        printf ("1. Student\n");
        printf ("2. Teacher\n");
        getInt(&c);
    }while (c!=2&&c!=1);
	do{
        system("cls");
		printf("\t\tMENU:\n");
		printf("\n 0. Quit");
		printf("\n 1. Add");
		printf("\n 2. Find");
		printf("\n 3. Delete");
		printf("\n 4. Show(Left->Root->Right)");
		printf("\n 5. Show(Root->Left->Right)");

		printf("\n Your chose: ");
		getInt(&a);
		if (c==1)
        {
            switch(a)
            {
                case 1: T.Add(); break;
                case 2: T.Find(); break;
                case 3: T.Delete(); break;
                case 4: T.Show(); break;
                case 5: T.Show2();break;
                case 0: break;
                default : printf("Error! Repeat!\n");getch();break;
            }
        }
        else
        {
            switch(a)
            {
                case 1: T2.Add(); break;
                case 2: T2.Find(); break;
                case 3: T2.Delete(); break;
                case 4: T2.Show(); break;
                case 5: T2.Show2();break;
                case 0: break;
                default : printf("Error! Repeat!\n");getch();break;
            }

        }

	}while(a!=0);
	printf("----------------------------Good bye!--------------------------------");
	getch();
	return 0;
}

