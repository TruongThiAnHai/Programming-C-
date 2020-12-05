#include<stdio.h>
#include<conio.h>
#include <malloc.h>
#include<math.h>
#include<windows.h>
int i,j;
int n1,m1,n2,m2;
int getInt(int* a) //ввод целого числа
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
int getDouble(float *a) //ввод вещественного числа
{
    float n;
    do{
        n = scanf("%f", a, sizeof(float));
        if (n < 0)
        return 0;
        if (n == 0)
        {
            printf("%s\n", "Error! Repeat input");
            scanf("%*c", 0);
        }
      } while (n == 0);
    return 1 ;
}
typedef struct complex_num
{
    float Re;
    float Im;
}num;
void output_matrix( num **p,int n,int m)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
        if (p[i][j].Im==0.0) printf("\t%-9.1f",p[i][j].Re);
        else if (p[i][j].Re==0.0) printf ("\t%-0.1fi\t",p[i][j].Im);
        else printf ("\t%-0.1f + %0.1fi",p[i][j].Re,p[i][j].Im);

		printf("\n");
	}
}

void input_matrix_complex( num **p,int n,int m)
{
	for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter[%d][%d]:\t ",i+1,j+1);
            printf ("Re= ");
            getDouble(&p[i][j].Re);
            printf ("\t\tIm= ");
            getDouble(&p[i][j].Im);
        }
    }

}
void input_matrix_real(num **p,int n,int m)
{
	for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter [%d][%d]= ",i+1,j+1);
            getDouble(&p[i][j].Re);
            p[i][j].Im=0.0;
        }
    }

}
void transpose_matrix( num **p4,num **p,int n,int m)
{
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
        {
            p4[i][j].Re=p[j][i].Re;
            p4[i][j].Im=-p[j][i].Im;
        }

	}
}
void plus_matrix( num **p,num **p1,num **p2,int n,int m)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
        {
            p[i][j].Re = p1[i][j].Re + p2[i][j].Re;
            p[i][j].Im = p1[i][j].Im + p2[i][j].Im;
        }

	}
}
void multiplication_matrix( num **p,num **p1, num **p2,int n,int m, int q)
{
    int k;
    for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		p[i][j].Re=0.0;
		p[i][j].Im=0.0;
		for(k=0;k<q;k++)
        {
            p[i][j].Re+=p1[i][k].Re*p2[k][j].Re-p1[i][k].Im*p2[k][j].Im;
            p[i][j].Im+=p1[i][k].Re*p2[k][j].Im+p1[i][k].Im*p2[k][j].Re;
		}
    }
}
void main()
{
    int a;
    num **p,**p1,**p2;
    printf ("Elements are complex or real number?\n");
    printf ("1. Complex number\n");
    printf ("2. Real number\n");
    do{
        getInt(&a);
        switch (a)
        {
            case 1:system("cls");printf ("\n------------------------Complex num-------------------------\n"); break;
            case 2:system("cls");printf ("\n------------------------Real num-------------------------\n"); break;
            default: printf ("Error! Repeat!");a=0;
        }
    }while (a==0);
    printf ("How many lines of matrix1? n1=");
    getInt(&n1);
    printf ("How many columns of matrix1? m1=");
    getInt(&m1);
    p1=(num**)malloc(n1*sizeof(num));
    for (i=0;i<n1;i++)
    {
        p1[i]=(num*)malloc(m1*sizeof(num));
    }
    printf ("\nMatrix 1:\n");
    if (a==1) input_matrix_complex(p1,n1,m1);
    if (a==2) input_matrix_real(p1,n1,m1);
    output_matrix(p1,n1,m1);
    printf ("\nHow many lines of matrix2? n2=");
    getInt(&n2);
    printf ("How many columns of matrix2? m2=");
    getInt(&m2);
    p2=(num**)malloc(n2*sizeof(num));
    for (i=0;i<n2;i++)
    {
        p2[i]=(num*)malloc(m2*sizeof(num));
    }
    printf ("\nMatrix 2:\n");
    if (a==1) input_matrix_complex(p2,n2,m2);
    if (a==2) input_matrix_real(p2,n2,m2);
    output_matrix(p2,n2,m2);
    printf ("\n------------------------------------------------------------\n");
    if (n1==m1)
    {
       printf ("Transpose matrix1:\n");
       p=(num**)malloc(n1*sizeof(num));
       for (i=0;i<n1;i++)
        {
            p[i]=(num*)malloc(m1*sizeof(num));
        }
       transpose_matrix(p,p1,n1,m1);
       output_matrix(p,n1,m1);
       free(p);
       for (i=0;i<n1;i++) free(p[i]);
    }
    else printf ("Matrix1 cannot transpose (ne mozhet transponirovat)");
    printf ("\n------------------------------------------------------------\n");
    if (n2==m2)
    {
       printf ("Transpose matrix2:\n");
       p=(num**)malloc(n2*sizeof(num));
        for (i=0;i<n2;i++)
        {
            p[i]=(num*)malloc(m2*sizeof(num));
        }
       transpose_matrix(p,p2,n2,m2);
       output_matrix(p,n2,m2);
       free(p);
       for (i=0;i<n2;i++) free(p[i]);
    }
    else printf ("Matrix2 cannot transpose (ne mozhet transponirovat)");
    printf ("\n------------------------------------------------------------\n");
    if (n1!=n2 || m1!=m2) printf ("Can not plus matrix1 and matrix2");
    else
    {
        printf ("\nSum matrix1 + matrix2:\n");
        p=(num**)malloc(n1*sizeof(num));
       for (i=0;i<n1;i++)
        {
            p[i]=(num*)malloc(m1*sizeof(num));
        }
        plus_matrix(p,p1,p2,n1,m1);
        output_matrix(p,n1,m1);
        free(p);
        for (i=0;i<n1;i++) free(p[i]);
    }
    printf ("\n------------------------------------------------------------\n");
   if (m1==n2)
   {
        printf ("\nMultiplication matrix1 X matrix2:\n");
        p=(num**)malloc(n1*sizeof(num));
        for (i=0;i<n1;i++)
        {
            p[i]=(num*)malloc(m2*sizeof(num));
        }
        multiplication_matrix(p,p1,p2,n1,m2,m1);
        output_matrix(p,n1,m2);
        free(p);
        for (i=0;i<n1;i++) free(p[i]);
   }
   else printf ("\nMatrix1 can not multiply by matrix2 (ne mozhet umnozhit)");
   free(p1);for (i=0;i<n1;i++) free(p1[i]);
   free(p2);for (i=0;i<n2;i++) free(p2[i]);
    getch();
}
