#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QPasien, QEmergency, QRiwayat;
	Pasien temp = clearPasien(), temp2 = clearPasien();
	int menu, nomorAntrian = 0, search;
	string nama, urgensi;
	
	createEmpty(&QPasien);
	createEmpty(&QEmergency);
	createEmpty(&QRiwayat);
	
	do{
		system("cls");
		printf("\n\t=== ATMA HOSPITAL ===\n");
		printf("\n[Antrian Pasien]");
		if(isEmpty(QPasien) == true && isEmpty(QEmergency) == true && temp2.nomorAntrian == 0){
			printf("\n[!] Antrian pasien kosong [!]");
		}
		printAntrian(QEmergency);
		if(temp2.nomorAntrian != 0)
			printPasien(temp2);		
		printAntrian(QPasien);
		printf("\n\n[Pasien dalam Perawatan]");
		printPasien(temp);
		printf("\n\n[1] Tambah Antrian Pasien ");
		printf("\n[2] Mulai Perawatan Pasien");
		printf("\n[3] Selesai Perawatan Pasien");
		printf("\n[4] Sisa Antrian (Tugas)");
		printf("\n[5] Riwayat Perawatan (Tugas)");
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
							if(strcmp(temp.urgensi, "Biasa") == 0 || strcmp(temp.urgensi, "Biasa (dilanjutkan)") == 0){
								strcpy(urgensi, "Emergency");
								printf("Nomor Antrian            : %d", nomorAntrian);
								printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", nomorAntrian);
								strcpy(temp.urgensi, "Biasa (dihentikan sementara)");					
								printf("\n[*] Perawatan pasien dengan nomor antrian %d dihentikan sementara [*]", temp.nomorAntrian);
								temp2 = temp;
								temp = createPasien(nomorAntrian, nama, urgensi);
							}else if(strcmp(temp.urgensi, "-") == 0){
								strcpy(urgensi, "Emergency");
								printf("Nomor Antrian            : %d", nomorAntrian);
								printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", nomorAntrian);
								strcpy(temp.urgensi, "Biasa (dihentikan sementara)");					
								temp = createPasien(nomorAntrian, nama, urgensi);
							}else{
								if(isFull(QEmergency) == true)
									printf("\n[!] Terlalu banyak pasien dengan urgensi Emergency [!]");
								else{
									strcpy(urgensi, "Emergency");								
									printf("Nomor Antrian            : %d", nomorAntrian);
									Enqueue(&QEmergency, createPasien(nomorAntrian, nama, urgensi));
									printf("\n[*] Berhasil menambahkan data pasien Emergency dengan nomor antrian %d ke antrian [*]", nomorAntrian);
								}
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
					EnqueueRiwayat(&QRiwayat, temp);	
					if(isEmpty(QEmergency) == false){
						temp = QEmergency.P[QEmergency.head];
						printf("\n[*] Pasien dengan nomor antrian %d menjalani perawatan [*]", temp.nomorAntrian);
						Dequeue(&QEmergency);						
					}else if(temp2.nomorAntrian != 0){
						strcpy(temp2.urgensi, "Biasa (dilanjutkan)");
						temp = temp2;
						temp2 = clearPasien();
						printf("\n[*] Perawatan pasien dengan nomor antrian %d dilanjutkan [*]", temp.nomorAntrian);
					}else{
						temp = clearPasien();
					}
				}				
				break;
			case 4:
				printf("\n[Sisa Antrian] (Tugas)");
				printf("\nMasukkan nomor antrian: "); scanf("%d", &search);
				if(hitungAntrian(QPasien, QEmergency, search) == -1)
					printf("\n[!] Nomor antrian tidak ditemukan [!]");
				else
					printf("\n[*] Nomor antrian %d menunggu %d orang.", search, hitungAntrian(QPasien, QEmergency, search));
				break;			
			case 5:
				printf("\n[Riwayat Perawatan] (Tugas)");
				printRiwayat(QRiwayat);			
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

