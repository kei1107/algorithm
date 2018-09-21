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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/E>
 問題文============================================================
 =================================================================
 解説=============================================================
 指定長方形の領域が
 ドーナツの内部に留まっていれば、y/x
 留まっていなければ、右上をドーナツに合わせてその中心までの傾き
 ================================================================
 */

double solve(){
    double res = 0;
    double W,H,w,h,x,y; cin >> W >> H >> w >> h >> x >> y;
    if((x+w/2 <= W/2) and (y+h/2 <= H/2)){
        res = y/x;
    }else{
        if(x+w/2 > W/2){
            x = (x-w/2+W/2)/2;
        }
        if(y+h/2 > H/2){
            y = (y-h/2+H/2)/2;
        }
        res = y/x;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
