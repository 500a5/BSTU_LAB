#ifndef TI_CODING_H
#define TI_CODING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
typedef struct {
    string name;
    double prob;
}probab;
typedef vector<probab> t_probabilitys;

typedef struct {
    string name;
    string code;
    double prob;
} code;
typedef vector<code> codeBase;

typedef struct node {
    string name;
    double prob;
    struct node* left;
    struct node* right;
}node;
typedef vector<node*> nodes;
void inputProbability(t_probabilitys& probabilitys);

codeBase getShenonFano(t_probabilitys, int);
codeBase getHafman(t_probabilitys, int);
string   coding(codeBase baseCode, string message, int block);
string   deCoding(codeBase baseCode, string code, int dopis);
void printCodeBase(codeBase baseCode, int block);

#endif //TI_CODING_H
