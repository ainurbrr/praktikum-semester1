
#include <stdio.h>

int jumlahBarang = 5;
int harga[5] = {30000,15000,150000,10000,10000};
char namaBarang[5][20]={"tupperware", "mug","termos","gelas","piring"};
int iter,totalHarga = 0,jumlahBelanja[10] = {0},pilihanBelanja[10] = {0},kuotabarang[5] = {0};



void printMenu(){
	printf("selamat datang di toko basmalah\n");
	printf("berikut ini adalah list barang yang kami jual\n");
	for(iter = 0;iter < jumlahBarang; iter++){
		printf("%d. %s : Rp %d\n", iter+1, namaBarang[iter], harga[iter]);
	}
}

void printRincian(){
	printf("total harga yang harus dibayar adalah %d dengan rincian sebagai berikut :\n", totalHarga);
	for(iter = 0;iter < 10;iter++){
		if(pilihanBelanja[iter] > 0){
			printf("%d %s %dx%d = %d\n" ,jumlahBelanja[iter],namaBarang[pilihanBelanja[iter] - 1],jumlahBelanja[iter],harga[pilihanBelanja[iter]-1],jumlahBelanja[iter]*harga[pilihanBelanja[iter]-1]);
		}
	}
	printf("terimakasih sudah berbelanja di toko basmalah \n");
}


int main(){
	int pilihanMenu, jumlah, indikator = 1, itrBelanja = 0;
	while(indikator == 1 && itrBelanja < 10){
		printMenu();
		printf("masukkan nomor barang yang akan dibeli :");
		scanf(" %d",&pilihanMenu);
		printf("masukkan jumlah :");
		scanf("%d", &jumlah);
		totalHarga = totalHarga + jumlah * harga[pilihanMenu-1];
		pilihanBelanja[itrBelanja] = pilihanMenu;
		jumlahBelanja[itrBelanja] = jumlah;
		itrBelanja++;
		printf("anda berhasil menambahkan %d %s ke dalam keranjang.apakah mau menambah barang yang dibeli?\n",jumlah, namaBarang);
		printf("1. yes\n2. no\n masukkan pilihan :");
		scanf("%d", &indikator);
	}
	printRincian();	
}
