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
	string nama, urgensi;
} Pasien;

typedef struct {
	Pasien P[MAX_SIZE];
	int head, tail;
} Queue;

Pasien createPasien(int nomorAntrian, string nama, string urgensi);
Pasien clearPasien();
void createEmpty(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);

void Enqueue(Queue *Q, Pasien P);
void Dequeue(Queue *Q);

void printPasien(Pasien P);
void printAntrian(Queue Q);
