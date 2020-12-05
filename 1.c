#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>
#include<conio.h>
typedef struct node
{
   int number;
   char *name;
   int age;
   int score;
   struct node *left;
   struct node *right;
   struct node *parent;
}node;
node *root = NULL;
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
int insert(int number, char* name, int age, int score)
{
   node *tempNode = (node*) malloc(sizeof(node));
   node *current;
   node *pr;

   tempNode->number = number;
   tempNode->name=name;
   tempNode->age=age;
   tempNode->score=score;
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
        if (number==pr->number) return 0;
        else if(number < pr->number)
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
int checkNumber(int number)
{
    node *current;
    current=root;
    while (current!=NULL)
    {
        if (current->number==number) return 0;
        if (current->number>number)
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
void Add()
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
       insert(number,name,age,score);
       printf("Added");
    }
    getch();
}
node* search(int number)
{
    node *current = root;
    while(current->number != number)
    {
      if(current->number > number)
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
void Find()
{
    int number;
    node *temp;
    system("cls");
    printf("Find number: ");
    getInt(&number);
    temp = search(number);
    if (temp!=NULL)
    {
        printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
        printf("\t%d\t%s\t\t%d\t%d\n ",temp->number,temp->name,temp->age,temp->score);
    }
    else printf("This number don't exist");
    getch();
}
void inorder_traversal(node* root)
 {
   if(root != NULL)
    {
      inorder_traversal(root->left);
      printf("\t%d\t%s\t\t%d\t%d\n ",root->number,root->name,root->age,root->score);
      inorder_traversal(root->right);
   }
}
void pre_order_traversal(node* root)
{
   if(root != NULL)
    {

      pre_order_traversal(root->left);
      printf("\t%d\t%s\t\t%d\t%d\n ",root->number,root->name,root->age,root->score);
      pre_order_traversal(root->right);
   }
}
void NLR(node* root)//Node->left->Right
{
   if(root!=NULL)
   {
      printf("\t%d\t%s\t\t%d\t%d\n ",root->number,root->name,root->age,root->score);
      NLR(root->left);
      NLR(root->right);
   }
}
void Show()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
    inorder_traversal(root);
    getch();
}
void Show2()
{
    system("cls");
    printf("\t%s\t%s\t\t%s\t%s\n","Number","Name","Age","Score");
    NLR(root);
    getch();
}
node *find_remove(node *root, int number)
{
    if (root == NULL)
        return NULL;
    if (root->number == number)
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left != NULL && root->right != NULL)
        {

            node *successor = root->right;
            while (successor->left != NULL)
            successor = successor->left;

            root->number = successor->number;
            find_remove(root->right, successor->number);
            return root;
        }
        if (root->left != NULL)
            return root->left;
        else
            return root->right;
    }
    if (number > root->number)
        root->right = find_remove(root->right, number);
    else
        root->left = find_remove(root->left, number);
    return root;
}
void Delete()
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
void main()
{
	int a;
	do{
        system("cls");
		printf("\t\tMENU:\n");
		printf("\n 1. Add");
		printf("\n 2. Find");
		printf("\n 3. Delete");
		printf("\n 4. Show(Left->Root->Right)");
		printf("\n 5. Show(Root->Left->Right)");
		printf("\n 6. Quit");
		printf("\n Your chose: ");
		getInt(&a);
		switch(a){
            case 1: Add(); break;
			case 2: Find(); break;
			case 3: Delete(); break;
			case 4: Show(); break;
			case 5: Show2();break;
			case 6: break;
			default : printf("Error! Repeat!\n");getch();break;
		}
	}while(a!=6);
	printf("----------------------------Good bye!--------------------------------");
	getch();
}
