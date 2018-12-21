#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class node{
    public:
        int dis, id;

        node(int i=0, int d=0){
            this->dis = d;
            this->id = i;
        }
};

int min_path(int a, int b){
    if(b==-1)
        return a;
    return min(a,b);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g;
    int* dis = new int[n+1];
    for(int i = 0; i <= n; i++)
        dis[i] = -1;
    for(int i = 0; i < n; i++)
    {
        vector<int> t;
        g.push_back(t);
    }
    int t;
    node* h = new node[k];
    for(int i = 0; i < k; i++)
    {
        cin >> t;
        node n(t, 0);
        h[i] = n;
    }
    
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    deque<node> d(h, h + k);

    while(d.size()>0){
        node u = d.back();
        d.pop_back();
        dis[u.id] = min_path(u.dis, dis[u.id]);
        for(int i = 0; i < g[u.id].size(); i++)
            if (dis[g[u.id][i]] == -1){
                node temp(g[u.id][i], u.dis+1);
                d.push_front(temp);
            }
    }
    
    for(int i = 0; i < n; i++)
        cout << dis[i+1] << endl;
    
    return 0;
}