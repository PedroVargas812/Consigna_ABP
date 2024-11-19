// Declaración de funciones
void limpiarBuffer();
float validarFloat(const char* mensaje);
int validarInt(const char* mensaje);
void menuPrincipal();
void ingresarProductos(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int* total_productos, int cantidad);
void editarProducto(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int total_productos);
void eliminarProducto(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int* total_productos);
void calcularTiempoYRecursos(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int total_productos);
void verificarViabilidad(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int total_productos, float tiempo_disponible, int recursos_disponibles);
void mostrarProductos(char nombres[5][50], int tiempos[], int recursos[], int cantidades[], int total_productos);
