#include <iostream>
#include <vector>

using namespace std;

class Polinom {
private:
    vector<double> v;
    int nr_elem;

public:
    Polinom ();
    Polinom (Polinom &x);
    explicit Polinom (vector<double> &x);
    ~Polinom ();

    double valoare (const double &x);     //valoarea polinomului in x

    Polinom operator+(Polinom a);
    Polinom operator-(Polinom a);
    Polinom operator*(Polinom a);

    void setPolinom (vector<double> v);
    vector<double> getPolinom();

    friend ostream &operator<<(ostream &os, const Polinom &ob);
    friend istream &operator>>(istream &is, Polinom &ob);
};

Polinom :: Polinom() {
    nr_elem = 0;
}

Polinom :: Polinom (Polinom &x) {
    nr_elem = x.nr_elem;
    v = x.v;
}

Polinom :: Polinom (vector<double> &x) {
    nr_elem = (int)x.size();
    v = x;
}

Polinom :: ~Polinom () {
    nr_elem = 0;
    v.clear();
}

double Polinom :: valoare (const double &x) {
    double p = 1, rez = 0;
    for (auto it : v) {
        rez += p * it;
        p = p * x;
    }
    return rez;
}

Polinom Polinom :: operator+(Polinom a) {
    Polinom rez;
    if (this->v.size() > a.v.size()) {
        int n = (int)this->v.size() - (int)a.v.size();
        for (int i = 0; i < n; ++i) rez.v.push_back(this->v[i]);
        for (unsigned int i = 0; i < a.v.size(); ++i)
            rez.v.push_back(this->v[n + i] + a.v[i]);
    }
    else {
        int n = (int)a.v.size() - (int)this->v.size();
        for (int i = 0; i < n; ++i) rez.v.push_back(a.v[i]);
        for (unsigned int i = 0; i < this->v.size(); ++i)
            rez.v.push_back(this->v[i] + a.v[n + i]);
    }
    return rez;
}

Polinom Polinom :: operator-(Polinom a) {
    Polinom rez;
    if (this->v.size() > a.v.size()) {
         int n = (int)this->v.size() - (int)a.v.size();
         for (int i = 0; i < n; ++i) rez.v.push_back(this->v[i]);
         for (unsigned int i = 0; i < a.v.size(); ++i) rez.v.push_back(this->v[n + i] - a.v[i]);
    }
    else {
         int n = (int)a.v.size() - (int)this->v.size();
         for (int i = 0; i < n; ++i) rez.v.push_back(-a.v[i]);
         for (unsigned int i = 0; i < this->v.size(); ++i) {
             double x = this->v[i] - a.v[n + i];
             if (x) rez.v.push_back(this->v[i] - a.v[n + i]);
         }
    }
    return rez;
}

Polinom Polinom :: operator*(Polinom a) {
    int n = (int)this->v.size();
    int m = (int)a.v.size();
    vector<double> aux(n + m - 1, 0);
    Polinom rez(aux);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            rez.v[i + j] += this->v[i] * a.v[j];
    return rez;
}

ostream &operator<<(ostream &os, const Polinom &ob) {
    auto putere = ob.v.size() - 1;
    int gol = true;
    os << "Polinomul este: ";
    for (double i : ob.v) {
        if (i) {
            if (!gol && i > 0) os << '+';
            gol = false;
            if (i == 1 && putere) os << "X";
            else if (i == -1 && putere) os << "-X";
            else {
                os << i;
                if (putere) os << "*X";
            }
            if (putere > 1) os << '^' << putere;
        }
        putere--;
    }
    os << '\n';
    return os;
}

istream &operator>>(istream &is, Polinom &ob) {
    cout << "Numarul de coeficienti este: ";
    is >> ob.nr_elem;
    double x;
    ob.v.clear();
    cout << "Coeficientii sunt: ";
    for (int i = 0; i < ob.nr_elem; ++i) {
        cin >> x;
        ob.v.push_back(x);
    }
    return is;
}

void Polinom :: setPolinom (vector<double> v) {
    this->v = v;
}

vector<double> Polinom :: getPolinom() {
    return this->v;
}

int main()
{
    vector<double> a = {5,6,7,8,-9,10};
    Polinom ob(a);
    a = {2,3,3};
    Polinom ob2(a);
    a = {2,1,1};
    Polinom ob3;
    ob3.setPolinom(a);
    ob2.setPolinom(ob3.getPolinom());
    a = {1};
    ob3.setPolinom(a);
    cin >> ob2;
    cout << ob2;
    return 0;
}