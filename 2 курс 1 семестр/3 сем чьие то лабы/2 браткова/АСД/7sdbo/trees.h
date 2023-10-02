#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

const int treeOk = 0;
const int treeEmpty = 1;
const int treeNoMem = 2;
const int treeEnd = 3;
extern int treeError;

typedef struct node
{
    char *word; // ��������� �� �����
    int countt; // ����� ���������
    struct node* L_son; // ����� ���
    struct node* R_son; // ������ ���
} node;

typedef struct node tree;

tree* InitTree (tree *T); //������������� ������
tree* CreateRoot(tree *T); // �������� �����
tree* PutTree (tree *T, char *w); //��������� ��������
tree* GetTree(tree *T, char *w); //���������� ��������
void OutputTree(tree *t); // ����� ������ � ������ �������
tree* DeleteTree(tree *t); //�������� ������
int isL_son(tree *t); //���� �� ����� ���
int isR_son(tree *t); //���� �� ������ ���
int isEmpty(tree *t) //������ ������/�� ������

#endif // TREES_H_INCLUDED
