//Sistema de pago crediticio SERFIGSA
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 80
using namespace std; 

typedef struct
{
    int dia;
    int mes;
    int ano;
} fechaTransaccion;

typedef struct
{
    char nombre[30];
    char apellido[30];
    char cedula[15];
    char estadoCiv[30];
    char email[100];
    int telef[8];
}cliente;

cliente client[MAX];
int ultRegis = 0;

//Funciones CRUD

//CREATE
void addClient(cliente cl);
//READ
void showClient(int pos);
void showClients();
int isClient(char id[]);
void startClient(int pos);
cliente getClient(int pos);
//UPDATE
void updateClient(cliente cl, int pos);
//DELETE
void deleteClient(int pos);

//OPCIONES
int menu();
void start();

//FICHEROS
FILE *registroCliente;
void saveClientes();
void readClientes();
int calcLastReg(FILE *archivo);


