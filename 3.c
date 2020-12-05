#include <stdio.h>
#include <conio.h>

typedef struct{
	char hten[30];
	int tuoi;
	float diemTB;
}sinh_vien;
sinh_vien sv;
long size = sizeof(sv);
char tl;
void nhap(FILE *fp){
	int n=0;
	fp = fopen("DSACH.C","wb");
	do{
	   //clrscr();
	   printf("\nNhap sinh vien thu %d: \n",++n);
	   fflush(stdin);
	   printf(" Ho ten: ");	gets(sv.hten);
	   printf(" Tuoi: "); 	scanf("%d",&sv.tuoi);
	   printf(" Diem trung binh: "); scanf("%f",&sv.diemTB);

	   fwrite(&sv,size,1,fp);
	   printf("\nCo nhap nua khong(Y/N): ");
	   fflush(stdin);
	   tl = getchar();
	}while(tl != 'n');
	fclose(fp);
}
void xuat(FILE *fp){
     int i=0;
     fp = fopen("DSACH.C","rb");
     //clrscr();
     printf("\n\tDANH SACH SINH VIEN.\n");
     printf("STT Ho ten\tTuoi\tDiemTB\n");
     while(fread(&sv,size,1,fp)>0)
	printf("%2d  %s\t%d\t%6.2f\n",++i,sv.hten,sv.tuoi,sv.diemTB);
     fclose(fp);
     getch();
}
void sua_diem(FILE *fp){
   int i;
   fp = fopen("DSACH.C","rb");
   fseek(fp,0,SEEK_SET);
   do{
   		//clrscr();
       printf("\nSua sinh vien thu : ");
       scanf("%d",&i);
       fflush(stdin);
       fseek(fp,(i-1)*size,SEEK_SET);
       fread(&sv,size,1,fp);
       printf("Thong tin hien tai: \n");
       printf("\n Ho ten: %s",sv.hten);
       printf("\n Tuoi: %d",sv.tuoi);
       printf("\n Diem trung binh: %.2f",sv.diemTB);
       fflush(stdin);
       printf("\nNhap moi: \n");
       printf(" Ho ten: "); 	gets(sv.hten);
       printf(" Tuoi: ");		scanf("%d",&sv.tuoi);
       printf("\nNhap diem trung binh moi: ");
       scanf("%f",&sv.diemTB);

	   fseek(fp,-size,SEEK_CUR);
       fwrite(&sv,size,1,fp);
       printf("\nTiep tuc bo sung(Y/N): ");
       fflush(stdin);
       tl = getchar();
   }while( tl != 'n');
   printf("Da sua xong.\n");
   fclose(fp);
}
int main(){
   FILE *f;
   char tl;
   do{
       //clrscr();
       printf("\n\tMENU:\n");
       printf("\nPhim 1. Tao danh sach.");
       printf("\nPhim 2. Sua diem.");
       printf("\nPhim 3. Hien danh sach.");
       printf("\nPhim 4. Thoat.");
       fflush(stdin);
       printf("\n\nBan chon: ");
       tl = getchar();
       switch(tl){
	   case '1': nhap(f); break;
	   case '2': sua_diem(f); break;
	   case '3': xuat(f); break;
       };
       getch();
     }while(tl != '4');

}










