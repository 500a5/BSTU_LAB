#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "poisk.h"
#include "tabbl.h"

int lin_poisk(table *T, int key)

{ int i,kol=0;

for(i=0;i<T->uk;i++)

{ kol++;

if(T->buf[i].data==key)

{// printf("%i",kol);

return T->buf[i].key;

}

}

//printf("%i",kol);

return -1;

}

int b_lin_poisk(table *t, int n, int key)

{ int i=0,kol=0;

t->buf[n].data=key;

while(t->buf[i].data!=key)

{ i++;

kol++;

}

if (i<n)

{ printf("%i",kol);

return t->buf[i].key;

}

else

{ printf("%i",kol);

return -1;

}

}

int bin_poisk(table *t, int n, int key)

{ int i,j,k,kol=0;

i=n-1;

j=0;

k=(i+j)/2;

while(i>=j)

{ kol+=2;

if(t->buf[k].data==key)

{ printf("%i",kol);

return t->buf[k].key;

}

else

if (t->buf[k].data>key)

i=k-1;

else

j=k+1;

k=(i+j)/2;

}

printf("%i",kol);

return -1;

}

int blok_poisk(table *t, int n, int key)

{ int k,j,i,kol=0;

k=sqrt(n)-1;

j=0;

while(j<n)

{ kol++;

if ( j+k<n && t->buf[j+k].data==key)

return t->buf[j+k].key;

else

if(j+k<n && t->buf[j+k].data>key)

{for(i=j;i<j+k;i++)

{ kol++;

if(t->buf[i].data==key)

{ printf("%i",kol);

return t->buf[i].key;

}

}

printf("%i",kol);

return -1;

}

else

{ j=j+k+1;

if(j+k>=n)

k=n-j-1;

}

}

printf("%i",kol);

return -1;

}
