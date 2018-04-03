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
 <url:https://yukicoder.me/problems/no/25>
 問題文============================================================
 peachは、分数で表された数が、有限小数で表されるかを知りたくなった。
 「有限小数」とは 1/8=0.125 のような有限の小数で表される数値のことである。
 4/3=1.33333… のような数は、有限の小数では表されないため該当しない。
 
 ここで、64ビット符号付き整数で表される自然数が2つ(N,M)与えられる。
 この時 N/Mが有限小数で表されるか判定してください。
 
 有限小数で表される時、0でない一番小さい桁の数字を出力してください。
 有限小数で表すことが出来ない時、−1を出力してください。
 
 小数にならない時も、0でない一番小さい桁の数字を求めてください。

 =================================================================
 解説=============================================================
 
 有限小数 => 既約分数にした形の時の分母が2と5の倍数のみとなる
 
 => 2と5を取り除いた時, N/Mは割り切れるはず
    この時、取り除いた2と5に対応する数だけ 10^n を Nに乗じてやれば、
    その値はMの倍数となるはず
 
 ================================================================
 */

/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }


ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    ll GCD = gcd(N,M);
    N /= GCD; M /= GCD;
    if(N%M == 0){
        string s = to_string(N/M);
        for(int i = (int)s.length()-1;i>=0;i--){
            if(s[i] == '0') continue;
            return res = s[i]-'0';
        }
    }else{
        int c2 = 0,c5 = 0;
        while(N%2==0){N/=2; c2++;}
        while(M%2==0){M/=2; c2--;}
        while(N%5==0){N/=5; c5++;}
        while(M%5==0){M/=5; c5--;}
        if(N%M!=0) return res = -1;
        res = N/M; res %= 10;
        while(c2 < 0 || c5 < 0){c2++; c5++;}
        ll x = 1;
        while(c2--){ x = (2*x)%10; }
        if(c5>0) x = 5*x;
        (res*=x)%=10;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
