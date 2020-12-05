#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>
#include<time.h>
#include<conio.h>
typedef struct node
{
   int key;
   char *info;
   struct node *left;
   struct node *right;
   struct node *pr;
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
int insert(int key, char* info)
{
   node *tempNode = (node*) malloc(sizeof(node));
   node *current;
   node *parent;

   tempNode->key = key;
   tempNode->info=info;
   tempNode->pr=NULL;
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
      parent = NULL;
      while(1)
      {
        parent = current;
        if (key==parent->key) return 0;
        else if(key < parent->key)
        {
            current->pr=current;
            current = current->left;
            if(current == NULL)
            {
               parent->left= tempNode;
               tempNode->pr=parent;
               return 1;
            }
         }
         else
        {
            current->pr=current;
            current = current->right;
            if(current == NULL)
            {
               parent->right = tempNode;
               tempNode->pr=parent;
               return 1;
            }
         }
      }
   }
   return 1;
}
int checkKey(int key)
{
    node *current;
    current=root;
    while (current!=NULL)
    {
        if (current->key==key) return 0;
        if (current->key>key)
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
    int key;
    char *info;
    printf("Enter key: ");
    getInt(&key);
    if (checkKey(key)==0) printf ("Error! This key already exists!");
    else
    {
       printf("Enter info: ");
       info=getstring();
       scanf("%s",info);
       insert(key,info);
       printf("Added");
    }
    getch();
}
node* search(int key)
{
    node *current = root;
    while(current->key != key)
    {
      if(current->key > key)
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
    int key;
    node *temp;
    system("cls");
    printf("Find key: ");
    getInt(&key);
    temp = search(key);
    if (temp!=NULL)
    {
        printf("\tKey\tInfo\n");
        printf("\n\t%d\t%s ",temp->key,temp->info);
    }
    else printf("This key don't exist");
    getch();
}
void inorder_traversal(node* root)
 {
   if(root != NULL)
    {
      inorder_traversal(root->left);
      printf("\n\t%d\t%s ",root->key,root->info);
      inorder_traversal(root->right);
   }
}
void Show()
{
    system("cls");
    printf("\tKey\tInfo\n");
    inorder_traversal(root);
    getch();
}
node *find_remove(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->key == key) {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left != NULL && root->right != NULL)
        {

            node *successor = root->right;
            while (successor->left != NULL)
                successor = successor->left;

            root->key = successor->key;
            find_remove(root->right, successor->key);
            return root;
        }
        if (root->left != NULL)
            return root->left;
        else
            return root->right;
    }
    if (key > root->key)
        root->right = find_remove(root->right, key);
    else
        root->left = find_remove(root->left, key);
    return root;
}
void Delete()
{
    system("cls");
    int key;
    printf ("Enter Delete key: ");
    getInt(&key);
    if (checkKey(key)) printf ("This key does not exist");
    else
    {
        root=find_remove(root,key);
        printf("Deleted");
    }
    getch();
}
node* minnode(node* ptr)
{
    if (ptr==NULL) return NULL;
    else
    {
        while (ptr->left) ptr=ptr->left;
        return ptr;
    }
}
node* nextNode(node* temp)
{
    node* ptr;
    if (temp->right!=NULL)
    {
        ptr=minnode(temp->right);
    }
    else
    {
        ptr=temp->pr;
        while ((ptr!=NULL)&&(temp==ptr->right))
        {
            temp=ptr;
            ptr=temp->pr;
        }
    }
    return ptr;
}

node* maxnode(node* ptr)
{
    if (ptr==NULL) return NULL;
    else
    {
        while (ptr->right) ptr=ptr->right;
        return ptr;
    }
}
node* preNode(node* temp)
{
    node* ptr;
    if (temp->left!=NULL)
    {
        ptr=maxnode(temp->left);
    }
    else
    {
        ptr=temp->pr;
        while ((ptr!=NULL)&&(temp==ptr->left))
        {
            ptr=temp->pr;
            temp=ptr;

        }
    }
    return ptr;
}
void FindNode()
{
    int key,m,n;
    node *temp,*temp1,*temp2;
    system("cls");
    printf("Fine an element closest in value to a given key\n");
    printf("Enter key: ");
    getInt(&key);
    if (checkKey(key)) printf ("This key does not exist!");
    else
    {
        temp=search(key);
        temp1=nextNode(temp);
        temp2=preNode(temp);
        printf("\tKey\tInfo\n");
        if ((temp1==NULL)&&(temp2==NULL)) printf ("Can not find");
        else if (((temp1->key-key)>(temp2->key-key))||(temp1==NULL))
        printf("\t%d\t%s",temp2->key,temp2->info);
        else
        printf("\t%d\t%s",temp1->key,temp1->info);
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
		printf("\n 4. Show");
		printf("\n 5. Find the node with the closest key");
		printf("\n 6. Quit");
		printf("\n Your chose: ");
		getInt(&a);
		switch(a){
            case 1: Add(); break;
			case 2: Find(); break;
			case 3: Delete(); break;
			case 4: Show(); break;
			case 5: FindNode(); break;
			case 6: break;
			default : printf("Error! Repeat!\n");getch();break;
		}
	}while(a!=6);
	printf("----------------------------Good bye!--------------------------------");
	getch();
}
