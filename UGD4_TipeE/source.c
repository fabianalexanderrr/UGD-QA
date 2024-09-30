#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

Pengunjung createPengunjung(int nomorPengunjung, string jenis){
	Pengunjung temp;
	
	temp.nomorPengunjung = nomorPengunjung;
	strcpy(temp.jenis, jenis);

	return temp;
}

Pengunjung clearPengunjung(){
	Pengunjung temp;
	
	temp.nomorPengunjung = 0;
	strcpy(temp.jenis, "-");

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

void Enqueue(Queue *Q, Pengunjung P){
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

Pengunjung Dequeue(Queue *Q){
	Pengunjung temp = (*Q).P[(*Q).head];

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

void printSedangBermain(Pengunjung P1, Pengunjung P2){
	if(P1.nomorPengunjung != 0)
		printf("[ %d ] vs [ %d ]", P1.nomorPengunjung, P2.nomorPengunjung);
	else
		printf("-");
}

void printAntrian(Queue Q1, Queue Q2){
	if(isEmpty(Q1) && isEmpty(Q2))
		printf("\n[!] Antrian Pengunjung Kosong [!]");
	
	int i;
	
	if(!isEmpty(Q1)){
		if(Q1.head <= Q1.tail){
			for(i = Q1.head; i <= Q1.tail; i++)
				printf("[ %d ] ", Q1.P[i].nomorPengunjung);
		}else{
			for(i = Q1.head; i <= MAX_SIZE - 1; i++)
				printf("[ %d ] ", Q1.P[i].nomorPengunjung);
	 
			for(i = 0; i <= Q1.tail; i++)
				printf("[ %d ] ", Q1.P[i].nomorPengunjung);
		}
	}
	if(!isEmpty(Q2)){
		if(Q2.head <= Q2.tail){
			for(i = Q2.head; i <= Q2.tail; i++)
				printf("[ %d ] ", Q2.P[i].nomorPengunjung);
		}else{
			for(i = Q2.head; i <= MAX_SIZE - 1; i++)
				printf("[ %d ] ", Q2.P[i].nomorPengunjung);
	 
			for(i = 0; i <= Q2.tail; i++)
				printf("[ %d ] ", Q2.P[i].nomorPengunjung);
		}
	}
}

void printPengunjung(Pengunjung P){
	printf("\nNomor Pengunjung : %d", P.nomorPengunjung);
	printf("\nJenis Pengunjung : %s\n", P.jenis);
}

void printAllPengunjung(Queue Q){
	if(!isEmpty(Q)){
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printPengunjung(Q.P[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printPengunjung(Q.P[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printPengunjung(Q.P[i]);
		}
	}
}

int sisaAntrian(Queue Q1, Queue Q2, int nomorPengunjung){
	int i, temp = 0;
	
	if(!isEmpty(Q1)){
		if(Q1.head <= Q1.tail){
			for(i = Q1.head; i <= Q1.tail; i++){
				if(Q1.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
			}
		}else{
			for(i = Q1.head; i <= MAX_SIZE - 1; i++){
				if(Q1.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
			}
	 
			for(i = 0; i <= Q1.tail; i++){
				if(Q1.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
			}
		}
	}
	
	if(Q2.head <= Q2.tail){
		for(i = Q2.head; i <= Q2.tail; i++){
			if(Q2.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
		}
	}else{
		for(i = Q2.head; i <= MAX_SIZE - 1; i++){
			if(Q2.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
		}
 
		for(i = 0; i <= Q2.tail; i++){
			if(Q2.P[i].nomorPengunjung == nomorPengunjung)
					return temp;
				else
					temp++;
		}
	}
	return -1;
}

int countData(Queue Q){	
	int count = 0;
	
	if(!isEmpty(Q)){
		int i;
		
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				count++;		
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				count++;
	 
			for(i = 0; i <= Q.tail; i++)
				count++;	
		}
	}
	
	return count;
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
