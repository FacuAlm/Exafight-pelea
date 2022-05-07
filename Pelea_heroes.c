#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CANT 13
void menu();
void iniciarBatalla();
void creditos();
void primeraEleccion();
void segundaEleccion();
void primerJugador();
void segundoJugador();

int opcion, i, j, pos, pj3, sj3, pj2, sj2, ataque;
struct datoHeroe{						// conjunto de los datos de los personajes

    char nombre[20];
    int vida;
    int poder;
    float defensa;
    int nivel;
};
struct datoHeroe heroe[CANT] = {
    {"Batman", 100, 10, 1.10, 2},
    {"Superman", 500, 100, 1.00, 3},
    {"Wonder Woman", 300, 20, 1.10, 3},
    {"Flash", 100, 10, 1.15, 1},
    {"Robin", 100, 10, 1.10, 1},
    {"Iron Man", 200, 15, 1.20, 2},							//Arreglo de estructuras
    {"Hulk", 300, 20, 1.40, 3},
    {"Capitan America", 200, 10, 1.20, 2},
    {"Thor", 300, 15, 1.20, 3},
    {"Spiderman", 100, 10, 1.10, 1},
    {"Green Lantern", 100, 10, 1.10, 1},
    {"Bruja Escarlata", 100, 10, 1.10, 1},
    {"Deadpool", 200, 25, 0.50, 2}
	
	};
struct datoHeroe eleccionp[4];
struct datoHeroe eleccions[4];

int main(){
	system("color 2");
	

    menu();
    
    system("cls");
    while(opcion!=3){
	
    switch (opcion){
    case 1:{
        primeraEleccion();
        system("cls");
        segundaEleccion();
        system("cls");

		iniciarBatalla();
        
		
		getch();
        system("cls");
        menu();
        
       

        break;
    }
    case 2:{
        creditos();
        printf("Presione cualquier tecla para volver al menu...");
        getch();
        system("cls");
        
        menu();
        
        

        break;
    }
    case 3:{
    	
        exit(0);
        break;
    }
    default:{
    	printf("Te has equivocado de tecla. Vuelve al menu principal");
    	getch();
        system("cls");
    	menu();
		break;
	}
    }
    system("cls");
    }
    
}

void menu(){
	
	printf("#########   #       #    #########    ##########   #      ##########    #        #    ############\n");
	Sleep(100);
	printf("#            #     #     #       #    #                   #             #        #         #\n");
	Sleep(100);
	printf("#             #   #      #       #    #            #      #             #        #         #\n");
	Sleep(100);
	printf("######          #        #########    #########    #      #  #######    ##########         #\n");
	Sleep(100);
	printf("#              # #       #       #    #            #      #        #    #        #         #\n");
	Sleep(100);
	printf("#             #   #      #       #    #            #      #        #    #        #         #\n"); 				//Menu del juego donde se muestra el nombre y
	Sleep(100);																												//las opciones disponigles
	printf("#########    #     #     #       #    #            #      ##########    #        #         #\n\n");
	Sleep(100);
    printf("Seleccione una opcion: \n\n");
    printf("1. Jugar\n");
    printf("2. Creditos\n");
    printf("3. Salir\n");
    scanf("%d", &opcion);
}

void primeraEleccion(){									// En esta funcion cargamos las estructutras del arreglo en otro que es el arreglo de							
    pj3 = 0;											// los personajes elegidos por el primer jugador
    pj2 = 0;
    printf("Turno del primer jugador\n");
    printf("Seleccione cuatro personajes.\n\n");
    printf("Para seleccionar un heroe presione el numero correspondiente a cada heroe, a continuacion presione ENTER\n\n");

    for (i = 0; i <= CANT-1; i++){
        printf("%d: %s---------------- Vida: %d    Poder: %d    Defensa: %.2f    Nivel: %d  \n\n", i, heroe[i].nombre, heroe[i].vida, heroe[i].poder, heroe[i].defensa, heroe[i].nivel);
    }

    for (i = 0; i < 4; i++){

        scanf("%d", &pos);

        eleccionp[i] = heroe[pos];
        	
        
        if (eleccionp[i].nivel == 3){
            pj3++;
        }
        if (pj3 > 1)
        {
            printf("No puede tener mas de un personaje nivel 3");
            system("pause");
            system("cls");
            primeraEleccion();
        }

        if (eleccionp[i].nivel == 2)
        {
            pj2++;
        }
        if (pj2 > 2)
        {
            printf("No puede tener mas de dos personajes nivel 2");
            system("pause");
            system("cls");

            primeraEleccion();
        }
    }
    
    system("cls");
    printf("Los Heroes elegidos por el jugador 1 son: \n");
    for (i = 0; i < 4; i++)
    {
        printf("%d: %s\n", i, eleccionp[i]);
    }

    system("pause");
}
void segundaEleccion(){									// En esta funcion cargamos las estructutras del arreglo en otro que es el arreglo de
    sj3 = 0;											// los personajes elegidos por el Segundo  jugador
    sj2 = 0;
    printf("Turno del segundo jugador\n");
    printf("Seleccione cuatro personajes\n");
	
    for (j = 0; j <= CANT-1; j++)
    {
        printf("%d: %s ----------------  Vida: %d Poder: %d Defensa: %.2f Nivel: %d  \n\n", j, heroe[j].nombre, heroe[j].vida, heroe[j].poder, heroe[j].defensa, heroe[j].nivel);
    }
	
    for (j = 0; j < 4; j++)
    {

        scanf("%d", &pos);
        

        eleccions[j] = heroe[pos];
        
        
        if (eleccions[j].nivel == 3)
        {
            sj3++;
        }
        if (sj3 > 1)
        {
            printf("No puede tener mas de un personaje nivel 3");
            system("pause");
            system("cls");
            segundaEleccion();
        }

        if (eleccions[j].nivel == 2)
        {
            sj2++;
        }
        if (sj2 > 2)
        {
            printf("No puede tener mas de dos personajes nivel 2");
            system("pause");
            system("cls");

            segundaEleccion();
        }
        
    }
    
    system("cls");
    printf("Los Heroes elegidos por el jugador 2 son: \n");
    for (j = 0; j < 4; j++)
    {
    
        printf("%d: %s\n", j, eleccions[j]);
       
    }
    
    system("pause");
}

void primerJugador(){
    printf("Turno del primer Jugador\n");

    printf("Presione 1 para atacar\n");
    scanf("%d", &ataque);
    printf("%s ataco a %s!!! \n", eleccionp[i].nombre, eleccions[j].nombre);
    eleccions[j].vida = (eleccions[j].vida * eleccions[j].defensa) - eleccionp[i].poder;
    if (eleccions[j].vida<=0){
	eleccions[j].vida=0;
    
    }
    printf("La vida de %s es %d \n", eleccions[j].nombre, eleccions[j].vida);
}

void segundoJugador(){
    printf("Turno del segundo Jugador\n");

    printf("Presione 1 para atacar\n");
    scanf("%d", &ataque);
    printf("%s ataco a %s!!! \n", eleccions[j].nombre, eleccionp[i].nombre);
    eleccionp[i].vida = (eleccionp[i].vida * eleccionp[i].defensa) - eleccions[j].poder;
    if (eleccionp[i].vida<=0){
	eleccionp[i].vida=0;
    
    }
    printf("La vida de %s es %d \n", eleccionp[i].nombre, eleccionp[i].vida);
}

void iniciarBatalla(){
	        for (i = 0; i <= 4; i++)
        {
            for (j = 0; j <= 4; j++)
            {

                while (eleccionp[i].vida > 0 && eleccions[j].vida > 0)
                {
                    printf("La batalla es entre %s vs %s\n\n", eleccionp[i].nombre, eleccions[j].nombre);

                    primerJugador();
                    system("pause");
                    system("cls");
                    if (eleccions[j].vida <= 0)
                    {
                        printf("EL JUGADOR 1 HA GANADO LA PARTIDA!!!\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {

                        printf("La batalla es entre %s vs %s\n\n", eleccionp[i].nombre, eleccions[j].nombre);
                        segundoJugador();
                        system("pause");
                        system("cls");
                    }
                    if (eleccionp[i].vida <= 0)
                    {
                        printf("EL JUGADOR 2 HA GANADO LA PARTIDA!!!\n");
                        system("pause");
                        system("cls");
                    }
                }
            }
        }
        printf("Juego terminado. Presione cualquier tecla para volver al menu\n");
        getch();
        system("cls");

}


		




