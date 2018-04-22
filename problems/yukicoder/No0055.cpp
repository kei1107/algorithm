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
 <url:https://yukicoder.me/problems/no/55>
 問題文============================================================
 異なる4点の整数座標を渡されました。
 方眼紙に4点を頂点とする正方形を描くのが仕事です。
 しかし、4点のうち1点だけがわからなくなってしましました。
 わかっているのは残りの3点の座標です。
 もし、1点を推測して正方形が描けるのであれば、
 正方形を描けるその1点の座標を答えなさい。
 正方形が描けない場合は-1を答えとします。
 =================================================================
 解説=============================================================
 ３点の位置関係を全探索して、正方形のうち3点に該当するような並びかどうかを確認する。
 ================================================================
 */

void solve(){
    ll X[3],Y[3];
    for(int i = 0; i < 3;i++) cin >> X[i] >> Y[i];
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3;k++){
                if((i==j)||(i==k)||(j==k)) continue;
                if(X[i]-(Y[j]-Y[i]) != X[k]) continue;
                if(Y[i]+(X[j]-X[i]) != Y[k]) continue;
                cout << X[k] + (X[j]-X[i]) << " " << Y[j] + (Y[k]-Y[i]) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
