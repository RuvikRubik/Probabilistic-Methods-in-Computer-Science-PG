

#include <iostream>
#include <random>
using namespace std;



int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);
    double random;
    int tab[4];
    int tab2[10];
    for (int j = 0; j < 4; j++) {
        tab[j] = 0;
    }
    for (int j = 0; j < 10; j++) {
        tab2[j] = 0;
    }
    for (int i = 0; i < 100000; ++i) {
        random = dist(mt);
        if (random <= 0.1) {
            tab[0]++;
        }
        else if (random <= 0.3) {
            tab[1]++;
        }
        else if (random <= 0.6) {
            tab[2]++;
        }
        else if (random <= 1) {
            tab[3]++;
        }
    }for (int j = 0; j < 4; j++) {
        cout <<j+1<<": " << tab[j] << endl;
    }

    for (int i = 0; i < 100000; ++i) {
        random = dist(mt);
        int x = 50 + (100 * random);
        for (int j = 0; j < 10; j++) {
            if (x >= (j*10) + 50 && x < ((j + 1)*10) + 50) {
                tab2[j]++;
            }
        }
    }
    for (int j = 1; j <= 10; j++) {
        cout << 50 + (j-1) * 10 << " - " << 50 + j * 10 << " " << tab2[j-1] << endl;
    }

}

