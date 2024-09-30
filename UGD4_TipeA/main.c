#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QReguler, QPrioritas, QRiwayat;
	Nasabah temp1 = clearNasabah(), temp2 = clearNasabah();
	int menu, nomorAntrianR = 0, nomorAntrianP = 100, cari;
	string jenisNasabah, layanan, teller;
	
	createEmpty(&QReguler);
	createEmpty(&QPrioritas);
	createEmpty(&QRiwayat);
	
	do{
		system("cls");
		printf("\n\t=== BANK CENTRAL ATMA ===\n");
		printf("\n[Antrian Nasabah Reguler]");
		printAntrian(QReguler);
		printf("\n\n[Teller 1]: ");
		printNasabah(temp1);
		printf("\n[Teller 2]: ");
		printNasabah(temp2);		
		printf("\n\n[Antrian Nasabah Prioritas] (Bonus)");
		printAntrian(QPrioritas);
		printf("\n\n[1] Tambah Antrian Nasabah Reguler");
		printf("\n[2] Panggil ke Teller 1");
		printf("\n[3] Panggil ke Teller 2");
		printf("\n[4] Teller 1 Selesai");
		printf("\n[5] Teller 2 Selesai");
		printf("\n[6] Tambah Antrian Nasabah Prioritas (Bonus)");
		printf("\n[7] Sisa Antrian (Tugas)");
		printf("\n[8] Riwayat Pelayanan (Tugas)");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\n[Tambah Antrian Nasabah Reguler]");
				if(isFull(QReguler))
					printf("\n[!] Antrian nasabah penuh [!]");
				else{
					nomorAntrianR = nomorAntrianR + 1;
					strcpy(jenisNasabah, "Reguler");
					strcpy(teller, "-");        
					printf("\nNomor Antrian              : %d", nomorAntrianR);
					printf("\nJenis Nasabah              : %s", jenisNasabah);
					while(true){
						printf("\nLayanan [Setoran/Penarikan]: ");fflush(stdin);gets(layanan);
						if(strcmpi(layanan, "setoran") == 0){
							strcpy(layanan, "Setoran");
							break;
						}else if(strcmpi(layanan, "penarikan") == 0){
							strcpy(layanan, "Penarikan");
							break;
						}else{
							printf("\t[!] Layanan tidak valid [!]");
						}
					}				
					printf("Teller                     : %s", teller);				
					EnqueueAntrian(&QReguler, createNasabah(nomorAntrianR, jenisNasabah, layanan, teller));
				}				
				break;
			case 2:				
				if(isEmpty(QReguler) == true && isEmpty(QPrioritas) == true)
					printf("\n[!] Antrian nasabah kosong [!]");
				else if(temp1.nomorAntrian != 0)
					printf("\n[!] Teller 1 sedang melayani nasabah [!]");
				else{
					printf("\n[Panggil ke Teller 1]");
					if(isEmpty(QPrioritas) == true){
						temp1 = QReguler.N[QReguler.head];
						strcpy(temp1.teller, "1");
						DequeueAntrian(&QReguler, "1");
					}else{
						temp1 = QPrioritas.N[QPrioritas.head];
						strcpy(temp1.teller, "1");
						DequeueAntrian(&QPrioritas, "1");
					}
				}				
				break;
			case 3:
				if(isEmpty(QReguler) == true && isEmpty(QPrioritas) == true)
					printf("\n[!] Antrian nasabah kosong [!]");
				else if(temp2.nomorAntrian != 0)
					printf("\n[!] Teller 2 sedang melayani nasabah [!]");
				else{
					printf("\n[Panggil ke Teller 2]");
					if(isEmpty(QPrioritas) == true){
						temp2 = QReguler.N[QReguler.head];
						strcpy(temp2.teller, "2");
						DequeueAntrian(&QReguler, "2");
					}else{
						temp2 = QPrioritas.N[QPrioritas.head];
						strcpy(temp2.teller, "2");
						DequeueAntrian(&QPrioritas, "2");
					}
				}				
				break;
			case 4:
				if(temp1.nomorAntrian == 0)
					printf("\n[!] Teller 1 tidak sedang melayani nasabah [!]");
				else{
					printf("\n[*] Teller 1 selesai melayani nasabah");
					EnqueueRiwayat(&QRiwayat, temp1);
					temp1 = clearNasabah();
				}				
				break;
			case 5:
				if(temp2.nomorAntrian == 0)
					printf("\n[!] Teller 2 tidak sedang melayani nasabah [!]");
				else{
					printf("\n[*] Teller 2 selesai melayani nasabah");
					EnqueueRiwayat(&QRiwayat, temp2);
					temp2 = clearNasabah();
				}				
				break;			
			case 6:
				if(isFull(QPrioritas))
					printf("\n[!] Antrian nasabah penuh [!]");
				else{
					printf("\n[Tambah Antrian Nasabah Prioritas (Bonus)]");
					nomorAntrianP = nomorAntrianP + 1;
					strcpy(jenisNasabah, "Prioritas");
					strcpy(teller, "-");
					printf("\nNomor Antrian              : %d", nomorAntrianP);
					printf("\nJenis Nasabah              : %s", jenisNasabah);
					while(true){
						printf("\nLayanan [Setoran/Penarikan]: ");fflush(stdin);gets(layanan);
						if(strcmpi(layanan, "setoran") == 0){
							strcpy(layanan, "Setoran");
							break;
						}else if(strcmpi(layanan, "penarikan") == 0){
							strcpy(layanan, "Penarikan");
							break;
						}else{
							printf("\n[!] Layanan tidak valid [!]");
						}
					}				
					printf("Teller                     : %s", teller);				
					EnqueueAntrian(&QPrioritas, createNasabah(nomorAntrianP, jenisNasabah, layanan, teller));
				}
				break;
			case 7:
				printf("\n[Sisa Antrian] (Tugas)");
				printf("\nMasukkan Nomor Antrian: ");scanf("%d", &cari);
				if(sisaAntrian(QReguler, cari) == -1 && sisaAntrian(QPrioritas, cari) == -1){
					printf("\n[!] Nomor antrian tidak ditemukan [!]");
				}else{
					if(cari > 100)
						printf("[*] Nomor antrian %d menunggu %d orang", cari, sisaAntrian(QPrioritas, cari));
					else
						printf("[*] Nomor antrian %d menunggu %d orang", cari, sisaAntrian(QReguler, cari) + countData(QPrioritas));						
				}
				break;
			case 8:
				printf("\n[Riwayat Pelayanan] (Tugas)");
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
