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
 <url:https://yukicoder.me/problems/no/731>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 3分探索でゴリ押す。
 
 ただ、最小二乗法を知ってると一瞬で解けたり
 ================================================================
 */

typedef long double ld;
ll N;
vector<ld> a;


ld TC(ld b,ld d){
    ld ret = 0;
    for(int i = 0; i < N;i++){
        ret += (a[i]-b)*(a[i]-b);
        b += d;
    }
    return ret;
}

ld D = 0;
ld C(ld b){
    ld ret = 0;

    ld l = -INF, r = INF;
    for(int kassa = 0; kassa < 100;kassa++){
        ld d1 = (r-l)/3 + l,d2 = (r-l)*2/3 + l;

        ld tc1 = TC(b,d1),tc2 = TC(b,d2);
        if(tc1 < tc2){
            r = d2;
        }else{
            l = d1;
        }
    }
    ret = TC(b,l);
    D = l;
    return ret;
}
void solve(){
    cin >> N;
    a.resize(N); for(auto& in:a) cin >> in;
    ld l = -INF, r = INF;
    for(int kassa = 0; kassa < 100; kassa++){
        ld b1 = (r-l)/3 + l,b2 = (r-l)*2/3 + l;

        ld c1 = C(b1), c2 = C(b2);
        if(c1 < c2){
            r = b2;
        }else{
            l = b1;
        }
    }

    ld B = l;
    C(l);
    ld cost = TC(B,D);
    cout << fixed << setprecision(12);
    cout << B << " " << D << endl;
    cout << cost << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
