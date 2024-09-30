#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QReguler, QVIP, QRiwayat;
	Pengunjung temp[2];
	temp[0] = clearPengunjung(), temp[1] = clearPengunjung();
	int menu, nomorPengunjung = 0, cari, i;
	string jenis, confirm;
	
	createEmpty(&QReguler);
	createEmpty(&QVIP);
	createEmpty(&QRiwayat);
	
	do{
		system("cls");
		printf("\n\t=== ATMA FANTASY ===\n");
		printf("\n[Sedang Bermain]\n");
		printSedangBermain(temp[0], temp[1]);		
		printf("\n\n[Antrian Pengunjung]\n");
		printAntrian(QVIP, QReguler);
		printf("\n\n[1] Tambah Pengunjung Reguler");
		printf("\n[2] Mulai Permainan");
		printf("\n[3] Permainan Selesai");
		printf("\n[4] Tambah Pengunjung VIP (Bonus)");
		printf("\n[5] Sisa Antrian (Tugas)");
		printf("\n[6] Riwayat Pengunjung (Tugas)");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\n[Tambah Pengunjung Reguler]");
				if(isFull(QReguler))
					printf("\n\n[!] Antrian pengunjung reguler penuh [!]");
				else{
					nomorPengunjung++;
					Enqueue(&QReguler, createPengunjung(nomorPengunjung, "Reguler"));
					printPengunjung(QReguler.P[QReguler.tail]);
					printf("\n[*] Berhasil menambahkan pengunjung [*]");
				}				
				break;
			case 2:
				printf("\n[Mulai Permainan]\n");				
				if(isEmpty(QReguler) && isEmpty(QVIP))
					printf("\n[!] Antrian pengunjung kosong [!]");
				else if((countData(QReguler) + countData(QVIP)) < 2)
					printf("\n[!] Jumlah pengunjung tidak mencukupi [!]");
				else if(temp[0].nomorPengunjung != 0)
					printf("\n[!] Sedang ada pengunjung yang bermain [!]");
				else{
					for(i = 0; i < 2; i++){
						if(isEmpty(QVIP))
							temp[i] = Dequeue(&QReguler);
						else
							temp[i] = Dequeue(&QVIP);
					}
					printf("\n[*] Berhasil memulai permainan [*]");										
				}	
				break;
			case 3:
				printf("\n[Permainan Selesai]\n");
				if(temp[0].nomorPengunjung == 0)
					printf("\n[!] Tidak ada pengunjung yang bermain [!]");
				else{
					printf("\n[*] Permainan telah selesai [*]\n");
					for(i = 0; i < 2; i++){
						while(true){
							printf("\nApakah pengunjung nomor %d ingin bermain lagi? [Y/N]: ", temp[i].nomorPengunjung);fflush(stdin);gets(confirm);
							if(strcmpi(confirm, "Y") == 0){
								if(strcmp(temp[i].jenis, "Reguler") == 0){
									if(!isFull(QReguler)){
										printf("\n[*] Pengunjung nomor %d ditambahkan ke antrian Reguler [*]\n", temp[i].nomorPengunjung);
										Enqueue(&QReguler, temp[i]);
									}else{
										printf("\n[!] Mohon maaf, antrian Reguler penuh [!]\n");
										if(isFull(QRiwayat))
											DequeueRiwayat(&QRiwayat);
										Enqueue(&QRiwayat, temp[i]);
									}									
								}else{
									if(!isFull(QVIP)){
										printf("\n[*] Pengunjung nomor %d ditambahkan ke antrian VIP [*]\n", temp[i].nomorPengunjung);
										Enqueue(&QVIP, temp[i]);
									}else{
										printf("\n[!] Mohon maaf, antrian Reguler penuh [!]\n");
										if(isFull(QRiwayat))
											DequeueRiwayat(&QRiwayat);
										Enqueue(&QRiwayat, temp[i]);
									}
								}
								break;
							}else if(strcmpi(confirm, "N") == 0){
								printf("\n[*] Pengunjung %d tidak bermain lagi [*]\n", temp[i].nomorPengunjung);
								if(isFull(QRiwayat))
									DequeueRiwayat(&QRiwayat);
								Enqueue(&QRiwayat, temp[i]);
								break;
							}else
								printf("\n[!] Input tidak valid [!]\n");
						}
						temp[i] = clearPengunjung();
					}	
				}				
				break;
			case 4:
				printf("\n[Tambah Pengunjung VIP]");
				if(isFull(QVIP))
					printf("\n\n[!] Antrian pengunjung VIP penuh [!]");
				else{
					nomorPengunjung++;
					Enqueue(&QVIP, createPengunjung(nomorPengunjung, "VIP"));
					printPengunjung(QVIP.P[QVIP.tail]);
					printf("\n[*] Berhasil menambahkan pengunjung [*]");
				}				
				break;	
			case 5:
				printf("\n[Sisa Antrian]\n");
				printf("\nMasukkan nomor pengunjung: "); scanf("%d", &cari);
				if(sisaAntrian(QVIP, QReguler, cari) == -1)
					printf("\n[!] Nomor pengunjung tidak ditemukan");
				else
					printf("\n[*] Pengunjung dengan nomor %d menunggu %d antrian [*]", cari, sisaAntrian(QVIP, QReguler, cari));
				break;		
			case 6:
				printf("\n[Riwayat Pengunjung] (Tugas)");
				if(isEmpty(QRiwayat))
					printf("\n[!] Riwayat pengunjung kosong [!]");
				else
					printAllPengunjung(QRiwayat);
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

