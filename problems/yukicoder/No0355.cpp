#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/355>
 問題文============================================================
 =================================================================
 解説=============================================================
 http://d.hatena.ne.jp/chakoku/20130505/1367744022
 ================================================================
 */

using query = tuple<int,int,int,int>;
set<query> querys;
pii Try(const query& q){
    cout << get<0>(q) << " " << get<1>(q) << " " << get<2>(q) << " " << get<3>(q) << endl;
    int X,Y; cin >> X >> Y;
    if(X == 4) exit(0);
    return {X,Y};
}
pii Check(const query& q1,const query& q2){
    int H = 0,B = 0;
    vector<int> v1 = {get<0>(q1),get<1>(q1),get<2>(q1),get<3>(q1)};
    vector<int> v2 = {get<0>(q2),get<1>(q2),get<2>(q2),get<3>(q2)};
    for(int i = 0; i < 4;i++) H += v1[i]==v2[i];
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4;j++){
            B += v1[i]==v2[j];
        }
    }
    B-=H;
    return {H,B};
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10;j++){
            if(i == j) continue;
            for(int k = 0; k < 10;k++){
                if(i == k || j == k) continue;
                for(int l = 0; l < 10;l++){
                    if(i == l || j == l || k == l) continue;
                    querys.insert(query(i,j,k,l));
                }
            }
        }
    }
    while(querys.size()){
        auto Q = *querys.begin(); querys.erase(Q);
        auto rep = Try(Q);
        
        set<query> next;
        for(auto T : querys){
            if(Check(T,Q) == rep){
                next.insert(T);
            }
        }
        querys = next;
    }
    return 0;
}
