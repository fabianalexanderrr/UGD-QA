#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QPasien;
	Pasien temp = clearPasien(), temp2 = clearPasien();
	int menu, nomorAntrian = 0;
	string nama, urgensi;
	
	createEmpty(&QPasien);
	
	do{
		system("cls");
		printf("\n\t=== ATMA HOSPITAL ===\n");
		printf("\n[Antrian Pasien]");
		if(isEmpty(QPasien) == true && temp2.nomorAntrian == 0){
			printf("\n[!] Antrian pasien kosong [!]");
		}
		if(temp2.nomorAntrian != 0)
			printPasien(temp2);		
		printAntrian(QPasien);
		printf("\n\n[Pasien dalam Perawatan]");
		printPasien(temp);
		printf("\n\n[1] Tambah Antrian Pasien");
		printf("\n[2] Mulai Perawatan Pasien");
		printf("\n[3] Selesai Perawatan Pasien");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\n[Tambah Antrian Pasien]");
				if(isFull(QPasien))
					printf("\n[!] Antrian pasien penuh [!]");
				else{
					nomorAntrian = nomorAntrian + 1;
					while(true){
						printf("\nNama Pasien	         : ");fflush(stdin);gets(nama);
						if(strlen(nama) == 0)
							printf("\n[!] Nama pasien tidak boleh kosong [!]");
						else
							break;						
					}
					while(true){
						printf("Urgensi [Biasa/Emergency]: ");fflush(stdin);gets(urgensi);
						if(strcmpi(urgensi, "biasa") == 0){
							strcpy(urgensi, "Biasa");
							printf("Nomor Antrian            : %d", nomorAntrian);
							Enqueue(&QPasien, createPasien(nomorAntrian, nama, urgensi));
							printf("\n[*] Berhasil menambahkan data pasien dengan nomor antrian %d ke antrian [*]", nomorAntrian);
							break;
						}else if(strcmpi(urgensi, "Emergency") == 0){
							if(strcmp(temp.urgensi, "Emergency") == 0){
								printf("\n[!] Sedang ada pasien Emergency yang menjalani perawatan [!]");
							}else if(strcmp(temp.urgensi, "-") == 0){
								strcpy(urgensi, "Emergency");						
								printf("Nomor Antrian            : %d", nomorAntrian);
								printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", nomorAntrian);						
								temp = createPasien(nomorAntrian, nama, urgensi);
							}else{
								strcpy(urgensi, "Emergency");							
								printf("Nomor Antrian            : %d", nomorAntrian);
								printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", nomorAntrian);						
								printf("\n[*] Perawatan pasien dengan nomor antrian %d dihentikan sementara [*]", temp.nomorAntrian);
								strcpy(temp.urgensi, "Biasa (dihentikan sementara)");
								temp2 = temp;
								temp = createPasien(nomorAntrian, nama, urgensi);
							}
							break;
						}else{
							printf("\t[!] Urgensi tidak valid [!]\n");
						}
					}
				}				
				break;
			case 2:				
				if(isEmpty(QPasien) == true)
					printf("\n[!] Antrian pasien kosong [!]");
				else if(temp.nomorAntrian != 0)
					printf("\n[!] Sedang ada pasien yang menjalani perawatan [!]");
				else{
					printf("\n[Mulai Perawatan Pasien]");
					temp = QPasien.P[QPasien.head];
					Dequeue(&QPasien);					
					printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", temp.nomorAntrian);	
				}				
				break;
			case 3:
				if(temp.nomorAntrian == 0)
					printf("\n[!] Tidak ada pasien yang menjalani perawatan [!]");
				else{
					printf("\n[Selesai Perawatan Pasien]");
					printf("\n[*] Pasien dengan nomor antrian %d selesai perawatan [*]", temp.nomorAntrian);	
					if(temp2.nomorAntrian != 0){
						strcpy(temp2.urgensi, "Biasa (dilanjutkan)");
						temp = temp2;
						temp2 = clearPasien();
						printf("\n[*] Perawatan pasien dengan nomor antrian %d dilanjutkan [*]", temp.nomorAntrian);
					}else{
						temp = clearPasien();
					}
				}				
				break;
			case 0:
				printf("\n[*] NAMA LENGKAP - NPM - KELAS [*]");
			default:
				printf("\nMenu tidak tersedia");
				break;
		}
		getch();
	}while(menu != 0);
		
	return 0;
}

