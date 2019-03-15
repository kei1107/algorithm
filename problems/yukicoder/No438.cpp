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
 <url:https://yukicoder.me/problems/no/438>
 問題文============================================================
 =================================================================
 解説=============================================================
 逆ポーランド記法的なイメージ
 
 結局 ax + by = zとなるようなa,bを求めればよく
 文字列の個数は 2*|a|+2*|b|-1となるので、|10000|の範囲でaを全探索すればいい
 
 x,y,zのどれかが0のときコーナーになりうるので事前に処理しておく
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll x,y,z; cin >> x >> y >> z;
    // ax + by = z
    // |a| + |b| := c or w
    // |a| + |b| - 1 := C or W
    
    if(z == 0) return "ccW";
    if(x == 0 && y == 0) return "NO";
    
    if(y && z%y==0 && 2*(z/y)-1<=10000){
        ll b = z/y;
        res = string(b,'w') + string(b-1,'C');
        return res;
    }
    if(x && z%x==0 && 2*(z/x)-1<=10000){
        ll a = z/x;
        res = string(a,'c') + string(a-1,'C');
        return res;
    }
    if(x == 0 || y == 0) return "NO";
    
    for(ll a = -10000; a <= 10000; a++){
        if((z-a*x)%y != 0) continue;
        ll b = (z-a*x)/y;
        if(abs(a)*2+abs(b)*2-1>10000) continue;
        
        if(a > 0 && b > 0){
            res = string(a,'c') + string(b,'w') + string(a+b-1,'C');
        }else if(a < 0){
            res = string(-a,'c') + string(-a-1,'C') + string(b,'w') + string(b-1,'C') + "W";
        }else if(b < 0){
            res = string(-b,'w') + string(-b-1,'C') + string(a,'c') + string(a-1,'C') + "W";
        }
        return res;
    }
    res = "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}
