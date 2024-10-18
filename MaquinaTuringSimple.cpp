//Elabora por Alejandra Jiménez Venegas
//Teoría de Autómatas
/*Este código es un ejemplo de cómo se puede implementar una máquina de Turing 
en C para realizar tareas específicas, como duplicar cadenas.
La combinación de lógica de programación y gráficos permite 
visualizar el proceso de la máquina de Turing de manera interactiva.*/

#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include <graphics.h>
#include <math.h>
#define color SetConsoleTextAttribute

//dise�o
void gotoxy(int x,int y);
void cuadros(int p,int q,int c, int f);
int margen(int x1, int y1, int x2, int y2);

//Automata
void diagramaT();
void grafo();

//Funciones 
void duplicar();
void q0(int posicionCabezal,char cadena[]);
void q1(int posicionCabezal,char cadena[]);
void q2(int posicionCabezal,char cadena[]);
void q3(int posicionCabezal,char cadena[]);
void q4(int posicionCabezal,char cadena[]);

//extras
void borrar();
void bienvenida();
void mostrarMenu();

int main(){
	int opc;
	bienvenida();
	borrar();
		do{
		mostrarMenu();
	    gotoxy(10, 2);
		scanf("%d%*c",&opc);
		system("cls");
		margen(1,1,115,25);
		switch(opc){
			case 1:
	    		diagramaT();
				initwindow(1000, 600);
				grafo();
				borrar();
	    		closegraph();
	    		break;
	    	case 2: 
				duplicar();
	    		borrar();
	    		break;
	    	case 3:
	    		gotoxy(40, 13);
	    		printf("Saliendo del programa....");
	    		Sleep(500);
	    		system("cls");
	    		return 0;
		}
		system("cls");
	}while(opc!=3); 
 }  

void mostrarMenu() {
    margen(1, 1, 100, 25);
    margen(49, 1, 67, 3);
    gotoxy(50, 2);
    printf("1. Diagrama");
    margen(69, 1, 88, 3);
    gotoxy(70, 2);
    printf("2. Ingresar datos");
    margen(90, 1, 100, 3);
    gotoxy(90, 2);
    printf("3. Salir");
    margen(1, 1, 47, 3);
    gotoxy(2, 2);
    printf("Opcion:");
}

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

void grafo(){
	//Estados
	outtextxy(95, 95, const_cast<char*>("q0"));
	outtextxy(495, 95, const_cast<char*>("q1"));
	outtextxy(795, 95, const_cast<char*>("q2"));
	outtextxy(95, 495, const_cast<char*>("q3"));
	outtextxy(495, 495, const_cast<char*>("q4"));
	outtextxy(795, 495, const_cast<char*>("q5"));
	
// Transiciones
	//q0
	outtextxy(300, 80, const_cast<char*>("0;-;R"));
	outtextxy(600, 80, const_cast<char*>("1;-;R"));
	outtextxy(40, 70, const_cast<char*>("a;1;R"));
	outtextxy(40, 55, const_cast<char*>("b;0;R"));
	outtextxy(270, 160, const_cast<char*>("_;_;S"));
	//q1
	outtextxy(150, 430, const_cast<char*>("_;b;L"));
	outtextxy(450, 70, const_cast<char*>("1;1;R"));
	outtextxy(450, 55, const_cast<char*>("0;0;R"));
	outtextxy(450, 40, const_cast<char*>("a;a;R"));
	outtextxy(450, 25, const_cast<char*>("b;b;R"));
	//q2
	outtextxy(750, 85, const_cast<char*>("1;1;R")); 
	outtextxy(550, 430, const_cast<char*>("_;a;L"));
	outtextxy(750, 55, const_cast<char*>("0;0;R"));
	outtextxy(750, 35, const_cast<char*>("a;a;R"));
	outtextxy(750, 15, const_cast<char*>("b;b;R"));
	//q3
	outtextxy(40, 470, const_cast<char*>("1;1;L")); 
	outtextxy(40, 455, const_cast<char*>("0;0;L")); 
	outtextxy(40, 440, const_cast<char*>("a;a;L")); 
	outtextxy(40, 425, const_cast<char*>("b;b;L")); 
	outtextxy(70, 200, const_cast<char*>("-;0;R")); 
	//q4
	outtextxy(450, 480, const_cast<char*>("1;1;L")); 
	outtextxy(450, 465, const_cast<char*>("0;0;L")); 
	outtextxy(450, 450, const_cast<char*>("a;a;L")); 
	outtextxy(450, 435, const_cast<char*>("b;b;L")); 
	outtextxy(150, 195, const_cast<char*>("-;1;R")); 

	//flecha para q0
	line(65,105,75,100);
	line(65,105,75,100);
	line(10,100,75,100);
	
	//Nodos
	circle(100,100,30); //q0
	circle(500,100,30); //q1
	circle(800,100,30); //q2
	circle(100,500,30); //q3
	circle(500,500,30); //q4
	circle(800,500,30); //q5
	circle(800,500,25); //q5 doble para final 
	
	//Lineas/direccion
	line(125,100,775,475);//q0-q5
	line(125,100,475,85);//q0-q1
	line(125,100,775,110);//q0-q2
	line(500,125,100,475);//q1-q3
	line(800,110,500,480);//q2-q4
	line(100,480,100,125);//q3-q0
	line(500,480,100,125);//q4-q0
	
	//Retornos
	ellipse(100, 80, 0, 180, 15, 30); //q0-q0
	ellipse(500, 80, 0, 180, 15, 30); //q1-q1
	ellipse(800, 80, 0, 180, 15, 30); //q2-q2
	ellipse(100,480, 0, 180, 15, 30); //q3-q3
	ellipse(500, 480, 0, 180, 15, 30); //q4-q4
}

void duplicar() {
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    int posicionCabezal = 0, i, bandera;
    char cadena[20];

    do {
        i = 0;
        bandera = 0;
        color(hConsola, 11);
        gotoxy(35, 2);
        printf("La cadena unicamente debe contener 1 y 0");
        color(hConsola, 7);
        gotoxy(45, 5);
        printf("Cadena: ");
        gets(cadena);

        while (cadena[i] != '\0') {
            if (cadena[i] == '1' || cadena[i] == '0') {
                i++;
            } else {
            	initwindow(1000, 600);
				grafo();
				setcolor(4);
			    circle(100, 100, 30);
			    Sleep(200);
				Sleep(800);
	    		closegraph();
                gotoxy(50, 13);
                color(hConsola, 11);
                printf("Cadena invalida");
                borrar();
                bandera = 1;
                return;
            }
        }
    } while (bandera != 0);
    
    cuadros(20, 1, 11, 7);
    for (i = 0; i < 20; i++) {
        gotoxy(13 + (i * 4), 8);
        printf("%c", 231);
    }

    for (i = 0; cadena[i] != '\0'; i++) {
        gotoxy(25 + (i * 4), 8);
        printf("%c", cadena[i]);
    }

    color(hConsola, 11);
    gotoxy(25, 10);
    printf("%c", 94);
    gotoxy(22, 15);
    printf("->");

    initwindow(1000, 600);
    grafo();
    q0(posicionCabezal, cadena);
    closegraph();
}


void q0(int posicionCabezal, char cadena[]) {
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    int bandera;
    gotoxy(25, 15);
    printf("q0");
    setcolor(5);
    circle(100, 100, 30);
    Sleep(200);

    do {
        bandera = 0;
        Sleep(750);
        setcolor(5);

        switch (cadena[posicionCabezal]) {
            case '1':
                setcolor(5);
                outtextxy(600, 80, const_cast<char*>("1;-;R"));
                Sleep(500);
                setcolor(15);
                outtextxy(600, 80, const_cast<char*>("1;-;R"));
                cadena[posicionCabezal] = '-';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(100, 100, 30);
                q2(posicionCabezal, cadena);
                break;
            case '0':
                setcolor(5);
                outtextxy(300, 80, const_cast<char*>("0;-;R"));
                Sleep(500);
                setcolor(15);
                outtextxy(300, 80, const_cast<char*>("0;-;R"));
                cadena[posicionCabezal] = '-';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(100, 100, 30);
                q1(posicionCabezal, cadena);
                break;
            case 'a':
                setcolor(5);
                outtextxy(40, 70, const_cast<char*>("a;1;R"));
                cadena[posicionCabezal] = '1';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'b':
                setcolor(5);
                outtextxy(40, 55, const_cast<char*>("b;0;R"));
                cadena[posicionCabezal] = '0';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '\0':
                setcolor(5);
                outtextxy(270, 160, const_cast<char*>("_;_;S"));
                Sleep(500);
                setcolor(15);
                outtextxy(270, 160, const_cast<char*>("_;_;S"));
                setcolor(15);
                circle(100, 100, 30);
                setcolor(2);
                circle(800, 500, 30);
                setcolor(2);
                circle(800, 500, 25); // q5 doble
                Sleep(5000);
                gotoxy(25, 15);
                printf("q5");
                setcolor(15);
                circle(800, 500, 30);
                setcolor(15);
                circle(800, 500, 25); //Doble circ plara q5
                color(hConsola, 11);
                gotoxy(37, 15);
                printf("La cadena es valida            ");
                puts(cadena);
                Sleep(2000);
                break;
        }

        Sleep(500);
        setcolor(15);
        outtextxy(40, 70, const_cast<char*>("a;1;R"));
        setcolor(15);
        outtextxy(40, 55, const_cast<char*>("b;0;R"));

    } while (bandera != 0);
}

void borrar()
{
	gotoxy(60,25); system("pause");
	system("cls");
}

void diagramaT(){
	//Informacion
	margen(4, 13, 110, 21);
	gotoxy(45,4);printf("DIAGRAMA DE TRANSICION:");
	gotoxy(35,7);printf("	Q=  {q0,q1,q2,q3,q4,q5}");
	gotoxy(35,8);printf("	%c=  {1, 0}",156);
	gotoxy(35,9);printf("	r=  {1, 0, - , _ , a , b}");
	gotoxy(35,11);printf("	F=  {q5}");
	gotoxy(35,10);printf("	S=  {q0}");
	
	//Transiciones q0
	gotoxy(5,15);printf("S(q0,1)->(q2,-,R)");
	gotoxy(5,16);printf("S(q0,0)->(q1,-,R)");
	gotoxy(5,17);printf("S(q0,a)->(q0,1,R)");
    gotoxy(5,18);printf("S(q0,b)->(q0,0,R)");
    gotoxy(5,19);printf("S(q0,_)->(q5,_,S)");
	
	//Transiciones q1
    gotoxy(25,15);printf("S(q1,1)->(q1,1,R) ");
    gotoxy(25,16);printf("S(q1,0)->(q1,0,R)");
    gotoxy(25,17);printf("S(q1,a)->(q1,a,R)");
    gotoxy(25,18);printf("S(q1,b)->(q1,b,R)");
    gotoxy(25,19);printf("S(q1,_)->(q3,b,L)");
     
    //Transiciones q2
    gotoxy(45,15);printf("S(q2,1)->(q2,1,R)");
    gotoxy(45,16);printf("S(q2,0)->(q2,0,R)");
    gotoxy(45,17);printf("S(q2,a)->(q2,a,R)");
    gotoxy(45,18);printf("S(q2,b)->(q2,b,R)");
    
    //Transiciones q3
    gotoxy(65,15);printf("S(q3,0)->(q3,0,L)");
	gotoxy(65,16);printf("S(q3,a)->(q3,a,L)");
    gotoxy(65,17);printf("S(q3,b)->(q3,b,L)");
    gotoxy(65,18);printf("S(q3,-)->(q0,0,R)");
    
    //Transiciones q4
    gotoxy(85,15);printf("S(q4,1)->(q4,1,L)");
    gotoxy(85,16);printf("S(q4,0)->(q4,0,L)");
    gotoxy(85,17);printf("S(q4,a)->(q4,a,L)");
    gotoxy(85,18);printf("S(q4,b)->(q4,b,L)");
    gotoxy(85,19);printf("S(q4,-)->(q0,1,R)");
    gotoxy(85,20);printf("S(q3,1)->(q3,1,L)");
    borrar();
}

void q1(int posicionCabezal, char cadena[]) {
    int bandera;
    gotoxy(25, 15);
    printf("q1");
    setcolor(15);
    setcolor(5);
    circle(500, 100, 30);

    do {
        bandera = 0;
        Sleep(750);

        switch (cadena[posicionCabezal]) {
            case '1':
                setcolor(5);
                outtextxy(450, 70, const_cast<char*>("1;1;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '0':
                setcolor(5);
                outtextxy(450, 55, const_cast<char*>("0;0;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'a':
                setcolor(5);
                outtextxy(450, 40, const_cast<char*>("a;a;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'b':
                setcolor(5);
                outtextxy(450, 25, const_cast<char*>("b;b;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '\0':
                setcolor(5);
                outtextxy(150, 430, const_cast<char*>("_;b;L"));
                Sleep(500);
                setcolor(15);
                outtextxy(150, 430, const_cast<char*>("_;b;L"));
                cadena[posicionCabezal + 1] = '\0';
                cadena[posicionCabezal] = 'b';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(500, 100, 30);
                q3(posicionCabezal, cadena);
                break;
        }

        Sleep(500);
        setcolor(15);
        outtextxy(450, 70, const_cast<char*>("1;1;R"));
        setcolor(15);
        outtextxy(450, 55, const_cast<char*>("0;0;R"));
        setcolor(15);
        outtextxy(450, 40, const_cast<char*>("a;a;R"));
        setcolor(15);
        outtextxy(450, 25, const_cast<char*>("b;b;R"));

    } while (bandera != 0);
}
void q2(int posicionCabezal, char cadena[]) {
    int bandera;
    setcolor(5);
    circle(800, 100, 30);
    gotoxy(25, 15);
    printf("q2");

    do {
        bandera = 0;
        Sleep(750);

        switch (cadena[posicionCabezal]) {
            case '1':
                setcolor(5);
                outtextxy(750, 85, const_cast<char*>("1;1;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '0':
                setcolor(5);
                outtextxy(750, 55, const_cast<char*>("0;0;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'a':
                setcolor(5);
                outtextxy(750, 35, const_cast<char*>("a;a;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'b':
                setcolor(5);
                outtextxy(750, 15, const_cast<char*>("b;b;R"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '\0':
                setcolor(5);
                outtextxy(550, 430, const_cast<char*>("_;a;L")); 
                Sleep(500);
                setcolor(15);
                outtextxy(550, 430, const_cast<char*>("_;a;L"));
                cadena[posicionCabezal + 1] = '\0';
                cadena[posicionCabezal] = 'a';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(800, 100, 30);
                q4(posicionCabezal, cadena);
                break;
        }

        Sleep(500);
        setcolor(15);
        outtextxy(750, 85, const_cast<char*>("1;1;R"));
        setcolor(15);
        outtextxy(750, 55, const_cast<char*>("0;0;R"));
        setcolor(15);
        outtextxy(750, 35, const_cast<char*>("a;a;R"));
        setcolor(15);
        outtextxy(750, 15, const_cast<char*>("b;b;R"));

    } while (bandera != 0);
}

int margen(int a, int b, int c, int d) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 13);
    int j, k, i;
    j = a;
    gotoxy(a - 1, b);
    printf("%c", 201);
    gotoxy(a - 1, d);
    printf("%c", 200);
    for (a; a <= c; a++) {
        gotoxy(a, b);
        printf("%c", 205);
        gotoxy(a, d);
        printf("%c", 205);
    }
    gotoxy(a, b);
    printf("%c", 187);
    gotoxy(a, d);
    printf("%c", 188);
    k = b + 1;
    for (k; k <= (d - 1); k++) {
        gotoxy(j - 1, k);
        printf("%c", 186);
        gotoxy(a, k);
        printf("%c", 186);
    }
    color(hConsole, 7);
}

void q3(int posicionCabezal, char cadena[]) {
    int bandera;
    setcolor(5);
    circle(100, 500, 30);
    gotoxy(25, 15);
    printf("q3");

    do {
        bandera = 0;
        Sleep(750);

        switch (cadena[posicionCabezal]) {
            case '1':
                setcolor(5);
                outtextxy(40, 470, const_cast<char*>("1;1;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;

            case '0':
                setcolor(5);
                outtextxy(40, 455, const_cast<char*>("0;0;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'a':
                setcolor(5);
                outtextxy(40, 440, const_cast<char*>("a;a;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'b':
                setcolor(5);
                outtextxy(40, 425, const_cast<char*>("b;b;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '-':
                setcolor(5);
                outtextxy(70, 200, const_cast<char*>("-;0;R"));
                Sleep(500);
                setcolor(15);
                outtextxy(70, 200, const_cast<char*>("-;0;R"));
                cadena[posicionCabezal] = '0';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(100, 500, 30);
                q0(posicionCabezal, cadena);
                break;
        }

        Sleep(500);
        setcolor(15);
        outtextxy(40, 470, const_cast<char*>("1;1;L"));
        setcolor(15);
        outtextxy(40, 455, const_cast<char*>("0;0;L"));
        setcolor(15);
        outtextxy(40, 440, const_cast<char*>("a;a;L")); 
        setcolor(15);
        outtextxy(40, 425, const_cast<char*>("b;b;L"));
    } while (bandera != 0);
}


void bienvenida() {
    int opcion;
    margen(1, 1, 100, 25);
    margen(29, 9, 69, 11);
    margen(44, 5, 55, 7);

    gotoxy(30, 10);
    printf("MAQUINA DE TURING PARA DUPLICAR CADENAS");
    gotoxy(45, 6);
    printf("BIENVENIDO");
    
    margen(19, 14, 82, 18);
    gotoxy(25, 15);
    printf("Una maquina de Turing es un modelo computacional que ");
    gotoxy(23, 16);
    printf("realiza una lectura/escritura de manera automatica sobre ");
    gotoxy(20, 17);
    printf("una entrada llamada cinta, generando una salida en esta misma.");
}

void q4(int posicionCabezal, char cadena[]) {
    int bandera;
    setcolor(5);
    circle(500, 500, 30); 
    gotoxy(25, 15);
    printf("q4");

    do {
        bandera = 0;
        Sleep(750);

        switch (cadena[posicionCabezal]) {
            case '1':
                setcolor(5);
                outtextxy(450, 480, const_cast<char*>("1;1;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '0':
                setcolor(5);
                outtextxy(450, 465, const_cast<char*>("0;0;L"));
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'a':
                setcolor(5);
                outtextxy(450, 450, const_cast<char*>("a;a;L")); 
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case 'b':
                setcolor(5);
                outtextxy(450, 435, const_cast<char*>("b;b;L")); 
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal--;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                bandera = 1;
                break;
            case '-':
                setcolor(5);
                outtextxy(150, 195, const_cast<char*>("-;1;R"));
                Sleep(500);
                setcolor(15);
                outtextxy(150, 195, const_cast<char*>("-;1;R"));
                cadena[posicionCabezal] = '1';
                gotoxy(25 + (posicionCabezal * 4), 8);
                printf("%c", cadena[posicionCabezal]);
                gotoxy(25 + ((posicionCabezal) * 4), 10);
                printf(" ");
                posicionCabezal++;
                gotoxy(25 + (posicionCabezal * 4), 10);
                printf("%c", 94);
                setcolor(15);
                circle(500, 500, 30);
                q0(posicionCabezal, cadena);
                break;
        }

        Sleep(500);
        setcolor(15);
        outtextxy(450, 480, const_cast<char*>("1;1;L"));
        setcolor(15);
        outtextxy(450, 465, const_cast<char*>("0;0;L"));
        setcolor(15);
        outtextxy(450, 450, const_cast<char*>("a;a;L"));
        setcolor(15);
        outtextxy(450, 435, const_cast<char*>("b;b;L"));
    } while (bandera != 0);
}

void cuadros(int p,int q ,int c, int f){
	int i;
	int x;
	
	for(x=0; x<q; x++){
		gotoxy(c,f);
		printf("%c",218);  
		gotoxy(c,f+(x*2)+1); 
		printf("%c",179);
		gotoxy(c,f+(x*2)+2); 
		printf("%c",195);
		
		for(i=0; i<p-1; i++){
			gotoxy(c+((i+1)*4),f);
			printf("%c",194);
			gotoxy(c+(i*4)+1,f+(x*2));
			printf("%c%c%c",196,196,196);
			gotoxy(c+(i*4)+1,f+(x*2)+1);
			printf("   %c",179);
			gotoxy(c+(i*4)+1,f+(x*2)+2);
			printf("%c%c%c",196,196,196,197);
			gotoxy(c+((i+1)*4),f+(x*2)+2);
			printf("%c",197);
			}
			
		gotoxy(c+(i*4)+1,f); 
		printf("%c%c%c%c",196,196,196,191);
		gotoxy(c+(i*4)+1,f+(x*2)+1);
		printf("   %c",179);
		gotoxy(c+(i*4)+1,f+(x*2)+2); 
		printf("%c%c%c%c",196,196,196,180);
	}
	gotoxy(c,f+(x*2)); 
	printf("%c",192);
	gotoxy(c+(i*4)+4,f+(x*2)); 
	printf("%c",217);
	
	for(i=0; i<p-1; i++){
		gotoxy(c+((i+1)*4),f+(x*2));
		printf("%c",193);
		}
}

