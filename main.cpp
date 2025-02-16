#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>

#define MAX_CATEGORIAS 3
#define MAX_UNIDADES 5
#define MAX_VENTAS 100

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */	

// Definición de categorías y precios
const char* categorias[MAX_CATEGORIAS] = {"Sol", "Palco", "Sombra"};
const int precios[MAX_CATEGORIAS] = {20000, 30000, 45000};

// Estructura para almacenar una venta
struct Venta {
    char nombre[50];
    int categoria;
    int cantidad;
    int total;
};

// Variables globales para almacenamiento y estadísticas
Venta ventas[MAX_VENTAS];
int totalVentas = 0;
int estadisticas[MAX_CATEGORIAS] = {0};
int ingresos[MAX_CATEGORIAS] = {0};

// Declaración de funciones
void mostrarCategorias();
void registrarVenta();
void mostrarResumen();
void mostrarEstadisticas();

int main() {
    int opcion;
    do {
        printf("\n Menu: \n 1. Registrar venta \n 2. Mostrar resumen de ventas \n 3. Mostrar estadisticas \n 4. Salir\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarResumen();
                break;
            case 3:
                mostrarEstadisticas();
                break;
            case 4:
                printf("Saliendo... \n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo. \n");
        }
    } while (opcion != 4);
    return 0;
}

// Función para mostrar las categorías
void mostrarCategorias() {
    printf("Categorias disponibles: \n");
    for (int i = 0; i < MAX_CATEGORIAS; i++) {
        printf("%d. %s - %d CRC \n", i + 1, categorias[i], precios[i]);
    }
}

// Función para registrar una venta
void registrarVenta() {
    if (totalVentas >= MAX_VENTAS) {
        printf("Limite de ventas alcanzado. \n");
        return;
    }

    Venta v;
    printf("Ingrese nombre del comprador: ");
    scanf("%s", v.nombre);
    
    mostrarCategorias();
    printf("Seleccione una categoria (1-%d): ", MAX_CATEGORIAS);
    scanf("%d", &v.categoria);
    v.categoria--;

    if (v.categoria < 0 || v.categoria >= MAX_CATEGORIAS) {
        printf("Seleccion invalida. \n");
        return;
    }

    printf("Ingrese la cantidad de entradas (Maximo %d): ", MAX_UNIDADES);
    scanf("%d", &v.cantidad);

    if (v.cantidad <= 0 || v.cantidad > MAX_UNIDADES) {
        printf("Cantidad invalida, puede comprar maximo 5 entradas. \n");
        return;
    }

    v.total = v.cantidad * precios[v.categoria];
    ventas[totalVentas++] = v;

    // Actualizar estadísticas
    estadisticas[v.categoria] += v.cantidad;
    ingresos[v.categoria] += v.total;

    printf("Venta registrada con exito: %s compro %d entradas en %s por %d CRC \n", v.nombre, v.cantidad, categorias[v.categoria], v.total);
}

// Función para mostrar resumen de ventas
void mostrarResumen() {
    printf("\n Resumen de ventas: \n");
    for (int i = 0; i < totalVentas; i++) {
        printf("%s - %s - %d entradas - Total: %d CRC\n", ventas[i].nombre, categorias[ventas[i].categoria], ventas[i].cantidad, ventas[i].total);
    }
}

// Función para mostrar estadísticas acumuladas
void mostrarEstadisticas() {
    printf("\n Estadisticas acumuladas: \n");
    for (int i = 0; i < MAX_CATEGORIAS; i++) {
        printf("%s: %d entradas vendidas - Total recaudado: %d CRC \n", categorias[i], estadisticas[i], ingresos[i]);
    }
}
