#include <stdio.h>
#define TAM 5  // Constante simbólica para la cantidad de productos

int main() {
    int codigos[TAM];
    float precios[TAM];
    int i;
    
    printf("Ingrese %d productos, se solicitará el código y precio:\n\n", TAM);
    
    // Carga de productos con validación
    for (i = 0; i < TAM; i++) {
        // Validar código de barras
        do {
            printf("Ingrese el código de barras (1-999999999): ");
            scanf("%d", &codigos[i]);
            
            if (codigos[i] < 1 || codigos[i] > 999999999) {
                printf("Error. El código de barras debe estar entre 1 y 999999999\n");
            }
        } while (codigos[i] < 1 || codigos[i] > 999999999);
        
        // Validar precio
        do {
            printf("Ingrese el precio: ");
            scanf("%f", &precios[i]);
            
            if (precios[i] < 0) {
                printf("Error. El precio no puede ser negativo\n");
            }
        } while (precios[i] < 0);
        
        printf("\n");
    }
    
    // Mostrar lista completa de productos
    printf("Código\t\tPrecio\n");
    printf("----------------------------\n");
    for (i = 0; i < TAM; i++) {
        printf("%d\t\t%.2f\n", codigos[i], precios[i]);
    }
    printf("\n");
    
    // Encontrar mayor y menor precio
    float mayor_precio = precios[0];
    float menor_precio = precios[0];
    int codigo_mayor = codigos[0];
    int codigo_menor = codigos[0];
    
    for (i = 1; i < TAM; i++) {
        if (precios[i] > mayor_precio) {
            mayor_precio = precios[i];
            codigo_mayor = codigos[i];
        }
        if (precios[i] < menor_precio) {
            menor_precio = precios[i];
            codigo_menor = codigos[i];
        }
    }
    
    // Mostrar resultados
    printf("Más caro: [%d] %.2f\n", codigo_mayor, mayor_precio);
    printf("Más barato: [%d] %.2f\n", codigo_menor, menor_precio);
    
    return 0;
}
