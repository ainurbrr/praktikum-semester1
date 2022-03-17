#include<stdio.h>
int main(){
	int kolom, baris, batas;
	printf("Masukkan Batas segitiga siku bolong :");
	scanf("%d", &batas);
	for(kolom=0; kolom<batas; kolom++){
		printf(" ");
		for(baris=batas-1; baris>=batas; baris--)
		printf(" ");
		for(baris=0; baris<2*kolom+1; baris++)
		if(kolom == 0 || kolom == batas-1){
			printf("*");
		}else if (baris == 0 || baris == 2*kolom){
			printf("*");
		}else{
			printf(" ");
		}
		printf("\n");
	}
	
	
}
