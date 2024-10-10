#include <iostream>
using namespace std;

class Kerucut {
private:
    double radius;
    double tinggi;

public:
    Kerucut(double r, double t) : radius(r), tinggi(t) {}

    double volume() {
        return (1.0 / 3) * M_PI * radius * radius * tinggi;
    }

    double luasPermukaan() {
        double s = sqrt(radius * radius + tinggi * tinggi);
        return M_PI * radius * (radius + s);
    }
};

int main() {
    // int a = 10;
    // cout << "Alamat memori dari variabel a adalah: " << &a << endl;
    // return 0;


    // int a = 20;
    // int *ptr = &a;
    // cout << "Nilai dari a: " << *ptr << endl;
    // return 0;


    Kerucut k(5.0, 12.0);
    cout << "Volume kerucut: " << k.volume() << endl;
    cout << "Luas permukaan kerucut: " << k.luasPermukaan() << endl;
    return 0;

    
}
