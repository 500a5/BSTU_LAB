#ifndef TREEBOL_H_INCLUDED
#define TREEBOL_H_INCLUDED

const int treeOk = 0;
const int treeEmpty = 1;
const int treeNoMem = 2;
const int treeEnd = 3;
static int treeError;

typedef struct node
{
    char *word; // указатель на слово
    int countt; // число вхождений
    struct node* L_son; // левый сын
    struct node* R_son; // правый сын
};

typedef struct node tree;
tree* InitTree (tree *T); //инициализаци€ дерева
tree* CreateRoot(tree *T); // создание корн€
tree* PutTree (tree *T, char *w); //включение элемента
tree* GetTree(tree *T, char *w); //исключение элемента
void OutputTree(tree *t); // вывод дерева в пр€мом пор€дке
tree* DeleteTree(tree *t); //удаление дерева
int isL_son(tree *t); //есть ли левый сын
int isR_son(tree *t); //есть ли правый сын
int isEmpty(tree *t) //дерево пустое/не пустое

#endif // TREEBOL_H_INCLUDED
