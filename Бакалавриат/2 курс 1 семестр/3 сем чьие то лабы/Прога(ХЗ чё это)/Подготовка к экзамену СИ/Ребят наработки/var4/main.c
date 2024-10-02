#include <stdio.h>
#include <stdlib.h>

#define STRLEN 50

typedef struct {
    float x;
    float y;
    float z;
} vektor;

void solution(char *,vektor);

//1 - если орт
//0 - если  не орт
int isOrt(vektor, vektor);


int main()
{
    char filename[STRLEN];
    gets(filename);

    printf("Enter vektor A: ");
    vektor a;
    scanf("%f%f%f",&a.x,&a.y,&a.z);

    solution(filename, a);

    return 0;
}

void solution(char *namef, vektor a){
    FILE *readF = fopen(namef,"r");
    FILE *writeF = fopen("tmp.txt","w");//временный файл

    vektor b;

    while(fscanf(readF,"%f%f%f",&b.x,&b.y,&b.z) > 0){
        if(!isOrt(a,b))
            fprintf(writeF,"%f %f %f\n",b.x,b.y,b.z);
    }



    fclose(readF);
    remove(namef);

    fclose(writeF);
    rename("tmp.txt",namef);

}

//1 - если орт
//0 - если  не орт
int isOrt(vektor a, vektor b){
    return  !((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
