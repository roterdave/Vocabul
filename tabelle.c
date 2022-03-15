#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WORTLAENGE 20

typedef struct {
	
	int		ID_Nummer;
	char	Wort_Sprache_1[20];
	char	Wort_Sprache_2[20];
	char	Sprache_1[20];
	char	Sprache_2[20];
	char    Lehrmittel[20];
	char	Lektion[20];
	char	Autor[20];
	int		Tag;
	int		Monat;
	int		Jahr;
} WORT;

//Funktion zur Reservierung des Speicherplatzes der Liste
 WORT* speicherWort(int size[0]){
	int i,j;

		
	WORT* woerterListe = (WORT*) malloc(size[0]*sizeof(WORT));
	if (woerterListe==NULL){
		printf("Fehler bei der Speicherreservierung!");
		exit(1);}
		
		
		//Initialisierung der Liste mit 0
		for (i=0;i<size[0];i++){
			woerterListe[i].ID_Nummer=0;
			for (j=0;j<20;j++){
			woerterListe[i].Wort_Sprache_1[j]='\0';
			woerterListe[i].Wort_Sprache_2[j]= '\0';
			woerterListe[i].Sprache_1[j]= '\0';
			woerterListe[i].Sprache_2[j]= '\0';
			woerterListe[i].Lehrmittel[j]= '\0';
			woerterListe[i].Lektion[j]= '\0';
			woerterListe[i].Autor[j]= '\0';
			}
			woerterListe[i].Tag=0;
			woerterListe[i].Monat=0;
			woerterListe[i].Jahr=0;
			
		}//for
		return woerterListe;
}//speicherWort

WORT* reallocWordlist(int size[0], WORT* woerterListe){
		int i,j;
		WORT* temp=NULL;
		temp=(WORT*) realloc(woerterListe,(size[0]+5)*sizeof(WORT));
		if (woerterListe==NULL){
			free(temp);
			printf("Fehler bei der Speicherreservierung!");
			exit(1);
		}
		//Initialisierung der Liste mit 0
		for (i=size[0]-1;i<size[0]+5;i++){
			woerterListe[i].ID_Nummer=0;
			for (j=0;j<20;j++){
			woerterListe[i].Wort_Sprache_1[j]='\0';
			woerterListe[i].Wort_Sprache_2[j]= '\0';
			woerterListe[i].Sprache_1[j]= '\0';
			woerterListe[i].Sprache_2[j]= '\0';
			woerterListe[i].Lehrmittel[j]= '\0';
			woerterListe[i].Lektion[j]= '\0';
			woerterListe[i].Autor[j]= '\0';
			}
			woerterListe[i].Tag=0;
			woerterListe[i].Monat=0;
			woerterListe[i].Jahr=0;
		}
		//printf("  Wort 1 	Wort 2\n");
		//for (i=0;i<size[1];i++){
		//printf("  %s        %s \n", (temp +i) -> Wort_Sprache_1, temp[i].Wort_Sprache_2);
		//}//for
		woerterListe=temp;
		printf("  Wort 1 	Wort 2\n");
		for (i=0;i<size[1];i++){
		printf("  %s        %s \n", (woerterListe +i) -> Wort_Sprache_1, woerterListe[i].Wort_Sprache_2);
		}//for
		
		//woerterListe=temp;
		
		return woerterListe;
}

int* woerterEingabe(int* size, WORT* woerterListe, WORT** ptr){
	int i;
	int entrySize;
	printf("Wieviele Wörter möchten Sie eingeben?\n");
	scanf(" %d", &entrySize);
	
	size[1] = size[1]+entrySize;
	
	//Test ob es genug Speicherplatz hat
	if(size[1]>=size[0]){*ptr=reallocWordlist(size, woerterListe); size[0]=size[0]+5;}
	woerterListe=*ptr;

	for (i=size[1]-entrySize;i<size[1];i++){
		printf("Geben Sie das erste Wort ein \n");
		scanf(" %s", woerterListe[i].Wort_Sprache_1);
		printf("Geben Sie das zweite Wort ein \n");
		scanf(" %s", woerterListe[i].Wort_Sprache_2);
		woerterListe[i].ID_Nummer=100000+i;
	}//for
	return size;
}//woerterEingabe

void woerterAusgabe(int size[1], WORT* woerterListe){
	int i; 
	
		printf(" %d, %d \n", size[0], size[1]);	
		printf("  ID Nummer Wort 1 	Wort 2\n");
		for (i=0;i<size[1];i++){
		printf("  %d         %s        %s \n", woerterListe[i].ID_Nummer,(woerterListe +i) -> Wort_Sprache_1, woerterListe[i].Wort_Sprache_2);
		}//for
			
		
		
		
	
	
}//woerterAusgabe

void saveWordlist(int size[0], WORT* woerterListe) {
	int i;
	
	FILE *f;
	f = fopen("Wordlist.txt", "w");
	if (f == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
	
    for (i=0;i<size[0];i++){
		fwrite (&woerterListe[i], sizeof(WORT), 1, f);
	 }
	 
        fclose(f);
	
}
void openWordlist( int* size , WORT* woerterListe){
	
	int i;
	
	FILE *f;
	f = fopen("Wordlist.txt", "r");
	if (f== NULL)
	{
		fprintf(stderr, "\n Error opening file\n");
		exit (1);
	}
		
		for(i=0;i<size[0];i++)
		fread(&woerterListe[i], sizeof(WORT),1,f);
		
		fclose(f);
		
		for(i=0;i<size[1];i++)
		printf("%s %s \n", woerterListe[i].Wort_Sprache_1, woerterListe[i].Wort_Sprache_2);
		
	}
	
	void saveSize(int* size) {
	
	int i;
	FILE *f;
	f = fopen("Size.bin", "w");
	if (f == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
	}
		for (i=0;i<2;i++){
		fwrite(&size[i],sizeof(int),1,f);
		}
     fclose(f);
	 }

	
	int* getSize(int*size){
		int i;
		FILE *f;
	f = fopen("Size.bin", "r");
	if (f== NULL)
	{
		fprintf(stderr, "\n Error opening file\n");
		exit (1);
	}
		for (i=0;i<2;i++){
		fread(&size[i], sizeof(int),1,f);
		}
		fclose(f);
		
		return size;
	}

int main(void) {
	printf("flag \n");
	static int* size;
	int arr[2]={5,0};
	size = arr;
	
	printf("%d \n", size[1]);
	
	size=getSize(size);
	
	
	
	char menu;
	
	
	printf("size is %d, %d \n", size[0], size[1]);
	
	WORT* woerterListe = speicherWort(size);
	WORT** ptr;
	ptr=&woerterListe;
	
	openWordlist(size,woerterListe);
	
	do{
	
	menu=0;
	
	printf("\nMenu:  Schreiben (a), Anzeigen (b), Speichern (c), Verlassen (e)\n");
	
	
	scanf(" %c", &menu);//ein Space-Abstand nach dem Anführungszeichen, sonst liest scanf das newline des letzten loops
	
	
	switch (menu){
	
		
		case 'a' : size=woerterEingabe(size, woerterListe,ptr); break;
		case 'b' : woerterAusgabe(size, woerterListe); break;
		case 'c' : saveWordlist(size, woerterListe),saveSize(size); break;
		case 'e' : exit(0);
		
		default: printf("Wrong Choice. Enter again\n");
                    break;
	}//switch
	
} while (menu!= 'e');
	
	free(woerterListe);
	
	
	
	
	
	return 0;
	
}
