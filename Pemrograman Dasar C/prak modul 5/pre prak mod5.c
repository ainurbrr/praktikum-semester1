#include <stdio.h>

char namaDepan[20], namaBelakang[20], nim[20];

int main(){
    printf("Input Data Anda");

    printf("\nMasukkan Nama Depan : ");
    gets(namaDepan);
    printf("Masukkan Nama Belakang : ");
    gets(namaBelakang);
    nim:
    printf("Masukkan Nim : ");
    gets(nim);
    if(strlen(nim)==15){
        printf("\nSelamat %s, Data kamu berhasil dibuat", namaDepan);
    }else{
    	printf("\nNim harus berjumlah 15 digit\n");	
    	goto nim;		
	}
	printf("\n=================\n");
	strcat(namaDepan, namaBelakang);
	printf("Nama Lengkap : %s\n", namaDepan);
	printf("Nim : %s", nim);
	printf("\n=================\n");
}
