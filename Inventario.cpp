#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char fecha[20];
    char producto[100];
    int cantidad;
    char nombre[200];
} registro;
int menu(int);
void abrir_inventario();
void modificar_inventario();
void registrar_salidas();
void ver_salidas();
void terminar();
int main() {
    int opcion;
    do {
        opcion = menu(opcion);
        switch (opcion) {
            case 1:
                abrir_inventario();
                break;
            case 2:
                modificar_inventario();
                break;
            case 3:
                registrar_salidas();
                break;
            case 4:
                ver_salidas();
                break;
            case 5:
                terminar();
                break;
        }
    } while (opcion != 5);
}
int menu(int op) {
    int x, y = 0;
    for (; y != 3;) {
        printf("*******************MENU******************\n");
        printf("Presione la tecla 1 para ver el inventario");
        printf("\nPresione la tecla 2 para modificar el inventario");
        printf("\nPresione la tecla 3 para registrar una salida");
        printf("\nPresione la tecla 4 para ver las salidas del dia");
        printf("\nPresione la tecla 5 para salir del programa");
        printf("\n");
        scanf("%d", &x);
        if (x <= 5 && x >= 1) {
            y = 3;
        } else {
            system("cls");
            printf("No es una opcion valida, intente nuevamente :D\n");
        }
    }
    system("cls");
    return x;
}
void modificar_inventario() {
    FILE *modi;
    char mod[1000];
    system("cls");
    modi = fopen("c:\\users\\roble\\onedrive\\escritorio\\proyecto_progra\\inventario.txt", "w");
    if (modi == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("Ingrese la modificacion a realizar: ");
    getchar();
    fgets(mod, 1000, stdin);
    fputs(mod, modi);
    fclose(modi);
}
void abrir_inventario() {
    FILE *inv;
    char l;
    system("cls");
    inv = fopen("c:\\users\\roble\\onedrive\\escritorio\\proyecto_progra\\inventario.txt", "r");
    if (inv == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    do {
        l = fgetc(inv);
        if (l != EOF) {
            printf("%c", l);
        }
    } while (l != EOF);
    fclose(inv);
    system("pause");
}
void registrar_salidas() {
    registro salidas;
    getchar();
    printf("Ingrese la fecha (DD/MM/AAAA): ");
    fgets(salidas.fecha, sizeof(salidas.fecha), stdin);
    printf("Ingrese el nombre del producto: ");
    fgets(salidas.producto, sizeof(salidas.producto), stdin);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &salidas.cantidad);
    getchar();
    printf("Ingrese el nombre del cliente: ");
    fgets(salidas.nombre, sizeof(salidas.nombre), stdin);
    system("cls");
    FILE *sali;
    sali = fopen("c:\\users\\roble\\onedrive\\escritorio\\proyecto_progra\\salidas.txt", "a");
    if (sali == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fputs(salidas.fecha, sali);
    fputs(salidas.producto, sali);
    fprintf(sali, "Cantidad: %d\n", salidas.cantidad);
    fputs(salidas.nombre, sali);
    fclose(sali);
}
void ver_salidas() {
    FILE *sal;
    char x;
    system("cls");
    sal = fopen("c:\\users\\roble\\onedrive\\escritorio\\proyecto_progra\\salidas.txt", "r");
    if (sal == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    do {
        x = fgetc(sal);
        if (x != EOF) {
            printf("%c", x);
        }
    } while (x != EOF);
    fclose(sal);
    printf("\n");
    system("pause");
}
void terminar() {
    printf("Gracias por usar el programa :D\n Vuelva pronto.");
}
