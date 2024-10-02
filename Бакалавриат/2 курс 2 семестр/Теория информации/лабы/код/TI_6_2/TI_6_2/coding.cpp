
#include <algorithm>
#include "coding.h"

void inputProbability(t_probabilitys &probabilitys)
{
    bool flag = true;
    probab tmp;
    double sum;
    size_t n;
    while (flag) {
        probabilitys.clear();
        cout << "Введите количество Символов: ";
        cin >> n;
        cout << "Введите " << n << " Символов и вероятностей: " << endl;
        for (size_t i = 0; i < n; ++i) {
            cin >> tmp.name;
            cin >> tmp.prob;
            probabilitys.push_back(tmp);
        }
        sum = 0;
        for(probab i : probabilitys)
            sum += i.prob;
        if((fabs(1 - sum)) < 1e-5)
            flag = false;
        else{
            cout << "Сумма вероятнгостей равна " << sum << " что не равно единице" <<endl;
            cout << "Пожалуйста перепроверьте исходные данные и введите ещё раз" << endl;
        }
    }
}
bool compare(probab p1, probab p2){
    if (p1.prob != p2.prob)
        return p1.prob > p2.prob;
    else
        return p1.name < p2.name;
}
void getShenonFano(codeBase &baseCode, int start, int end){
    if ((end - start) == 2){
        baseCode[start].code += '0';
        baseCode[end - 1].code += '1';
    }else{
        double min = 5.;
        int minIndex = start;
        for (size_t i = start; i < end; ++i) {
            double left = 0;
            double right = 0;
            for (size_t j = start; j < i; ++j)
                left += baseCode[j].prob;
            for (size_t j = i; j < end; ++j)
                right += baseCode[j].prob;
            if (fabs(right - left) < min){
                min = fabs(right - left);
                minIndex = i;
            }
        }
        for (size_t i = start; i < minIndex; ++i)
            baseCode[i].code += '0';
        for (size_t i = minIndex; i < end; ++i)
            baseCode[i].code += '1';
        if ((minIndex - start) != 1)
            getShenonFano(baseCode, start, minIndex);
        if ((end - minIndex) != 1)
            getShenonFano(baseCode, minIndex, end);
    }
}

t_probabilitys getComp(t_probabilitys probabilitys, int block)
{
    t_probabilitys result;
    int count = probabilitys.size();
    for (int i = 1; i < block; ++i)
        count *= probabilitys.size();
    for (int j = 0; j < probabilitys.size(); ++j)
        for (int i = 0; i < count/probabilitys.size(); ++i)
            result.push_back(probabilitys[j]);
    count/=probabilitys.size();
    for (int k = 1; k < block; ++k) {
        count/=probabilitys.size();
        for (int i = 0; i < result.size(); i+=count*probabilitys.size()){

            for (int j = 0; j < probabilitys.size(); ++j) {
                for (int l = i + j*count; l < i + (j+1)*count; ++l) {
                    result[l].name += probabilitys[j].name;
                    result[l].prob *= probabilitys[j].prob;
                }
            }


        }

    }
    double s = 0;
    for (int m = 0; m < result.size(); ++m) {
        s += result[m].prob;
    }
    return result;
}

codeBase getShenonFano(t_probabilitys probabilitys, int block)
{
    if (block < 1){
        cerr << "Размер блока меньше 1" << endl;
        return codeBase();
    }
    if (block > 1)
        probabilitys = getComp(probabilitys, block);
    sort(probabilitys.begin(), probabilitys.end(), compare);
    codeBase baseCode;
    code tmpCode;
    for(probab p: probabilitys){
        tmpCode.name = p.name;
        tmpCode.code = "";
        tmpCode.prob = p.prob;
        baseCode.push_back(tmpCode);
    }
    getShenonFano(baseCode, 0, baseCode.size());
    return baseCode;
}
string coding(codeBase baseCode, string message, int block)
{
    string codeResult = "";
    int dopis = 0;
    for (int i = 0; i < message.size(); i += block){
        string ch = "";
        for (int j = 0; j < block; ++j)
            if ((i+j)<message.size())
                ch += message[i + j];

        if (ch.length() < block) {
            while (ch.size() != block) {
                ch += baseCode[0].name[0];
                dopis++;
            }
        }
        bool flagSearch = false;
        for(code cod:baseCode){
            if(ch == cod.name){
                flagSearch = true;
                codeResult += cod.code;
                break;
            }
        }
        if(!flagSearch)
            cerr << "Для символа " << ch << " нет кода";
    }
    return to_string(dopis) + "||" + codeResult;
}
string   deCoding(codeBase baseCode, string code, int dopis)
{
    string message = "";
    string tmp = "";
    for (int i = 0; i < code.size(); ++i) {
        tmp += code[i];
        for (int j = 0; j < baseCode.size(); ++j) {
            if (tmp == baseCode[j].code){
                message += baseCode[j].name;
                tmp.clear();
                break;
            }
        }
    }
    string lastMessage = "";
    for (int i = 0; i < message.size() - dopis; ++i) {
        lastMessage += message[i];
    }
    return lastMessage;
}
bool compareNode(node *n1, node *n2){
    if(n1->prob != n2->prob)
        return n1->prob > n2->prob;
    else
        return n1->name < n2->name;
}
void getHafman(codeBase &baseCode, node n, string accum){
    if ((n.left == nullptr) && (n.right == nullptr)) {
        for (int i = 0; i < baseCode.size(); ++i)
            if (n.name == baseCode[i].name){
                baseCode[i].code = accum;
                break;
            }
    }else{
        getHafman(baseCode, *n.left, accum + '1');
        getHafman(baseCode, *n.right, accum + '0');
    }
}
codeBase getHafman(t_probabilitys probabilitys, int block)
{
    if (block < 1){
        cerr << "Размер блока меньше 1" << endl;
        return codeBase();
    }
    if (block > 1)
        probabilitys = getComp(probabilitys, block);
    sort(probabilitys.begin(), probabilitys.end(), compare);
    codeBase baseCode;
    code tmpBase;
    node *tmp = new node;
    nodes ns;
    for(probab p:probabilitys){
        tmp = new node;
        tmp->name = p.name;
        tmp->prob = p.prob;
        tmp->left = nullptr;
        tmp->right = nullptr;
        tmpBase.name = p.name;
        tmpBase.prob = p.prob;
        tmpBase.code = "";
        ns.push_back(tmp);
        baseCode.push_back(tmpBase);
    }

    while (ns.size() != 1){
        sort(ns.begin(), ns.end(), compareNode);
        node *n1 = ns.back();
        ns.pop_back();
        node *n2 = ns.back();
        ns.pop_back();
        tmp = new node;
        tmp->name = n1->name + n2->name;
        tmp->prob = n1->prob + n2->prob;
        tmp->left = n1;
        tmp->right = n2;
        ns.push_back(tmp);
    }
    getHafman(baseCode, *ns[0], "");
    return baseCode;
}
double getL(codeBase baseCode){
    double res = 0;
    for (code c:baseCode)
        res += c.prob *(c.code.length());
    return res;
}
double getEntropy(codeBase baseCode)
{
    double rez = 0;
    for (code c : baseCode)
        if(c.prob != 0)
            rez -= c.prob*log2(c.prob);
    return rez;
}
void printCodeBase(codeBase baseCode, int block)
{
    cout << "Результат кодирования:" << endl;
    for (code c:baseCode)
        cout << c.name + " " + c.code + " P=" << c.prob <<endl;
    cout << "Энтропия = " << getEntropy(baseCode)/block << endl;
    cout << "Средняя длинна = " << getL(baseCode)/block << endl;

}