#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day3/problems/B>
 問題文============================================================
 =================================================================
 解説=============================================================
 双方向リストを作って頑張る
 ================================================================
 */

struct node{
    int prev,v,next;
    node(int prev = 0,int v = 0,int next = 0):prev(prev),v(v),next(next){}
};
vector<int> solve(){
    vector<int> res;
    int N,Q; cin >> N >> Q;
    vector<int> a(N+2); a[0] = 0; a[N+1] = N+1;
    for(int i = 1; i <= N;i++) cin >> a[i];
    
    vector<node> X(N+2);
    X[0] = node(INF,0,a[1]);
    X[N+1] = node(a[N],N+1,INF);
    for(int i = 1; i <= N;i++){
        X[a[i]] = node(a[i-1],a[i],a[i+1]);
    }
    
    if(N == 1) {
        res.push_back(1);
        return res;
    }
    
//    for(int i = 0; i <= N+1;i++){
//        cout << i << " : " << X[i].prev << "," << X[i].v << "," << X[i].next << endl;
//    }
    while(Q--){
        ll q; cin >> q;
        ll prev = X[q].prev;
        ll v = q;
        ll next = X[q].next;
        
        if(prev != 0 && next != N+1){
            node nodel1 = X[X[0].next];
            node noder1 = X[prev];
            node nodev = X[v];
            node nodel2 = X[next];
            node noder2 = X[X[N+1].prev];
            
            
            X[0].next = nodel2.v;
            X[nodel1.v].prev = nodev.v;
            X[noder1.v].next = X[N+1].v;
            X[nodev.v].prev = noder2.v;
            X[nodev.v].next = nodel1.v;
            X[nodel2.v].prev = X[0].v;
            X[noder2.v].next = nodev.v;
            X[N+1].prev = noder1.v;
        }
        if(prev == 0){
            node nodev = X[v];
            node nodel = X[next];
            node noder = X[X[N+1].prev];
            
            X[0].next = nodel.v;
            X[nodel.v].prev = X[0].v;
            X[noder.v].next = nodev.v;
            X[nodev.v].prev = noder.v;
            X[nodev.v].next = X[N+1].v;
            X[N+1].prev = nodev.v;
        }
        if(next == N+1){
            node nodel = X[X[0].next];
            node noder = X[prev];
            node nodev = X[v];
            
            X[0].next = nodev.v;
            X[nodev.v].prev = X[0].v;
            X[nodev.v].next = nodel.v;
            X[nodel.v].prev = nodev.v;
            X[noder.v].next = X[N+1].v;
            X[N+1].prev = noder.v;
            
        }
        
//        for(int i = 0; i <= N+1;i++){
//            cout << i << " : " << X[i].prev << "," << X[i].v << "," << X[i].next << endl;
//        }
    }
    int ind = X[0].next;
    while(ind != N+1){
        res.push_back(ind);
        ind = X[ind].next;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
