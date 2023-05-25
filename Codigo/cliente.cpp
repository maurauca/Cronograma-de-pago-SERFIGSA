// Sistema de pago crediticio SERFIGSA
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 80
using namespace std;

// estructura fecha
typedef struct
{
    int dia;
    int mes;
    int ano;
} fecha;

// estructura solicitud
typedef struct
{
    char cedula;
    int monto;
    char producto;
    int frecuencia;
    fecha pago;
} solicitud;

// estructura datos personales de cliente
typedef struct
{
    char nombre[30];
    char apellido[30];
    char cedula[15];
    char estadoCiv[30];
    char email[100];
    char telef[8];
    fecha transaccion;
    fecha Nac;
} cliente;

cliente client[MAX];
int lastReg = 0;

solicitud soli[MAX];
int lastSolicitud = 0;

// Funciones CRUD

// CREATE
void addClient(cliente cl);
void addSolicitud(solicitud sol);
// READ
void showClient(int pos);
void showSolicitud(int pos);
void showClients();
void showSolicitudes();
int isClient(char cedula[]);
int isSolicitud(char cedula[]);
void startClient(int pos);
cliente getClient(int pos);
// UPDATE
void updateClient(cliente cl, int pos);
void updateSolicitud(solicitud soli, int pos);
// DELETE
void deleteClient(int pos);
void deleteSolicitud(int pos);

// OPCIONES
int menu();
void start();

// FICHEROS
FILE *registroCliente;
void saveClientes();
void readClientes();
int calcLastReg(FILE *archivo);

void saveClientes()
{
    registroCliente = fopen("datoscliente.bin", "wb");
    fwrite(client, sizeof(cliente), lastReg, registroCliente);
    fclose(registroCliente);
}

void readClientes()
{
    registroCliente = fopen("datoscliente.bin", "rb");
    if (registroCliente == NULL)
    {
        return;
    }
    lastReg = calcLastReg(registroCliente);
    fread(client, sizeof(cliente), MAX, registroCliente);
    fclose(registroCliente);
}

int calcLastReg(FILE *archivo)
{
    int size, num;
    fseek(archivo, 0, SEEK_END);
    size = ftell(archivo);
    rewind(archivo);
    num = size / sizeof(cliente);
    return num;
}

void addClient(cliente cl)
{
    client[lastReg] = cl;
    lastReg++;
}
void addSolicitud(solicitud sol)
{
    soli[lastSolicitud] = sol;
    lastSolicitud++;
}

void showClient(int pos)
{
    cout << "Nombre: " << client[pos].nombre << endl;
    cout << "apellidos: " << client[pos].apellido << endl;
    cout << "Cedula: " << client[pos].cedula << endl;
    cout << "Estado civil: " << client[pos].estadoCiv << endl;
    cout << "Email: " << client[pos].email << endl;
    cout << "Num de telefono: " << client[pos].telef << endl;
}

void showSolicitud(int pos)
{
    cout << "Cedula: " << soli[pos].cedula << endl;
    cout << "Monto: " << soli[pos].monto << endl;
    cout << "Producto: " << soli[pos].producto << endl;
    cout << "Frecuencia: " << soli[pos].frecuencia << endl;
    cout << "Fecha de pago: " << soli[pos].pago.dia << "/" << soli[pos].pago.mes << "/" << soli[pos].pago.ano << endl;
}

int isClient(char cedula[])
{
    int posicion = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(cedula, client[i].cedula) == 0)
        {
            posicion = i;
            break;
        }
    }
}

int isSolicitud(char cedula[])
{
    for (int i = 0; i < lastSolicitud; i++)
    {
        if (strcmp(cedula, soli[i].cedula) == 0)
        {
            return i;
        }
        
    }
    return -1; 
}

cliente getClient(int pos)
{
    return client[pos];
}

void updateClient(cliente cl, int pos)
{
    client[pos] = cl;
}

void updateSolicitud(solicitud sol, int pos){
    soli[pos] = sol;
}

void deleteClient(int pos)
{
    if (pos == lastReg)
    {
        cout << " No hay registro de este cliente. Intente de nuevo por favor. \n";
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        client[i] = client[i + 1];
    }
    lastReg--;
    startClient(lastReg);
}

void deleteSoli(int pos)
{
    if (pos == lastSolicitud)
    {
        cout << "No encontramos el registro de esta solicitud. Intente nuevamente." << endl;
        return;
    }

    for (int i = pos; i < lastSolicitud; i++)
    {
        soli[i] = soli[i+1];
    }
    lastSolicitud--;
    cout << "Solicitud eliminada correctamente. " << endl;
    
    
}

void showClients()
{
    system("cls");

    if (lastReg == 0)
    {
        cout << "No existe un registro de este cliente. Intente de nuevo \n";
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout << "+++++++++++++++++++++++++++++++++++\n";
        showClient(i);
    }
    cout << "Ultimo registro... \n";
}

void showSolicitudes()
{
    system("cls");
    if (lastSolicitud == 0)
    {
        cout << "No hay solicitudes registradas." << endl;
        return;
    }
    for (int i = 0; i < lastSolicitud; i++)
    {
        cout << "Solicitud" << i + 1 << ":" << endl;
        showSolicitud(i);
    }
}

void startClient(int pos)
{
    strcpy(client[pos].cedula, "");
    strcpy(client[pos].nombre, "");
    strcpy(client[pos].apellido, "");
    client[pos].Nac.dia = 0;
    client[pos].Nac.mes = 0;
    client[pos].Nac.ano = 0;
    strcpy(client[pos].email, "");
    strcpy(client[pos].telef, "");
    strcpy(client[pos].estadoCiv, "");
    client[pos].transaccion.dia = 0;
    client[pos].transaccion.mes = 0;
    client[pos].transaccion.ano = 0;
}

int menu()
{
    int op;
    cout << "---------------------SISTEMA DE PAGO SERFIGSA---------------------" << endl;
    cout << "Cantidad de clientes registrados: " << lastReg << endl;
    cout << "1- Iniciar registro de cliente" << endl;
    cout << "2- Editar cliente" << endl;
    cout << "3- Eliminar cliente" << endl;
    cout << "4- Buscar registro de cliente" << endl;
    cout << "5- Mostrar todos los registros de clientes" << endl;
    cout << "6- Salir del programa " << endl;
    cout << "Digite la opcion: " << endl;
    cin >> op;
    return op;
}

void start()
{
    int op, pos, answ;
    char cedula[9];
    cliente cl;
    readClientes();
    do
    {
        system("cls || clear");
        op = menu();
        switch (op)
        {
        case 1:
            cout << "Ingrese su numero de cedula, con este numero verificaremos su usuario." << endl;
            scanf(" %[^\n]", cl.cedula);
            cout << "Ingrese su nombre: " << endl;
            scanf(" %[^\n]", cl.nombre);
            cout << "Ingrese su apellido: " << endl;
            scanf(" %[^\n]", cl.apellido);
            cout << "Ingrese su fecha de nacimiento (dd/MM/yy)" << endl;
            scanf("%d/%d/%d", &cl.Nac.dia, &cl.Nac.mes, &cl.Nac.ano);
            cout << "Ingrese su email: " << endl;
            scanf(" %[^\n]", cl.email);
            cout << "Ingrese su numero telefonico: " << endl;
            scanf(" %[^\n]", cl.telef);
            cout << "Indique su estado civil (soltero, casado, viudo, divorciado, concubinato, separacion): " << endl;
            scanf(" %[^\n]", cl.estadoCiv);
            cout << "Ingrese la fecha en la que se realiza la transacción (dd/MM/yy): " << endl;
            scanf("%d/%d/%d", &cl.transaccion.dia, &cl.transaccion.mes, &cl.transaccion.ano);
            addClient(cl);
            system("pause");
            break;

        case 2:
            system("cls||clear");
            cout << "Ingrese la cedula a buscar: " << endl;
            scanf(" %[^\n]", cedula);
            pos = isClient(cedula);
            cout << "Datos a editar: " << endl;
            cout << "Cedula de cliente: " << endl;
            scanf(" %[^\n]", cl.cedula);
            cout << "Nombre de cliente: " << endl;
            scanf(" %[^\n]", cl.nombre);
            cout << "Apellido de cliente: " << endl;
            scanf(" %[^\n]", cl.apellido);
            cout << "Fecha de nacimiento de cliente: " << endl;
            scanf("%d/%d/%d", &cl.Nac.dia, &cl.Nac.mes, &cl.Nac.ano);
            cout << "Email de cliente: " << endl;
            scanf(" %[^\n]", cl.email);
            cout << "Numero telefonico de cliente: " << endl;
            scanf(" %[^\n]", cl.telef);
            cout << "Estado civil de cliente: " << endl;
            scanf(" %[^\n]", cl.estadoCiv);
            cout << "Fecha de transaccion realizada: " << endl;
            scanf("%d/%d/%d", &cl.transaccion.dia, &cl.transaccion.mes, &cl.transaccion.ano);
            updateClient(cl, pos);
            cout << "Registro actualizado exitosamente." << endl;
            system("pause");
            break;

        case 3:
            system("cls||clear");
            if (lastReg = 0)
            {
                cout << "No hay registro que eliminar." << endl;
                break;
            }
            cout << "Escriba el numero de cedula del cliente que desea identificar: " << endl;
            cin >> cedula;
            pos = isClient(cedula);
            cl = getClient(pos);
            cout << "Desea eliminar el cliente?" << endl;
            cout << "Escriba 1 para SI o 2 para NO: ";
            cin >> answ;
            if (answ == 1)
            {
                deleteClient(pos);
                cout << "Cliente eliminado... " << endl;
            }
            else
            {
                cout << "Operacion cancelada..." << endl;
            }
            system("pause");
            break;

        case 4:
            system("cls||clear");
            cout << "Escriba la cedula del cliente a buscar: " << endl;
            scanf(" %[^\n]", cedula);
            pos = isClient(cedula);
            showClient(pos);
            system("pause");
            break;

        case 5:
            system("cls||clear");
            showClients();
            system("pause");
            break;

        case 6:
            cout << "Gracias por usar nuestros servicios!" << endl;
            break;

        default:
            system("cls||clear");
            cout << "Opcion no valida..." << endl;
            system("pause");
            break;
        }
    } while (op != 6);
    saveClientes();
}
