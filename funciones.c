#include <stdio.h>
#include <string.h>
#include "funciones.h"

void limpiarBuffer() {
    while (getchar() != '\n');
}

float validarFloat(const char* mensaje) {
    float valor;
    int valido;
    do {
        printf("%s", mensaje);
        valido = scanf("%f", &valor);
        
        // Verificar si el valor es positivo
        if (valido != 1 || valor <= 0) {
            printf("Error: Ingrese un número positivo.\n");
            limpiarBuffer();
            valido = 0;
            continue;
        }

        // Extraer la parte decimal
        float decimal = valor - (int)valor;
        
        // Verificar si la parte decimal es mayor a 0.6
        if (decimal > 0.59) {
            printf("Error: La parte decimal no puede ser mayor a 0.59\n");
            limpiarBuffer();
            valido = 0;
            continue;
        }

        // Verificar que solo se hayan ingresado números
        if (getchar() != '\n') {
            printf("Error: Ingrese solo números.\n");
            limpiarBuffer();
            valido = 0;
        }
    } while (!valido);
    return valor;
}

int validarInt(const char* mensaje) {
    int valor;
    int valido;
    do {
        printf("%s", mensaje);
        valido = scanf("%d", &valor);
        
        if (valido != 1 || valor < 0) {
            printf("Error: Ingrese un número entero no negativo.\n");
            limpiarBuffer();
            valido = 0;
        } else if (getchar() != '\n') {
            printf("Error: Ingrese solo números enteros.\n");
            limpiarBuffer();
            valido = 0;
        }
    } while (!valido);
    return valor;
}

void ingresarProductos(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int *total_productos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nIngreso de producto #%d:\n", i + 1);
        if (*total_productos >= 5) {
        printf("No se pueden agregar más productos.\n");
        return;
    }
    
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombres[*total_productos]);
    
    printf("Ingrese el tiempo de fabricación por unidad (minutos): ");
    scanf("%d", &tiempos[*total_productos]);
    
    printf("Ingrese los recursos necesarios por unidad: ");
    scanf("%d", &recursos[*total_productos]);
    
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &cantidades[*total_productos]);
    
    (*total_productos)++;
    printf("Producto agregado exitosamente.\n");
    }
}

void editarProducto(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos) {
    char nombre[5];
    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %[^\n]", nombre);
    
    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            printf("Nombre actual: %s\n", nombres[i]);
            printf("Nuevo nombre: ");
            scanf(" %[^\n]", nombres[i]);
            printf("Nuevo tiempo de fabricación por unidad (minutos): ");
            scanf("%d", &tiempos[i]);
            printf("Nuevos recursos por unidad: ");
            scanf("%d", &recursos[i]);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            printf("Producto editado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int *total_productos) {
    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf(" %[^\n]", nombre);
    
    for (int i = 0; i < *total_productos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            for (int j = i; j < *total_productos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            (*total_productos)--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcularTiempoYRecursos(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos) {
    int tiempo_total = 0;
    int recursos_totales = 0;

    for (int i = 0; i < total_productos; i++) {
        tiempo_total += tiempos[i] * cantidades[i];
        recursos_totales += recursos[i] * cantidades[i];
    }

    printf("Tiempo total necesario: %d minutos\n", tiempo_total);
    printf("Recursos totales necesarios: %d unidades\n", recursos_totales);
}

void verificarViabilidad(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos, float tiempo_disponible, int recursos_disponibles) {
    float tiempo_total = 0;
    int recursos_totales = 0;

    for (int i = 0; i < total_productos; i++) {
        tiempo_total += tiempos[i] * cantidades[i];
        recursos_totales += recursos[i] * cantidades[i];
    }

    if (tiempo_total <= tiempo_disponible && recursos_totales <= recursos_disponibles) {
        printf("Es viable cumplir con la demanda.\n");
    } else {
        printf("No es viable cumplir con la demanda.\n");
        if (tiempo_total > tiempo_disponible) {
            printf("Falta tiempo: %d minutos\n", tiempo_total - tiempo_disponible);
        }
        if (recursos_totales > recursos_disponibles) {
            printf("Faltan recursos: %d unidades\n", recursos_totales - recursos_disponibles);
        }
    }
}

void mostrarProductos(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("%d. %s - Tiempo: %d min/unidad, Recursos: %d/unidad, Cantidad: %d\n",
               i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
    printf("\n");
}




void menuPrincipal() {
    int opcion;
    int total_productos = 0;
    float tiempo_disponible;
    int recursos_disponibles;
    char nombres[5][50];
    int tiempos[5], recursos[5], cantidades[5];

    tiempo_disponible = validarFloat("Ingrese el tiempo disponible(horas.minutos): ");
    recursos_disponibles = validarInt("Ingrese la cantidad total de recursos disponibles: ");

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ingresar multiples productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular tiempo y recursos\n");
        printf("5. Verificar viabilidad\n");
        printf("6. Mostrar productos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("Opción inválida. Ingrese un número.\n");
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                int cantidad = validarInt("¿Cuántos productos desea ingresar? ");
                ingresarProductos(nombres, tiempos, recursos, cantidades, &total_productos, cantidad);
                break;
            }
            case 2: 
                editarProducto(nombres, tiempos, recursos, cantidades, total_productos); 
                break;
            case 3: 
                eliminarProducto(nombres, tiempos, recursos, cantidades, &total_productos); 
                break;
            case 4: 
                calcularTiempoYRecursos(nombres, tiempos, recursos, cantidades, total_productos); 
                break;
            case 5: 
                verificarViabilidad(nombres, tiempos, recursos, cantidades, total_productos, tiempo_disponible, recursos_disponibles); 
                break;
            case 6: 
                mostrarProductos(nombres, tiempos, recursos, cantidades, total_productos); 
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default: 
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 7);
}
