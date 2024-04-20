// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class generator {
private:
    int a;
    unsigned int M;
    int c;
    unsigned int x = 0;
public:

    generator(int a, int M, int c, int x) {
        this->a = a;
        this->M = M;
        this->c = c;
        this->x = x;
    }
    
    int generate() {
        x = (a * x + c) % M;
        return x;
    }
};

class generator2 {
private:
    int tab[7] = { 1,0,0,1,1,0,1 };
    int p, q;
public:
    generator2(int p,int q) {
        this->p = p;
        this->q = q;
    };

    int generate() {
        int value = tab[p - 1] ^ tab[q - 1];
        for (int i = 5; i >= 0; i--) {
            tab[i + 1] = tab[i];
        }
        tab[0] = value;
        return value;
    }

};



int main()
{
    cout << "zadanie 1" << endl;
    unsigned int M = (1 << 31);
    generator gen(69069, M,1,15);
    generator2 gen2(7, 3);
    double number = 0;
    int tab[10];
    // zadanie 1
    for (int j = 0; j < 10; j++) {
        tab[j] = 0;
    }
    for (int i = 0; i < 100000; i++) {
        double value = gen.generate();
        double temp = 10 *value / M;
        for (int j = 0; j < 10; j++) {
            if (temp > j && temp < j + 1) {
                tab[j]++;
            }
        }
    }
    for (int j = 0; j < 10; j++) {
        cout << tab[j] << endl;
    }
    cout << "zadanie 2" << endl;
    //zadanie 2
    for (int j = 0; j < 10; j++) {
        tab[j] = 0;
    }
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 31; j++) {
            if (gen2.generate()) {
                number += pow(2, j);
            }
        }
        double value = number;
        double temp = 10 * value / M;
        for (int j = 0; j < 10; j++) {
            if (temp > j && temp < j + 1) {
                tab[j]++;
            }
        }
        number = 0;

    }
    for (int j = 0; j < 10; j++) {
        cout << tab[j] << endl;
    }

}

