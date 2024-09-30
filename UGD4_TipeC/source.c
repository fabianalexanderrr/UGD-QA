#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

Produk createProduk(int nomorProduksi, string namaBarang, string status){
	Produk temp;
	
	temp.nomorProduksi = nomorProduksi;
	strcpy(temp.namaBarang, namaBarang);
	strcpy(temp.status, status);
	
	return temp;
}

void createEmpty(Queue *Q){
	(*Q).head = -1;
	(*Q).tail = -1;
}

bool isEmpty(Queue Q){
	if(Q.head == -1 && Q.tail == -1)
		return true;
	else
		return false;
}

bool isFull(Queue Q){
	if((Q.head < Q.tail && Q.tail - Q.head == MAX_SIZE-1) || (Q.head > Q.tail
	&& Q.head - Q.tail == 1))
		return true;
	else
		return false;
}

bool isOneElement(Queue Q){
	if(Q.head == Q.tail && !isEmpty(Q))
		return true;
	else
		return false;
}

void Enqueue(Queue *Q, Produk P){
	if(isEmpty(*Q)){ 
		(*Q).head = (*Q).tail = 0;
		(*Q).P[(*Q).tail] = P; 
	}else{
		if((*Q).tail == MAX_SIZE - 1)
			(*Q).tail = 0; 
		else
			(*Q).tail++;

		(*Q).P[(*Q).tail] = P;
	}
}

Produk Dequeue(Queue *Q){
	Produk temp = (*Q).P[(*Q).head];

	if(isOneElement(*Q))
		createEmpty(&(*Q));
	else{
		if((*Q).head == MAX_SIZE - 1)
			(*Q).head = 0; 
		else 
			(*Q).head++; 
	}
	return temp;
}

void printProduk(Produk P){
	printf("\nNomor Produksi : %d", P.nomorProduksi);
	printf("\nNama Barang    : %s", P.namaBarang);
	printf("\nStatus         : %s\n", P.status);
}

void printQueue(Queue Q){
	if(!isEmpty(Q)){
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printProduk(Q.P[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printProduk(Q.P[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printProduk(Q.P[i]);
		}
	}
}

int countData(Queue Q){	
	if(isEmpty(Q))
		return 0;
		
	int i, count = 0;
	
	if(Q.head <= Q.tail){
		for(i = Q.head; i <= Q.tail; i++)
			count++;
			
		return count;
	}else{
		for(i = Q.head; i <= MAX_SIZE - 1; i++)
			count++;
 
		for(i = 0; i <= Q.tail; i++)
			count++;
			
		return count;
	}
}

int hitungSearchProduk(Queue Q, string cari){
	int i, count = 0;
	
	if(!isEmpty(Q)){
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					count++;
				}
			}		
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					count++;
				}		
			}		
	 
			for(i = 0; i <= Q.tail; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					count++;
				}		
			}
		}
	}
	return count;
}

void tampilSearchProduk(Queue Q, string cari){
	int i;
	
	if(!isEmpty(Q)){
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					printProduk(Q.P[i]);
				}
			}		
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					printProduk(Q.P[i]);
				}		
			}		
	 
			for(i = 0; i <= Q.tail; i++){
				if(strcmpi(Q.P[i].namaBarang, cari) == 0){
					printProduk(Q.P[i]);
				}		
			}
		}
	}
}
