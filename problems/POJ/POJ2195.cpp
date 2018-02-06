#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:http://poj.org/problem?id=2195>
 問題文============================================================
 家と人の位置の関係が与えられる。
 
 全ての人が重複しないいずれかの家に入る時、全ての人が移動しなければならない最小コストを求めよ
 =================================================================
 
 解説=============================================================
 ある人と全ての到達可能な家に対する距離をコストとした辺を貼った際の
 容量[人の数]の最小費用流と同値
 ================================================================
 */
#define MAX_V 100

struct edge{
    int to;
    int cap;
    int cost;
    int rev;
    edge(){}
    edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[2*MAX_V+2];
int dist[2*MAX_V+2];
int prevv[2*MAX_V+2],preve[2*MAX_V+2];

void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,(int)G[to].size()));
    G[to].push_back(edge(from,0,-cost,(int)G[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
    int res=0;
    while(f>0){
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update = true;
        while(update){
            update = false;
            for(int v=0; v<V ;v++){
                if(dist[v]==INF) continue;
                for(int i=0; i<G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if(dist[t]==INF) return -1;
        
        int d = f;
        for(int v=t; v!=s; v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*dist[t];
        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}


struct house{
    int x,y,id;
    house(){}
    house(int x,int y,int id):x(x),y(y),id(id){}
};

struct person{
    int x,y,id;
    person(){}
    person(int x,int y,int id):x(x),y(y),id(id){}
};

house House[MAX_V];
person Person[MAX_V];

int N,M;
void init(){
    for(int i = 0; i < 2*MAX_V + 2;i++) G[i].clear();
    
}
int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    while(true){
        scanf("%d%d",&N,&M);
        if(N == 0&& M == 0) break;
        init();
        int hid = 0, pid = 0;
        for(int i = 0; i < N;i++){
            for(int j = 0; j < M;j++){
                char c; cin >> c;
                if(c == 'm'){
                    Person[pid] = person(i,j,pid);
                    pid++;
                }
                if(c == 'H'){
                    House[hid] = house(i,j,hid);
                    hid++;
                }
            }
        }
        V = hid + pid + 2;
        int Source = hid + pid, Sink = Source + 1;
        for(int i = 0; i < pid; i++) add_edge(Source,i,1,0);
        for(int i = 0; i < hid; i++) add_edge(i + pid, Sink,1,0);
        for(int i = 0; i < pid; i++){
            for(int j = 0; j < hid; j++){
                add_edge(i,pid + j,1,abs(Person[i].x - House[j].x) + abs(Person[i].y - House[j].y));
            }
        }
        cout << min_cost_flow(Source, Sink, pid) << endl;
    }
    return 0;
}
