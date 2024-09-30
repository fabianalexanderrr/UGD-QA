#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QLow, QHigh, QRiwayat;
	int menu, cari, ukuran;
	string priority, namaProses;
	Proses temp;
	
	createEmpty(&QLow);
	createEmpty(&QHigh);
	createEmpty(&QRiwayat);
	
	do{
		system("cls");
		printf("\n\t=== ATMA OS Memory Management ===\n");
		printf("\n[Antrian Proses Memori]");
		printAll(QLow, QHigh);
		printf("\n\n[1] Tambah Proses Priority Low");
		printf("\n[2] Proses Selesai");
		printf("\n[3] Tambah Proses Priority High (Bonus)");
		printf("\n[4] Estimasi Waktu (Tugas)");
		printf("\n[5] Riwayat Proses (Tugas)");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\n[Tambah Proses Priority Low]");
				if(isFull(QLow))
					printf("\n[!] Antrian proses penuh [!]");
				else{
					strcpy(priority, "Low");
					printf("\nPriority      : %s", priority);
					while(true){
						printf("\nNama Proses   : "); fflush(stdin);gets(namaProses);
						if(!isNamaUnik(QLow, QHigh, namaProses))
							printf("[!] Nama proses %s sudah ada antrian proses", namaProses);
						else if(strlen(namaProses) == 0)
							printf("[!] Nama proses tidak boleh kosong");
						else
							break;
					}  
					
					while(true){
						printf("Ukuran [1-16] : ");scanf("%d", &ukuran);
						if(ukuran < 1 || ukuran > 16){
							printf("\t[!] Ukuran tidak boleh kurang dari 0 atau lebih dari 16 [!]\n");
						}else{
							break;
						}
					}							
					Enqueue(&QLow, createProses(ukuran, namaProses, priority));
					printf("\n[*] Proses %s ditambahkan ke antrian proses", namaProses);
				}				
				break;
			case 2:				
				if(isEmpty(QLow) == true && isEmpty(QHigh) == true)
					printf("\n[!] Antrian proses kosong [!]");
				else{
					printf("\n[Proses Selesai]");
					if(isEmpty(QHigh) == true){
						temp = QLow.P[QLow.head];
						Dequeue(&QLow);
					}else{
						temp = QHigh.P[QHigh.head];
						Dequeue(&QHigh);
					}
					EnqueueRiwayat(&QRiwayat, temp);
					printf("\n[*] Proses %s dengan ukuran %d selesai", temp.namaProses, temp.ukuran);
				}				
				break;
			case 3:
				printf("\n[Tambah Proses Priority High]");
				if(isFull(QHigh))
					printf("\n[!] Antrian proses penuh [!]");
				else{
					strcpy(priority, "High");
					printf("\nPriority      : %s", priority);
					while(true){
						printf("\nNama Proses   : "); fflush(stdin);gets(namaProses);
						if(!isNamaUnik(QLow, QHigh, namaProses))
							printf("[!] Nama proses %s sudah ada antrian proses", namaProses);
						else
							break;
					}  
					
					while(true){
						printf("Ukuran [1-16] : ");scanf("%d", &ukuran);
						if(ukuran < 1 || ukuran > 16){
							printf("\t[!] Ukuran tidak boleh kurang dari 0 atau lebih dari 16 [!]\n");
						}else{
							break;
						}
					}							
					Enqueue(&QHigh, createProses(ukuran, namaProses, priority));
					printf("\n[*] Proses %s ditambahkan ke antrian proses", namaProses);
				}		
				break;
			case 4:
				printf("\n[Estimasi Waktu] (Tugas)");
				printf("\nNama Proses   : ");fflush(stdin);gets(namaProses);
				if(estimasiWaktu(QLow, QHigh, namaProses) == -1){
					printf("\n[!] Proses tidak ditemukan [!]");
				}else{
					printf("\n[*] Estimasi waktu proses %s adalah %.2f detik.", namaProses, estimasiWaktu(QLow, QHigh, namaProses));						
				}
				break;
			case 5:
				printf("\n[Riwayat Proses] (Tugas)");
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

