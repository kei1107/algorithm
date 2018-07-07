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
 <url:https://beta.atcoder.jp/contests/arc082/tasks/arc082_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 じっくり証明して頑張って自力AC 嬉しい
 
 この問題は３パターンの分類に分けることができる
 la = { llim,lval} , ua = { rlim, rval}
 とすれば
 初期状態のaが
 a <= llim の時
    今見ている区間(r[i] --- r[i+1])は lvalから始まる　(= r[i]の時 lval)
 a >= ulim の時
    今見ている区間(r[i] --- r[i+1])は rvalから始まる　(= r[i]の時 rval)
 llim < a < ulim の時
    今見ている区間(r[i] --- r[i+1])は a + (これまでの区間の移動量)から始まる
 
 この　la と uaのlimは区間の移動に伴って上限または下限で押しつぶされることによって変化を生じる
 
 よって実際にシミュレーションしつつクエリに答える。という方法を取ることによってACできる
 
 ================================================================
 */

void solve(){
    ll X,K; cin >> X >> K;
    vector<ll> R(K+2);
    R[0] = 0;
    for(int i = 1; i <= K;i++) cin >> R[i];
    R[K+1] = LINF;
    
    pll la,ua;  // { lim , val }
    ua = {X,X};
    la = {0,0};
    int Q; cin >> Q;
    int idx = 0;
    ll sum = 0;
    while(Q--){
        ll t,a; cin >> t >> a;
        while(R[idx+1] <= t){
            ll D = R[idx+1] - R[idx];
            if(idx%2 == 0){ // dec
                sum -= D;
                ua = {ua.first,max(ua.second-D,0LL)};
                la = {min(la.first+max(0LL,D-la.second),X),max(la.second-D,0LL)};
            }else{ // inc
                sum += D;
                ua = {max(ua.first-max(0LL,ua.second-(X-D)),0LL),min(ua.second+D,X)};
                la = {la.first,min(la.second+D,X)};
            }
            idx++;
        }
        
        ll nowa = a;
        if(la.first < a && a < ua.first){
            nowa = a + sum;
        }
        if(a <= la.first){
            nowa = la.second;
        }
        if(a >= ua.first){
            nowa = ua.second;
        }
        
        ll D = t - R[idx];
        if(idx%2==0){ // dec
            cout << max(0LL,nowa-D) << endl;
        }else{ // inc
            cout << min(X,nowa+D) << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
