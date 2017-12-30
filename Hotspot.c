#include <stdio.h>
#include <stdlib.h>              /* For exit() function */
#include <conio.h>
#include <string.h>
void start();
void stop();
void login();
int compare();
char ssid[1000],paswd[100];
char command[100]="netsh wlan set hostednetwork mode=allow ssid=";
int main()
{
   int i;
   printf("\n\t\tHELLO\n\n");
   printf("|Press 1| To Start Hotspot\n|Press 2| To Stop Hotspot\n|Press 3| To Restart Hotspot\n|Press 4| To Exit\n");
   printf("\nEnter Your Choice: ");
   scanf("%d",&i);
   switch(i)
    {
    case 1:
        login();
        start();
        break;
    case 2:
        stop();
        break;
    case 3:
        stop();
        login();
        start();
        break;
    case 4:
        break;
    default:
        printf("CHOICE INVAILID\nPLEASE TRY AGAIN\nPRESS ANY KEY TO CONTINUE");
        getch();
        system("cls");
        main();
        return 0;
    }

   return 0;
}

void start()
{  int i;
    i=compare();
    if(i==1)
    {
        system(strcat(strcat(strcat(command,ssid)," key="),paswd));
        system("netsh wlan start hostednetwork");
        printf("\nPlease do not forget your Ssid and Password.\n THANKYOU. ");
   }
    else
    printf("Wrong SSId or Password.");

    printf("\n||PRESS ANY KEY TO CONTINUE||");
    getch();

}


void stop()
{   system("cls");
    printf("\n");
    system("netsh wlan stop hostednetwork");
    printf("THANKYOU");

    printf("\n||PRESS ANY KEY TO CONTINUE||");
    getch();
}

void login()
{  char a[10];
   FILE *fptr3;

   fptr3 = fopen("users login credentials.txt", "w");
   if(fptr3 == NULL)
   {
      printf("Error!");
      exit(1);
   }
    gets(a);                     /*done just because code was not running properly.*/

    printf("\nEnter a SSId: ");
    gets(ssid);

    printf("Enter a Password: ");
    gets(paswd);



   fprintf(fptr3,"%s%s",ssid,paswd);

   fclose(fptr3);
    system("cls");
}

int compare()
{
   FILE *fp1, *fp2;
   int ch1, ch2;

   fp1 = fopen("users login credentials.txt", "r");
   fp2 = fopen("login credentials.txt", "r");

   if (fp1 == NULL)
    {
      printf("Cannot open user login credentials.txt for reading" );
      exit(1);
   }
   else if (fp2 == NULL)
   {
      printf("Cannot open login credentials.txt for reading ");
      exit(1);
   }
   else
   {
      ch1 = getc(fp1);
      ch2 = getc(fp2);

      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
        {
         ch1 = getc(fp1);
         ch2 = getc(fp2);
        }

      if (ch1 == ch2)
     {
        fclose(fp1);
        fclose(fp2);
        return 1;
     }
      else if (ch1 != ch2)
            {
                fclose(fp1);
                fclose(fp2);
                return 0;
            }


    }

}

