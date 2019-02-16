/*

    Juego Domino
        - Estructura de ficha
        - Crear fichas

*/
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>

 #define TOTALFICHAS 28

 struct ficha{
     int valores[2];
 };

int orden[28];

struct ficha *nuevaFicha(int num1, int num2);

void revolverFichas();

struct ficha *fichas = NULL;

int main(){

    printf("\n----JUEGO DE DOMINO---- \n\n");
    struct ficha *temp;
    int cont=0;
    int i = 0, j = 0;

  while(i<=6){
        
        j = 0;
        while(j <= i)
        {
            fichas = realloc(fichas,(cont+1)*sizeof(struct ficha));//Reserva espacio en memoria
            temp = nuevaFicha(i,j);
            memcpy(&fichas[cont],temp,sizeof(struct ficha)); 
           // free(temp);
            cont++;
            j++;

        }
        i++;
    }

    
   // system("read -p '****press enter to continue playing...' var");
    revolverFichas();
    printf("Fichas del Juego....\n");
    system("read -p '****press enter to continue playing...' var");
    i = 0;
    for(i=0;i<cont;i++){
        printf("[%i|%i] ", fichas[orden[i]].valores[0],fichas[orden[i]].valores[1]);
       // system("read -p '****press enter to continue...' var");

    }

    printf("\nCantidad Fichas: %i \n", cont);
    printf("\n\n");

    return 0;

};

void revolverFichas(){

    int i=0, cont=0, aleatorio;
    int vec[28];
    memset(&vec,0,sizeof(int)*TOTALFICHAS);
    srand(time(NULL));
    while(i<TOTALFICHAS){
        aleatorio = rand() %28;
        if (vec[aleatorio] == 0) {
            orden[i] = aleatorio;
            i++;
            vec[aleatorio]=1;
        }
        
    }
    

};

struct ficha *nuevaFicha(int num1, int num2){

    struct ficha *nueva = calloc(1,sizeof(struct ficha)); // Reserva espacio en la memoria dinamica
 
        nueva ->valores[0] = num1;
        nueva ->valores[1] = num2;
       // printf("[%i|%i]-- ",nueva ->valores[0],nueva ->valores[1]);
        
    return nueva;
};

