#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

Pasien createPasien(int nomorAntrian, string nama, string urgensi){
	Pasien temp;
	
	temp.nomorAntrian = nomorAntrian;
	strcpy(temp.nama, nama);
	strcpy(temp.urgensi, urgensi);
	
	return temp;
}

Pasien clearPasien(){
	Pasien temp;
	
	temp.nomorAntrian = 0;
	strcpy(temp.nama, "-");
	strcpy(temp.urgensi, "-");

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

void Enqueue(Queue *Q, Pasien P){
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

void Dequeue(Queue *Q){
	if(isOneElement(*Q))
		createEmpty(&(*Q));
	else{
		if((*Q).head == MAX_SIZE - 1)
			(*Q).head = 0; 
		else 
			(*Q).head++; 
	}
}

void printPasien(Pasien P){
	printf("\nNomor Antrian : %d", P.nomorAntrian);
	printf("\nNama Pasien   : %s", P.nama);
	printf("\nUrgensi       : %s\n", P.urgensi);
}

void printAntrian(Queue Q){
	if(!isEmpty(Q)){
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printPasien(Q.P[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printPasien(Q.P[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printPasien(Q.P[i]);
		}
	}
}
