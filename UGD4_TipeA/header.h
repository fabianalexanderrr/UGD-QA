#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

// NAMA LENGKAP
// NPM
// KELAS

typedef char string[50];

typedef struct {
	int nomorAntrian;
	string jenisNasabah, layanan, teller;
} Nasabah;

typedef struct {
	Nasabah N[MAX_SIZE];
	int head, tail;
} Queue;

Nasabah createNasabah(int nomorAntrian, string jenisNasabah, string layanan, string teller);
Nasabah clearNasabah();
void createEmpty(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);

void EnqueueAntrian(Queue *Q, Nasabah N);
void DequeueAntrian(Queue *Q, string teller);

void printNasabah(Nasabah N);
void printAntrian(Queue Q);

void EnqueueRiwayat(Queue *Q, Nasabah N);
void DequeueRiwayat(Queue *Q);
void printRiwayat(Queue Q);

int sisaAntrian(Queue Q, int nomorAntrian);
int countData(Queue Q);
