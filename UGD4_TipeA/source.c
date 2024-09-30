#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

Nasabah createNasabah(int nomorAntrian, string jenisNasabah, string layanan, string teller){
	Nasabah temp;
	
	temp.nomorAntrian = nomorAntrian;
	strcpy(temp.jenisNasabah, jenisNasabah);
	strcpy(temp.layanan, layanan);
	strcpy(temp.teller, teller);
	
	return temp;
}

Nasabah clearNasabah(){
	Nasabah temp;
	
	temp.nomorAntrian = 0;
	strcpy(temp.jenisNasabah, "-");
	strcpy(temp.layanan, "-");
	strcpy(temp.teller, "-");
	
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

void EnqueueAntrian(Queue *Q, Nasabah N){
	if(isEmpty(*Q)){ 
		(*Q).head = (*Q).tail = 0;
		(*Q).N[(*Q).tail] = N; 
	}else{
		if((*Q).tail == MAX_SIZE - 1)
			(*Q).tail = 0; 
		else
			(*Q).tail++;

		(*Q).N[(*Q).tail] = N;
	}
	printf("\n[*] Antrian %d ditambahkan ke antrian nasabah", N.nomorAntrian);
}

void DequeueAntrian(Queue *Q, string teller){
	strcpy((*Q).N[(*Q).head].teller, teller);
	Nasabah temp = (*Q).N[(*Q).head];

	if(isOneElement(*Q))
		createEmpty(&(*Q));
	else{
		if((*Q).head == MAX_SIZE - 1)
			(*Q).head = 0; 
		else 
			(*Q).head++; 
	}
	printf("\n[*] Antrian %d menuju ke teller %s", temp.nomorAntrian, temp.teller);
}

void printNasabah(Nasabah N){
	printf("\nNomor Antrian : %d", N.nomorAntrian);
	printf("\nJenis Nasabah : %s", N.jenisNasabah);
	printf("\nLayanan       : %s", N.layanan);
	printf("\nTeller        : %s\n", N.teller);
}

void printAntrian(Queue Q){
	if(isEmpty(Q))
		printf("\n[!] Antrian nasabah kosong [!]");
	else{
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printNasabah(Q.N[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printNasabah(Q.N[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printNasabah(Q.N[i]);
		}
	}
}

void EnqueueRiwayat(Queue *Q, Nasabah N){
	if(isFull(*Q))
		DequeueRiwayat(&(*Q));

	if(isEmpty(*Q)){ 
		(*Q).head = (*Q).tail = 0;
		(*Q).N[(*Q).tail] = N; 
	}else{
		if((*Q).tail == MAX_SIZE - 1)
			(*Q).tail = 0; 
		else
			(*Q).tail++;

		(*Q).N[(*Q).tail] = N;
	}
	printf("\n[*] Antrian %d selesai dilayani", N.nomorAntrian);

}

void DequeueRiwayat(Queue *Q){
	if(isOneElement(*Q))
		createEmpty(&(*Q));
	else{
		if((*Q).head == MAX_SIZE - 1)
			(*Q).head = 0; 
		else 
			(*Q).head++; 
	}
}

void printRiwayat(Queue Q){
	if(isEmpty(Q))
		printf("\n[!] Riwayat layanan kosong [!]");
	else{
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printNasabah(Q.N[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printNasabah(Q.N[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printNasabah(Q.N[i]);
		}
	}
}

int sisaAntrian(Queue Q, int nomorAntrian){
	int i;
	
	if(Q.head <= Q.tail){
		for(i = Q.head; i <= Q.tail; i++){
			if(Q.N[i].nomorAntrian == nomorAntrian)
				return i - Q.head;
		}
	}else{
		for(i = Q.head; i <= MAX_SIZE - 1; i++){
			if(Q.N[i].nomorAntrian == nomorAntrian)
				return i - Q.head;
		}
 
		for(i = 0; i <= Q.tail; i++){
			if(Q.N[i].nomorAntrian == nomorAntrian)
				return MAX_SIZE - Q.head + i;
		}
	}
	return -1;
}

int countData(Queue Q){	
	if(isEmpty(Q))
		return 0;
		
	if(Q.head <= Q.tail)
		return Q.tail - Q.head + 1;
	else
		return MAX_SIZE - Q.head + Q.tail;
}
