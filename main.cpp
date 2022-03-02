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
    Polinom (vector<double> &x);
    ~Polinom ();
    double valoare (const double &x);
    Polinom operator+(Polinom a);
    Polinom operator-(Polinom a);
    Polinom operator*(Polinom a);
};

Polinom :: Polinom() {
    nr_elem = 0;
}

Polinom :: Polinom (Polinom &x) {
    nr_elem = x.nr_elem;
    v = x.v;
}

Polinom :: Polinom (vector<double> &x) {
    nr_elem = x.size();
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
        int n = this->v.size() - a.v.size();
        for (int i = 0; i < n; ++i) rez.v.push_back(this->v[i]);
        for (unsigned int i = 0; i < a.v.size(); ++i)
            rez.v.push_back(this->v[n + i] + a.v[i]);
    }
    else {
        int n = a.v.size() - this->v.size();
        for (int i = 0; i < n; ++i) rez.v.push_back(a.v[i]);
        for (unsigned int i = 0; i < this->v.size(); ++i)
            rez.v.push_back(this->v[i] + a.v[n + i]);
    }
    return rez;
}

Polinom Polinom :: operator-(Polinom a) {
    Polinom rez;
    if (this->v.size() > a.v.size()) {
         int n = this->v.size() - a.v.size();
         for (int i = 0; i < n; ++i) rez.v.push_back(this->v[i]);
         for (unsigned int i = 0; i < a.v.size(); ++i) rez.v.push_back(this->v[n + i] - a.v[i]);
    }
    else {
         int n = a.v.size() - this->v.size();
         for (int i = 0; i < n; ++i) rez.v.push_back(-a.v[i]);
         for (unsigned int i = 0; i < this->v.size(); ++i) rez.v.push_back(this->v[i] - a.v[n + i]);
    }
    return rez;
}

Polinom Polinom :: operator*(Polinom a) {
    int n = this->v.size();
    int m = a.v.size();
    vector<double> aux(n + m - 1, 0);
    Polinom rez(aux);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            rez.v[i + j] += this->v[i] * a.v[j];
    return rez;
}

int main()
{
    vector<double> a = {5,6,7,8,-9,10};
    Polinom ob;
    a = {2,3,4};
    Polinom ob2(a);
    Polinom ob3 = ob+ob2;
    return 0;
}