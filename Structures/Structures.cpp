#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
    Complex add(const Complex& other) const {
        return { real + other.real, imag + other.imag };
    }

    Complex subtract(const Complex& other) const {
        return { real - other.real, imag - other.imag };
    }

    Complex multiply(const Complex& other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    Complex divide(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "No zero" << endl;
            return { 0, 0 };
        }
        return {
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        };
    }

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex a = { 4, 3 };
    Complex b = { 2, -1 };

    Complex sum = a.add(b);
    Complex difference = a.subtract(b);
    Complex product = a.multiply(b);
    Complex quotient = a.divide(b);

    cout << "Сумма ";
    sum.print();

    cout << "Разность ";
    difference.print();

    cout << "Произведение ";
    product.print();

    cout << "Частное ";
    quotient.print();

    return 0;
}
