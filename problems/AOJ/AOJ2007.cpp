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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2007&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 全通りの支払いパターンを試す
 ================================================================
 */
int B;
void solve(){
    int x1,x2,x3,x4; cin >> x1 >> x2 >> x3 >> x4;
    vector<int> ret;
    int minX = INF;
    for(int i = 0; i <= x1;i++){
        for(int j = 0; j <= x2; j++){
            for(int k = 0; k <= x3; k++){
                for(int l = 0; l <= x4;l++){
                    if(10*i+50*j+100*k+500*l < B) continue;
                    int X = x1 - i + x2 - j + x3 - k + x4 - l;
                    int leftB = 10*i+50*j+100*k+500*l - B;
                    X += leftB/500;
                    leftB %= 500;
                    X += leftB/100;
                    leftB %= 100;
                    X += leftB/50;
                    leftB %= 50;
                    X += leftB/10;
                    if(X < minX){
                        ret = vector<int>{i,j,k,l};
                        minX = X;
                    }
                }
            }
        }
    }
    int kane[4] = {10,50,100,500};
    for(int i = 0; i < 4;i++){
        if(ret[i] != 0){
            cout << kane[i] << " " << ret[i] << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    bool f = false;
    while(cin >> B,B){
        if(f)cout << endl;
        f = true;
        solve();
    }
    return 0;
}
