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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1132>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ある2点が円上となるような点が最適な円となる可能性のあるもの
 
 よって nC2通りの全てのパターンにてその円を求めていくつの点が含まれるのかを確認すれば良い
 
 ================================================================
 */

typedef complex<double> Point;
int n;
int solve(){
    int res = 1;
    vector<Point> ps(n);
    for(int i = 0; i < n;i++){
        double x,y; cin >> x >> y;
        ps[i] = Point(x,y);
    }
    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n;j++){
            double dist = abs(ps[i]-ps[j]);
            if(dist > 2) continue;
            Point mp = (ps[i]+ps[j])/2.;
            Point dp = ps[i]-ps[j];
            double x = sqrt(1-dist*dist/4);
            Point cp = Point(-dp.imag()*x/dist+mp.real(),dp.real()*x/dist+mp.imag());
            int cnt = 0;
            for(int k = 0; k < n;k++){
                if(abs(cp-ps[k]) < 1.0 + 1e-9) cnt++;
            }
            res = max(res,cnt);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}
