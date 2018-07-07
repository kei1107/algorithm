#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2592>
 問題文============================================================
 
 pw と vw_i, pf_i,vf_i,th_i (1 <= i <= 10^5)
 が与えられる
 
 ここで、Wと F_i (1 <= i <= 10^5) を自由に決めていいとき
 
 W*pw + Σ(F_i * pf_i)   (1)
 を最小化したい
 
 但し、
 各iに対して
 W >= 0
 W * vw_i + F_i * vf_i >= th_i
 F_i >= 0
 を満たす必要がある
 
 1≤N≤10^5, 1≤pw≤100, −100≤vw_i≤100, 1≤pf_i≤100, 1≤vf_i≤100,−100≤th_i≤100
 =================================================================
 解説=============================================================
 
 三分探索を行う
 
 (1)式に関して,Wを固定した時、条件より
 F_i = max((th_i - W*vw_i)/vf_i,0.)
 が最適であり、Σ(F_i * pf_i) = Y(Const) と固定できる
 
 よって(1)は W*pw = Xとすれば
 X + Y (2)
 となり、 X が増加すれば Yが減少し、Xが減少すればYが増加する関係となるので、
 X + Y が下に凸な値となることが分かる
 
 よって Wを固定した場合について三分探索を行うことによって最適な解を探索できる
 ================================================================
 */

int N;
using CVDR = const vector<double>&;
double C(double W,double pw,CVDR vw,CVDR pf,CVDR vf,CVDR th){
    double ret = W*pw;
    for(int i = 0; i < N;i++){
        double F = max((th[i] - W*vw[i])/vf[i],0.);
        ret += (F*pf[i]);
    }
    return ret;
}
double solve(){
    double res = 0;
    double pw; cin >> pw;
    vector<double> vw(N),pf(N),vf(N),th(N);
    for(int i = 0; i < N;i++) cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0,r = 1e5;
    for(int kassa = 0; kassa < 100; kassa++){
        double xl = l + (r-l)/3.;
        double xr = l + (r-l)*2/3.;
        double lret = C(xl,pw,vw,pf,vf,th);
        double rret = C(xr,pw,vw,pf,vf,th);
        if(lret < rret){
            r = xr;
        }else{
            l = xl;
        }
    }
    res = C(l,pw,vw,pf,vf,th);
    return res;
}
int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N,N){
        cout << fixed << setprecision(12) <<  solve() << endl;
    }
    return 0;
}
