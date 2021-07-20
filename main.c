#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Texte[1000],Chifr[1000],motPS[20],Mat[26][26],OUT[1000],LETRE,R;
int i,j,k,LONG,posi,posj,choix;
FILE *in;
FILE *out;
void Matrice()
{
k=65;
for (i=0;i<26;i++){
    LETRE=k;
   for(j=0;j<26;j++){
       Mat[i][j]=LETRE;
       if(LETRE==90)
       LETRE=65;
       else
       LETRE++;
   }
   k++;}
}
void Tapez_txt_original()
{
printf("\n\t\t\tTapez le texte que vous souhaitez chiffrer:\n");
fflush(stdin);
gets(Texte);
in = fopen("in.txt","w");
if (!in) printf("Probleme d'ouverture\n");
else fprintf(in,"%s",Texte);
fclose(in);
}
void Tapez_txt_crypte()
{
printf("\n\t\t\tTapez le texte chiffre:\n");
fflush(stdin);
gets(Texte);
in = fopen("in.txt","w");
if (!in) printf("Probleme d'ouverture\n");
else fprintf(in,"%s",Texte);
fclose(in);
}



void Cryptage()
{
Matrice();
printf("\n\n\n\t\t\tEntrez un mot de passe pour chiffrer le texte\n\n\n \t\t\t===>");
fflush(stdin);
gets(motPS);

FILE*filleMP;
filleMP= fopen("mote de passe.txt","w");
if (!filleMP) printf("Probleme d'ouverture\n");
else
fprintf(filleMP,"%s",motPS);
fclose(filleMP);

LONG=strlen(motPS);

in = fopen("in.txt", "r");
  if (!in)printf("Probleme d'ouverture\n");
   else {
       j=0;i=0;
  while (!feof(in)){
    R=fgetc(in);
    Texte[i]=R;
    if((R>=65&&R<=90) || (R>=97 && R<=122)){
    Chifr[i]= motPS[j];
    if(j==LONG-1)
    j=0;
    else
    j++;
    }
    else
    Chifr[i]=R;
    i++;
     }
   }
  fclose(in);

i=0;
do{
    if (Texte[i]>=65 && Texte[i]<=90 && Chifr[i]>=65 && Chifr[i]<=90){
    posi=Texte[i]-65;
    posj=Chifr[i]-65;
    OUT[i]=Mat[posi][posj];}
    else if (Texte[i]>=65 && Texte[i]<=90 && Chifr[i]>=97 && Chifr[i]<=122){
    posi=Texte[i]-65;
    posj=Chifr[i]-97;
    OUT[i]=Mat[posi][posj];}
    else if (Texte[i]>=97 && Texte[i]<=122 && Chifr[i]>=65&& Chifr[i]<=90){
    posi=Texte[i]-97;
    posj=Chifr[i]-65;
    OUT[i]=Mat[posi][posj]+32;}
    else if (Texte[i]>=97 && Texte[i]<=122 && Chifr[i]>=97 && Chifr[i]<=122){
    posi=Texte[i]-97;
    posj=Chifr[i]-97;
    OUT[i]=Mat[posi][posj]+32;}
    else
    OUT[i]=Texte[i];
    i++;
}while(Texte[i]!=-1);


out = fopen("out.txt","w");
if (!out) printf("Probleme d'ouverture\n");
else
fprintf(out,"%s",OUT);
fclose(out);

printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  Texte CRYPTE  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
printf("%s",OUT);
printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");

}
void Decryptage()
{
Matrice();
printf("\n\n\t\t\tEntrez un mot de passe pour chiffrer le texte!\n\n\n \t\t\t===>");
fflush(stdin);
gets(motPS);
char test[20];

FILE*filleMP;
filleMP= fopen("mote de passe.txt","r");
if (!filleMP) printf("Probleme d'ouverture\n");
else
i=0;
while (!feof(filleMP)){
    test[i]=fgetc(filleMP);
    i++;}
    test[i-1]='\0';
fclose(filleMP);

if(strcmp(motPS,test)!=0){
do{
    system("COLOR C");
printf("\n\n\n\!!!Le mot de passe est incorrect !!! \n\n\t(1)====>reessayer \n\t(2)===>revenir a le Menu \n\t(3)===>Quitter\n\t");
scanf("%d",&choix);
     switch(choix){
        case 1 :system("cls");printf("Entrez le mot correct ====> ");fflush(stdin);gets(motPS);break;
        case 2 : choix=3;system("cls");break;
        case 3 : quitter();exit(-1);break;
        default :system("cls");printf("\n\nvotre choix n'est pas valide !!!\n");
        }
        if(strcmp(motPS,test)==0)choix=3;
      }while(choix!=3);
   }
   system("COLOR A");
if(strcmp(motPS,test)==0){
LONG=strlen(motPS);

in = fopen("in.txt", "r");
  if (!in)printf("Probleme d'ouverture\n");
   else {
       j=0;i=0;
  while (!feof(in)){
    R=fgetc(in);
    Texte[i]=R;
    if((R>=65&&R<=90) || (R>=97 && R<=122)){
    Chifr[i]= motPS[j];
    if(j==LONG-1)
    j=0;
    else
    j++;
    }
    else
    Chifr[i]=R;
    i++;
     }
   }
  fclose(in);


i=0;
do{
    if (Texte[i]>=65 && Texte[i]<=90 && Chifr[i]>=65 && Chifr[i]<=90){
    posi=Chifr[i]-65;
    for(j=0;j<26;j++)
    if(Mat[posi][j]==Texte[i])
    posj=j;
    OUT[i]=Mat[0][posj];}
    else if (Texte[i]>=65 && Texte[i]<=90 && Chifr[i]>=97 && Chifr[i]<=122){
    posi=Chifr[i]-97;
    for(j=0;j<26;j++)
    if(Mat[posi][j]==Texte[i])
    posj=j;
    OUT[i]=Mat[0][posj];}
    else if (Texte[i]>=97 && Texte[i]<=122 && Chifr[i]>=65&& Chifr[i]<=90){
    posi=Chifr[i]-65;
    for(j=0;j<26;j++)
    if(Mat[posi][j]==Texte[i]-32)
    posj=j;
    OUT[i]=Mat[0][posj]+32;}
    else if (Texte[i]>=97 && Texte[i]<=122 && Chifr[i]>=97 && Chifr[i]<=122){
    posi=Chifr[i]-97;
    for(j=0;j<26;j++)
    if(Mat[posi][j]==Texte[i]-32)
    posj=j;
    OUT[i]=Mat[0][posj]+32;}
    else
    OUT[i]=Texte[i];
    i++;
}while(Texte[i]!=-1);


out = fopen("out.txt","w");
if (!out) printf("Probleme d'ouverture\n");
else
fprintf(out,"%s",OUT);
fclose(out);
printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  Texte ORIGINAL °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
printf("%s",OUT);
printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
 }
}

void quitter(){
 system("cls");
 printf("\n\n        \t------------FIN-----------\n\n\n");
 printf("\n\n        \t------------MERCI---------\n\n\n");
 }

int main()
{
    system("COLOR A");
int choix;
           printf("\n");
           printf("\t\t\t °°                                °°                               \n");
           printf("\t\t\t °°                                                          °°     \n");
           printf("\t\t\t °°                                °°                        °°°°°° \n");
           printf("\t\t\t °°°°°°°   °°°°°°°   °°°°°°°       °°   °°°°°°°   °°   °°    °°   ° \n");
           printf("\t\t\t °°   °°   °°   °°   °°   °°       °°   °°   °°   °°   °°    °°     \n");
           printf("\t\t\t °°   °°   °°   °°   °°   °°   °°  °°   °°   °°   °°   °°    °°     \n");
           printf("\t\t\t °°°°°°°   °°°°°°°   °°   °°   °°  °°   °°°°°°°   °°°°°°°    °°     \n");
           printf("\t\t\t                               °°°°°°                           \n\n\n");

do{
           printf("\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
           printf("\t\t\t° D-CRYPTAGE-CRYPTAGE-CRYPTAGE°{MENU}°CRYPTAGE-CRYPTAGE-CRYPTAGE-D °\n");
           printf("\t\t\t° y °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Y °\n");
           printf("\t\t\t° C °                                                          ° C °\n");
           printf("\t\t\t° R °              [1] ===> operation de cryptage              ° R °\n");
           printf("\t\t\t° Y °                                                          ° Y °\n");
           printf("\t\t\t° P °             [2] ===> operation de decryptage             ° P °\n");
           printf("\t\t\t° T °                                                          ° T °\n");
           printf("\t\t\t° A °                    [3] ===> quitter                      ° A °\n");
           printf("\t\t\t° G °                                                          ° G °\n");
           printf("\t\t\t° E °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° E °\n");
           printf("\t\t\t° DYCRYPTAGE-DYCRYPTAGE-DYCRYPTAGE-DYCRYPTAGE-DYCRYPTAGE-DYCRYPTAG °\n");
           printf("\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");

           printf("\n\t\t\t                        Entre votre choix : ");
  scanf("%d",&choix);
  printf("\n\n");
  switch(choix){
case 1:system("cls");Tapez_txt_original();Cryptage();break;
case 2:system("cls");Tapez_txt_crypte();Decryptage();break;
case 3:quitter();exit(-1);break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
}
}while(choix!=3);

    return 0;
}
