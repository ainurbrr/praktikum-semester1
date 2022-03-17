#include<stdio.h>

int main(){
	int baris,kolom,batas;
	
	printf("Masukkan Batas diamond bolong :");
	scanf("%d", &batas);
	for(baris=1;baris<=batas;baris++){
		for(kolom=batas;kolom>=baris;kolom--){
			printf(" ");
		}for(kolom=1;kolom<=baris;kolom++){
			if(kolom==1){
				printf("*");
			}else{
				printf("*");
			}
		}for(kolom=(baris-1);kolom>=1;kolom--){
			if(kolom==1){
				printf("*");
			}else{
				printf("*");
			}
		}
		printf("\n");
	}
	for(baris=1;baris<=batas-1;baris++){
		for(kolom=0;kolom<=baris;kolom++){
			printf(" ");
		}for(kolom=1;kolom<=(batas-baris);kolom++){
			if(kolom==1){
				printf("*");
			}else{
				printf("*");
			}
		}for(kolom=(batas-baris-1);kolom>=1;kolom--){
			if(kolom==1){
				printf("*");
			}else{
				printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
