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
	int nomorPengunjung;
	string jenis;
} Pengunjung;

typedef struct {
	Pengunjung P[MAX_SIZE];
	int head, tail;
} Queue;

Pengunjung createPengunjung(int nomorPengunjung, string jenis);
Pengunjung clearPengunjung();
void createEmpty(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);

void Enqueue(Queue *Q, Pengunjung P);
Pengunjung Dequeue(Queue *Q);

void printSedangBermain(Pengunjung P1, Pengunjung P2);
void printAntrian(Queue Q1, Queue Q2);
void printPengunjung(Pengunjung P);
void printAllPengunjung(Queue Q);

int countData(Queue Q);
int sisaAntrian(Queue Q1, Queue Q2, int nomorPengunjung);

void DequeueRiwayat(Queue *Q);
