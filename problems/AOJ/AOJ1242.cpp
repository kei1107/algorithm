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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1242>
 問題文============================================================
 
 頂点が格子点上にある多角形が与えられる．
 多角形が通るマスと多角形に含まれるマスの数を答えよ
 
 =================================================================
 解説=============================================================
 
 解説みた http://algoogle.hadrori.jp/aoj/1242/
 
 平面走査して、愚直に調べればよい
 ================================================================
 */

double getx(int a,int b,int vy,vector<int>& x,vector<int>& y){
    if(y[a] < y[b]) swap(a,b);
    double A = y[a] - vy, B = vy - y[b];
    return (B*x[a]+A*x[b])/(A+B);
}
ll N;
ll solve(){
    ll res = 0;
    vector<int> x(N),y(N); for(int i = 0; i < N;i++) cin >> x[i] >> y[i];
    int l = *min_element(y.begin(), y.end()), r = *max_element(y.begin(), y.end());
    for(int i = l; i < r; i++){
        vector<pair<double,double>> xs;
        for(int j = 0; j < N;j++){
            int nextj = (j+1)%N;
            if(y[j] == y[nextj]) continue;
            if(i < min(y[j],y[nextj])) continue;
            if(i+1 > max(y[j],y[nextj])) continue;
            double x1 = getx(j,nextj,i,x,y),x2 = getx(j,nextj,i+1,x,y);
            if(x1 > x2) swap(x1,x2);
            xs.push_back(make_pair(x1,x2));
        }
        sort(xs.begin(),xs.end());
        int Xr = -INF;
        for(int j = 0; j < xs.size()-1; j+=2){
            int l = max(int(floor(xs[j].first)),Xr),r = ceil(xs[j+1].second);
            res += r - l;
            Xr = r;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N,N){
        cout << solve() << endl;
    }
    return 0;
}
