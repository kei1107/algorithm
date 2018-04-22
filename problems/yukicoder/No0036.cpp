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
 <url:https://yukicoder.me/problems/no/36>
 問題文============================================================
 本田君には競技プログラミングをやっている友達がたくさんいます。
 いつも素数の魅力を語られる本田君は素数に嫌気がさしてしまいました。
 
 そこで、友達の前で整数を使う時は、「素数,1,使う数自身」以外で割り切れる整数のみにすると決意しました。
 そのために、与えられた整数が友達の前で使っても良いかを判定するプログラムを作ることにしました。
 =================================================================
 解説=============================================================
 
 素因数の個数が3個以上あれば良い

 ================================================================
 */

string solve(){
    ll N; cin >> N;
    if(N == 1) return "NO";
    ll cnt = 0;
    for(ll i = 2; i*i <= N;i++){
        while(N%i==0){
            N/=i; cnt++;
        }
    }
    if(N != 1) cnt++;
    return (cnt>=3)?"YES":"NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
