#include <stdio.h>


int main(){
	int barang1, barang2, barang3, total, bayar, diskon;
	float persen;
	
	printf(">>> INFOTECH STORE <<<\n");
	printf("masukkan harga barang 1: ");
	scanf("%d", &barang1);
	printf("masukkan harga barang 2: ");
	scanf("%d", &barang2);
	printf("masukkan harga barang 3: ");
	scanf("%d", &barang3);
	total= barang1+barang2+barang3;
	
	
	if(total>=100000 && total<300000){
		printf("anda mendapatkan potongan 10 persen\n");
		persen=0.1;
		diskon=total*persen;
		bayar= total-diskon;
		printf("\ntotal harga : %d\n", total );
		printf("diskon : %d\n", diskon );
		printf("total bayar anda sebesar : %d\n", bayar);
	}else if(total>=300000 && total<500000){
		printf("anda mendapatkan potongan 20 persen\n");
		persen=0.2;
		diskon=total*persen;
		bayar= total-diskon;
		printf("\ntotal harga : %d\n", total );
		printf("diskon : %d\n", diskon );
		printf("total bayar anda sebesar : %d\n", bayar);
	}else if(total>500000){
		printf("anda mendapatkan potongan 25 persen\n");
		persen=0.25;
		diskon=total*persen;
		bayar= total-diskon;
		printf("\ntotal harga : %d\n", total );
		printf("diskon : %d\n", diskon );
		printf("total bayar anda sebesar : %d\n", bayar);
	}else{
		printf("tidak ada potongan, terima kasih\n");
		printf("\ntotal bayar anda sebesar : %d\n", total);
	}

	

printf("\n selamat berbelanja kembali :v");

return 0;
	
}
