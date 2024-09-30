#include "header.h"

// NAMA LENGKAP
// NPM
// KELAS

Proses createProses(int ukuran, string namaProses, string priority){
	Proses temp;
	
	temp.ukuran = ukuran;
	strcpy(temp.namaProses, namaProses);
	strcpy(temp.priority, priority);
	
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

bool isNamaUnik(Queue QLow, Queue QHigh, string namaProses){
	if(isEmpty(QLow) && isEmpty(QHigh))
		return true;
	else{
		int i;

		if(QLow.head <= QLow.tail){
			for(i = QLow.head; i <= QLow.tail; i++)
				if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
					return false;
		}else{
			for(i = QLow.head; i <= MAX_SIZE - 1; i++)
				if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
					return false;
	 
			for(i = 0; i <= QLow.tail; i++)
				if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
					return false;
		}
		
		if(!isEmpty(QHigh)){
			if(QHigh.head <= QHigh.tail){
				for(i = QHigh.head; i <= QHigh.tail; i++)
					if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
						return false;
			}else{
				for(i = QHigh.head; i <= MAX_SIZE - 1; i++)
					if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
						return false;
		 
				for(i = 0; i <= QHigh.tail; i++)
					if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
						return false;
			}
		}
		return true;
	}
}

void Enqueue(Queue *Q, Proses P){
	int tempUkuran = 0;
	
	if(P.ukuran > 8){
		tempUkuran = P.ukuran - 8;
		P.ukuran = 8;
	}
	
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
	
	if(tempUkuran > 0) {
		P.ukuran = tempUkuran;
		Enqueue(*(&Q), P);
	}
}

void Dequeue(Queue *Q){
	Proses temp = (*Q).P[(*Q).head];

	if(isOneElement(*Q))
		createEmpty(&(*Q));
	else{
		if((*Q).head == MAX_SIZE - 1)
			(*Q).head = 0; 
		else 
			(*Q).head++; 
	}
}

void printProses(Proses P){
	printf("\nNama Proses : %s", P.namaProses);
	printf("\nUkuran	    : %d", P.ukuran);
	printf("\nPriority    : %s\n", P.priority);
}

void printQueue(Queue Q){
	int i;

	if(Q.head <= Q.tail){
		for(i = Q.head; i <= Q.tail; i++)
			printProses(Q.P[i]);
	}else{
		for(i = Q.head; i <= MAX_SIZE - 1; i++)
			printProses(Q.P[i]);
 
		for(i = 0; i <= Q.tail; i++)
			printProses(Q.P[i]);
	}
}

void printAll(Queue QLow, Queue QHigh) {
	if(isEmpty(QLow) && isEmpty(QHigh))
		printf("\n[!] Antrian proses kosong [!]");
	else{
		if(!isEmpty(QHigh))
			printQueue(QHigh);
		if(!isEmpty(QLow))
			printQueue(QLow);
	}	
}

void EnqueueRiwayat(Queue *Q, Proses P){
	if(strcmp(P.namaProses, (*Q).P[(*Q).tail].namaProses) == 0)
		(*Q).P[(*Q).tail].ukuran = (*Q).P[(*Q).tail].ukuran + P.ukuran;
	else{
		if(isFull(*Q))
			DequeueRiwayat(&(*Q));
		
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
		printf("\n[!] Riwayat proses kosong [!]");
	else{
		int i;
	
		if(Q.head <= Q.tail){
			for(i = Q.head; i <= Q.tail; i++)
				printProses(Q.P[i]);
		}else{
			for(i = Q.head; i <= MAX_SIZE - 1; i++)
				printProses(Q.P[i]);
	 
			for(i = 0; i <= Q.tail; i++)
				printProses(Q.P[i]);
		}
	}
}

float estimasiWaktu(Queue QLow, Queue QHigh, string namaProses){
	int i;
	float temp = 0;
	
	if(!isEmpty(QHigh)){
		if(QHigh.head <= QHigh.tail){
			for(i = QHigh.head; i <= QHigh.tail; i++){
				temp = temp + QHigh.P[i].ukuran;
				if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
					return temp / 2;
			}
		}else{
			for(i = QHigh.head; i <= MAX_SIZE - 1; i++){
				temp = temp + QHigh.P[i].ukuran;
				if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
					return temp / 2;
			}
	 
			for(i = 0; i <= QHigh.tail; i++){
				temp = temp + QHigh.P[i].ukuran;
				if(strcmpi(QHigh.P[i].namaProses, namaProses) == 0)
					return temp / 2;
			}
		}
	}
	
	if(QLow.head <= QLow.tail){
		for(i = QLow.head; i <= QLow.tail; i++){
			temp = temp + QLow.P[i].ukuran;
			if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
				return temp / 2;
		}
	}else{
		for(i = QLow.head; i <= MAX_SIZE - 1; i++){
			temp = temp + QLow.P[i].ukuran;
			if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
				return temp / 2;
		}
 
		for(i = 0; i <= QLow.tail; i++){
			temp = temp + QLow.P[i].ukuran;
			if(strcmpi(QLow.P[i].namaProses, namaProses) == 0)
				return temp / 2;
		}
	}
	return -1;
}
