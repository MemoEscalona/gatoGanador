#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
////////////////////////////////////////////////////VARIABLES/////////////////////////////////////////////////////////////
int y,z,op;
int x,contador,usuario,win,posicion,posicion2;
char CAT[3][3]={ {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
char opc,opc2='S',a,b,c; 
/////////////////////////////////////////DECLARACION DE  FUNCION GOTOXY///////////////////////////////////////////////////
int gotoxy(int x,int y)
{
    COORD coord;
    HANDLE h_stdout;
    coord.X=x;
    coord.Y=y;
    if((h_stdout=GetStdHandle(STD_OUTPUT_HANDLE))==INVALID_HANDLE_VALUE)
        return 0;
    if(SetConsoleCursorPosition(h_stdout,coord)==0)
        return 0;
    return 1;
}
////////////////////////////////////////////////////////////ULTIMO/////////////////////////////////////////////////////////////////
////////////////////////////////////////SIRVE PARA DECIR QUE HA ACABADO EL JUEGO//////////////////////////////////////////////////
///////////////////////////////////////Y PREGUNTA SI SE DESEA VOLVER A JUGAR//////////////////////////////////////////////////////
ULTIMO()
{
  gotoxy(1,24); 
  printf("Finalizando Secuencia de Gato... Modo: CPU Vs Usuario.");
  for(x=0;x<80;x++)
  {
   gotoxy(x,25);printf(".");
  }
  gotoxy(55,26);
  printf("\nDesea volver a jugar? [S/N]\n");
  opc2=toupper(getche());
  if(opc2=='S')
  {
     system("cls");
     main();
  }
  else
  {
      exit(0);
  }
}
////////////////////////////////////////////////DECLARACION DE LAS FORMAS DE GANAR////////////////////////////////////////////////
///////////////////////////////////////////////PARA CUANDO COMPUTADORA ES X//////////////////////////////////////////////////////
GANADOR()
{
     ////OPCIONES POSIBLES PARA QUE GANE LA X
if(CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='X'||
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='X'||
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||
   CAT[0][0]=='X'&& CAT[1][1]=='X'&& CAT[2][2]=='X'||
   CAT[0][2]=='X'&& CAT[1][1]=='X'&& CAT[2][0]=='X'||
   CAT[0][0]=='X'&& CAT[1][0]=='X'&& CAT[2][0]=='X'||
   CAT[0][2]=='X'&& CAT[1][2]=='X'&& CAT[2][2]=='X'||
   CAT[0][1]=='X'&& CAT[1][1]=='X'&& CAT[2][1]=='X')
 {
                    gotoxy(1,20);
                    printf("\n\nEl ganador es la computadora!!!\n");
                    win=2;posicion=10;
 }
////OPCIONES POSIBLES PARA QUE SEA EMPATE
if(CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='O'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O' )

 {
 gotoxy(1,20);
 printf("\n\n Empate....\n");
 win=2;posicion=10; 
 }
 getch();
 ULTIMO();
 return 0;
 }
 ///////////////////////////////////////////////PARA CUANDO COMPUTADORA ES O//////////////////////////////////////////////////////
GANADORU()
{
     ////OPCIONES POSIBLES PARA QUE GANE LA O
if(CAT[0][0]=='O'&& CAT[0][1]=='O'&& CAT[0][2]=='O'||
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='O'||
   CAT[2][0]=='O'&& CAT[2][1]=='O'&& CAT[2][2]=='O'||
   CAT[0][0]=='O'&& CAT[1][1]=='O'&& CAT[2][2]=='O'||
   CAT[0][2]=='O'&& CAT[1][1]=='O'&& CAT[2][0]=='O'||
   CAT[0][0]=='O'&& CAT[1][0]=='O'&& CAT[2][0]=='O'||
   CAT[0][2]=='O'&& CAT[1][2]=='O'&& CAT[2][2]=='O'||
   CAT[0][1]=='O'&& CAT[1][1]=='O'&& CAT[2][1]=='O')
 {
                    gotoxy(1,20);
                    printf("\n\nEl ganador es la computadora!!!\n");
                    win=2;posicion=10;
 }
////OPCIONES POSIBLES PARA QUE SEA EMPATE
if(CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='O'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='O'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='X'&& CAT[2][2]=='O'||

   CAT[0][0]=='O'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='X'||

   CAT[0][0]=='O'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='X'&& CAT[1][1]=='X'&& CAT[1][2]=='O'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='X'||

   CAT[0][0]=='X'&& CAT[0][1]=='X'&& CAT[0][2]=='O'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='X'&& CAT[2][1]=='O'&& CAT[2][2]=='O'||

   CAT[0][0]=='X'&& CAT[0][1]=='O'&& CAT[0][2]=='X'&&
   CAT[1][0]=='O'&& CAT[1][1]=='X'&& CAT[1][2]=='X'&&
   CAT[2][0]=='O'&& CAT[2][1]=='X'&& CAT[2][2]=='O' )

 {
 gotoxy(1,20);
 printf("\n\n Empate....\n");
 win=2;posicion=10; 
 }
 getch();
 ULTIMO();
 return 0;
 }
////////////////////////////////////////////DECLARACION FUNCION CAR///////////////////////////////////////////////////
/////////////////////////////esta funcion genera una barra de carga//////////////////////////////////////////////////
CAR()
{
  system("cls");
  gotoxy(1,19);
  printf("Cargando Juego...\n");
  for(y=1;y<60;y++)
  {
   gotoxy(y,20);
   printf("�");
  }
  for(x=1;x<11;x++)
  {
   for(y=1;y<1500;y++)
    {
    gotoxy(x,20);
    printf("�");
    }
   z=z+1;
  }

  for(x=10;x<60;x++)
  {
   for(y=1;y<50;y++)
    {
     gotoxy(x,20);
     printf("�");
    }
   z=z+1;
  }
  return 0;
}
//////////////////////////////////////////////////FUNCION DIBUJO//////////////////////////////////////////////////////////////////
/////////////////////////////////////////SOLO SIRVE PARA IMPRIMIR EL DIBUJO//////////////////////////////////////////////////////
DIBUJO()
{
 gotoxy(25,15); printf ("        �    �    \n");
 gotoxy(25,16); printf ("    ������������� \n");
 gotoxy(25,17); printf ("        �    �    \n");
 gotoxy(25,18); printf ("    ������������� \n");
 gotoxy(25,19); printf ("        �    �    \n");
 return 0;
}
//////////////////////////////////////////////////DIBUJO 1////////////////////////////////////////////////////////////////////
///////////////////////////SOLO SIRVE PARA IMPRIMIR EL DIBUJO y el tiro inicial del CPU.//////////////////////////////////////
DIBUJO1()
{
 gotoxy(25,15); printf ("        �    �    \n");
 gotoxy(25,16); printf ("    ������������� \n");
 gotoxy(25,17); printf ("        �    �    \n");
 gotoxy(25,18); printf ("    ������������� \n");
 gotoxy(25,19); printf ("        �    �    \n");
 getch();
 gotoxy(40,19);printf("X");
 return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////JUGADAS MODO CPU///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////JUGADA 1////////////////////////////////////////////////////////////////////
JUGADA1()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(30,15); printf("O"); CAT[0][0]='O';
              gotoxy(40,15); printf("X"); CAT[0][2]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 2:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      GANADOR();
                      }
                      break;
                 case 3:
                     gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                     break;
                 case 4:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,17); printf("O"); CAT[1][0]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      GANADOR();
                      }
                      break;
                 case 5:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(35,17); printf("O"); CAT[1][1]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      GANADOR();
                      }
                      break;
                 case 6:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(40,17); printf("O"); CAT[1][2]='O';
                      gotoxy(30,19); printf("X"); CAT[2][0]='X';
                      if (win==0)
                      {
                       posicion2=0;
                       while(posicion2<=9)
                       {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                          case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 2:
                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                               gotoxy(35,19); printf("X"); CAT[1][2]='X';
                               GANADOR();
                              break;
                          case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 4:
                              gotoxy(30,17); printf("O"); CAT[1][0]='O';
                              gotoxy(35,19); printf("X"); CAT[1][2]='X';
                              GANADOR();
                              break;
                          case 5:
                               gotoxy(35,17); printf("O"); CAT[1][1]='O';
                               gotoxy(35,19); printf("X"); CAT[1][2]='X';
                               GANADOR();
                               break;
                          case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 8:
                               gotoxy(35,19); printf("O"); CAT[2][1]='O';
                               gotoxy(35,17); printf("X"); CAT[1][1]='X';
                               GANADOR();
                               break;
                          case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;              
                          default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                       }
                       }
                      }
                      }
                      break;
                 case 7:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,19); printf("O"); CAT[2][0]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      GANADOR();
                      }
                      break;
                 case 8:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(35,19); printf("O"); CAT[2][1]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      GANADOR();
                      }
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
   
              }
              
    
    }
    }
 return 0;
}
//////////////////////////////////////////////////JUGADA 2////////////////////////////////////////////////////////////////////
JUGADA2()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(35,15); printf("O"); CAT[0][1]='O';
              gotoxy(30,15); printf("X"); CAT[0][0]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 2:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 3:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(40,15); printf("O"); CAT[0][2]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      GANADOR();
                      }
                      break;
                 case 4:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,17); printf("O"); CAT[1][0]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      GANADOR();
                      }
                      break;
                      
                 case 5:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(35,17); printf("O"); CAT[1][1]='O';
                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                         gotoxy(45,12); scanf("%d",&posicion2);
                         switch(posicion2)
                         {
                          case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 2:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 3:
                               gotoxy(40,15); printf("O"); CAT[0][2]='O';
                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                               GANADOR();
                          break;
                          case 4:
                               gotoxy(30,17); printf("O"); CAT[1][0]='O';
                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                               GANADOR();
                          break;
                          case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 6:
                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                               GANADOR();
                          break;
                          case 7:
                               posicion=0;
                               while(posicion<=9)
                               {
                                gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                if (win==0)
                                {
                                   posicion2=0;
                                   while(posicion2<=9)
                                   {
                                    gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                    gotoxy(45,12); scanf("%d",&posicion2);
                                    switch(posicion2)
                                    {
                                                     case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 2:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                          gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                          GANADOR();
                                                     break;
                                                     case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                          gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                          GANADOR();
                                                     break;
                                                     case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;
                                                     case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break; 
                                                     default:
                                                     gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                                                     break;                  
                                    }
                                   }
                                }
                               }
                          break;
                          case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;    
                          default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                    
                         }
                        }
                        }
                      }
                      break;
                 case 6:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(40,17); printf("O"); CAT[1][2]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      GANADOR();
                      }
                      break;
                      
                 case 7:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,19); printf("O"); CAT[2][0]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      GANADOR();
                      }
                      break;
                 case 8:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(35,19); printf("O"); CAT[2][0]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      GANADOR();
                      }
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 default:
                         gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
   }
 }
 }
return 0;
}
//////////////////////////////////////////////////JUGADA 3////////////////////////////////////////////////////////////////////
JUGADA3()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(40,15); printf("O"); CAT[0][2]='O';
              gotoxy(30,15);printf("X"); CAT[0][0]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 2:
                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                      gotoxy(35,17);printf("X"); CAT[1][1]='X';
                      GANADOR();
                      break;
                 case 3:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 case 4:
                      gotoxy(30,17); printf("O"); CAT[1][0]='O';
                      gotoxy(35,17);printf("X"); CAT[1][1]='X';
                      GANADOR();
                      break;
                 case 5:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(35,17); printf("O"); CAT[1][1]='O';
                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                         gotoxy(45,12); scanf("%d",&posicion2);
                         switch(posicion2)
                         {
                          case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 2:
                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                               gotoxy(35,19); printf("X"); CAT[2][1]='X';
                               GANADOR();
                          break;
                          case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 4:
                               gotoxy(30,17); printf("O"); CAT[1][0]='O';
                               gotoxy(35,19); printf("X"); CAT[2][1]='X';
                               GANADOR();
                          break;
                          case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;
                          case 6:
                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                               gotoxy(30,17); printf("X"); CAT[1][0]='X';
                               GANADOR();
                          break;
                          case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                          case 8:
                               gotoxy(35,19); printf("O"); CAT[2][1]='O';
                               gotoxy(30,17); printf("X"); CAT[1][0]='X';
                               GANADOR();
                          break;
                          case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                          break;    
                          default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                    
                         }
                        }
                        }
                      }
                      break;
                 case 6:
                      gotoxy(40,17); printf("O"); CAT[1][2]='O';
                      gotoxy(35,17);printf("X"); CAT[1][1]='X';
                      GANADOR();
                      break;
                 case 7:
                      gotoxy(30,19); printf("O"); CAT[2][0]='O';
                      gotoxy(35,17);printf("X"); CAT[1][1]='X';
                      GANADOR();
                      break;
                 case 8:
                      gotoxy(35,19); printf("O"); CAT[2][1]='O';
                      gotoxy(35,17);printf("X"); CAT[1][1]='X';
                      GANADOR();
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
   
              }
 }
 }
return 0;
}
//////////////////////////////////////////////////JUGADA 4////////////////////////////////////////////////////////////////////
JUGADA4()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(30,17);printf("O"); CAT[1][0]='O';
              gotoxy(35,17);printf("X"); CAT[1][1]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(30,15); printf("O"); CAT[1][0]='O';
                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:
                              gotoxy(35,15); printf("O"); CAT[0][1]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 3:
                              gotoxy(40,15); printf("O"); CAT[0][2]='O';
                              gotoxy(35,19); printf("X"); CAT[2][1]='X';
                              GANADOR();
                         break;
                         case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:
                         gotoxy(40,17); printf("O"); CAT[1][2]='O';
                         gotoxy(35,19); printf("X"); CAT[2][1]='X';
                         GANADOR();
                         break;
                         case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 8:
                              gotoxy(35,19); printf("O"); CAT[2][1]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;     
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;              
                         }
                         }
                         }
                         }
                         break;
                 case 2:
                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 3:
                      gotoxy(40,15); printf("O"); CAT[0][2]='O';
                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                        break;
                 case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 6:
                      gotoxy(40,17); printf("O"); CAT[1][2]='O';
                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 7:
                      gotoxy(30,19); printf("O"); CAT[2][0]='O';
                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 8:
                      gotoxy(35,19); printf("O"); CAT[2][1]='O';
                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 default:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
   
              }
 }
 }
return 0;
}
//////////////////////////////////////////////////JUGADA 5////////////////////////////////////////////////////////////////////
JUGADA5()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(30,15);printf("X"); CAT[0][0]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 ////caso 
                 case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 ///caso
                 case 2:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(35,15); printf("O"); CAT[0][1]='O';
                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 3:
                              gotoxy(40,15); printf("O"); CAT[0][2]='O';
                              gotoxy(30,19); printf("X"); CAT[2][0]='X';
                              GANADOR();
                         break;
                         case 4:
                              gotoxy(30,17); printf("O"); CAT[1][0]='O';
                              gotoxy(30,19); printf("X"); CAT[2][0]='X';
                              GANADOR();
                         break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:
                         gotoxy(40,17); printf("O"); CAT[1][2]='O';
                         gotoxy(30,19); printf("X"); CAT[2][0]='X';
                         GANADOR();
                         break;
                         case 7:
                               posicion=0;
                               while(posicion<=9)
                               {
                               gotoxy(30,19); printf("O"); CAT[2][0]='O';
                               gotoxy(40,15); printf("X"); CAT[0][2]='X';
                               if (win==0)
                               {
                               posicion2=0;
                               while(posicion2<=9)
                               {
                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                               gotoxy(45,12); scanf("%d",&posicion2);
                               switch(posicion2)
                               {      
                               case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 2:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 4:
                                    gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                    gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                    GANADOR();
                               break;
                               case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 6:
                                    gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                    gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                    GANADOR();
                               break;
                               case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break; 
                               default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                  
                               }
                               }
                               }
                               }
                         break;
                         case 8:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;     
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;              
                         }
                         }
                         }
                         }
                         break;
                 //////caso
                 case 3:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:
                              gotoxy(35,15); printf("O"); CAT[0][1]='O';
                              gotoxy(30,17); printf("X"); CAT[1][0]='X';
                              GANADOR();
                         break;
                         case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 4:
                              gotoxy(30,17); printf("O"); CAT[1][0]='O';
                              gotoxy(35,19); printf("X"); CAT[2][1]='X';
                              GANADOR();
                         break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:
                              gotoxy(40,17); printf("O"); CAT[1][2]='O';
                              gotoxy(35,19); printf("X"); CAT[2][1]='X';
                              GANADOR();
                         break;
                         case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 8:
                              gotoxy(35,19); printf("O"); CAT[2][1]='O';
                              gotoxy(30,17); printf("X"); CAT[1][0]='X';
                              GANADOR();
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;     
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;              
                         }
                         }
                         }
                         }
                      break;
                 //////caso     
                 case 4:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(30,17); printf("O"); CAT[1][0]='O';
                       gotoxy(40,17); printf("X"); CAT[1][2]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:
                              gotoxy(35,15); printf("O"); CAT[0][1]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 3:
                              posicion=0;
                               while(posicion<=9)
                               {
                               gotoxy(40,15); printf("O"); CAT[0][2]='O';
                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                               if (win==0)
                               {
                               posicion2=0;
                               while(posicion2<=9)
                               {
                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                               gotoxy(45,12); scanf("%d",&posicion2);
                               switch(posicion2)
                               {      
                               case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 2:
                                    gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                    gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                    GANADOR();
                               break;
                               case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 8:
                                    gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                    gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                    GANADOR();
                               break;
                               case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                               }
                               }
                               }
                               }
                         break;
                         case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                             break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 7:
                               posicion=0;
                               while(posicion<=9)
                               {
                               gotoxy(30,19); printf("O"); CAT[2][0]='O';
                               gotoxy(40,15); printf("X"); CAT[0][2]='X';
                               if (win==0)
                               {
                               posicion2=0;
                               while(posicion2<=9)
                               {
                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                               gotoxy(45,12); scanf("%d",&posicion2);
                               switch(posicion2)
                               {      
                               case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 2:
                                    gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                    gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                    GANADOR();
                               break;
                               case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 8:
                                    gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                    gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                    GANADOR();
                               break;
                               case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                               }
                               }
                               }
                               }
                         break;
                         case 8:
                              gotoxy(35,19); printf("O"); CAT[2][1]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;     
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;              
                         }
                         }
                         }
                         }
                         break;
                      break;
                 //////caso
                 case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                       break;
                 //////caso
                 case 6:
                      posicion=0;
                               while(posicion<=9)
                               {
                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                               gotoxy(30,17); printf("X"); CAT[1][0]='X';
                               if (win==0)
                               {
                               posicion2=0;
                               while(posicion2<=9)
                               {
                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                               gotoxy(45,12); scanf("%d",&posicion2);
                               switch(posicion2)
                               {      
                               case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 2:
                                    gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                    gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                    GANADOR();
                               break;
                               case 3:
                                    gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                    gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                    GANADOR();
                               break;
                               case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 7:
                               posicion=0;
                               while(posicion<=9)
                               {
                               gotoxy(30,19); printf("O"); CAT[2][0]='O';
                               gotoxy(40,15); printf("X"); CAT[0][2]='X';
                               if (win==0)
                               {
                               posicion2=0;
                               while(posicion2<=9)
                               {
                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                               gotoxy(45,12); scanf("%d",&posicion2);
                               switch(posicion2)
                               {      
                               case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 2:
                                    gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                    gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                    GANADOR();
                               break;
                               case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 4:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               case 8:
                                    gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                    gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                    GANADOR();
                               break;
                               case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                               }
                               }
                               }
                               }
                         break;
                         case 8:
                                    gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                    gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                    GANADOR();
                               break;
                               case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                               break;
                               default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                               }
                               }
                               }
                               }
                 break;
                 //////caso     
                 case 7:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(30,19); printf("O"); CAT[2][0]='O';
                       gotoxy(40,15); printf("X"); CAT[0][2]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:
                              gotoxy(35,15); printf("O"); CAT[0][1]='O';
                              gotoxy(40,17); printf("X"); CAT[1][2]='X';
                              GANADOR();
                         break;
                         case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 4:
                              gotoxy(30,17); printf("O"); CAT[1][0]='O';
                              gotoxy(35,15); printf("X"); CAT[0][1]='X';
                              GANADOR();
                         break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:
                              gotoxy(40,17); printf("O"); CAT[1][2]='O';
                              gotoxy(35,15); printf("X"); CAT[0][1]='X';
                              GANADOR();
                         break;
                         case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;  
                         break;
                         case 8:
                              gotoxy(35,19); printf("O"); CAT[2][1]='O';
                              gotoxy(35,15); printf("X"); CAT[0][1]='X';
                              GANADOR();
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                         }
                         }
                         }
                         }
                      break;
                 case 8:
                      posicion=0;
                      while(posicion<=9)
                      {
                       gotoxy(35,19); printf("O"); CAT[2][1]='O';
                       gotoxy(35,15); printf("X"); CAT[0][1]='X';
                       if (win==0)
                       {
                        posicion2=0;
                        while(posicion2<=9)
                        {
                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                        gotoxy(45,12); scanf("%d",&posicion2);
                        switch(posicion2)
                        {
                         case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 2:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 3:
                              posicion=0;
                              while(posicion<=9)
                              {
                              gotoxy(40,15); printf("O"); CAT[0][2]='O';
                              gotoxy(30,19); printf("X"); CAT[2][0]='X';
                              if (win==0)
                              {
                              posicion2=0;
                              while(posicion2<=9)
                              {
                              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                              gotoxy(45,12); scanf("%d",&posicion2);
                              switch(posicion2)
                              {
                              case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 2:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 4:
                                   gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                   gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                   GANADOR();
                              break;
                              case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 6:
                                   gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                   gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                   GANADOR();
                                   break;
                              case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
                              default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                         }
                         }
                         }
                         }
                         break;
                         case 4:
                              gotoxy(30,17); printf("O"); CAT[1][0]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 6:
                              gotoxy(40,17); printf("O"); CAT[1][2]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 7:
                              gotoxy(30,19); printf("O"); CAT[2][0]='O';
                              gotoxy(40,15); printf("X"); CAT[0][2]='X';
                              GANADOR();
                         break;
                         case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                         break;
                         default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;                   
                         }
                         }
                         }
                         }
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
   
              }
 }
 }
return 0;
}
//////////////////////////////////////////////////JUGADA 6////////////////////////////////////////////////////////////////////
JUGADA6()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(40,17); printf("O"); CAT[1][2]='O';
              gotoxy(35,17);printf("X"); CAT[1][1]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,15); printf("O"); CAT[0][0]='O';
                      gotoxy(30,19); printf("X"); CAT[2][0]='X';
                      if (win==0)
                      {
                      posicion2=0;
                      while(posicion2<=9)
                      {
                      gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                      gotoxy(45,12); scanf("%d",&posicion2);
                      switch(posicion2)
                      {
                      case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 2:
                           gotoxy(35,15); printf("O"); CAT[0][1]='O';
                           gotoxy(40,15); printf("X"); CAT[0][2]='X';
                           GANADOR();
                      break;
                      case 3:
                           gotoxy(40,15); printf("O"); CAT[0][2]='O';
                           gotoxy(35,19); printf("X"); CAT[2][1]='X';
                           GANADOR();
                      break;
                      case 4:
                           gotoxy(30,17); printf("O"); CAT[1][0]='O';
                           gotoxy(40,15); printf("X"); CAT[0][2]='X';
                           GANADOR();
                      break;
                      case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 8:
                           gotoxy(35,19); printf("O"); CAT[2][1]='O';
                           gotoxy(40,15); printf("X"); CAT[0][2]='X';
                           GANADOR();
                      break;
                      case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;                   
                      }
                      }
                      }
                      }
                 break;
                 case 2:
                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 3:
                      gotoxy(40,15); printf("O"); CAT[0][2]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 4:
                      gotoxy(30,17); printf("O"); CAT[1][0]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                 case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                       break;
                 case 7:
                      gotoxy(30,19); printf("O"); CAT[2][0]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 8:
                      gotoxy(35,19); printf("O"); CAT[2][1]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                      break;
                 case 9:
                      gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:
                              gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                              break;
   
              }
 }
 }
return 0;
}
//////////////////////////////////////////////////JUGADA 7////////////////////////////////////////////////////////////////////
JUGADA7()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(30,19); printf("O"); CAT[2][0]='O';
              gotoxy(40,17);printf("X"); CAT[1][2]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      gotoxy(30,15); printf("O"); CAT[0][0]='O';
                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                      GANADOR();
                 break;
                 case 2:
                      gotoxy(35,15);printf("O"); CAT[0][1]='O';
                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                      GANADOR();
                 break;
                 case 3:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(40,15); printf("O"); CAT[0][2]='O';
                      gotoxy(35,17); printf("X"); CAT[1][1]='X';
                      if (win==0)
                      {
                      posicion2=0;
                      while(posicion2<=9)
                      {
                      gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                      gotoxy(45,12); scanf("%d",&posicion2);
                      switch(posicion2)
                      {
                      case 1:
                           gotoxy(30,15); printf("O"); CAT[0][0]='O';
                           gotoxy(30,17); printf("X"); CAT[1][0]='X';
                           GANADOR();
                      break;
                      case 2:
                           gotoxy(35,15); printf("O"); CAT[0][1]='O';
                           gotoxy(30,17); printf("X"); CAT[1][0]='X';
                           GANADOR();
                      break;
                      case 3:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 4:
                           gotoxy(30,17); printf("O"); CAT[1][0]='O';
                           gotoxy(30,15); printf("X"); CAT[0][0]='X';
                           GANADOR();
                      break;
                      case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 8:
                           gotoxy(35,19); printf("O"); CAT[2][1]='O';
                           gotoxy(30,15); printf("X"); CAT[0][0]='X';
                           GANADOR();
                      break;
                      case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;                   
                      }
                      }
                      }
                      }
                 break;
                 case 4:
                      gotoxy(30,17);printf("O"); CAT[1][0]='O';
                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                      GANADOR();
                 break;
                 case 5:
                      gotoxy(35,17);printf("O"); CAT[1][1]='O';
                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                      GANADOR();
                 break;
                 case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 case 7:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 case 8:
                      gotoxy(35,19);printf("O"); CAT[2][1]='O';
                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                      GANADOR();
                 break;
                 case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 default:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
}
}
}
return  0;
}
//////////////////////////////////////////////////JUGADA 8////////////////////////////////////////////////////////////////////
JUGADA8()
{
 win=0;
 while(posicion2<=9)
 {
 while(win<=1)
 {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(35,19); printf("O"); CAT[2][1]='O';
              gotoxy(35,17);printf("X"); CAT[1][1]='X';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                 case 1:
                      posicion=0;
                      while(posicion<=9)
                      {
                      gotoxy(30,15); printf("O"); CAT[0][0]='O';
                      gotoxy(40,17); printf("X"); CAT[1][2]='X';
                      if (win==0)
                      {
                      posicion2=0;
                      while(posicion2<=9)
                      {
                      gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                      gotoxy(45,12); scanf("%d",&posicion2);
                      switch(posicion2)
                      {
                      case 1:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 2:
                           gotoxy(35,15); printf("O"); CAT[0][1]='O';
                           gotoxy(30,17); printf("X"); CAT[1][0]='X';
                           GANADOR();
                      break;
                      case 3:
                           gotoxy(40,15); printf("O"); CAT[0][2]='O';
                           gotoxy(30,17); printf("X"); CAT[1][0]='X';
                           GANADOR();
                      break;
                      case 4:
                           gotoxy(30,17); printf("O"); CAT[1][0]='O';
                           gotoxy(30,15); printf("X"); CAT[0][0]='X';
                           GANADOR();
                      break;
                      case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 6:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 7:
                           gotoxy(30,19); printf("O"); CAT[2][0]='O';
                           gotoxy(30,15); printf("X"); CAT[0][0]='X';
                           GANADOR();
                      break;
                      case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;
                      default:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                      break;                   
                      }
                      }
                      }
                      }
                 break;
                 case 2:
                      gotoxy(35,15);printf("O"); CAT[0][1]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                 break;
                 case 3:
                      gotoxy(40,15);printf("O"); CAT[0][2]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                 break;
                 case 4:
                      gotoxy(30,17);printf("O"); CAT[1][0]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                 break;
                 case 5:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 case 6:
                      gotoxy(40,17);printf("O"); CAT[1][2]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                 break;
                 case 7:
                      gotoxy(30,19);printf("O"); CAT[2][0]='O';
                      gotoxy(30,15);printf("X"); CAT[0][0]='X';
                      GANADOR();
                 break;
                 case 8:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 case 9:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
                 default:gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion2=0;
                 break;
 }
 }
 }
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////JUGADAS MODO USUARIO///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////JUGADA 1////////////////////////////////////////////////////////////////////
JUGADA1U()
{
          win=0;
          while(posicion2<=9)
          {
          while(win<=1)
          {
              gotoxy(30,15);printf("X"); CAT[0][0]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 2:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                          case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 4:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 6:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 4:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 6:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 7:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 8:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 9:
                                                                                                                       gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                          break;
                                                                          case 7:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 8:
                                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                               gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 9:
                                                                               gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                               gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                     }
                                     }
                               break;
                               case 3:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:
                                                     case 2:
                                                     case 3:
                                                     case 5:
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                           posicion2=0;
                                                           while(posicion2<=9)
                                                           {
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            case 1:
                                                                            case 2:
                                                                            case 3:
                                                                            case 5:
                                                                            case 6:
                                                                            case 8:
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            break;
                                                                            case 4:
                                                                                 posicion=0;
                                                                                 while(posicion<=9)
                                                                                 {
                                                                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 1:
                                                                                                                  case 2:
                                                                                                                  case 3:
                                                                                                                  case 4:
                                                                                                                  case 5:
                                                                                                                  case 6:
                                                                                                                  case 7:
                                                                                                                  case 8:
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 9:
                                                                                                                       gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  
                                                                                                  }
                                                                               }
                                                                            break;
                                                                            case 7:
                                                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                 gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                                            case 9:
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                            }
                                                            }
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                     }
                                     }
                               break;
                               case 4:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:
                                                     case 4:
                                                     case 5:
                                                     case 7:
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:                                                                                 posicion=0;
                                                          while(posicion<=9)
                                                          {
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion);
                                                          switch(posicion)
                                                          {
                                                                          case 1:
                                                                          case 2:
                                                                          case 3:
                                                                          case 4:
                                                                          case 5:
                                                                          case 7:
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 6:
                                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                               gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 8:
                                                                               posicion2=0;
                                                                               while(posicion2<=9)
                                                                               {
                                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                               gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion2);
                                                                               switch(posicion2)
                                                                               {
                                                                                case 1:
                                                                                case 2:
                                                                                case 3:
                                                                                case 4:
                                                                                case 5:
                                                                                case 7:
                                                                                case 8:
                                                                                case 9:
                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                break;
                                                                                case 6:
                                                                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                                     GANADORU();
                                                                                break;
                                                                               }
                                                                               }
                                                                          break;
                                                                          case 9:
                                                                               gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                               gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                               GANADORU();
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                     }
                                     }
                               break;
                               case 6:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                    {
                                                     case 1:
                                                     case 3:
                                                     case 5:
                                                     case 6:
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();                                                     
                                                     break;
                                                     case 7:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           case 1:
                                                                           case 3:
                                                                           case 4:
                                                                           case 5:
                                                                           case 6:
                                                                           case 7:
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 2:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                 gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     case 1:
                                                                                     case 2:
                                                                                     case 3:
                                                                                     case 4:
                                                                                     case 5:
                                                                                     case 6:
                                                                                     case 7:
                                                                                     case 8:
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 9:
                                                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 8:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                 gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     case 1:
                                                                                     case 8:
                                                                                     case 3:
                                                                                     case 4:
                                                                                     case 5:
                                                                                     case 6:
                                                                                     case 7:
                                                                                     case 9:
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 2:
                                                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 9:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     case 1:
                                                                                     case 9:
                                                                                     case 3:
                                                                                     case 4:
                                                                                     case 5:
                                                                                     case 6:
                                                                                     case 7:
                                                                                     case 8:
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 2:
                                                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                          }
                                                          }
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU(); 
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU(); 
                                                     break;
                                    }
                                    }
                               break;
                               case 7:
                                     posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      case 1:
                                                      case 4:
                                                      case 5:
                                                      case 7:
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                           case 1:
                                                                           case 2:
                                                                           case 4:
                                                                           case 5:
                                                                           case 6:
                                                                           case 7:
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 3:
                                                                                gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 8:
                                                                                posicion2=0;
                                                                                while(posicion2<=9)
                                                                                {
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion2);
                                                                                switch(posicion2)
                                                                                {
                                                                                                 case 1:
                                                                                                 case 2:
                                                                                                 case 4:
                                                                                                 case 5:
                                                                                                 case 6:
                                                                                                 case 7:
                                                                                                 case 8:
                                                                                                 case 9:
                                                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                 break;
                                                                                                 case 3:
                                                                                                      gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                                      GANADORU();
                                                                                                 break;
                                                                                }
                                                                                }
                                                                           break;
                                                                           case 9:
                                                                                gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                GANADORU();
                                                                           break;
                                                           }
                                                           }
                                                      break;
                                     }
                                     }
                               break;
                               case 8:
                                    posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      case 1:
                                                      case 4:
                                                      case 5:
                                                      case 8:
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                            posicion=0;
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            case 1:
                                                                            case 3:
                                                                            case 4:
                                                                            case 5:
                                                                            case 6:
                                                                            case 8:
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            case 2:
                                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               GANADORU();
                                                                            break;
                                                                            case 7:
                                                                                 posicion2=0;
                                                                                 while(posicion2<=9)
                                                                                 {
                                                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                 gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                                 switch(posicion2)
                                                                                 {
                                                                                                  case 1:
                                                                                                  case 3:
                                                                                                  case 4:
                                                                                                  case 5:
                                                                                                  case 6:
                                                                                                  case 7:
                                                                                                  case 8:
                                                                                                  case 9:
                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                  break;
                                                                                                  case 2:
                                                                                                       gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                                       GANADORU();
                                                                                                  break;
                                                                                 }
                                                                                 }
                                                                            break;
                                                                            case 9:
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                                                   
                                                            }
                                                            }
                                                      break;
                                                      case 7:
                                                           gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
                               case 9:
                                    posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      case 1:
                                                      case 4:
                                                      case 5:
                                                      case 9:
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                           case 1:
                                                                           case 3:
                                                                           case 4:
                                                                           case 5:
                                                                           case 6:
                                                                           case 9:
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 2:
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 7:
                                                                                posicion2=0;
                                                                                while(posicion2<=9)
                                                                                {
                                                                                gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion2);
                                                                                switch(posicion2)
                                                                                {
                                                                                                 case 1:
                                                                                                 case 3:
                                                                                                 case 4:
                                                                                                 case 5:
                                                                                                 case 6:
                                                                                                 case 7:
                                                                                                 case 8:
                                                                                                 case 9:
                                                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                 break;
                                                                                                 case 2:
                                                                                                    gotoxy(35,15);printf("X"); CAT[0][1]='X';  
                                                                                                    GANADORU();
                                                                                                 break;
                                                                                }
                                                                                }
                                                                           break;
                                                                           case 8:
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                GANADORU();
                                                                           break;
                                                           }
                                                           }
                                                      break;
                                                      case 7:
                                                           gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 8:
                                                           gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           GANADORU();
                                                      break;
                                                           
                                                      
                                     }
                                     }
                               break;
                               case 5:
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
              }
          }
          }
return 0;
}
////////////////////////////////////////////////////////JUGADA2////////////////////////////////////////////////////////////////
JUGADA2U()
{         
          while(posicion2<=9)
          {
              gotoxy(35,15);printf("X"); CAT[0][1]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 1:
                                     while(posicion<=9)
                                     {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                   gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 6:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                         gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 8:
                                                                                              gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 8:
                                                                         gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                         gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 9:
                                                                         gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                         gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 3:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                   gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 4:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                         gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 8:
                                                                                              gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 8:
                                                                         gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 7:
                                                                         gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 4:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 3:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 8:
                                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 6:
                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                               gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                               GANADORU();
                                                          break;
                                                          case 8:
                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                               gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                             break;
                                     }
                                     }
                               break;
                               case 6:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                 gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 1:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                               gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 8:
                                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 4:
                                                               gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;
                                                          case 8:
                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                                 break;
                                     }
                                     }
                               break;
                               case 7:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                 gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 1:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                             gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 8:
                                                                      gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 3:
                                                            gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                            gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                            GANADORU();
                                                       break;
                                                       case 8:
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 8:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  while(posicion2<=9)
                                                  {
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                  switch(posicion2)
                                                  {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break; 
                                                       case 4:
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            GANADORU();
                                                       break;
                                                       case 6:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                               break;
                                                               case 7:
                                                                    gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                    GANADORU();
                                                               break;         
                                                            }
                                                            }
                                                       break;
                                                       case 7:
                                                            gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            GANADORU();
                                                       break;          
                                                  }
                                                  }
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 9:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 3:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                             gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 8:
                                                                      gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 1:
                                                            gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            GANADORU();
                                                       break;
                                                       case 8:
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               
              }
          }
return 0;
}
////////////////////////////////////////////////////////JUGADA3////////////////////////////////////////////////////////////////
JUGADA3U()
{         win=0;
          while(posicion2<=9)
          {
          while(win<=1)
          {
              gotoxy(40,15);printf("X"); CAT[0][2]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 2:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                           posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                          case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 6:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 4:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 1:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 2:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 3:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 4:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 5:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 6:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 9:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 8:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 7:
                                                                                                                       gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                          break;
                                                                          case 9:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 8:
                                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                               gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 7:
                                                                               gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                               gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                     }
                                     }
                               break;
                               case 1:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:
                                                     case 2:
                                                     case 3:
                                                     case 5:
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                           posicion2=0;
                                                           while(posicion2<=9)
                                                           {
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            case 1:
                                                                            case 2:
                                                                            case 3:
                                                                            case 5:
                                                                            case 6:
                                                                            case 8:
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            break;
                                                                            case 4:
                                                                                 posicion=0;
                                                                                 while(posicion<=9)
                                                                                 {
                                                                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 1:
                                                                                                                  case 2:
                                                                                                                  case 3:
                                                                                                                  case 4:
                                                                                                                  case 5:
                                                                                                                  case 6:
                                                                                                                  case 7:
                                                                                                                  case 8:
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 9:
                                                                                                                       gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  
                                                                                                  }
                                                                               }
                                                                            break;
                                                                            case 7:
                                                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                 gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                                            case 9:
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                            }
                                                            }
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          GANADORU();
                                                     break;
                                     }
                                     }
                               break;
                               case 4:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 3:
                                                     case 4:
                                                     case 5:
                                                     case 1:
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                        //////////////////////PENDIENTE/////////////
                                                     case 9:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                          case 1:
                                                                          case 3:
                                                                          case 4:
                                                                          case 5:
                                                                          case 6:
                                                                          case 9:
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 2:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 7:
                                                                                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }
                                                                               }
                                                                               break;
                                                                          case 7:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 2:
                                                                                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }                
                                                                               }
                                                                          break;
                                                                          case 8:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                case 2:
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                GANADORU();
                                                                                break;
                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                break;
                                                                               }
                                                                               }
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                     }
                                     }
                               break;
                               case 6:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                    {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();                                                     
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();                                                     
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU(); 
                                                     break;
                                                     case 1:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 8:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                 gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 4:
                                                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 4:
                                                                                gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 7:
                                                                                gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                GANADORU();
                                                                           break;
                                                          }
                                                          }
                                                     break;
                                    }
                                    }
                               break;
                               case 7:
                                     posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 2:
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 8:
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 9:
                                                                                posicion2=0;
                                                                                while(posicion2<=9)
                                                                                {
                                                                                gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion2);
                                                                                switch(posicion2)
                                                                                {
                                                                                                 case 2:
                                                                                                     gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                                     GANADORU();
                                                                                                 break;
                                                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                 break; 
                                                                                }
                                                                                }
                                                                           break;
                                                           }
                                                           }
                                                      break;
                                     }
                                     }
                               break;
                               case 8:
                                    posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                            posicion=0;
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            case 2:
                                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                               gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                               GANADORU();
                                                                            break;
                                                                            case 9:
                                                                                 posicion2=0;
                                                                                 while(posicion2<=9)
                                                                                 {
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                                 switch(posicion2)
                                                                                 {
                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                  break;
                                                                                                  case 2:
                                                                                                       gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                                       GANADORU();
                                                                                                  break;
                                                                                 }
                                                                                 }
                                                                            break;
                                                                            case 7:
                                                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                 gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                 GANADORU();
                                                                            break;
                                                            }
                                                            }
                                                      break;
                                                      case 7:
                                                           gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
                               case 9:
                                     posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                           break;
                                                                           case 1:
                                                                                gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 7:
                                                                                gotoxy(30,19);printf("X"); CAT[2][0];
                                                                                gotoxy(35,19);printf("X"); CAT[2][1];
                                                                           break;
                                                                           case 8:
                                                                                posicion2=0;
                                                                                while(posicion2<=9)
                                                                                {
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion2);
                                                                                switch(posicion2)
                                                                                {
                                                                                                 case 1:
                                                                                                      gotoxy(30,15); printf("X"); CAT[0][0]='X';
                                                                                                      GANADORU();
                                                                                                 break;
                                                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                 break;
                                                                                }
                                                                                }
                                                                           break;
                                                           }
                                                           }
                                                      break;
                                                      case 7:
                                                           gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 8:
                                                           gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
              }
          }
          }
return 0;
}
////////////////////////////////////////////////////////////JUDADA 4///////////////////////////////////////////////////////////
JUGADA4U()
{
            while(posicion2<=9)
          {
              gotoxy(30,17); printf("X"); CAT[1][0]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 1:
                                     while(posicion<=9)
                                     {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                   gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 8:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                         gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 6:
                                                                                              gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 6:
                                                                         gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                         gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 9:
                                                                         gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                         gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 7:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(30,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                   gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 2:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                         gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 6:
                                                                                              gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 6:
                                                                         gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                         gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 3:
                                                                         gotoxy(40,17);printf("X"); CAT[0][2]='X';
                                                                         gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 8:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                 gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 1:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 6:
                                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 6:
                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                             break;
                                     }
                                     }
                               break;
                               case 6:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                 gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                               GANADORU();
                                                          break;
                                                          case 8:
                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                               GANADORU();
                                                          break;
                                                          case 9:
                                                               gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                                 break;
                                     }
                                     }
                               break;
                               case 3:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                 gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 7:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                             gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 2:
                                                                      gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 2:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 8:
                                                                      gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 8:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 2:
                                                                      gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                            }
                                                            }
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 2:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 9:
                                                  while(posicion2<=9)
                                                  {
                                                  gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                  gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                  switch(posicion2)
                                                  {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break; 
                                                       case 6:
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;
                                                       case 7:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                            gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                               break;
                                                               case 6:
                                                                    gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                    GANADORU();
                                                               break;         
                                                            }
                                                            }
                                                       break;
                                                       case 8:
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;          
                                                  }
                                                  }
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 9:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 7:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                             gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 6:
                                                                      gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 1:
                                                            gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;
                                                       case 6:
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               
              }
          } 
return 0;
}
///////////////////////////////////////////////////////////JUGADA 5////////////////////////////////////////////////////////////
JUGADA5U()
{
          while(posicion2<=9)
          {
              gotoxy(35,17); printf("X"); CAT[1][1]='X';
              gotoxy(30,15); printf("O"); CAT[0][0]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 2:
                                    while(posicion<=9)
                                    {
                                    gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                    gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                    gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                    gotoxy(45,12); scanf("%d",&posicion);
                                    switch(posicion)
                                                    {
                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                         break;
                                                                         case 3:
                                                                              while(posicion2<=9)
                                                                              {
                                                                               gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                               gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion2);
                                                                               switch(posicion2)
                                                                                                {
                                                                                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                      break;
                                                                                                                      case 4:
                                                                                                                      while(posicion<=9)
                                                                                                                      {
                                                                                                                      gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                                                                      gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                                                                      gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                                      gotoxy(45,12); scanf("%d",&posicion);
                                                                                                                      switch(posicion)
                                                                                                                                      {
                                                                                                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                                                           break;
                                                                                                                                                           case 9:
                                                                                                                                                           gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                                                                           GANADORU();
                                                                                                                                                           break;
                                                                                                                                      }
                                                                                                                      }
                                                                                                                      break;
                                                                                                                      case 6:
                                                                                                                      gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                                                                      gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                                                      GANADORU();
                                                                                                                      break;
                                                                                                                      case 9:
                                                                                                                      gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                                                      gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                                                                      GANADORU();
                                                                                                                      break;
                                                                                                }
                                                                               }
                                                                         break;
                                                                         case 4:
                                                                         while(posicion2<=9)
                                                                         {
                                                                         gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                         gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion2);
                                                                         switch(posicion2)
                                                                                          {
                                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                               break;
                                                                                                               case 9:
                                                                                                                while(posicion<=9)
                                                                                                                {
                                                                                                                gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                                gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                                                switch(posicion)
                                                                                                                                {
                                                                                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                                                     break;
                                                                                                                                                     case 7:
                                                                                                                                                     gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                                                                                                     GANADORU();
                                                                                                                                                      break;
                                                                                                                                }
                                                                                                                }
                                                                                                               break;
                                                                                                               case 7:
                                                                                                                while(posicion<=9)
                                                                                                                {
                                                                                                                 gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                                                 switch(posicion)
                                                                                                                                 {
                                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                                  break;
                                                                                                                                  case 9:
                                                                                                                                  gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                                                  GANADORU();
                                                                                                                                  break;
                                                                                                                                 }
                                                                                                               }
                                                                                                               break;
                                                                                                               case 3:
                                                                                                               while(posicion<=9)
                                                                                                               {
                                                                                                               gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                                               gotoxy(30,17); printf("O"); CAT[2][0]='O';
                                                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                                                               switch(posicion)
                                                                                                                               {
                                                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                                break;
                                                                                                                                case 9:
                                                                                                                                gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                                                GANADORU();
                                                                                                                                break;
                                                                                                                               }
                                                                                                               }
                                                                                                               break;
                                                                                                                }
                                                         }
                                                    break;
                                                    case 6:
                                                         while(posicion2<=9)
                                                         {
                                                         gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                         gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                         gotoxy(45,12); scanf("%d",&posicion2);
                                                         switch(posicion2)
                                                         {
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 3:
                                                                               gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 9:
                                                                               gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 7:
                                                                                while(posicion<=9)
                                                                               {
                                                                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                               gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                    break;
                                                                                    case 9:
                                                                                    gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                    GANADORU();
                                                                                    break;
                                                                               }
                                                                               }
                                                                          break;
                                                                          }
                                                         }
                                                    break;
                                                     case 7:
                                                         while(posicion2<=9)
                                                         {
                                                         gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                         gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                         gotoxy(45,12); scanf("%d",&posicion2);
                                                         switch(posicion2)
                                                         {
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 9:
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               
                                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                    break;
                                                                                    case 4:
                                                                                    gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                                    GANADORU();
                                                                                    break;
                                                                               }
                                                                               }
                                                                          break;
                                                                          case 6:
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                               gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                    break;
                                                                                    case 9:
                                                                                    gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                    GANADORU();
                                                                                    break;
                                                                               }
                                                                               }
                                                                          break;
                                                                          case 4:
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                               gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                    break;
                                                                                    case 9:
                                                                                    gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                    GANADORU();
                                                                                    break;
                                                                               }
                                                                               }
                                                                          break;
                                                         }
                                                         }
                                                    break;
                                                    case 9:
                                                         while(posicion2<=9)
                                                         {
                                                         gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                         gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                         gotoxy(45,12); scanf("%d",&posicion2);
                                                         switch(posicion2)
                                                         {
                                                                          
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 3:
                                                                               gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 6:
                                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 7:
                                                                                while(posicion<=9)
                                                                               {
                                                                               gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                               gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                    break;
                                                                                    case 6:
                                                                                    gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                                    GANADORU();
                                                                                    break;
                                                                               }
                                                                               }
                                                                          break;
                                                         }
                                                         }
                                                    break;
                                                   
                                                   }
                                    }
                              case 3:
                                   while(posicion<=9)
                                    {
                                    gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                    gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                    gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                    gotoxy(45,12); scanf("%d",&posicion);
                                    switch(posicion)
                                    {
                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                    break;
                                                    case 2:
                                                         gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                         GANADORU();
                                                    break;
                                                    case 4:
                                                         while(posicion2<=9)
                                                         {
                                                         gotoxy(30,17); printf("X"); CAT[1][2]='X';
                                                         gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                         gotoxy(45,12); scanf("%d",&posicion2);
                                                         switch(posicion2)
                                                         {
                                                                          
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 2:
                                                                               
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                               gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                          break;
                                                                                          case 9:
                                                                                              gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                              GANADORU();
                                                                                          break;  
                                                                                          }
                                                                               }
                                                                          break;
                                                                          case 8:
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                               break; 
                                                                                               case 9:
                                                                                                    gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                    GANADORU();
                                                                                               break; 
                                                                               }
                                                                               }
                                                                          break;
                                                                          case 9:
                                                                               while(posicion<=9)
                                                                               {
                                                                               gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                                               switch(posicion)
                                                                               {
                                                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                               break;
                                                                                               case 8:
                                                                                                    gotoxy(35,19); printf("X"); CAT[2][2]='X';
                                                                                                    GANADORU();
                                                                                               break;  
                                                                               }
                                                                               }
                                                                          break;
                                                                          }
                                                         }
                                                    break;
                                                    case 6:
                                                         gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                         GANADORU();
                                                    break;
                                                    case 8:
                                                         gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                         GANADORU();
                                                    break;
                                                    case 9:
                                                         gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                         GANADORU();
                                                    break;
                                    }
                                   }
                                   break;          
                                   case 4:
                                        while(posicion<=9)
                                                          {
                                                           gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                           gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                            break;
                                                            case 2:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                 gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 3:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                       gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 9:
                                                                                            gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 7:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 9:
                                                                                            gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 9:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 3:
                                                                                            gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }     
                                                            break;
                                                            case 3:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 2:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                       gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 9:
                                                                                            gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 8:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                       gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 9:
                                                                                            gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 9:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                       break;
                                                                                       case 2:
                                                                                            gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                            GANADORU();
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                            case 7:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 2:
                                                                                       gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                       gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 8:
                                                                                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                       gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 9:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                       break;
                                                                                                       case 2:
                                                                                                            gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                                            GANADORU();
                                                                                                       break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                            case 8:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 7:
                                                                                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 9:
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 3:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                       gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                       break;
                                                                                                       case 9:
                                                                                                            gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                                            GANADORU();
                                                                                                       break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                            case 9:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 3:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                       gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                       break;
                                                                                                       case 8:
                                                                                                            gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                                            GANADORU();
                                                                                                       break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 7:
                                                                                       gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 8:
                                                                                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                       gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                           }
                                                          }
                                   break;
                                   case 6:
                                        while(posicion<=9)
                                                          {
                                                           gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                           gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                            break;
                                                            case 2:
                                                                 gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 3:
                                                                 gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 7:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 8:
                                                                      gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                      GANADORU();
                                                                 break;
                                                                 case 9:
                                                                      gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                      gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                      GANADORU();
                                                                 break;
                                                                 case 2:
                                                                      while(posicion<=9)
                                                                      {
                                                                      gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                      gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                      gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                      gotoxy(45,12); scanf("%d",&posicion);
                                                                      switch(posicion)
                                                                      {
                                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                      break;
                                                                      case 9:
                                                                           gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                           GANADORU();
                                                                      break;
                                                                      }
                                                                      }
                                                                 break;
                                                                 }
                                                                 }
                                                            break;
                                                            case 8:
                                                                 gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 9:
                                                                 gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 GANADORU();
                                                            break;     
                                                           }
                                                          }
                                   break;
/////////////////////////////////////////////////////77PENDIENTE
                                   case 7:
                                        while(posicion<=9)
                                                          {
                                                           gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                           gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                            break;
                                                            case 4:
                                                                 gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 6:
                                                                 gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 8:
                                                                 gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 9:
                                                                 gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                 gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 2:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                 gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 4:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                                       gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 9:
                                                                                             gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 6:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                                       gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 9:
                                                                                             gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 9:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 4:
                                                                                             gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                           }
                                                          }
                                   break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                   case 8:
                                        while(posicion<=9)
                                                          {
                                                           gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                           gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                            break;
                                                            case 4:
                                                                 gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 6:
                                                                 gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 7:
                                                                 gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 9:
                                                                 gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 3:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 6:
                                                                                       gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                                       gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 9:
                                                                                       gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                       gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                                       GANADORU();
                                                                                  break;
                                                                                  case 4:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                                       gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 9:
                                                                                             gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                           }
                                                          }
                                   break;
                                   case 9:
                                        while(posicion<=9)
                                                          {
                                                           gotoxy(40,19); printf("X"); CAT[2][2]='X';
                                                           gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                            break;
                                                            case 2:
                                                                 gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                 gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 3:
                                                                 gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                 gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 6:
                                                                 gotoxy(40,17); printf("X"); CAT[1][2]='X';
                                                                 gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 8:
                                                                 gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                 gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                                 GANADORU();
                                                            break;
                                                            case 4:
                                                                 while(posicion2<=9)
                                                                 {
                                                                 gotoxy(30,17); printf("X"); CAT[1][0]='X';
                                                                 gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                                 switch(posicion2)
                                                                 {
                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                  break;
                                                                                  case 2:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                       gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 3:
                                                                                             gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 3:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                       gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 8:
                                                                                             gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                             GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                                  case 8:
                                                                                       while(posicion<=9)
                                                                                       {
                                                                                       gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                                                       gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                                                       gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                       gotoxy(45,12); scanf("%d",&posicion);
                                                                                       switch(posicion)
                                                                                       {
                                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                        break;
                                                                                        case 3:
                                                                                        gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                                                                        GANADORU();
                                                                                        break;
                                                                                       }
                                                                                       }
                                                                                  break;
                                                                 }
                                                                 }
                                                            break;
                                                            
                                                           }
                                                          }
                                   break;                                                                                                                                                                                              
              }                
          }
return 0;
}
///////////////////////////////////////////////////////////JUGADA 6////////////////////////////////////////////////////////////
JUGADA6U()
{
            while(posicion2<=9)
          {
              gotoxy(40,17); printf("X"); CAT[1][2]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 3:
                                     while(posicion<=9)
                                     {
                                     gotoxy(40,15); printf("X"); CAT[0][2]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 1:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                   gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 8:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                         gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 4:
                                                                                              gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 4:
                                                                         gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                         gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 7:
                                                                         gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                         gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 7:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                   gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 9:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                         gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 4:
                                                                                              gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 4:
                                                                         gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                         gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 3:
                                                                         gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                         gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 8:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 1:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 7:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                               gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 2:
                                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 4:
                                                               gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                               GANADORU();
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                             break;
                                     }
                                     }
                               break;
                               case 4:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                 gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                               GANADORU();
                                                          break;
                                                          case 8:
                                                               gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                               GANADORU();
                                                          break;
                                                          case 9:
                                                               gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                                 break;
                                     }
                                     }
                               break;
                               case 1:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(35,19); printf("X"); CAT[2][1]='X';
                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 3:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                             gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 4:
                                                                      gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 4:
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            GANADORU();
                                                       break;
                                                       case 9:
                                                            gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 2:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  while(posicion2<=9)
                                                  {
                                                  gotoxy(30,19); printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                  switch(posicion2)
                                                  {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break; 
                                                       case 4:
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                            GANADORU();
                                                       break;
                                                       case 1:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                            gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                               break;
                                                               case 8:
                                                                    gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                    GANADORU();
                                                               break;         
                                                            }
                                                            }
                                                       break;
                                                       case 8:
                                                            gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                            gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                            GANADORU();
                                                       break;          
                                                  }
                                                  }
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 9:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                 gotoxy(35,19); printf("O"); CAT[2][1]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 2:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                             gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 4:
                                                                      gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 1:
                                                            gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                            gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                            GANADORU();
                                                       break;
                                                       case 4:
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               
              }
          } 
return 0;
}
///////////////////////////////////////////////////////////JUGADA 7////////////////////////////////////////////////////////////
JUGADA7U()
{          win=0;
          while(posicion2<=9)
          {
          while(win<=1)
          {
              gotoxy(30,19);printf("X"); CAT[2][0]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                                case 1:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                           posicion2=0;
                                                           while(posicion2<=9)
                                                           {
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            break;
                                                                            case 8:
                                                                                 posicion=0;
                                                                                 while(posicion<=9)
                                                                                 {
                                                                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 3:
                                                                                                                       gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                            break;
                                                                            case 3:
                                                                                 gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                 gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                 GANADORU();
                                                                            break;
                                                                            case 9:
                                                                                 gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                 gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                 GANADORU();
                                                                            break;
                                                            }
                                                            }
                                                     break;
                                     }
                                     }
                               break;
                               case 2:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           case 3:
                                                                                gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 8:
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 1:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                                  gotoxy(40,15);printf("O"); CAT[0][0]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 8:
                                                                                                                       gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                          break;
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                     }
                                     }
                               break;
                               case 3:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 2:
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 8:
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 9:
                                                                                posicion2=0;
                                                                                while(posicion2<=9)
                                                                                {
                                                                                gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                                                gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion2);
                                                                                switch(posicion2)
                                                                                {
                                                                                                 case 2:
                                                                                                     gotoxy(35,15); printf("X"); CAT[0][1]='X';
                                                                                                     GANADORU();
                                                                                                 break;
                                                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                 break; 
                                                                                }
                                                                                }
                                                                           break;
                                                           }
                                                           }
                                                      break;
                                     }
                                     }
                               break;
                               case 4:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 9:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 2:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 3:
                                                                                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }
                                                                               }
                                                                               break;
                                                                          case 3:
                                                                               gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                               GANADORU();
                                                                          break;
                                                                          case 6:
                                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                               gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                               GANADORU();
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                     }
                                     }
                               break;
                               case 6:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                    {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU();                                                     
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                          GANADORU(); 
                                                     break;
                                                     case 1:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 8:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                 gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 2:
                                                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 2:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                 gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 8:
                                                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 3:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                 gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 8:
                                                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                          }
                                                          }
                                                     break;
                                    }
                                    }
                               break;
                               case 8:
                                    posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 1:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                             break;
                                                             case 2:
                                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                  GANADORU();
                                                             break;
                                                             case 3:
                                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                  GANADORU();
                                                             break;
                                                             case 6:
                                                                  posicion2=0;
                                                                  while(posicion2<=9)
                                                                  {
                                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                                  switch(posicion2)
                                                                  {
                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                        break;
                                                                        case 2:
                                                                             gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                             GANADORU();
                                                                        break;           
                                                                  }
                                                                  }
                                                             break;              
                                                           }
                                                           }
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
                               case 9:
                                     posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 2:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                   default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                   break;
                                                                   case 1:
                                                                        gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                        gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                        GANADORU();
                                                                   break;
                                                                   case 3:
                                                                        gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                        gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                        GANADORU();
                                                                   break;
                                                                   case 6:
                                                                        posicion2=0;
                                                                        while(posicion2<=9)
                                                                        {
                                                                        gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                        gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                        gotoxy(45,12); scanf("%d",&posicion2);
                                                                        switch(posicion2)
                                                                        {
                                                                              default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                              break;
                                                                              case 1:
                                                                                   gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                   GANADORU();
                                                                              break;           
                                                                        }
                                                                        }
                                                                   break;       
                                                           }
                                                           }
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
              }
          }
          }
return 0;
}
///////////////////////////////////////////////////////////JUGADA 8////////////////////////////////////////////////////////////
JUGADA8U()
{         
          while(posicion2<=9)
          {
              gotoxy(35,19);printf("X"); CAT[2][1]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                               break;
                               case 7:
                                     while(posicion<=9)
                                     {
                                     gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 1:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                   gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 6:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                         gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 2:
                                                                                              gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 2:
                                                                         gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                         gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 3:
                                                                         gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                         gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 9:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                   while(posicion2<=9)
                                                   {
                                                   gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                   gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                                   gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                   gotoxy(45,12); scanf("%d",&posicion2);
                                                   switch(posicion2)
                                                   {
                                                                    default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                    break;
                                                                    case 4:
                                                                         while(posicion<=9)
                                                                         {
                                                                         gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                         gotoxy(30,15); printf("O"); CAT[0][0]='O';
                                                                         gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                         gotoxy(45,12); scanf("%d",&posicion);
                                                                         switch(posicion)
                                                                         {
                                                                                         default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                         break;
                                                                                         case 2:
                                                                                              gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                              GANADORU();
                                                                                         break;
                                                                         }
                                                                         }
                                                                    break;
                                                                    case 2:
                                                                         gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                         GANADORU();
                                                                    break;
                                                                    case 1:
                                                                         gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                         gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                         GANADORU();
                                                                    break;
                                                   }
                                                   }
                                             break;
                                             case 8:
                                                  gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 4:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                 gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 1:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 6:
                                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 6:
                                                               gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                             break;
                                     }
                                     }
                               break;
                               case 6:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 1:
                                                 while(posicion2<=9)
                                                 {
                                                 gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                 gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                          break;
                                                          case 3:
                                                               while(posicion<=9)
                                                               {
                                                               gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                               gotoxy(35,15); printf("O"); CAT[0][1]='O';
                                                               gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                               gotoxy(45,12); scanf("%d",&posicion);
                                                               switch(posicion)
                                                               {
                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                     break;
                                                                     case 4:
                                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                          GANADORU();
                                                                     break;          
                                                               }
                                                               }
                                                          break;
                                                          case 4:
                                                               gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                               gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                               GANADORU();
                                                          break;
                                                          case 2:
                                                               gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                               gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                               GANADORU();
                                                          break;       
                                                 }
                                                 } 
                                                 break;
                                     }
                                     }
                               break;
                               case 1:
                                    while(posicion<=9)
                                     {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                 gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 7:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                             gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 2:
                                                                      gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 9:
                                                            gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;
                                                       case 2:
                                                            gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                            gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 2:
                                    while(posicion<=9)
                                     {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(40,19); printf("O"); CAT[2][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  while(posicion2<=9)
                                                  {
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(40,15); printf("O"); CAT[0][2]='O';
                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                  switch(posicion2)
                                                  {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break; 
                                                       case 4:
                                                            gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            GANADORU();
                                                       break;
                                                       case 6:
                                                            while(posicion<=9)
                                                            {
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(30,17); printf("O"); CAT[1][0]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                               default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                               break;
                                                               case 7:
                                                                    gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                    GANADORU();
                                                               break;         
                                                            }
                                                            }
                                                       break;
                                                       case 7:
                                                            gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                            gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                            GANADORU();
                                                       break;          
                                                  }
                                                  }
                                             break;
                                             case 3:
                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  gotoxy(30,17);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 6:
                                                  gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               case 3:
                                    while(posicion<=9)
                                     {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(40,17); printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                             break;
                                             case 1:
                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 9:
                                                  gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 4:
                                                  while(posicion2<=9)
                                                 {
                                                 gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                 gotoxy(30,15); printf("O"); CAT[0][2]='O';
                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                 gotoxy(45,12); scanf("%d",&posicion2);
                                                 switch(posicion2)
                                                 {
                                                       default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                       break;
                                                       case 9:
                                                            while(posicion<=9)
                                                            {
                                                             gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                                             gotoxy(30,19); printf("O"); CAT[2][0]='O';
                                                             gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                             gotoxy(45,12); scanf("%d",&posicion);
                                                             switch(posicion)
                                                             {
                                                                 default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                 break;
                                                                 case 2:
                                                                      gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                      GANADORU();
                                                                 break;            
                                                             }
                                                             }
                                                       break;
                                                       case 7:
                                                            gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                            gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                            GANADORU();
                                                       break;
                                                       case 2:
                                                            gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                            gotoxy(40,19);printf("O"); CAT[2][2]='O';
                                                            GANADORU();
                                                       break;           
                                                 }
                                                 } 
                                             break;
                                             case 2:
                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                             case 7:
                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                  GANADORU();
                                             break;
                                     }
                                     }
                               break;
                               
              }
          }
return 0;
}



///////////////////////////////////////////////////////////JUGADA 9////////////////////////////////////////////////////////////
JUGADA9U()
{          win=0;
          while(posicion2<=9)
          {
          while(win<=1)
          {
              gotoxy(40,19);printf("X"); CAT[2][2]='X';
              gotoxy(35,17); printf("O"); CAT[1][1]='O';
              gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
              gotoxy(45,12); scanf("%d",&posicion2);
              switch(posicion2)
              {
                                case 1:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                     gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                           posicion2=0;
                                                           while(posicion2<=9)
                                                           {
                                                            gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                            gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                            gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                            gotoxy(45,12); scanf("%d",&posicion);
                                                            switch(posicion)
                                                            {
                                                                            default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                            break;
                                                                            case 7:
                                                                                 posicion=0;
                                                                                 while(posicion<=9)
                                                                                 {
                                                                                                  gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                                  gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                                  case 2:
                                                                                                                       gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                            break;
                                                                            case 2:
                                                                                 gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                 gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                                            case 8:
                                                                                 gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                 gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                                                 GANADORU();
                                                                            break;
                                                            }
                                                            }
                                                     break;
                                     }
                                     }
                               break;
                               case 2:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           case 1:
                                                                                gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 8:
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                                GANADORU();
                                                                           break;
                                                                           case 3:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                                  gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                                  gotoxy(45,12); scanf("%d",&posicion);
                                                                                                  switch(posicion)
                                                                                                  {
                                                                                                                  case 8:
                                                                                                                       gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                                                       GANADORU();
                                                                                                                  break;
                                                                                                                  default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                                                  break;
                                                                                                  }
                                                                               }
                                                                          break;
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                          }
                                                          }
                                                     break;
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                     }
                                     }
                               break;
                               case 3:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                     gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                     posicion2=0;
                                                     while(posicion2<=9)
                                                     {
                                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                     gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                     gotoxy(45,12); scanf("%d",&posicion2);
                                                     switch(posicion2)
                                                     {
                                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                      break;
                                                                      case 1:
                                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                           GANADORU();
                                                                      break;
                                                                      case 2:
                                                                           posicion=0;
                                                                           while(posicion<=9)
                                                                           {
                                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                           gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                                           switch(posicion)
                                                                           {
                                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                                           break;
                                                                                           case 7:
                                                                                                gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                                                GANADORU();
                                                                                           break;
                                                                           }
                                                                           }
                                                                      break;
                                                                      case 7:
                                                                           gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                           GANADORU();
                                                                      break;
                                                     }
                                                     }
                                                     break;
                                                     case 7:
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                          GANADORU();
                                                     break;
                                     }
                                     }
                               break;
                               case 4:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                     gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                     {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                     break;
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 6:
                                                          gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                          GANADORU();
                                                     break;
                                                     case 3:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                          gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                          default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                          break;
                                                                          case 1:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 8:
                                                                                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }
                                                                               }
                                                                          break;
                                                                          case 2:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 8:
                                                                                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }
                                                                               }
                                                                               break;
                                                                          case 8:
                                                                               posicion=0;
                                                                               while(posicion<=9)
                                                                               {
                                                                                gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                                                gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                gotoxy(45,12); scanf("%d",&posicion);
                                                                                switch(posicion)
                                                                                {
                                                                                                case 2:
                                                                                                     gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                                     GANADORU();
                                                                                                break;
                                                                                                default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                                break;
                                                                                }
                                                                               }
                                                                               break;
                                                          }
                                                          }
                                                     break;
                                     }
                                     }
                               break;
                               case 6:
                                    posicion=0;
                                    while(posicion<=9)
                                    {
                                     gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                     gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion);
                                     switch(posicion)
                                    {
                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                     break;
                                                     case 1:
                                                          gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 2:
                                                          gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();
                                                     break;
                                                     case 4:
                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU();                                                     
                                                     break;
                                                     case 8:
                                                          gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                                          gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                                          GANADORU(); 
                                                     break;
                                                     case 7:
                                                          posicion2=0;
                                                          while(posicion2<=9)
                                                          {
                                                          gotoxy(30,19);printf("X"); CAT[2][0]='X';
                                                          gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                                          gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                          gotoxy(45,12); scanf("%d",&posicion2);
                                                          switch(posicion2)
                                                          {
                                                                           default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                           break;
                                                                           case 2:
                                                                                posicion=0;
                                                                                while(posicion<=9)
                                                                                {
                                                                                 gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                                 gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                                 gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                                 gotoxy(45,12); scanf("%d",&posicion);
                                                                                 switch(posicion)
                                                                                 {
                                                                                     default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion=0;
                                                                                     break;
                                                                                     case 4:
                                                                                          gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                          GANADORU();
                                                                                     break;            
                                                                                 }
                                                                                }
                                                                           break;
                                                                           case 1:
                                                                                 gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                 gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                                 GANADORU();
                                                                           break;
                                                                           case 4:
                                                                                 gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                                 gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                                                 GANADORU();
                                                                           break;
                                                          }
                                                          }
                                                     break;
                                    }
                                    }
                               break;
                               case 8:
                                    posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(35,19);printf("X"); CAT[2][1]='X';
                                     gotoxy(30,19);printf("O"); CAT[2][0]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 3:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                             default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                             break;
                                                             case 2:
                                                                  gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                  GANADORU();
                                                             break;
                                                             case 1:
                                                                  gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                  gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                                  GANADORU();
                                                             break;
                                                             case 4:
                                                                  posicion2=0;
                                                                  while(posicion2<=9)
                                                                  {
                                                                  gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                                  gotoxy(30,15);printf("O"); CAT[0][0]='O';
                                                                  gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                  gotoxy(45,12); scanf("%d",&posicion2);
                                                                  switch(posicion2)
                                                                  {
                                                                        default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                        break;
                                                                        case 2:
                                                                             gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                                             GANADORU();
                                                                        break;           
                                                                  }
                                                                  }
                                                             break;              
                                                           }
                                                           }
                                                      break;
                                                      case 2:
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
                               case 9:
                                     posicion2=0;
                                     while(posicion2<=9)
                                     {
                                     gotoxy(40,19);printf("X"); CAT[2][2]='X';
                                     gotoxy(35,19);printf("O"); CAT[2][1]='O';
                                     gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                     gotoxy(45,12); scanf("%d",&posicion2);
                                     switch(posicion2)
                                     {
                                                      default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                      break;
                                                      case 1:
                                                           gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 2:
                                                           posicion=0;
                                                           while(posicion<=9)
                                                           {
                                                           gotoxy(35,15);printf("X"); CAT[0][1]='X';
                                                           gotoxy(30,17);printf("O"); CAT[1][0]='O';
                                                           gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                           gotoxy(45,12); scanf("%d",&posicion);
                                                           switch(posicion)
                                                           {
                                                                   default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                   break;
                                                                   case 1:
                                                                        gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                        gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                        GANADORU();
                                                                   break;
                                                                   case 3:
                                                                        gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                                        gotoxy(40,17);printf("O"); CAT[1][2]='O';
                                                                        GANADORU();
                                                                   break;
                                                                   case 6:
                                                                        posicion2=0;
                                                                        while(posicion2<=9)
                                                                        {
                                                                        gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                                        gotoxy(40,15);printf("O"); CAT[0][2]='O';
                                                                        gotoxy(20,12); printf("Usuario,Elija posici�n [   ].\n");
                                                                        gotoxy(45,12); scanf("%d",&posicion2);
                                                                        switch(posicion2)
                                                                        {
                                                                              default:gotoxy(10,13);printf("Error.Rectifica posici�n...");getch();getch();posicion2=0;
                                                                              break;
                                                                              case 1:
                                                                                   gotoxy(30,15);printf("X"); CAT[0][0]='X';
                                                                                   GANADORU();
                                                                              break;           
                                                                        }
                                                                        }
                                                                   break;       
                                                           }
                                                           }
                                                      break;
                                                      case 3:
                                                           gotoxy(40,15);printf("X"); CAT[0][2]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 4:
                                                           gotoxy(30,17);printf("X"); CAT[1][0]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                                      case 6:
                                                           gotoxy(40,17);printf("X"); CAT[1][2]='X';
                                                           gotoxy(35,15);printf("O"); CAT[0][1]='O';
                                                           GANADORU();
                                                      break;
                                     }
                                     }
                               break;
              }
          }
          }
return 0;
}
//////////////////////////////////////////////////////////FUNCION USER/////////////////////////////////////////////////////////
///////////////////////////////////////////MODO DE JUEGO CUANDO EMPIEZA A JUGAR EL USUARIO////////////////////////////////////
USER()
{
 while(posicion<=9)
 {
      system("cls");
      printf("  G   A   T   O ! !   \n");
      gotoxy(1,2); printf("Tabla de posiciones");
      gotoxy(1,3);printf("Instrucciones.Elija su posici�n y Presione Enter");
      gotoxy(1,4);printf ("                             1  � 2  � 3  \n");
      gotoxy(1,5);printf ("                            �������������� \n");
      gotoxy(1,6);printf ("                             4  � 5  � 6  \n");
      gotoxy(1,7);printf ("                            �������������� \n");
      gotoxy(1,8);printf ("                             7  � 8  � 9  \n");
      gotoxy(1,9);printf("Modo:Usuario  Vs CPU.\n\n");
      gotoxy(1,10);printf("                  USUARIO :[   ]                 CPU :[   ] \n");
      gotoxy(30,10);printf("X");
      gotoxy(57,10);printf("O");
      DIBUJO();
      getch();
      gotoxy(20,12); printf("Usuario, Elija posicion [  ].\n");
      gotoxy(45,12); scanf("%d",&posicion); 
      switch(posicion)
      {
       case 1:
            JUGADA1U();
            break;
       case 2:
            JUGADA2U();
            break;
       case 3:
            JUGADA3U();
            break;
       case 4:
            JUGADA4U();
            break;
       case 5:
            JUGADA5U()
            ;break;
       case 6:
            JUGADA6U()
            ;break;
       case 7:
            JUGADA7U();
            break;
       case 8:
            JUGADA8U()
            ;break;
       case 9:
            JUGADA9U();
            break;
       default:
              gotoxy(10,13);
              printf("Error.Rectifica posici�n...");
              getch();
              getch();
              posicion=0;
              break;
  }
 }
return 0;
}
////////////////////////////////////////////////////////////FUNCION CPU/////////////////////////////////////////////////////
//////////////////////////////////////////MODO DE JUEGO CUANDO EMPIEZA A JUGAR EL CPU//////////////////////////////////////
CPU()
{
      while(posicion<=9)
 {
      system("cls");
      printf("  G   A   T   O ! !   \n");
      gotoxy(1,2); printf("Tabla de posiciones");
      gotoxy(1,3);printf("Instrucciones.Elija su posici�n y Presione Enter");
      gotoxy(1,4);printf ("                             1  � 2  � 3  \n");
      gotoxy(1,5);printf ("                            �������������� \n");
      gotoxy(1,6);printf ("                             4  � 5  � 6  \n");
      gotoxy(1,7);printf ("                            �������������� \n");
      gotoxy(1,8);printf ("                             7  � 8  � 9  \n");
      gotoxy(1,9);printf("Modo:CPU  Vs Usuario.\n\n");
      gotoxy(1,10);printf("                  CPU :[   ]                 Usuario :[   ] \n");
      gotoxy(26,10);printf("X");
      gotoxy(57,10);printf("O");
      DIBUJO1();
      gotoxy(20,12); printf("Usuario, Elija posicion [  ].\n");
      gotoxy(45,12); scanf("%d",&posicion);
      switch(posicion)
      {
          case 1:
               JUGADA1();
               break;
          case 2:
               JUGADA2();
               break;
          case 3:
               JUGADA3();
               break;
          case 4:
               JUGADA4();
               break;
          case 5:
               JUGADA5();
               break;
          case 6:
               JUGADA6();
               break;
          case 7:
               JUGADA7();
               break;
          case 8:
               JUGADA8();
               break;
          case 9:
               gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion=0;
               break;
          default: 
               gotoxy(10,13); printf("rectifica posicion"); getch(); getch(); posicion=0;
               break;
      }
}
return 0;
}                 
//////////////////////////////////////////////////FUNCION PRINCIPAL/////////////////////////////////////////////////////////
main()
{
      gotoxy(30,0); printf("Bienvenido\n");
      gotoxy(30,1); printf("El Gato\n"); 
      printf("Quien comienza?\n Para que comienze usted precione U\n Para que comienze la compu presione la tecla C\n Para ver el registro de juegos presione cualquier tecla\n");
      opc=toupper(getch());
      switch(opc)
      {
                 case 'U':
                      printf("Usted inicia\n");
                      system("pause");
                      CAR();
                      for(x=0;x<3;x++)
                      {
                                      {
                                      for(y=0;y<3;y++)
                                                      CAT[x][y]=' ';
                                      }
                      }
                      posicion=0;
                      win=0;
                      USER();
                      getch();             
                      break;
                 case 'C':
                      printf("La compu inicia\n");
                      system("pause");
                      CAR();
                      for(x=0;x<3;x++)
                      {
                                      {
                                      for(y=0;y<3;y++)
                                                      CAT[x][y]=' ';
                                      }
                      }
                      posicion=0;
                      win=0;
                      CPU();
                      getch();
                      break;
                 default:
                         LECTURA();
                         break;
      }
      getch();
      return 0;
}
///////////////////////////////////////////////////////Registro//////////////////////////////////////////////////////////////////////////
LECTURA()
{
      char n;
      struct registro {
                   char ganados[14];
                   char perdidos[14];
                   char empatados[14];
                   }record;
      FILE *fp;
      fp=fopen("datos.dat","rb");
      while((fread(&record,sizeof(struct registro),1,fp))>0)
      {
                                 printf("Ganados:%s\n",record.ganados);
                                 printf("Perdidos:%s\n",record.perdidos);
                                 printf("Empatados:%s\n",record.empatados);    
      }
      fclose(fp);
      printf("Desea realizar regresar al menu? [S/N]\n");
      n=toupper(getch());
      if (n=='S')
      {
               main();
      }
      else
      {
      return 0;
      }
}
