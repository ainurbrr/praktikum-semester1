#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <fstream>

int menu, i, member=0,s=0, simpanIndex, listnew=0;
char kode[4], Un[20], Pw[20], PwTemp[20];
char listUn[20][50],listPw[20][50],listkode[20][50];
char listunew[20][20],listpnew[20][20],listknew[20][20];
int kodeuser;
bool cekchar, cekU, cekl, cekNum, cekUn;
char ganti;


FILE *data;
int main(){
menu:
  printf("MENU\n");
  printf(" 1. Registrasi\n 2. Login\n 3. Tampilkan semua data\n 4. EXIT\n");
  printf("PILIH MENU : ");
  scanf("%i", &menu);

  switch(menu)
  {
  case 1 :
  reg :

  	printf("==REGISTRASI==\n");
  	printf("Input username : ");
  	scanf("%s", &Un);
	if(strlen(Un)<6){
		printf("Username yang anda masukkan kurang dari 6 digit\n");
		goto reg;
	}else if(strlen(Un)>6){
		  cekchar = false;
		  for(i=0; i<strlen(Un); i++){
			  if(isalnum(Un[i])==0){
				  if(Un[i]!='.'){
					  cekchar =true;
					  printf("Username tidak boleh ada special karakter, kecuali titik (.)\n");
					  goto reg;
				  }
			  }
		  }
	  }
	cekUn = false;
	for(i=0;listUn[i][i]!='\0';i++){
		if(strcmp(listUn[i],Un)==0){
			cekUn=true;
			printf("Username yang anda input telah terdaftar\n");
			goto reg;
		}
	}
	
	pw :
  	printf("Input password : ");
  	scanf("%s", &Pw);
	if(strlen(Pw)<8){
		printf("Password harus lebih dari 8 digit\n");
		goto pw;
	}else if(strlen(Pw)>8){
		cekl=false;
		cekU=false;
		cekNum=false;
		cekchar=false;

		for(i=0;i<strlen(Pw); i++){
			if(Pw[i]>=48 && Pw[i]<=57){
				cekNum=true;
			}else if(Pw[i]>=65 && Pw[i]<=90){
				cekU=true;
			}else if(Pw[i]>=97 && Pw[i]<=122){
				cekl=true;
			}else if(Pw[i]>=33 && Pw[i]<=64){
			cekchar=true;}
		}if (cekl==true && cekU==true && cekNum==true && cekchar==true){

		}else{
			printf("Password harus mengandung angka besar & kecil, huruf, dan karakter spesial\n");
			goto pw;
		}
	}
	//palindrome
	strcpy(PwTemp, Pw);
	if(Pw==strrev(PwTemp)){
		printf("Password yang anda masukkan palindrome\n");
		goto pw;
	}
	
	strcpy(listUn[member],Un);
	strcpy(listPw[member],Pw);
	//mengambil kode user dari 3 huruf diawal yg di cpslok
	for(i=0;i<3;i++){
		kode[i]=toupper(Un[i]);
	}
	//kode kasi -
	kode[3]='-';
	member +=1;
	//simpan kode ke list
	strcpy(listkode[member],kode);

  	printf("username berhasil didaftarkan");
  	printf("\nUsername : %s", Un);
  	printf("\nPassword : %s", Pw);
  	printf("\nKode User : %s%04d\n ",kode,member);

	data = fopen("datalogin.txt", "w");
	for(i=0;listPw[i][i]!='\0';i++){
  	fprintf(data,"%d.",i+1);
	fprintf(data, "Username : %s\n", listUn[i]);
  	fprintf(data, "Password : %s\n", listPw[i]);
  	fprintf(data, "Kode User : %s%04d\n",listkode[i+1], i+1);}
	fclose(data);
  	goto menu;
	  break;
	  
  case 2 :
  login :
  data = fopen("datalogin.txt", "r");
  fclose(data);
  	printf("==LOGIN==\n");
  	printf("Input Username : ");
	scanf("%s", Un);
	cekUn=false;
	for(i=0; listUn[i][i] !='\0';i++){
		if(strcmp(listUn[i],Un)==0){
			simpanIndex=i;
			cekUn=true;
		}
	}
	if(cekUn==false){
		printf("Username tidak ditemukan\n");
		goto login;}
  	printf("Input Password : ");
  	scanf("%s", Pw);
	if(strcmp(listPw[simpanIndex],Pw)==0){}
	else{
		printf("password yang anda masukkan salah\n");
		printf("ingin mengganti password?(y/n)");
		fflush(stdin);
		scanf("%c", &ganti);
		if(ganti=='y'){
			printf("masukkan password baru : ");
			scanf("%s", listPw[simpanIndex]);
		goto login;}
		else{
			goto login;}
	}
  	printf("SELAMAT DATANG %s\n", Un);
  	printf("== Data Anda ==\n");
	printf("Usename : %s\n",Un);
	printf("Kode User : %s%04d\n",listkode[simpanIndex+1], simpanIndex+1);
  	//untuk kode user mulainya dari 1 jadi ditambah 1
  	
  	 data = fopen("datalogin.txt", "w");
  	for(i=0;listPw[i][i]!='\0';i++){
    fprintf(data,"%d.",i+1);
	fprintf(data, "Username : %s\n", listUn[i]);
  	fprintf(data, "Password : %s\n", listPw[i]);
  	fprintf(data, "Kode User : %s%04d\n",listkode[i+1], i+1);
  	}fclose(data);
  	goto menu;
	break;
  case 3 :
  	printf("== LIST DATA ==\n");
	for(i=0;listUn[i][i]!='\0';i++){
		printf("== %d ==\n", i+1);
		printf("Username : %s\n", listUn[i]);
		printf("Kode User : %s%04d\n", listkode[i+1],i+1);
	}goto menu;
	break;
  case 4 : 
  	break;
  default:;
	break;
}
   return 0;
}
