#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
static int round=1;
void converter(char *cn);
void uppdeck();
void lowsd();
void gotoxy(int x,int y);
void abox();
void deck1();
void deck2();
void hanging();
int main ()
{
    system("color 4f");
    about();
    printf("\n\n\n\n\n\n\n");
    deck1();
    printf("\n");
    int ch1;
      printf(" %c*****************************************%c\n",186,186);
      printf(" %c        %cWELCOME TO%c                     %c\n",186,175,174,186);
      printf(" %c                %cHANGMAN%c                %c\n",186,175,174,186);
      printf(" %c                     %cGAME%c              %c\n",186,175,174,186);
      printf(" %c*****************************************%c\n",186,186);
       deck2();
       printf("\n");
      printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
      printf("             %c  |/   |    %c\n",186,186);
      printf("             %c  |    X    %c\n",186,186);
      printf("             %c  |   \\|/   %c\n",186,186);
      printf("             %c  |    |    %c \n",186,186);
      printf("             %c  |   / \\   %c \n",186,186);
      printf("             %c__|_________%c\n\n",186,186);

      printf("             %cInstructions:\n",175);
      printf("  %cYou have to guess a word entering letter.\n",175);
      printf("%cIn 'HARD' mode you will get less chances than \n              'EASY' mode.\n",175);
      printf("%cWORD challenge is a special feauture where a  \n",175);
      printf("random word will be picked outside of category!\n");
      printf("%cFor every right guessing you will get 5 points.\n",175);
       printf("\n");
      printf("               (X)Start Game\n");
      printf("               (Y)EXIT\n");
          char ch;

      printf("          Press 'X' or 'Y' :");
        repeat2:
                            scanf(" %c",&ch);
                    converter(&ch);
      if(ch=='x')
    {
   repeat :
            printf("\n");
      printf("                Game Mode:\n");
      printf("                 (1)HARD\n");
      printf("                 (2)EASY\n");
      printf("              (ANY KEY TO EXIT)\n");
      printf("             Press '1' or '2' : ");

                           scanf(" %d",&ch);

                           if(ch!=1 && ch!=2){
                                 printf("\n");
     printf("           EXITING...........!\n");
                       exit(1);
                           }
                                            printf("\n");
    printf("          Select Word Category:\n");
    int ch2;
    printf("              (1)Animal\n");
    printf("              (2)Fruits & Flower\n");
    printf("              (3)Foods\n");
    printf("              (4)Sports\n");
    printf("              (5)'Word Challenge'\n");
    printf("       (ANY KEY without(1-5) TO EXIT)\n");
    printf("              Enter Command:");
    scanf("%d",&ch2);
      char *fname[100];        //declaring string pointer as it works as variable
        if(ch2==1){
            *fname="animal.txt";      //83-96 assing file name as string
        }
        else if(ch2==2){
            *fname="f&f.txt";
        }                               //string will be asigned according to command of  81th line
        else if(ch2==3){
            *fname="Foods.txt";
                     }
        else if(ch2==5){
            *fname="challange.txt";
        }
        else if(ch2==4){
            *fname="sports.txt";
        }
        else {
              printf("\n");
     printf("           EXITING...........!\n");
                       exit(1);
        }
       FILE *file;                      //opening file
       file=fopen(*fname,"r");      //string pointer as name of the file to open
        char string[500][500];
    int k=0,k1=0;
    int k2=130;
    while(fgets(string[k],k2,file)){
         string[k][strlen(string[k])-1]='\0';   //storing words in a string line by line from file
         k++;    //lenghth of the word
        }
        k1=k-1;
        int v;
        srand(time(0));
        int x=rand()%k1;   //(main logic) the random word indicates the position of the srtring
        char string2[100];
        strcpy(string2,string[x]);   //random number generated,works as the location of string
        v=strlen(string2);
          char b[50],alpha;
               char d='_';


        fclose(file);       //file closed
        int xy,t,i2,t1=0;
        static int score=0;
                   if(ch==1){      //Mode selection
                    xy=(v+v)-1;
                   }
                   else if(ch==2){    //hard and easy mode
                    xy=v+v;
                   }
                   printf("                                             ROUND %d\n",round);
        printf("      You got %d Chances to guess the word\n",xy);

     printf("\t\t");
     int i;
         for(i=0;i<v;i++)
	  {
	  printf("%c ",d);
	  b[i]=d;               //taking the number of dashes according to length of the word
	  }
          printf("\n");
          char ch4;
            int p=0;
          int p1=0;
             int x1;
             for(i=0;i<=xy;i++){                //starting the main  loop
                     if(p!=v && i==xy){
        printf("\n            Game over...!\n");
        hanging();
        printf("           THE WORD IS '%s'\n",string2);   //game over part
        printf("       (X)READY FOR SECOND ROUND:\n");
        printf("          (ANY KEY TO EXIT)\n");
        char g;
        repeat4:
         scanf(" %c",&g);
            converter(&g);
        if(g=='x'){
            char b[50];
            round++;
            goto repeat;
            }
            else{
        printf("           EXITING...........!\n");
        exit(1);
            }
        }
        if((xy-i)>9){
        uppdeck();
        printf("            %c%d CHANCES LEFT %c\n",186,xy-i,186);
        lowsd();
        }
          else if((xy-i)<=9)
              {
                uppdeck();
                printf("            %c %d CHANCES LEFT %c\n",186,xy-i,186);
                lowsd();
              }
        printf("                                                SCORE: %d\n",score);
                    if(p==v){            //winning case
        printf("\n            You Won...!\n");
        printf("         THE WORD IS '%s'\n",string2);
        printf("    (X)READY FOR SECOND ROUND:\n");
        printf("         (ANY KEY TO EXIT)\n");
        char g;
            scanf(" %c",&g);
            converter(&g);
                if(g=='x'){
                char b[50];
                round++;
                goto repeat;       //jumping to repeat
                    }
        else{
        printf("           EXITING...........!\n");
                    exit(1);
                }
            }
        if(p1==0 && i!=0){
            printf("             Try Again...! \n");         //try again
        }
             p1=0;
            printf("\nGuess..?:");
          scanf(" %c",&ch4);
           converter(&ch4);           //convertering letter to lowercase(protection)
           int i;
           t1=0;
      for(i=0;i<v;i++){           //main loop 2 (matching wuth the string chracter by charcter
        if(string2[i]==ch4){
              b[i]=string2[i];     //correct letter goes to string and replaces dashes
               score+=5;
           p++;
           p1=1;           //counting win
             x1=i;
             for(i=0;i<v;i++)
             if(i==0){
                printf("               %c ",b[i]);
             }
             else
                printf("%c ",b[i]);

          }
        }
      }                         //ending loop
     }
      else if (ch=='y'){
      printf("    Thank You for playing the Game!\n");
        printf("           EXITING...........!\n");
        exit(1);

      }
      else if(ch!='y' && ch!='x')
      {
          printf("ENTER CORRECT COMMAND...!!\n");    //error enters
          goto repeat2;
      }

      return 0;
}


void converter (char *ch)
{
      if(isupper(*ch)){
        *ch=tolower(*ch);
      }

}

void uppdeck()
{

  for(int i=0;i<=17;i++){
    if(i==0){
        printf("\n            %c",201);
    }
    else if(i==17){
        printf("%c\n",187);
    }
    else{
        printf("%c",205);
    }
  }

}
void lowsd()
{


     for(int i=0;i<=17;i++){
    if(i==0){
        printf("            %c",200);
    }
    else if(i==17){
        printf("%c\n",188);
    }
    else{
        printf("%c",205);
    }
  }

}
    void gotoxy(int x,int y)
{
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

   void abox()
{
    int i;
    gotoxy(10,3);
    printf("%c",201);
    gotoxy(11,3);
    for(i=1; i<100; i++)
        printf("%c",205);
    gotoxy(10,24);
    for(i=1; i<=100; i++)
        printf("%c",205);


    gotoxy(110,3);
    printf("%c",187);

    for(i=0; i<=20; i++)
    {
        gotoxy(10,4+i);
        if(i==20){
           printf("%c",200);
        }
        else
        printf("%c",186);
    }

    for(i=0; i<=20; i++)
    {
        gotoxy(110,4+i);
        if(i==20){
            printf("%c",188);
        }
        else
        printf("%c",186);
    }
}
void about()
{
       abox();
    gotoxy(45,4);
    printf("     THE HANGMAN GAME");
    gotoxy(45,5);
    printf("This Project Is Created BY");

    gotoxy(15,8);
    printf("Navid Zaman");
    gotoxy(15,9);
    printf("ID: 2020-2-60-044");
    gotoxy(15,10);
    printf("B.Sc in Computer Science & Engineering");

    gotoxy(15,11);
    printf("East West University");
    gotoxy(15,12);
    printf("Email   : 2020-2-60-044@std.ewubd.edu");


    gotoxy(60,8);
    printf("Nadia Sultana Pattowary");
    gotoxy(60,9);
    printf("ID: 2020-2-60-024");
    gotoxy(60,10);
    printf("B.Sc in Computer Science & Engineering");

    gotoxy(60,11);
    printf("East West University");
    gotoxy(60,12);
    printf("Email   : 2020-2-60-024@std.ewubd.edu");

    gotoxy(15,15);
    printf("Farhana Moni");
    gotoxy(15,16);
    printf("ID: 2020-2-60-036");
    gotoxy(15,17);
    printf("B.Sc in Computer Science & Engineering");

    gotoxy(15,18);
    printf("East West University");
    gotoxy(15,19);
    printf("Email   : 2020-2-60-036@std.ewubd.edu");
    gotoxy(40,22);

    printf("Press Any Key to Continue......");
    getch();
    return 0;
}
void deck1()
{
    for(int i=0;i<43;i++){
            if(i==0){
                 printf(" %c",201);
            }
            else if(i==43-1){
                printf("%c",187);
            }
            else
        printf("%c",205);
    }
}
void deck2()
{
    for(int i=0;i<43;i++){
            if(i==0){
                 printf(" %c",200);
            }
            else if(i==43-1){
                printf("%c",188);
            }
            else
        printf("%c",205);
    }
}


void hanging()
{



     printf("       YOU HAVE BEEN HANGED\n");
    printf("               _______\n");
      printf("             |/   | \n");
      printf("             |    X \n");
      printf("             |   \\|/\n");
      printf("             |    | \n");
      printf("             |   / \\\n");
      printf("           __|_________\n\n");
}
