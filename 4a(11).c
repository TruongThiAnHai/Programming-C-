#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>
const int size=10;
typedef struct Item
{
    int key,n;
    int release;
    char *info;
}Item;
typedef struct Table
{
    int n;
    Item item[10];
}Table;
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

void Add(Table* table)
{
    int n,j;
    system("cls");
    char *info;
    n=table->n;
    if (table->n==size)
    {
        printf("\nTable overflow, can't add item");
    }
    else
    {
        printf ("\nEnter key:");
        getInt(&table->item[n].key);
        printf ("Enter info:");
        info=getstring();
        scanf("%s",info);
        table->item[n].info=info;
        table->item[n].release=count(table->item[n].key, table);
        table->n++;
        printf("This item was added");
    }
    getch();

}
int count(int key,Table* table)
{
    int i,j=1;
	for (i=1;i<table->n;i++)
    {
        if (key==table->item[i].key)
        {
           j++;
        }
    }
    return j;
}
void Find_key (Table* table)
{

    int k,j,i,r,m;
    system("cls");
    printf ("Find key=");
    getInt(&k);
    j=count(k,table);
    if (j==1) printf ("This key don't exist");
    else
    {
        printf("\nKey\tRelease\t\tInfo\n");
        for (i=1;i<(table- fd=fopen(fname,"r+b");>n);i++)
        {
            if (table->item[i].key==k)
            {
                m=table->item[i].key;
                r=table->item[i].release;
                printf ("\n%d\t%d\t\t%s",m,r,table->item[i].info);
            }

        }
    }

    getch();
}
void Find_release (Table* table)
{

    int k,j,i,r,m;
    system("cls");
    printf ("Find release=");
    getInt(&k);
    printf("\nKey\tRelease\t\tInfo\n");
    for (i=1;i<(table->n);i++)
    {
        if (table->item[i].release==k)
        {
            m=table->item[i].key;
            r=table->item[i].release;
            printf ("\n%d\t%d\t\t%s",m,r,table->item[i].info);
        }

    }
    getch();
}
void Find (Table *table)
{
    system("cls");
    int i,n;
    printf("Find by:\n");
    printf ("1. Key\n");
    printf ("2. Release\n");
    printf("\n Your chose: ");
    getInt(&n);
    switch(n)
    {
            case 1: Find_key(table); break;
			case 2: Find_release(table); break;
			default : printf("Error! Repeat!\n");getch();break;
    }
}
void Delete(Table* table)
{
    system("cls");
    int i=0,j=table->n,k;
    Item ch;
    while(i < j)
    {
      ch = table->item[j];
      table->item[j] = table->item[i];
      table->item[i] = ch;
      i++;
      j--;
   }
   for (i = 2; i <table->n; i++)
	{
		for (j =1; j < i; j++)
		{
			if (table->item[i].key == table->item[j].key)
			{
				for (k = i; k < table->n; k++)
				{
					table->item[k] = table->item[k+1];
					table->n--;
					i--;
				}
			}
		}
	}
	printf("\n\t\tTable is cleaned");
	getch();

}
void Show(Table* table)
{
    int i;
    int k,r;
    char *ch;
	system("cls");
	printf("\nKey\tRelease\t\tInfo\n");
	for (i=1;i<(table->n);i++)
    {
        ch=table->item[i].info;
        k=table->item[i].key;
        r=table->item[i].release;
        printf ("\n%d\t%d\t\t%s",k,r,ch);
    }
    getch();
}
void main()
{
	int a;
	Table *table;
	table=(Table*)malloc(sizeof(Table));
	table->n=1;
	do{
        system("cls");
		printf("\t\tMENU:\n");
		printf("\n 1. Add");
		printf("\n 2. Find");
		printf("\n 3. Delete");
		printf("\n 4. Show");
		printf("\n 5. Quit");
		printf("\n Your chose: ");
		getInt(&a);
		switch(a){
            case 1: Add(table); break;
			case 2: Find(table); break;
			case 3: Delete(table); break;
			case 4: Show(table); break;
			case 5: break;
			default : printf("Error! Repeat!\n");getch();break;
		}
	}while(a!=5);
	printf("----------------------------Good bye!--------------------------------");
	getch();
}
