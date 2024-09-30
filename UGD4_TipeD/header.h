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
	int ukuran;
	string namaProses, priority;
} Proses;

typedef struct {
	Proses P[MAX_SIZE];
	int head, tail;
} Queue;

Proses createProses(int ukuran, string namaProses, string priority);
void createEmpty(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);
bool isNamaUnik(Queue QLow, Queue QHigh, string namaProses);

void Enqueue(Queue *Q, Proses P);
void Dequeue(Queue *Q);

void printProses(Proses P);
void printQueue(Queue Q);
void printAll(Queue QLow, Queue QHigh);

void EnqueueRiwayat(Queue *Q, Proses P);
void DequeueRiwayat(Queue *Q);
void printRiwayat(Queue Q);

float estimasiWaktu(Queue QLow, Queue QHigh, string namaProses);
