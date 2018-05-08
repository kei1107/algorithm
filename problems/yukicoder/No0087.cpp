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
 <url:https://yukicoder.me/problems/no/87>
 問題文============================================================
 2015年~N年の間(2015やNも含む)で7月23日(水)となる回数を求めよ
 =================================================================
 解説=============================================================
 カレンダーについて調べると400年周期で曜日が一致することがわかる。
 
 よって、この400年について実際にシミュレーションすれば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    
    ll sum = 0;
    ll t = 0;
    for(int i = 2015; i < 2415; i++){
        if(i%400 == 0) sum+=2;
        else if(i%100 == 0) sum +=1;
        else if(i%4 == 0) sum += 2;
        else sum += 1;
        if(sum%7 ==0)t++;
    }
    ll x = (N-2014)/400;
    res += x*t;
    
    sum = 0;
    t = 0;
    for(ll i = 2014+x*400+1; i < N+1; i++){
        if(i%400 == 0) sum+=2;
        else if(i%100 == 0) sum +=1;
        else if(i%4 == 0) sum += 2;
        else sum += 1;
        if(sum%7 ==0)t++;
    }
    res += t;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
