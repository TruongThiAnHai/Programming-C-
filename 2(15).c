#include <stdio.h>
#include <conio.h>
#include<malloc.h>
int i,j,k;
int getInt1(int* a)
{
    int n;
    do {
        n=scanf("%d",a);
        if (n==0 || (*a<=0) )
        {
            printf ("Error");
            scanf ("%*[^\n]");
            n=0;
        }

    }while (n==0);
    return 1;
}
int getInt (int* a)
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
        if (n<0) return 0;

    }while (n==0);
    return 1;
}
typedef  struct Line
{
    int m;//количество элементов в строке
    int *element;//массив элементов
} Line;
typedef struct Matrix
{
    int lines;//количество строк
    Line *n;//массиив строк
} Matrix;
void input_matrix(Matrix *rm)
{
    int a;
    int *p;
    printf ("How many lines? lines=");
    getInt1(&a);
    rm->lines = a;
    rm->n=(Line*)malloc(a*sizeof(Line));
    for (i=0;i<rm->lines;i++)
    {
        printf ("\n--------------------------------------------------------\n");
        printf ("Enter number of elements in line %d: n=",i+1);
        getInt1(&a);
        rm->n[i].m=a;
        p= (int*)malloc(a*sizeof(int));
        rm->n[i].element=p;
        printf ("Enter elements of line:\n");
        for (j=0;j<a;j++,p++)
        {
            printf ("Enter elements %d: ",j+1);
            getInt (p);
        }
        free(rm);
    }
}
void output_matrix(Matrix pb)
{
    int *p;
    for (i=0; i<pb.lines;i++)
    {
        p=pb.n[i].element;
        for (j=0;j<(pb.n[i].m);j++,p++)
        {
            printf ("\t%-5d",*p);
        }
        printf ("\n");
    }
}
void funtion(Matrix p1)
{
    int count=0,k,t=0,b,*pb;
    b=p1.n[i].m;
    pb=(int*)malloc(b*sizeof(int));
    for (j=0;j<(p1.n[i].m);j++)
    {
        for (k=j+1;k<(p1.n[i].m);k++)
        {
            if ((p1.n[i].element[j])==(p1.n[i].element[k]))
            {
                count++;
            }
        }
        if (count!=0)
        {
            *(pb+t)=p1.n[i].element[j];
            t++;
        }
        else b--;
        count=0;
    }
    for(j=0;j<b-1;j++)
    {   for(t=j+1;t<b;t++)
            if(*(pb+j)==*(pb+t))
            {
                k=*(pb+t);
                *(pb+t)=*(pb+(b-1));
                *(pb+(b-1))=k;
                b--;
                t--;
            }
    }
    for (j=0;j<b;j++)
    {
        printf ("\t%-5d",*(pb+j));
    }
    if (b==0) printf ("\tThere are no elements in this line that occur more than 2 times");
    free(pb);
}
main()
{
    Matrix p1;
    int p;
    input_matrix(&p1);
    printf ("\n-----------------------------------------------------------------\n");
    printf ("Old matrix:\n");
    output_matrix(p1);
    printf ("\n-----------------------------------------------------------------\n");
    printf ("New matrix:\n");
    for (i=0;i<(p1.lines);i++)
    {
        funtion(p1);
        printf ("\n");
    }
    getch();
}
