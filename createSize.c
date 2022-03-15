#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int size=10;
	
	FILE *f;
	f = fopen("Size.bin", "w");
	if (f == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
	fwrite(&size,sizeof(int),1,f);
    
	 
        fclose(f);
	return (0);
}
