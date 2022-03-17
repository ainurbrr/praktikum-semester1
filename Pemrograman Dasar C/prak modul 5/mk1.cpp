#include <stdio.h>
#include <string.h>

int main(){
	char var1[]= "Universitas ";
	char var2[]= "Muhammadiyah Malang";
	strcat(var1,var2);
	
	printf("%s", var1);
	return 0;
}