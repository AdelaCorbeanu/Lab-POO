#include <iostream>
#include <string>
#include <vector>

using namespace std;

class forma {
public:
    double h;
    double frisca;
    double gem;
    void calculeaza_gemul() {
        cin >> h;
        gem = frisca * h * 2;
    }
};

class cerc : public forma {
public:
    double raza;
    cerc() {
        cin >> raza;
        frisca = 3.14 * raza * raza;
        calculeaza_gemul();
    }
};

class dreptunghi : public forma {
public:
    double l, L;
    dreptunghi() {
        cin >> l >> L;
        frisca = l * L;
        calculeaza_gemul();
    }
};

class patrat : public forma {
public:
    double latura;
    patrat() {
        cin >> latura;
        frisca = latura * latura;
        calculeaza_gemul();
    }
};

class triunghi : public forma {
public:
    double c, C;
    triunghi() {
        cin >> c >> C;
        frisca = (c * C) / 2;
        calculeaza_gemul();
    }
};

int main() {
    string comanda;
    vector<forma*> v;
    double total_gem = 0, total_frisca = 0;
    while (cin >> comanda && comanda != "STOP") {
        if (comanda == "ADD") {
            string s;
            cin >> s;
            if (s == "cerc") {
                cerc x;
                v.push_back(new cerc(x));
            }
            else if (s == "drepunghi") {
                dreptunghi x;
                v.push_back(new dreptunghi(x));
            }
            else if (s == "patrat") {
                patrat x;
                v.push_back(new patrat(x));
            }
            else {
                triunghi x;
                v.push_back(new triunghi(x));
            }
            cout << v.back()->gem << " " << v.back()->frisca << '\n';
            total_gem += v.back()->gem;
            total_frisca += v.back()->frisca;
        }
        else if (comanda == "REMOVE") {
            int x;
            cin >> x;
            total_gem -= v[x-1]->gem;
            total_frisca -= v[x-1]->frisca;
            v.erase(v.begin()+x-1);
        }
        else {
            cout << total_gem << " " << total_frisca << '\n';
        }
    }
    return 0;
}
