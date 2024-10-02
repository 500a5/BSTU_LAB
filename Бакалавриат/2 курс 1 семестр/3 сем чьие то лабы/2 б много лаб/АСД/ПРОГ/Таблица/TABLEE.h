#ifndef Table_Size
	#define Table_Size 100
#endif

#ifndef base_type
	#define base_type int
#else
	#define base_type_non_include_tabl_as_massif
#endif

#ifndef t_index
	#define t_index long long unsigned int
#endif

const short Table_OK = 0;
const short Table_FULL = -1;
const short Table_EMPTY = -2;
const short NoKey = -2;

extern short Table_Error = 0;

struct elem_tabl{base_type data; t_index key;};
typedef struct elem_tabl elem_tabl;

struct Table_M{elem_tabl mass[Table_Size]; t_index uk;};
typedef struct Table_M Table_M;

void TableInit(Table_M* T);
void TableDone(Table_M* T);

void TablePut(Table_M* T, t_index key, base_type E);
void TableGet(Table_M* T, t_index key, base_type *E);

int TableEmpty(Table_M* T);
int TableFull(Table_M* T);
