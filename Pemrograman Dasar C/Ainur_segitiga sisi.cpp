#include<stdio.h>

int main(){
	int baris, bintang, spasi, jumlah;
	printf("masukkan batas segitiga : ");
	scanf("%d", &jumlah);
	int banyak_bintang = jumlah;
	int banyak_baris = banyak_bintang;
	for (baris = 1; baris <= banyak_baris; baris++){
		printf(" ");
		for (spasi = 1; spasi <= banyak_bintang; spasi++){
			printf(" ");
	}for (bintang = 1; bintang <= baris; bintang++){
		printf("*");
		printf(" ");
	}
	printf("\n");
	banyak_bintang = banyak_bintang - 1;
	}

	return 0;
}
