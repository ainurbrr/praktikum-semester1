#include <stdio.h>


int main(){
	int hargabarang, total=0, bayar, diskon;
	float persen;
	
	for(int i=1; i<=3;i++){
		printf("masukkan harga barang %i :", i);
		scanf("%d", &hargabarang);
		total=total+hargabarang;
	}
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
	}else if(total>=500000){
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
