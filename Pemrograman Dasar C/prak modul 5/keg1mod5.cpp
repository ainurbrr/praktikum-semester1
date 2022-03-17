#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h> 
using namespace std;

int menu,lchar=0,schar=0,nmber=0,spchr=0,login=0;
int pwlen,unlen,uncmp,pwcmp,kucmp,nourut;
char regpwchk[20],unstring[20],pwstring[20],kustring[9],kustringtemp[9];
char un[50][20], pw[50][20], ku[50][8];
char regun[20], regpw[20],end[0];

int main(){
		
  printf("MENU\n");
  printf(" 1. Rgistrasi\n 2. Login\n 3. Tampilkan semua data\n 4. EXIT\n");
  printf("PILIH MENU : ");
  scanf("%i", &menu);
  end[0]='\0';
  for(int i=0;i<=50;i++){
	  for(int k=0;k<=20;k++){
		  un[i][k]='\0';
		  pw[i][k]='\0';
		  ku[i][k]='\0';
		  kustring[k]='\0';
	  }
  }
 menu :
switch(menu)
{
case 1:
reg1 :
	lchar=0,schar=0,nmber=0,spchr=0;
	fflush(stdin);
	printf("==REGISTRASI==\n");
	printf("Input username : ");
	gets( regun);
	printf("Input password : ");
	gets(regpw);
	unlen=strlen(regun);
	if(unlen<6){
		printf("Username minimum 6 character\n");
		goto reg1;
		spchr=0;
	}
	for(int i=0;regun[i] !=0;i++){
		if((regun[i]=='!'||regun=='@'||regun=='#'||regun=='$'||
		regun=='%'||regun=='^'||regun=='&'||regun=='*'||regun=='('
||regun==')'||regun==','))
		spchr++;}
    if(spchr>0){
		printf("karakter spesial selain titik(.) terdeteksi!\n");
		printf("Username tidak boleh mengikutsertakan karakter selain titik(.)\n\n");
		goto reg1;}
    strcpy(regpwchk,regpw);
    strrev(regpwchk);
    if(!strcmp(regpw,regpwchk)){
		printf("%s adalah palindrome\n", regpw);
		printf("password tidak boleh berbentuk palindrome\n\n");
		goto reg1;}
    spchr=0;
    pwlen=strlen(regpw);
    if(pwlen<8){
		printf("password minimum 8 character\n");
		goto reg1;}
    for(int i=0;regpw[i]!=0;i++){
		if(regpw[i]>='A' && regpw[i]<='Z')
			lchar++;
		if(regpw[i]>='a' && regpw[i]<='z')
			schar++;
		if(regpw[i]>='0' && regpw[i]<='9')
			nmber++;
		if(((regpw[i]=='!')||regpw=='@'||regpw=='#'||regpw=='$'||
		regpw=='%'||regpw=='^'||regpw=='&'||regpw=='*'||regpw=='('
		||regpw==')'||regpw==','||regpw=='.'))
			spchr++;	  	
	}if(lchar==0){
		printf("Huruf kapital tidak ditemukan!\n");
		printf("password harus terdiri dari huruf kecil, kapital, angka, dan karakter spesial\n\n");
		goto reg1;
	}else if(schar==0){
		printf("Huruf kecil tidak ditemukan!\n");
		printf("password harus terdiri dari huruf kecil, kapital, angka, dan karakter spesial\n\n");
		goto reg1;
	}else if(nmber==0){
		printf("angka tidak ditemukan!\n");
		printf("password harus terdiri dari huruf kecil, kapital, angka, dan karakter spesial\n\n");
		goto reg1;
	}else if(spchr==0){
		printf("karakter spesial tidak ditemukan!\n");
		printf("password harus terdiri dari huruf kecil, kapital, angka, dan karakter spesial\n\n");
		goto reg1;}
    for(int j=0;j<=50;j++){
		if(!un[j][0]){
			for(int i=0;i<=50;i++){
				for(int k=0;k<=unlen;k++){
					unstring[k]=un[i][k];}
					uncmp=strcmp(unstring,regun);
					if(uncmp==0){
						printf("Username duplikat tidak tersedia");
						goto reg1;}
				
			}
		nourut=j;	
		break;}
	}
	for(int i=0;regun[i]!=0;i++){
		un[j][i]=regun[i];}
    for(int i=0;regpw[i]!=0;i++){
		pw[j][i]=regpw[i];}
    printf("username berhasil didaftarkan\n");
    printf("Username : ");
    for(int i=0;regun[i]!=0;i++){
		printf("%s", un[j][i]);}
    printf("\nPassword : ");
    for(int i=0;regpw[i]!=0;i++){
		printf("%s%", pw[j][i]);}
    printf("\nKode User : ");
    for(int i=0;i<=2;i++){
		if(un[j][i]>='A' && un[j][i]<='Z'){
		{ku[j][i]=un[j][i];}
		}else{ku[j][i]=un[j][i]-32;}
	}
	
	nourut++;
	for(int i=0;i<=2;i++){kustring[i]=ku[j][i];}
    kustring[3]='\0';
//sprintf(kustring,"%04d",nourut); gagal pake sprintf karena bentrok sama strcat
    snprintf(kustringtemp, 9, "%s-%04d%c", kustring,nourut,end[0]);
    for(int i=0;i<-7;i++){ku[j][i]=kustringtemp[i];}
    	for(int i=0;i<=7;i++){
			printf("%s", ku[j][i]);
		}
		getch();
		login++;
		kustringtemp[0]='\0';
		system("close");
		goto menu;
	break;
case 2:
	break;
default:
	break;
}
 return 0; 
}