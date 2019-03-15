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
 <url:https://atcoder.jp/contests/abc115/tasks/abc115_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 レベルNバーガーの層数とパティの数は事前に前処理で計算できる。
 
 あとは、現在のレベルN,食す総数Xについて再帰的に下のバーガーまで潜っていけばいい
 解説がわかりやすい => https://img.atcoder.jp/abc115/editorial.pdf
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    ll N,X; cin >> N >> X;
    vector<ll> sumL(51),sumP(51);
    sumL[0] = 1;
    sumP[0] = 1;
    for(int i = 1; i <= 50; i++){
        sumL[i] = 2*sumL[i-1] + 3;
        sumP[i] = 2*sumP[i-1] + 1;
    }
    
    ll L = N;
    while(X){
        if(L == 0) { X-=1; res++; }
        else{
            if(X == 1){ // B
                X--;
            }else if(X <= sumL[L-1]+1){ // L-1 B
                X-=1;
            }else if(X == sumL[L-1]+2){ // P
                res += sumP[L-1] + 1;
                X -= sumL[L-1] + 2;
            }else if(X <= sumL[L-1]*2 + 2){ // L-1 B
                res += sumP[L-1] + 1;
                X -= sumL[L-1] + 2;
            }else if(X == sumL[L-1]*2 + 3){ // B
                res += sumP[L-1]*2 + 1;
                X -= sumL[L-1]*2 + 3;
            }
            L-=1;
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
