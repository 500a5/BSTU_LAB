#ifndef CYCLIC_CODING_H_INCLUDED
#define CYCLIC_CODING_H_INCLUDED

#include <vector>
#include <random>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iterator>

void dellNull(std::vector<int>& x1);
std::vector<int> operator * (const std::vector<int>& x1, const std::vector<int>& x2);
std::vector<int> operator + (const std::vector<int>& x1, const std::vector<int>& x2);
std::vector<int> operator % (const std::vector<int>& x1, const std::vector<int>& x2);
bool operator == (const std::vector<int>& x1, const std::vector<int>& x2);
std::ostream& operator << (std::ostream& stream, const std::vector<int>& x);

class CyclicCode {
    public:
        CyclicCode (int r = 4, int t = 2) : r_(r), n_((1 << r_) - 1), k_(n_ - r_), E_(std::vector<std::vector<int>>(n_ + 1)), g_(r_ * 2 + 1), t_(t) {
            srand(time(nullptr));
            setlocale(LC_ALL, "Rus");
        };
        void output_GF();
        std::vector<int> coding(const std::vector<int>& info);
        virtual std::vector<int> decoding(std::vector<int>& code);
        std::vector<int> generate_info();
        std::vector<int> read_info();
        void output_vector(const std::vector<int>& x);
        void putMistake(std::vector<int>& code);
        std::vector<int> computeE(const std::vector<int>& s);
        void output_E(const std::vector<int>& x);
    protected:
        int r_, n_, k_, t_;
        std::vector<std::vector<int>> E_;
        std::vector<int> g_;
        void compute_GF();
        void output_bound();
        int random(int low, int high);
        int getNumE(const std::vector<int>& E);
        std::vector<int> multE(const std::vector<int>& E1, const std::vector<int>& E2);
};



//std::istream& operator >> (std::istream&, Fractions&);
#endif // CYCLIC_CODING_H_INCLUDED
