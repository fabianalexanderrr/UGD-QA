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
	int nomorProduksi;
	string namaBarang, status;
} Produk;

typedef struct {
	Produk P[MAX_SIZE];
	int head, tail;
} Queue;

Produk createProduk(int nomorProduksi, string namaBarang, string status);
void createEmpty(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);

void Enqueue(Queue *Q, Produk P);
Produk Dequeue(Queue *Q);

void printProduk(Produk P);
void printQueue(Queue Q);

int countData(Queue Q);
int hitungSearchProduk(Queue Q, string cari);
void tampilSearchProduk(Queue Q, string cari);
