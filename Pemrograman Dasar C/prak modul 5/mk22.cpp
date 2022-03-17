#include <stdio.h>
#include <string.h>

int main(){
	
	char var1[]="Informatika UMM";
	char huruf='i';
	char* hasil=strchr(var1, 'i');
	
	while(hasil !='\0'){
		
	printf("karakter '%c' pada kalimat '%s' ditemukan pada huruf ke-%d\n", huruf, var1, hasil-var1+1);
	hasil = strchr(hasil+1, huruf);		
	}
	return 0;
}