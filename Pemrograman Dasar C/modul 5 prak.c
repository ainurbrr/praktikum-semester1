#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	
	//Deifinisi variable dan arrays
	char kode[3], username[20], password[20], passTemp[20], listUsername[20][20], listPassword[20][20], listKode[20][20];
	int menu, i, member = 0, simpanIndex;
	bool cekSymbol, cekBesar, cekKecil, cekAngka, cekUser;
	
	//Infinite loop menu

	while(0 < 10){
		//input menu
		printf("MENU\n1. Register\n2. Login\n3. Tampil Data\n4. EXIT\nPILIH MENU : ");
		scanf("%d", &menu);
		
		//jika kita milih registrasi
		if(menu == 1){
			
			//Looping Username
		while(0 < 5){
			//Meminta inputan username
			printf("Input Username : ");
			scanf("%s", username);
			
			//Username harus lebih dari 6
			if(strlen(username) > 6){
				
			//kalo udah lebih dari 6 masuk sini
			
			//reset cekSymbol 
			cekSymbol = false;
			
			//Untuk Pengecekan Symbol kita cek per character
			for(i = 0; i < strlen(username); i++){
				
				//gunakan isalnum untuk mengecek symbol
				if(isalnum(username[i]) == 0){
					//Untuk pengecekan titik .
					if(username[i] != '.'){
						cekSymbol = true; // <<----- Flag atau penanda
					}
				}
			}
			
			
			//Jika ada symbol, flag akan bernilai true maka mengulang
			if(cekSymbol == true){
				printf("username yang anda masukkan mengandung symbol selain titik\n");
				
				//ulang ke loop atas input username karena mengandung symbol selain titik
				continue;
			}
			
			//reset value cekUser sebelum digunakan
			cekUser = false;
			
			//check apakah sudah terdaftar kedalam listUsername	
			//gunakan looping array of String						//username yang terdaftar disimpan kedalam array of String "listUsername"
			for(i = 0; listUsername[i][i] != '\0'; i++){
				//kalo misal username sudah tedaftar
				if(strcmp(listUsername[i], username) == 0){
					cekUser = true;  // <<-- cekUser bernilai true, menandakan username yang diinputkan sudah ada dalam listUsername
				}
			}
			
			//melakukan pengecekan penanda,, jika false maka lanjut jika true maka masuk if disini
			if(cekUser == true){
				//ulang ke inputan username karena username sudah terdaftar
				printf("Username yang anda masukkan sudah terdaftar.\n");
				continue;
			}
				
				
				//ketika sudah memenuhi semua syarat,, maka break dari loop username 
				break;
			}else{
				
				//jika kurang dari 6 digit maka ulang
				printf("Username yang anda masukkan kurang dari 6 digit\n");
				continue;
			}
		}
			
			   //Looping password	
			//2. Password
			while(8 > 7){
				//inputan password
				printf("Input Password : ");
				scanf("%s", password);
				
				//Jika lebih dari 8, maka masuk seleksi berikutnya
				//=========================LOGIKA PASSWORD NOMOR 1=====================
				if(strlen(password) > 8){
					
					//================LOGIKA PASSWORD NOMOR 2.========================
					//Mengecek apakah password sudah menyertakan huruf kecil, huruf besar, angka, dan symbol
					//48 - 57 Angka -> cekAngka 
					//65 - 90 Huruf Besar -> cekBesar
					//97 - 122 Huruf Kecil -> cekKecil
					//Lainnya = Symbol -> cekSymbol
					
					//jangan lupa reset boolean
					cekAngka = false;
					cekBesar = false;
					cekKecil = false;
					cekSymbol = false;
					
					//looping ke tiap tiap character dari password 
					for(i =0; i < strlen(password); i++){
						
						//cekAngka
						if(password[i] >= 48 && password[i] <= 57){
							cekAngka = true;
						}else if(password[i] >= 65 && password[i] <= 90){    //<<--- cek Huruf Besar
							cekBesar = true;
						}else if(password[i] >= 97 && password[i]<=122){    //<<--- cek Huruf kecil
							cekKecil = true;
						}else{
							cekSymbol = true;			//<<-- Cek Symbol
						}
					}
					
					//mengecek apakah semua kriteria angka,symbol dan huruf sudah terpenuhi
					if(cekAngka == true && cekBesar == true && cekKecil == true && cekSymbol == true){
						
					}else{
						//jika ada salah satu yang tidak terpenuihi,, maka ulang
						printf("Password harus mengandung angka besar & kecil, huruf, dan symbol\n");
						continue;
					}
					//=================================================================
					//==============LOGIKA PASSWORD NOMOR 3. Palindrome================
					
					//Mengcopy nilai password kedalam variabel passTemp
					strcpy(passTemp, password);
					
					//membandingkan apakah password sama dengan password apabila dibalik (Palindrome)
					if(password == strrev(passTemp)){
						
						//Jika sama maka ulang
						printf("Password anda palindrome\n");
						continue;
					}
					
					//keluar dari looping password
					break;
				}else{
					//jika password kurang dari 8 digit maka ulang
					printf("Password yang anda masukkan kurang dari 8 digit\n");
					continue;
				}
			}

			//menyimpan data username ke list username dan data password ke listPassword
			strcpy(listUsername[member], username);
			strcpy(listPassword[member], password);


			
			
			//3 Angka kode pertama dari 3 angka Username yang di CAPSLOCK
			for(i = 0; i < 3; i++){
				kode[i] = toupper(username[i]);
			}
			//kode kasih -
			kode[3] = '-';
			member += 1;
			
			//simpan kode ke listKode
			strcpy(listKode[member], kode);
			
			//di outputkan
			printf("Username berhasil didaftarkan \n");
			printf("Username : %s\nPassword : %s\nKode User : %s%04d\n", username, password, kode, member);
			
			//listUser 								//listPassword
			//misal udin adad di index 0			//passwordnya udin ada di listPassword index 0
		}else if(menu == 2){
			
			//looping passeword
			while(0<1){
				
				//input username
				printf("Input Username : ");
				scanf("%s", username);
				
				//reset variabel cekUser
				cekUser = false;
				//mengecek apakah username terdaftar pada listUsername
				for(i = 0; listUsername[i][i] != '\0'; i++){
					if(strcmp(listUsername[i], username) == 0){
						simpanIndex = i;	//<<-- menyimpan index yang ada pada username yang terdaftar untuk didapatkan passwordnya pada listpasword
						cekUser = true;		//<<<---- jika iya maka penanda cekUser berubah nilai menjadi true
					}
				}
				
				if(cekUser == false){		//<<<--- jika penanda cekUser tidak berubah nilai maka username tidak terdaftar
					printf("Username tidak ada\n");
				//karena tidak terdaftar maka ulang
					continue;
				}
				
				//input password user
				printf("Input Password : ");
				scanf("%s", password);
				//menggunakan index yang disimpan pada line 200 untuk mengambil password
				
				if(strcmp(listPassword[simpanIndex], password) == 0){

				}else{
					//jika password yang dimasukkan salah atau tidak sama maka ulag
					printf("Password salah\n");
					continue;
				}
				
				break; //<<<--- keluar dari looping login ketika sudah berhasil login
			}
			
			//output apabila berhasil login
			printf("====SELAMAT DATANG %s====\n", username);
			printf("Username : %s\nKode User : %s%04d\n", username, listKode[simpanIndex+1], simpanIndex+1);
			
/*					0			1			2		3
		username  	x			y			z		
		password	x			y			z
		kode					x			y		z				<<<--- kita menghitung kode dari 1, bukan dari 0
*/
		}else if(menu == 3){
			//mengoutputkan data dari listUsername, listPaswword, dan listKode
			printf("===LIST DATA===\n");
			for(i = 0; listUsername[i][i] != '\0'; i++){
				printf("==%d==\n", i+1);						//i+1 karena i dimulai dari 0, sedang kita menghitung dari 1
				printf("Username : %s\n", listUsername[i]);
				printf("Kode User : %s%04d\n", listKode[i+1], i+1);
			}
			
		}else{
			//kalau pilih no.4 auto keluar
			return 0;
		}
			
	}
	
	return 0;
}