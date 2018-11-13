#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
struct registro {
                   char ganados[14];
                   char perdidos[14];
                   char empatados[14];
                   }record;
ALTA()
{
      FILE *fp;
      fp=fopen("datos.dat","ab");
      do
      {
                                 system("cls");
                                 printf("Ganados:");
                                 gets(record.ganados);
                                 if (record.ganados[0]=='\0')
                                    break;
                                 printf("Perdidos:");
                                 gets(record.perdidos);
                                 printf("Empatados:");   
                                 gets(record.empatados);
                                 fwrite(&record, sizeof(struct registro),1,fp);
      }
      while(1);
      fclose(fp);
      return 0;
}
LECTURA()
{
      FILE *fp;
      fp=fopen("datos.dat","rb");
      while((fread(&record,sizeof(struct registro),1,fp))>0)
      {
                                 printf("Ganados:%s\n",record.ganados);
                                 printf("Perdidos:%s\n",record.perdidos);
                                 printf("Empatados:%s\n",record.empatados);    
      }
      fclose(fp);
      getch();
      return 0;
}
main()
{
      int i;
       do
       {
       system("cls");
       printf("Elija la opcion deseada:\n");
       printf("1.-Alta\n");
       printf("2.-Lectura\n");
       scanf("%i",&i);
       switch (i)
       {
             case 1:
                  ALTA();
             break;
             case 2:
                  LECTURA();
             break;
             default:
                     i=0;
             break;
             }
       }
       while (i==0);
      getch();
      return 0;
}
