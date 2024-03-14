//UNIVERSIDAD TECNOLOGICA DE PEREIRA 
//Jean Paul Puerta SalaZar y David Buitrago Rodriguez.
//juego ahorcado
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <windows.h> 


using namespace std;

void menu();//funcion global (menu) 

//variables globales
char PalabraM[10];//palabra escogida para el ahorcado
char PalabraG[10];//guiones del juego
char MiMatriz[20][10]={"colombia","brasil","peru","chile","argentina","honduras","panama","bolivia","uruguay","paraguay","canada","mexico","noruega","dinamarca","alemania","francia","portugal","italia","grecia","australia"};//matriz que guarda palabras para el ahorcado
//

void gotoxy(int x,int y)//posicionamiento gotoxy
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 

 
 void Horca(int w)//funcion del dibujo del ahorcado
 {
 	/*
	 Nombre de subrutina: Horca
 	Objetivo: Dibujar la horca para el juego
 	Parametros:
 	W = Variable que trae la funcion, corresponde al numero de vidas.
 	Ejemplo de uso: Horca(3) dibuja horca con cabeza, pecho y brazo izquierdo.
 	*/
 	
 	
 	//dibuja horca sin persona.
 	gotoxy(60,5);
 	printf("_");
	gotoxy(62,5);
 	printf("_"); 
	gotoxy(64,5);
 	printf("_");
	gotoxy(66,5);
 	printf("_"); 
 	gotoxy(63,5);
 	cout<<(char)(124);
 	gotoxy(63,4);
 	cout<<(char)(124);
 	gotoxy(63,3);
 	cout<<(char)(124);
 	gotoxy(63,2);
 	cout<<(char)(124);
 	gotoxy(64,1);
 	printf("_");
 	gotoxy(66,1);
 	printf("_");
 	gotoxy(68,1);
 	printf("_");
 	gotoxy(70,1);
 	printf("_");
 	gotoxy(70,2);
 	cout<<(char)(124);
 	if(w>=0)//dibuja cabeza
 	{
 		gotoxy(70,3);
 		printf("O");
	}
	if(w>0)//dibuja cabeza y brazo izquierdo.
	{
		gotoxy(69,4);
		cout<<(char)(47);
	
	}
	if(w>1)//dibuja cabeza,brazo izquierdo y pecho.
	{
		gotoxy(70,4);
		cout<<(char)(124);
	
	}
	if(w>2)//dibuja cabeza,brazo izquierdo, pecho y brazo derecho.
	{
		gotoxy(71,4);
		cout<<(char)(92);
	
	}
	if(w>3)//dibuja cabeza,brazo izquierdo, pecho, brazo derecho y pierna izquierda.
	{
		gotoxy(69,5);
		cout<<(char)(47);
	
	}
	if(w>4)//dibuja cabeza,brazo izquierdo, pecho, brazo derecho, pierna izquierda y pierna derecha.
	{
		gotoxy(71,5);
		cout<<(char)(92);
	
	}
}
 
int SeleccionarPalabra()//retorna un numero aleatorio.
{
	/*
	Nombre de subrutina: SeleccionarPalabra
	Objetivo: encontrar un numero aleatorio entre en 0 y el 19 para encontrar una posicion en MiMatriz.
	Funcion sin parametros.
	Variable num: Para guardar numero aleatorio.
	Ejemplo de uso: SeleccionarPalabra() 
	Retorna 5.
	
	
	*/
    int num;
    srand(time(NULL));//inicializa en funcion del tiempo.
    num=1+rand()%(20-1);//significara que num es un numero del 0-19.

    return (num);
}



void Comparar(char P1[], char P2[],int L1)//Parte de la jugabilidad 
{
	/*
	Nombre de la subrutina:Com
	Objetivos:Comparar la letra digitada con la cadena PalabraM a raiz del juego.
	Palametros:Dos cadenas y un entero.
	P1=Cadena que trae de la funcion AgregarPalabra y es la cadena PalabraM.
	P2=Cadena que trae de la funcion AgregarPalabra y es la cadena PalabraG.
	L1=trae de la funcion AgregarPalabra la longitud de P1 Y P2.
	Variables:
	Vida=Numero de vidad o intentos que puede tener en el juego, maximo 6 intentos.
	n=Se usa para guardar la opcion de seguir jugando o no seguir jugando.
	Caracter=Guarda la letra que digite el jugador mientras esta adivinando la palabra.
	Ejemplo de uso:Comparar("Peru","----",4) 
	----
	digite caracter: u
	---u
	*/
	
	
	int Vida=0;//inicializar vidas en 0.
	int n;
	char Caracter[1];
	while(Vida < 6)//ciclo que cuenta los intentos o para que siga jugando mientras los intentos o variable vida no aumente.
	{	
	
		printf("%s\n",P2);/*imprime la cadena guiones(PaLabraG) 
		y muestra como va cambiando si el usuario va adivinando, gracias al ciclo.*/
		
		cout<<"\ndigite caracter: \n";
		cin>>Caracter;
		fflush(stdin);//limpia buffer.
		strlwr(Caracter);//si se digita una letra mayuscula, se pasara a minuscula por el bien del juego.
		int j=0;//para uso de ciclo interno, inicializado en 0.
		int C = 0;//contador que sirve para ver si la letra que digito esta en la cadena de palabra(PalabraM)
		system("cls");//limpia pantalla
		while(j<L1)//ciclo interno, busca a lo largo de la palabra si la letra que digito esta, por eso, va de j hasta la longitud de la palabra.
		{
			if(Caracter[0]==P1[j])//condicion que sirve para ver si la letra que se digito esta en las posiciones de la cadena de palabras.
			{
				/*
				si cumple se cambiara la cadena guion en la posicion j, por la letra digitada en ese momento
				y se le suma a la variable C.
				*/
				P2[j]=Caracter[0];
				C++;
				
			}
			j++;	
		}
		//printf("contador es %d\n",c);
		//printf("l1 %d\n",L1);
		if(!C)//condicion que sirve para verificar que despues del ciclo interno C vale 0
		{
			/*si cumple significa que no se encontro la letra en la palabra,
			 ya que C solo se suma si se encuentra la palabra.
			*/
			
			Horca(Vida);//Se llama la funcion Horca para que dibuje la horca y el cuerpo segun los intentos ya que se lleva vida como parametro.
			Vida++;//se suma a vida lo que tenga mas 1.
			gotoxy(60,6);
			printf("llevas %d vidas perdida \n",Vida);
			cout<<"caracter  ";
			cout<<Caracter[0];
			cout<<" no esta \n";
		}
		if((strcmp(P1,P2) == 0))//condicion que sirve para ver si el usuario adivino la palabra.
		{
			printf("GANASTE\n\n");
			
			break;//rompe ciclo
		}
		
	}
	if(Vida==6)//si vida llega a los 6 intentos se muestra en pantalla el "PERDISTE".
	{
		printf("la palabra era\n");
		cout<<P1;
		printf("\n");
		printf("-----------\n");
		printf("PERDISTE\n\n");
		
		
	}
	for(int z=0;z<L1;z++)
	{
		P1[z]='\0';
		P2[z]='\0';
	}
		
	system("pause");
	printf("-OPCIONES-\n");
	printf("1.si quiere volver a jugar \n");
	printf("2.cualquier otro numero, si no quiere volver a jugar  \n");
	cin>>n;
	system("cls");//limpia pantalla
	if(n==1)//si el usuario digita 1, el programa hace recursion a la funcion menu y vuelve y empieza el juego.
	{
		menu();
	}
	
	
}


void AgregarPalabra(int num)//Guarda palabra en posicion num de la matriz(MiMatriz) en la cadena palabraM.
{
	/*
	Nombre de subrutina:AgregarPalabra
	Objetivos:Copiar la posicion en la matriz en una cadena.
	Parametros:
	num=trae lo que retorna la funcion SeleccionarPalabra(0-19)
	Variables:
	L1=longitud de la cadena (PalabraM).
	Ejemplo de uso:AgregarPalabra(4) copia argentina en la cadena PalabraM.
	
	*/
	strcpy(PalabraM,MiMatriz[num]);
	//printf("%s\n",PalabraM);
	
	int L1=strlen(PalabraM);
	for(int i=0;PalabraM[i]!='\0';i++)//Ciclo que usamos para formar los guiones del juego.
	{
		/*Se usa variable i en 0 para el ciclo
		el ciclo recorrera toda la cadena hasta 
		el espacio nulo*/
		PalabraG[i]='-';//Se llena de guiones por cada posicion (i).
	}
	//printf("%s\n",PalabraG);
	Comparar(PalabraM,PalabraG,L1);//Se llama funcion (Com) que se lleva a PalabraM, PalabraG,  L1.
	
}
void menu()//Llamar a otras funciones
{	
	int p=SeleccionarPalabra();//funcion entera retorna numero aleatorio entre 0-19.
 	AgregarPalabra(p);//Llama la funcion y se lleva como parametro a p.
	
}

main()//funcion principal.
{
	menu();//Llama a menu.
}
