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
 <url:https://yukicoder.me/problems/no/336>
 問題文============================================================
 =================================================================
 解説=============================================================
 Nが小さい場合について、愚直に答えを確かめると (test関数)
 OEISでヒットする >>  https://oeis.org/A001250
 
 ページ下部の方に、O(n^2)でとくやり方が乗っているので、その通りに実装するだけ
 ================================================================
 */


bool kadomatsu(int a,int b,int c){ return (b<a && b<c)||(b>a && b>c);}
void test(){
    for(int i = 1; i < 10;i++){
        int cnt = 0;
        vector<int> v(i); iota(v.begin(),v.end(),1);
        do{
            
            bool ok = true;
            for(int j = 0; j < i-2; j++){
                if(kadomatsu(v[j], v[j+1], v[j+2])) continue;
                ok = false;
                break;
            }
            cnt+=ok;
        }while(next_permutation(v.begin(),v.end()));
        cout << i << " : " << cnt << endl;
    }
}
const ll MOD = 1e9+7;
ll calc(ll n){
    ll ret = 1;
    map<ll,ll> A = {{-1,0},{0,2}};
    ll k = 0,e = 1;
    for(int i = 0; i <= n;i++){
        ll Am = 0;
        e = -e;
        for(int j = 0; j <= i; j++){
            ll& a = A[k];
            Am += a;
            if(Am >= MOD) Am -= MOD;
            a = Am;
            k += e;
        }
    }
    if(n&1) ret = A[n/2];
    else ret = A[-n/2];
    return ret;
}
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    if(N <= 2) return 0;
    res = calc(N);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //test();
    cout << solve() << endl;
    return 0;
}
