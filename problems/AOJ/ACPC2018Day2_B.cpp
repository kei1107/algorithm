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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/B>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ukuが優先的にダメージを与えることができる場合と
 牛が優先的にダメージを与えることができる場合をそれぞれ考える

 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N,M; cin >> N >> M;
    {
        ll num = 0;
        ll uku = 2*N,ei = 2*M;
        ll uku_dame = 0,ei_dame = 0;
        while(true){
            if(num%2 == 0){
                ll uku_num = (uku-uku_dame)/2;
                ei_dame+=uku_num;
            }else{
                ll ei_num = min(M,ei-ei_dame);
                uku_dame+=ei_num;
            }
            if(uku-uku_dame<=0) break;
            if(ei-ei_dame<=0) break;
            num++;
        }
        res = min(res,num);
    }
    {
        ll num = 0;
        ll uku = 2*N,ei = 2*M;
        ll uku_dame = 0,ei_dame = 0;
        while(true){
            if(num%2 == 0){
                ll uku_num = min(N,uku-uku_dame);
                ei_dame+=uku_num;
            }else{
                ll ei_num = (ei-ei_dame)/2;
                uku_dame+=ei_num;
            }
            if(uku-uku_dame<=0) break;
            if(ei-ei_dame<=0) break;
            num++;
        }
        res = min(res,num);

    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
