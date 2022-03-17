#include<stdio.h>
#include<string.h>

int jumlahtempat = 10;
int harga[10] = {45000,75000,80000,88000,95000,100000,115000,125000,150000,212000};
char stasiuntujuan[10][20]= {"surabaya", "malang","jombang","gresik","banyuwangi","semarang","jogja","solo","magelang","bandung"};
char tanggaltiket[10][20]= {"5 januari 2021","10 januari 2021","15 januari 2021","20 januari 2021","25 januari 2021","30 januari 2021",
"5 januari 2021","5 februari 2021","10 januari 2021","25 januari 2021"};
char jamtiket[10][10]= {"09:00 WIB","07:00 WIB","10:00 WIB","15:00 WIB","12:00 WIB","17:00 WIB","19:00 WIB","13:00 WIB","07:30 WIB","14:00 WIB"};
int iter, totalHarga = 0, jumlahpemesanan[10] = {0}, pilihantiket[10] = {0}, stoktiket[10] = {30, 50, 20, 40, 40,30,40,30,25,45};

void printMenu(){
	printf("selamat datang di pemesanan tiket kereta api ndoho\n");
	printf("berikut ini adalah list tiket kereta api ndoho\n");
	for(iter = 0;iter < jumlahtempat; iter++){
		printf("%d. %d stok tiket, %s , %s, %s : Rp. %d\n", iter+1, stoktiket[iter], tanggaltiket[iter], jamtiket[iter], stasiuntujuan[iter], harga[iter]);
	}
}

void printRincian(){
	printf(" total harga yang harus dibayar adalah Rp. %d dengan rincian sebagai berikut :\n", totalHarga);
	for(iter = 0;iter < 10;iter++){
		if(pilihantiket[iter] > 0){
			printf("%d %s, %d x Rp. %d = Rp. %d\n\n" ,jumlahpemesanan[iter],stasiuntujuan[pilihantiket[iter] - 1],jumlahpemesanan[iter],harga[pilihantiket[iter]-1],jumlahpemesanan[iter]*harga[pilihantiket[iter]-1]);
		}
	}
	printf(" terimakasih, Stay save, jangan lupa berdoaa dan semoga selamat sampai tujuan.\n\n jangan lupa 3M demi keamanan bersama yaitu\n 1. Mencuci tangan\n 2. Memakai masker\n 3. Menjaga jarak\n");
}

int cekjadwal(int colected,int input){
	int status = 1;
	for(iter = 0; iter < input; iter++){
		if(pilihantiket[iter]-1 == colected){
			status = 1;
		}else{
			if(strcmp(tanggaltiket[colected], tanggaltiket[pilihantiket[iter]-1]) == 0){
				status = 0;
				break;
			}
		}
	}
	return status;
}

int main(){
	int pilihanMenu;
	int jumlah;
	int indikator = 1;
	int itrBelanja = 0;
	
	while(indikator == 1 && itrBelanja < 10){
		printMenu();
		printf(" masukkan nomor tiket kereta yang akan dibeli :");
		scanf(" %d",&pilihanMenu);
		printf(" masukkan jumlah tiket :");
		scanf(" %d", &jumlah);
		if(jumlah <= stoktiket[pilihanMenu-1]){
			if(cekjadwal(pilihanMenu-1,itrBelanja) == 1){
				stoktiket[pilihanMenu-1]-=jumlah;
				totalHarga = totalHarga + jumlah * harga[pilihanMenu-1];
				pilihantiket[itrBelanja] = pilihanMenu;
				jumlahpemesanan[itrBelanja] = jumlah;
				itrBelanja++;
				printf(" anda berhasil menambahkan %d %s ke dalam keranjang.\n apakah mau menambah barang yang dibeli?\n",jumlah, stasiuntujuan[pilihanMenu-1]);
				printf("1. yes\n2. no\n masukkan pilihan : ");
				scanf("%d", &indikator);
			}else{
				printf("Mohon maaf, tidak dapat membeli tiket dengan tanggal yang sama.\n\n", stoktiket[pilihanMenu-1]);
			}
		}else{
			printf("stok yang di pesan melebihi stok yang tersedia\n\n");
		}
	}
	printRincian();	
}



