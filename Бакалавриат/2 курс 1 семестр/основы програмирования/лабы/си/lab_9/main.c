#include <stdio.h>

struct point{
    int x;
    int y;
};

void input(struct point *p){
        scanf("%d%d",&p->x,&p->y);

}

void chak(struct point p,struct point q) {
    if((p.x+p.y)%2==(q.x+q.y)%2){
        printf("„€");
    } else{ printf("…’");
    }
}


int main() {
    struct point p,q;
    input(&p);
    input(&q);
    chak(p,q);
    return 0;
}