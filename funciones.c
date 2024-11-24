#include <stdio.h>
#include <string.h>
#include "funciones.h"

void limpiarBuffer() {
    while (getchar() != '\n');
}
int validarInt(const char* mensaje) {
    int valor;
    int valido;
    do {
        printf("%s", mensaje);
        valido = scanf("%d", &valor);

        if (valido != 1 || valor < 0) {
            printf("Error: Ingrese un numero entero no negativo.\n");
            limpiarBuffer();
            valido = 0;
        } else if (getchar() != '\n') {
            printf("Error: Ingrese solo numeros enteros.\n");
            limpiarBuffer();
            valido = 0;
        }
    } while (!valido);
    return valor;
}
int validarInt1(const char* mensaje) {
    int valor;
    int valido;
    do {
        printf("%s", mensaje);
        valido = scanf("%d", &valor);

        if (valido != 1 || valor < 0 || valor >=6 ) {
            printf("Error: Ingrese un numero entero positivo o menor a 5 .\n");
            limpiarBuffer();
            valido = 0;
        } else if (getchar() != '\n') {
            printf("Error: Ingrese solo numeros enteros.\n");
            limpiarBuffer();
            valido = 0;
        }
    } while (!valido);
    return valor;
}
void ingresarProductos(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int *total_productos, int cantidad) {
    for (int i = 0; i < cantidad; i++) { 
        if (*total_productos >= 5) { 
            printf("No se pueden agregar mas productos. Limite alcanzado.\n");
            return; 
        }

        printf("\nIngreso de producto #%d:\n", *total_productos + 1);

        printf("Ingrese el nombre del producto: "); 
        scanf(" %[^\n]", nombres[*total_productos]); 

        printf("Ingrese el tiempo de fabricacion por lote de produccion (horas): "); 
        scanf("%d", &tiempos[*total_productos]); 

        printf("Ingrese el valor economico necesario por lote de produccion: "); 
        scanf("%d", &recursos[*total_productos]); 

        printf("Ingrese la cantidad de lotes de demandada: "); 
        scanf("%d", &cantidades[*total_productos]); 

        (*total_productos)++; 
        printf("Producto agregado exitosamente.\n");
    }
}
void editarProducto(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos registrados para editar.\n");
        return;
    }

    char nombre[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %[^\n]", nombre);

    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Producto encontrado.\n");
            int opcion = 0;
            do {
                printf("\nSeleccione lo que desea editar:\n");
                printf("1. Nombre\n");
                printf("2. Tiempo de fabricacion por lote\n");
                printf("3. Valor economico por lote\n");
                printf("4. Cantidad de lotes de demanda\n");
                printf("5. Editar todo\n");
                printf("0. Volver al menu principal\n");
                printf("Opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        printf("Nombre actual: %s\n", nombres[i]);
                        printf("Nuevo nombre: ");
                        scanf(" %[^\n]", nombres[i]);
                        printf("<<Nombre actualizado exitosamente.>>\n");
                        break;

                    case 2:
                        printf("Tiempo actual de fabricacion: %d horas\n", tiempos[i]);
                        printf("Nuevo tiempo de fabricacion (horas): ");
                        while (scanf("%d", &tiempos[i]) != 1 || tiempos[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }
                        printf("<<Tiempo actualizado exitosamente.>>\n");
                        break;

                    case 3:
                        printf("Recursos economicos actuales: $%d\n", recursos[i]);
                        printf("Nuevos recursos economicos (dolares): ");
                        while (scanf("%d", &recursos[i]) != 1 || recursos[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }
                        printf("<<Valores economicos actualizados exitosamente.>>\n");
                        break;

                    case 4:
                        printf("Cantidad actual de lotes de demanda: %d\n", cantidades[i]);
                        printf("Nueva cantidad de lotes de demanda: ");
                        while (scanf("%d", &cantidades[i]) != 1 || cantidades[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }
                        printf("<<Cantidad de lotes actualizada exitosamente.>>\n");
                        break;

                    case 5:
                        printf("Editar todos los datos del producto.\n");
                        printf("Nombre actual: %s\n", nombres[i]);
                        printf("Nuevo nombre: ");
                        scanf(" %[^\n]", nombres[i]);

                        printf("Nuevo tiempo de fabricacion por lote de produccion (horas): ");
                        while (scanf("%d", &tiempos[i]) != 1 || tiempos[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }

                        printf("Nuevos recursos economicos en dolares por lote de produccion: ");
                        while (scanf("%d", &recursos[i]) != 1 || recursos[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }

                        printf("Nueva cantidad de lotes de demanda: ");
                        while (scanf("%d", &cantidades[i]) != 1 || cantidades[i] < 0) {
                            printf("Error: Ingrese un numero entero no negativo.\n");
                            limpiarBuffer();
                        }
                        printf("<<Todos los datos del producto fueron actualizados exitosamente.>>\n");
                        break;

                    case 0:
                        printf("Volviendo al menu principal...\n");
                        break;

                    default:
                        printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                }
            } while (opcion != 0);
            return;
        }
    }

    // Si no se encuentra el producto
    printf("Producto no encontrado. Volviendo al menú principal...\n");
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
            printf("<<Producto eliminado exitosamente>>.\n");
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

    printf("Tiempo total necesario: %d horas\n", tiempo_total);
    printf("Recursos economicos totales necesarios: %d dolares\n", recursos_totales);
}

void verificarViabilidad(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos, float tiempo_disponible, int recursos_disponibles) {
    if (total_productos == 0) {
        printf("No hay productos registrados para verificar.\n");
        return;
    }

    int opcion;
    printf("Seleccione la opcion para verificar la viabilidad:\n");
    printf("1. Verificar viabilidad en general\n");
    printf("2. Verificar viabilidad por producto\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Verificación en general
        float tiempo_total = 0;
        int recursos_totales = 0;

        for (int i = 0; i < total_productos; i++) {
            tiempo_total += tiempos[i] * cantidades[i];
            recursos_totales += recursos[i] * cantidades[i];
        }

        if (tiempo_total <= tiempo_disponible && recursos_totales <= recursos_disponibles) {
            printf("\nEs viable cumplir con la demanda en general.\n");
            printf("Tiempo disponible: %.2f horas, Tiempo requerido: %.2f horas\n", tiempo_disponible, tiempo_total);
            printf("Recursos disponibles: %d dólares, Recursos requeridos: %d dólares\n", recursos_disponibles, recursos_totales);
        } else {
            printf("\nNo es viable cumplir con la demanda en general.\n");
            if (tiempo_total > tiempo_disponible) {
                printf("Falta tiempo: %.2f horas\n", tiempo_total - tiempo_disponible);
            }
            if (recursos_totales > recursos_disponibles) {
                printf("Faltan recursos economicos: %d dólares\n", recursos_totales - recursos_disponibles);
            }
        }
    } else if (opcion == 2) {
        // Verificación por producto
        printf("\nViabilidad por producto:\n");
        for (int i = 0; i < total_productos; i++) {
            float tiempo_requerido = tiempos[i] * cantidades[i];
            int recursos_requeridos = recursos[i] * cantidades[i];

            printf("\nProducto: %s\n", nombres[i]);
            printf("Tiempo requerido: %.2f horas, Tiempo disponible: %.2f horas\n", tiempo_requerido, tiempo_disponible);
            printf("Recursos requeridos: %d dolares, Recursos disponibles: %d dolares\n", recursos_requeridos, recursos_disponibles);

            if (tiempo_requerido <= tiempo_disponible && recursos_requeridos <= recursos_disponibles) {
                printf(">> Es viable fabricar este producto.\n");
            } else {
                printf(">> No es viable fabricar este producto.\n");
                if (tiempo_requerido > tiempo_disponible) {
                    printf("   Falta tiempo: %.2f horas\n", tiempo_requerido - tiempo_disponible);
                }
                if (recursos_requeridos > recursos_disponibles) {
                    printf("   Faltan recursos economicos: %d dolares\n", recursos_requeridos - recursos_disponibles);
                }
            }
        }
    } else {
        printf("Opcion invalida. Volviendo al menu principal...\n");
    }
}

void mostrarProductos(char nombres[5][50], int tiempos[5], int recursos[5], int cantidades[5], int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("%d. %s - Tiempo: %d hora/lote, Recursos: %d/dolares por lotes, Cantidad: %d\n",
               i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
    printf("\n");
}
void menuPrincipal() {
    int opcion;
    int total_productos = 0;
    int tiempo_disponible;
    int recursos_disponibles;
    int respuesta;
    char nombres[5][50];
    int tiempos[5], recursos[5], cantidades[5];
   printf("<<Electronic industries>>\n"); 

    tiempo_disponible = validarInt("Ingrese el tiempo disponible para elabroar el pedido(horas): ");
    recursos_disponibles = validarInt("Ingrese la cantidad total del capital disponible en dolares (aproximar a un numero entero): ");
    printf("<------------------------------>\n");
   do {
    printf("¿Desea ingresar productos en este momento? (1-Si/2-No): ");
    scanf("%d", &respuesta);
    
    if (respuesta < 1 || respuesta > 2) {
        printf("Error: Opcion no encontrada. Por favor, intente de nuevo.\n");
    }
} while (respuesta < 1 || respuesta > 2);

if (respuesta == 1) {
    int cantidad = validarInt1("¿Cuantos productos desea ingresar? ");
    ingresarProductos(nombres, tiempos, recursos, cantidades, &total_productos, cantidad);
}
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ingresar multiples productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular tiempo y recursos economicos en dolares\n");
        printf("5. Verificar viabilidad\n");
        printf("6. Mostrar productos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Opcion invalida. Ingrese un numero.\n");
            limpiarBuffer();
            continue;
        }
        switch (opcion) {
            case 1: {
            
                int cantidad = validarInt1("¿Cuantos productos desea ingresar? ");
                    ingresarProductos(nombres, tiempos, recursos, cantidades, &total_productos, cantidad);break;
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
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 7);
}
