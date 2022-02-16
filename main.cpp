#include <iostream>
#include <cstring>
using namespace std;

double gem[100], frisca[100], total_gem, total_frisca;
char comanda[50], forma[50];

struct cerc {
    int raza;
};

struct dreptunghi {
    int L, l;
};

struct patrat {
    int latura;
};

struct triunghi {
    int C, c;
};

int main() {
    int h;
    int index_forma = 0;

    cin >> comanda;
    while (strcmp(comanda, "STOP")) {

        double arie_baza, volum;          //frisca, gem
        int index_remove;

        if (!strcmp(comanda, "ADD")) {
            cin >> forma;

            if (!strcmp(forma, "cerc")) {
                cerc x;
                cin >> x.raza;
                cin >> h;
                arie_baza = 3.14 * x.raza * x.raza;
            }

            else if (!strcmp(forma, "dreptunghi")) {
                dreptunghi x;
                cin >> x.L >> x.l;
                arie_baza = x.L * x.l;
            }

            else if (!strcmp(forma, "patrat")) {
                patrat x;
                cin >> x.latura;
                arie_baza = x.latura * x.latura;
            }

            else {
                triunghi x;
                cin >> x.C >> x.c;
                arie_baza = double(x.C * x.c) / 2;
            }

            index_forma ++;
            volum = arie_baza * h;
            cout << volum << " " << arie_baza << '\n';
            gem[index_forma] = volum;
            frisca[index_forma] = arie_baza;
            total_gem += volum;
            total_frisca += arie_baza;
        }

        else if (!strcmp(comanda, "REMOVE")) {
            cin >> index_remove;
            total_gem -= gem[index_remove];
            total_frisca -= frisca[index_remove];
            for (int i = index_remove; i < index_forma; ++ i) {
                frisca[i] = frisca[i + 1];
                gem[i] = gem[i + 1];
            }
            index_forma --;
        }

        else {
            cout << total_gem << " " << total_frisca << '\n';
        }
        cin >> comanda;
    }
    return 0;
}
