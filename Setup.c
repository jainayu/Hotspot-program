#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
#include <conio.h>
#include <string.h>
int main()
{
   char ssid[1000],paswd[100];
   FILE *fptr;

   fptr = fopen("login credentials.txt", "w+");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Enter a SSId: ");
   gets(ssid);
   printf("\n(Password must be atleast 8 characters long)\n");
   printf("Enter a Password: ");
   gets(paswd);
   if(strlen(paswd)<8)
   {
       printf("PASSWORD STRENGTH POOR.\nPLEASE TRY AGAIN");
       getch();
       system("cls");
       main();
       return 0;
   }

   fprintf(fptr,"%s%s",ssid,paswd);
   printf("THANK YOU\nSSid And Password Saved.\n|| Press any key to exit ||");
   getch();

   fclose(fptr);
    system("cls");


   return 0;
}

