#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class exs{
    public:
    int order, p, w;
    exs(int o=0, int p=0){
        this->order = o;
        this->p = p;
    }
};

class klass{
    public:
        exs* exsersises;
        long long ec, sep, sew;
    klass(int ec=0){
        this->exsersises = new exs[ec];
        this->sep = 0;
        this->sew = 0;
        this->ec = ec;
    }
};

int main(){
    int n;
    cin >> n;
    klass* k = new klass[n];
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        klass tk(t);
        k[i] = tk;
    }
    long long o = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k[i].ec; j++){
            int p;
            cin >> p;
            exs te(o, p);
            k[i].exsersises[j] = te;
            k[i].sep += p;
            o++;
        }

    o = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k[i].ec; j++){
            int w;
            cin >> w;
            k[i].exsersises[j].w = w;
            k[i].sew += w;
            o++;
        }
    
    sort(k, &k[n], [](klass a, klass b) {
        return a.sep*b.sew < b.sep*a.sew;
    });

    o = 0;
    long long r = 0;
    // string report = "";
    for(int i = 0; i < n; i++)
    {
        sort(k[i].exsersises, &k[i].exsersises[k[i].ec], [](exs a, exs b) {
            return a.p*b.w < b.p*a.w;
        });

        for(int j = 0; j < k[i].ec; j++){
            o += k[i].exsersises[j].p;
            r += o*k[i].exsersises[j].w;
        }

        // for(int j = 0; j < k[i].ec; j++)
        //     report = report + to_string(k[i].exsersises[j].order) + " ";
    }
    cout << r << endl;
    // cout << r << endl << report;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k[i].ec; j++)
            cout << k[i].exsersises[j].order << ' ';

    return 0;
}