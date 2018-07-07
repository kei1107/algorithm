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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1193&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 制約が小さいので
 愚直シミュレーションで通る
 ================================================================
 */

int H;

ll check(vector<int>& vec){
    ll ret = 0;
    
    for(int i = 0; i < 3;i++){
        ll t = vec[i];
        ll cnt = 1;
        for(int j = i+1; j < 5;j++){
            if(vec[j] != t) break;
            cnt++;
        }
        if(cnt >= 3){
            for(int j = i; j < i+cnt;j++){
                vec[j] = 0;
            }
            ret += t*cnt;
            return ret;
        }
    }
    return ret;
}
ll solve(){
    ll res = 0;
    vector<vector<int>> Stone(H,vector<int>(5,0));
    for(int i = H-1; i >= 0; i--){
        for(int j = 0; j < 5;j++){
            cin >> Stone[i][j];
        }
    }
    while(true){
        ll t = res;
        for(int i = H-1; i >= 0; i--){
            res += check(Stone[i]);
        }
        if(t == res) break;
        while(true){
            bool update = false;
            for(int i = 0; i < H-1;i++){
                for(int j = 0; j < 5;j++){
                    if(Stone[i][j] == 0 && Stone[i+1][j] != 0){
                        update = true;
                        swap(Stone[i][j],Stone[i+1][j]);
                    }
                }
            }
            if(!update) break;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> H,H){
        cout << solve() << endl;
    }
    return 0;
}
