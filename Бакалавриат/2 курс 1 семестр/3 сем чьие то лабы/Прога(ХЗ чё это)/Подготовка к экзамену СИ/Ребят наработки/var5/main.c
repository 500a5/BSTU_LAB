#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct{
    char x;
    int y;
} fig;

void input_fig(fig*,int);
int ladya_in_point(fig*,fig,fig,int);
int find_fig_in_line(fig*,fig,int);

int equalFigX(fig,fig);
int equalFigY(fig,fig);


int main()
{
    fig a[N];
    input_fig(a,N);
    fig point;
    fig ladya;
    printf("Input x and y about point");
    scanf("%c%d",&point.x, &point.y);
    printf("Input x and y about ladya");
    scanf("%c%d",&ladya.x, &ladya.y);



    return 0;

}

void input_fig(fig*a,int n){
    int i;
    for (i = 0; i < n; i++){
        printf("Input x and y %d figur",i+1);
        scanf("%c",&a[i].x);
        scanf("%d",&a[i].y);
        }
}

int ladya_in_point(fig* a,fig ladya,fig point,int n){
    if(point.x == ladya.x){
        return find_fig_in_line(a,ladya,&equalFigX);
    } else if(point.y == ladya.y){
        return find_fig_in_line(a,ladya,&equalFigY);
    }
    return 0;
}

//1 если X фигур равны
int equalFigX(fig a1,fig a2){
    if(a1.x == a2.x)
        return 1;
}

//1 если Y фигур равны
int equalFigY(fig a1,fig a2){
    if(a1.y == a2.y)
        return 1;
}

int find_fig_in_line(fig* a,fig ladya,int (*equalFig)(fig,fig)){
    int i = 0;
    while(i < N){
        if(equalFig(a[i],ladya))
            return 0;
        i++;
    }
    return 1;
}





