#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

int main(int argc, char *argv[]) {
	
	Queue QProduksi, Qqc, QPacking;
	int menu, nomorProduksi = 0, jumlah, i;
	string namaBarang, status;
	Produk temp;
	
	createEmpty(&QProduksi);
	createEmpty(&Qqc);
	createEmpty(&QPacking);
	
	do{
		system("cls");
		printf("\n\t=== ATMA FACTORY ===\n");
		printf("\n[1] Tambah Proses Produksi");
		printf("\n[2] Tampil Proses Produksi");
		printf("\n[3] Selesai Proses Produksi");
		printf("\n[4] Tampil Proses Quality Control (Bonus)");
		printf("\n[5] Selesai Proses Quality Control (Bonus)");
		printf("\n[6] Tampil Proses Packing (Tugas)");
		printf("\n[7] Selesai Proses Packing (Tugas)");
		printf("\n[8] Pencarian Produk (Tugas)");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\n[Tambah Proses Produksi]");
				if(isFull(QProduksi))
					printf("\n[!] Antrian proses Produksi penuh [!]");
				else{
					nomorProduksi++;
					strcpy(status, "Produksi");      
					printf("\nNomor Produksi : %d", nomorProduksi);
					printf("\nStatus         : %s", status);
					while(true){
						printf("\nNama Barang    : ");fflush(stdin);gets(namaBarang);
						if(strlen(namaBarang) == 0){
							printf("\t[!] Nama barang tidak boleh kosong [!]");
						}else
							break;	
					}
					while(true){
						printf("Jumlah Barang  : ");scanf("%d", &jumlah);
						if(jumlah < 1){
							printf("\t[!] Jumlah barang tidak boleh kurang dari 1 [!]\n");
						}else if(countData(QProduksi) + jumlah > 5){
							printf("\t[!] Jumlah barang melebihi kapasitas Produksi [!]\n");
						}else
							break;	
					}
					printf("[*] Berhasil menambahkan %d %s ke antrian Produksi", jumlah, namaBarang);
					for(i = 0; i < jumlah; i++){
						Enqueue(&QProduksi, createProduk(nomorProduksi, namaBarang, status));
					}								
				}				
				break;
			case 2:				
				if(isEmpty(QProduksi))
					printf("\n[!] Antrian proses Produksi kosong [!]");
				else{
					printf("\n[Tampil Proses Produksi]");
					printQueue(QProduksi);	
				}				
				break;
			case 3:
				if(isEmpty(QProduksi))
					printf("\n[!] Antrian proses Produksi kosong [!]");
				else{
					printf("\n[Selesai Proses Produksi]");
					printProduk(QProduksi.P[QProduksi.head]);
					while(true){
						printf("\nHasil Produksi [Berhasil/Gagal]: ");fflush(stdin);gets(status);
						if(strcmpi(status, "Berhasil") == 0){
							strcpy(QProduksi.P[QProduksi.head].status, "Quality Control");
							printf("\n[*] Produksi %s Berhasil!", QProduksi.P[QProduksi.head].namaBarang);
							printf("\n[*] Produk dengan nomor produksi %d memasuk proses Quality Control.", QProduksi.P[QProduksi.head].nomorProduksi);
							Enqueue(&Qqc, Dequeue(&QProduksi));
							break;
						}else if(strcmpi(status, "Gagal") == 0){
							printf("\n[!] Produksi %s Gagal!", QProduksi.P[QProduksi.head].namaBarang);
							printf("\n[!] Produk dengan nomor produksi %d kembali memasuki proses Produksi.", QProduksi.P[QProduksi.head].nomorProduksi);
							Enqueue(&QProduksi, Dequeue(&QProduksi));
							break;
						}else{
							printf("\t[!] Input tidak valid [!]");
						}
					}
				}				
				break;
			case 4:
				if(isEmpty(Qqc))
					printf("\n[!] Antrian proses Quality Control kosong [!]");
				else{
					printf("\n[Tampil Proses Quality Control]");
					printQueue(Qqc);	
				}				
				break;
			case 5:
				if(isEmpty(Qqc))
					printf("\n[!] Antrian proses Quality Control kosong [!]");
				else{
					printf("\n[Selesai Proses Quality Control]");
					printProduk(Qqc.P[Qqc.head]);
					while(true){
						printf("\nHasil Quality [Berhasil/Gagal]: ");fflush(stdin);gets(status);
						if(strcmpi(status, "Berhasil") == 0){
							strcpy(Qqc.P[Qqc.head].status, "Packing");
							printf("\n[*] Quality Control %s Berhasil!", Qqc.P[Qqc.head].namaBarang);
							printf("\n[*] Produk dengan nomor produksi %d memasuk proses Packing.", Qqc.P[Qqc.head].nomorProduksi);
							Enqueue(&QPacking, Dequeue(&Qqc));
							break;
						}else if(strcmpi(status, "Gagal") == 0){
							strcpy(Qqc.P[Qqc.head].status, "Produksi");
							printf("\n[!] Quality Control %s Gagal!", Qqc.P[Qqc.head].namaBarang);
							printf("\n[!] Produk dengan nomor produksi %d kembali memasuki proses Produksi.", Qqc.P[Qqc.head].nomorProduksi);
							Enqueue(&QProduksi, Dequeue(&Qqc));
							break;
						}else{
							printf("\t[!] Input tidak valid [!]");
						}
					}
				}				
				break;			
			case 6:
				if(isEmpty(QPacking))
					printf("\n[!] Antrian proses Packing kosong [!]");
				else{
					printf("\n[Tampil Proses Packing]");
					printQueue(QPacking);	
				}
				break;
			case 7:
				if(isEmpty(QPacking))
					printf("\n[!] Antrian proses Packing kosong [!]");
				else if(countData(QPacking) < 2)
					printf("\n[!] Jumlah produk tidak cukup untuk dilakukan Packing [!]");
				else{
					printf("\n[Selesai Proses Packing]");
					for(i = 0; i < 2; i++){
						temp = Dequeue(&QPacking);
						printf("\n[*] Produk %s telah selesai melalui proses Packing", temp.namaBarang);	
					}	
				}
				break;
			case 8:
				if(isEmpty(QProduksi) && isEmpty(Qqc) && isEmpty(QPacking)){
					printf("\n[!] Antrian proses kosong [!]");
				}else{
					printf("\nNama Barang : ");fflush(stdin);gets(namaBarang);
					if(hitungSearchProduk(QProduksi, namaBarang) + hitungSearchProduk(Qqc, namaBarang) + hitungSearchProduk(QPacking, namaBarang) == 0){
						printf("\t[!] Nama barang tidak ditemukan [!]");
					}else{
						tampilSearchProduk(QProduksi, namaBarang);
						tampilSearchProduk(Qqc, namaBarang);
						tampilSearchProduk(QPacking, namaBarang);
						printf("\n[*] %d produk ditemukan", hitungSearchProduk(QProduksi, namaBarang) + hitungSearchProduk(Qqc, namaBarang) + hitungSearchProduk(QPacking, namaBarang));						
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

