/*
   Proyecto
   Diana Estefania Ortiz Ledesma
   A01209403
   19 de junio de 2018
*/

// Incluir librerias
#include <stdlib.h> // libreria standar
#include <stdio.h>  // libreria standar input/output

/**
  * Imprime el menu principal del programa
  */
void menu_principal(){
    printf("\n ");
    printf("Trivia : How I Met Your Mother\n");
    printf("1. Instrucciones\n");
    printf("2. Comenzar Partida\n");
    printf("3. Instrucciones Agregar Preguntas\n");
    printf("4. Agregar Preguntas\n");
    printf("5. Salir\n");
    printf("Ingresar opcion que se quiera realizar: ");
}

/**
  * Imprime instrucciones
  */
void imprimir_instrucciones(){
    FILE * archivo;
    char letra;
    archivo = fopen("instrucciones.txt","r");
    if(archivo != NULL){
        printf("\n");
        letra = fgetc(archivo);
            while(letra != EOF){
                printf("%c", letra);
                letra = getc(archivo);
        }

    }
        else printf("El archivo no existe");
    fclose(archivo);
}

/**
  * Imprime hasta el salto de linea
  * @param FILE * archivo : archivo que se lee e imprime
  */
void imprimir(FILE * archivo) {
    char linea = ' ';
    while (linea != '\n'){
        fscanf(archivo, "%c", &linea);
        printf("%c", linea);
    }
}

/**
  * Conocer valor del archivo
  * @param FILE * archivo : archivo
  * @return numero : valor de la linea en el archivo
  */
int numero_archivo(FILE * archivo) {
    int numero = 0;
    while (numero != '\n'){
        fscanf(archivo, "%i", &numero);
        return numero;
    }
}

/**
  * Conocer valor ingresado por el jugador
  * @return respuesta : valor ingresado
  */
int respuesta_ingresada() {
    printf("Ingresar valor de la respuesta correcta : ");
    int respuesta = 0;
    scanf("%i", &respuesta);
    return respuesta;
}

/**
  * Pausa la ejecución del programa y luego limpia la pantalla
 */
void pausa() {
    system("pause");
    system("cls");
}

/**
  * Finaliza la trivia
  */
void fin_trivia() {
    printf("\t Fin de la trivia \n \n");
    printf("\t Gracias por participar \n \n");
}

/**
  * Imprime frase al perder la trivia
  */
void perder() {
    printf ("\n \t Ups! Alcanzaste el limite de preguntas incorrectas! \n \n");
    printf ("\t Suerte para la proxima \n \n");
    fin_trivia();
}

/**
  * Imprime frase al ganar la trivia
  */
void ganar() {
    printf("\n \t Felicidades! Completaste la trivia con menos de cinco errores! \n \n");
    fin_trivia();
}

/**
  * Imprime pregunta con opciones de respuesta e instruccion para ingresar respuesta
  * Evalua la respuesta
  */
void preguntas_completas(){
    FILE * preguntas = fopen("preguntas1.txt", "r");
    FILE * respuestas1 = fopen("respuestas1.txt", "r");
    FILE * respuestas2 = fopen("respuestas2.txt", "r");
    FILE * respuestas3 = fopen("respuestas3.txt", "r");
    FILE * respuestas = fopen("respuestas.txt", "r");
    int i;
    int correctas = 0;
    int incorrectas = 0;
    for (i = 0; i < 31; i++){
        printf("\t Challenge Accepted \n \n");
        imprimir(preguntas);
        imprimir(respuestas1);
        imprimir(respuestas2);
        imprimir(respuestas3);
        if (respuesta_ingresada() == numero_archivo(respuestas)){
            correctas = correctas + 1;
            printf("Correcto!\n");
            printf("Respuestas correctas : %i \n \n", correctas);
            pausa();
            if (i == 30){
                ganar();
            }
        }
        else {
                incorrectas = incorrectas + 1;
                printf("Incorrecto!\n");
                printf("Respuestas incorrectas : %i\n" , incorrectas);
                pausa();
                if (incorrectas == 5){
                    perder();
                    pausa();
                    return 0;
                }
        }
    }
    fclose(preguntas);
    fclose(respuestas1);
    fclose(respuestas2);
    fclose(respuestas3);
    fclose(respuestas);
}

/**
  * Imprime instrucciones para agregar preguntas
  */
void imprimir_instrucciones1(){
    FILE * archivo;
    char letra;
    archivo = fopen("instrucciones1.txt","r");
    if(archivo != NULL){
        printf("\n");
        letra = fgetc(archivo);
            while(letra != EOF){
                printf("%c", letra);
                letra = getc(archivo);
        }

    }
        else printf("El archivo no existe");
    fclose(archivo);
}

/**
  * Imprime el menu para preguntas completas
  */
void menu_preguntas(){
    printf("1. Agregar pregunta\n");
    printf("2. Agregar respuesta numero uno\n");
    printf("3. Agregar respuesta numero dos\n");
    printf("4. Agregar respuesta numero tres\n");
    printf("5. Agregar valor de respuesta\n");
    printf("6. Menu principal\n");
    printf("Ingresar opcion que se quiera realizar: ");
}

/**
  * Agrega cadena que contiene la pregunta al archivo correspondiente
  */
void agregar_pregunta(){
    FILE * archivo = fopen("preguntas1.txt", "at");
    char frase[50];
    printf ("Escribir pregunta : ");
    gets (frase);
    fprintf (archivo, "%s", frase);
    fclose (archivo);
}

/**
  * Agrega cadena que contiene la primer respuesta al archivo correspondiente
  */
void agregar_respuesta1(){
    FILE * archivo = fopen("respuestas1.txt", "at");
    char frase[50];
    printf ("Escribir respuesta con 1. : ");
    gets (frase);
    fprintf (archivo, "%s", frase);
    fclose (archivo);
}

/**
  * Agrega cadena que contiene la segunda respuesta al archivo correspondiente
  */
void agregar_respuesta2(){
    FILE * archivo = fopen("respuestas2.txt", "at");
    char frase[50];
    printf ("Escribir respuesta con 2. : ");
    gets (frase);
    fprintf (archivo, "%s", frase);
    fclose (archivo);
}

/**
  * Agrega cadena que contiene la tercer respuesta al archivo correspondiente
  */
void agregar_respuesta3(){
    FILE * archivo = fopen("respuestas3.txt", "at");
    char frase[50];
    printf ("Escribir respuesta con 3. : ");
    gets (frase);
    fprintf (archivo, "%s", frase);
    fclose (archivo);
}

/**
  * Agrega entero que contiene valor de respuesta correcta al archivo correspondiente
  */
void agregar_valor(){
    FILE * archivo = fopen("respuestas.txt", "at");
    char valor[2];
    printf ("Escribir valor de respuesta correcta : ");
    gets (valor);
    fprintf (archivo, "%s", valor);
    fprintf (archivo, "\n");
    fclose (archivo);
}

/**
  * Imprime menu para agregar cada parte de una pregunta completa
  * Ejecuta cada opcion
  */
void agregar_preguntascompletas(){
while(1){
    menu_preguntas();
    int numero = 0;
    scanf("%i%*c", &numero);
    switch(numero){
        case 1 :
                agregar_pregunta();
                pausa();
            break;
        case 2 :
                agregar_respuesta1();
                pausa();
            break;
        case 3 :
                agregar_respuesta2();
                pausa();
            break;
        case 4 :
                agregar_respuesta3();
                pausa();
            break;
        case 5 :
                agregar_valor();
                pausa();
            break;
        case 6 :
                pausa();
                return 0;
            break;
        }
    }
}

int main(){
    while(1){
        menu_principal();
        int opcion = 0;
        scanf("%i%*c", &opcion);
        pausa();
        switch(opcion){
            case 1:
                    imprimir_instrucciones();
                    pausa();
                break;
            case 2:
                    preguntas_completas();
                break;
            case 3:
                    imprimir_instrucciones1();
                    pausa();
                break;
            case 4:
                    agregar_preguntascompletas();
                break;
            case 5:
                break;
        }
    }
}
