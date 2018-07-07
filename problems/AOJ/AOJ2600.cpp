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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2600>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 imos法を使う。
 クエリごとにカバーできる範囲をimos法にて確認する
 
 その後、東西方向及び南北方向に関して両方ともカバーできないような点が存在すればNo
 そうでなければYesとなる
 
 ================================================================
 */

string solve(){
    string res;
    int N,W,H; cin >> N >> W >> H;
    vector<int> x(N),y(N),w(N);
    vector<int> X(W+2),Y(H+2);
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i] >> w[i];
        X[max(0,x[i]-w[i])]++;
        X[min(W+1,x[i]+w[i])]--;
        
        Y[max(0,y[i]-w[i])]++;
        Y[min(H+1,y[i]+w[i])]--;
    }
    
    bool xf = true;
    for(int i = 0; i < W;i++){
        X[i+1] += X[i];
        if(X[i] == 0) xf = false;
    }
    bool yf = true;
    for(int i = 0; i < H;i++){
        Y[i+1] += Y[i];
        if(Y[i] == 0) yf = false;
    }
    if(xf | yf){
        res = "Yes";
    }else{
        res = "No";
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
