#pragma comment(lib, "compl.lib")
#include <iostream>
#include <complex>

class Complex {
public:
	double re, im;

	Complex(double a, double b);
	void mysub(Complex*, Complex*);
	void mymul(Complex*, Complex*);
	void myabs();
};

int main() {
	Complex 
		a(5, -2.5), 
		b(1.5, 10), 
		r(1, 1);
	std::complex<double>
		aBuf(5, -2.5),
		bBuf(1.5, 10),
		rBuf(1, 1);

	a.mysub(&b, &r);
	rBuf = aBuf - bBuf; 
	std::cout << "a - b = " << r.re << " + " << r.im << " * i " << std::endl;
	std::cout << "a - b = " << rBuf.real() << " + " << rBuf.imag() << " * i " << std::endl;

	a.mymul(&b, &r);
	rBuf = aBuf * bBuf;
	std::cout << "a * b = " << r.re << " * " << r.im << " * i " << std::endl;
	std::cout << "a * b = " << rBuf.real() << " * " << rBuf.imag() << " * i " << std::endl;

	a.myabs();
	rBuf = std::abs(aBuf);
	std::cout << "|a| = " << r.re << std::endl;
	std::cout << "|a| = " << rBuf.real() << std::endl;

}
