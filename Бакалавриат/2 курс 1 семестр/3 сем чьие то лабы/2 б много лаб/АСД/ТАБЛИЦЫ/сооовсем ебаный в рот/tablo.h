#define sizee  450

const short TableOk=0;
const short TableEmpty=1;
const short TableFull=2;
const short TableNoKey=3;
static short TableError;

typedef struct
        {
            int key;
            int data;
        } element;

typedef struct
        {
            element buf[sizee+1];
            unsigned uk;
        }table;


table vvod_up_tabl(size_t n);
table vvod_neup_table(size_t n);
void initTable(table *T);
int isFullTAble(table *T);
int isEmptyTable(table *T);
int poisk(table *T, int key);
void putTable(table *T, element e);
void getTable(table *T, element *e, int key);
//void write_table(table *t, int n);
//void read_table(table *t, int n);
