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
 <url:https://atcoder.jp/contests/abc121/tasks/abc121_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 どう実装するのがベストなんやろ(精進不足)
 F(N):=1..Nまでで2^iに1が立っている数字の個数
 を実装
 F(B)とF(A-1) (A>=2)の差分をとって、i番目(2^i)の個数が奇数の場合答えに2^iを加算
 ================================================================
 */

vector<ll> two;
vector<ll> f(ll N){
    vector<ll> ret(two.size());
    ll cnt = 0;
    ll t = 1;
    while(true){
        ll T = N-(t-1);
        if(T <= 0) break;
        
        ret[cnt] = (T/(2*t))*t;
        
        T -= T/(2*t)*(2*t);
        ret[cnt] += min(T,t);
        
        cnt++;
        t *= 2;
    }
    return ret;
}
template<class Type>
Type solve(Type res = Type()){
    ll A,B; cin >> A >> B;
    ll t = 1;
    while(t <= 1e12+10){
        two.push_back(t);
        t *= 2;
    }
    auto ret1 = f(B);
    vector<ll> ans = ret1;

    if(A >= 2){
        auto ret2 = f(A-1);
        for(int i = 0; i < two.size();i++){
            ans[i] -= ret2[i];
        }
    }
    
    for(ll i = 0; i < two.size();i++){
        if(ans[i]%2==1){
            res += 1LL<<i;
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
