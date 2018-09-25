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
 <url:https://yukicoder.me/problems/no/165>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 4点の全探索するO(N^4)で間に合わない
 
 よって、もう少し工夫する
 問題となる四角形は必ずX軸若しくはY軸に平行になるため
 X軸の2点 or Y軸の2点を全探索することを考える(今回はY軸)
 
 とすると [ylower,yupper]の範囲にあって、
 任意の[xlower,xupper]で条件を満たす四角形を作ればいいことになる。
 ここで、得点がB以下であれば、xupperは大きくしていきたいので
 尺取り法でO(N)で [ylower,yupper]を固定した時の最大の点数がわかる
 
 よって O(N^3）で解ける
 ================================================================
 */

struct Point{
    ll x,y,p;
    Point(ll x = 0,ll y = 0,ll p = 0):x(x),y(y),p(p){}
    bool operator < (const Point& o) const{
        return x<o.x;
    }
};
ll solve(){
    ll res = 0;
    ll N,B; cin >> N >> B;
    vector<Point> P(N);
    vector<ll> ys(N);
    for(int i = 0; i < N;i++){
        ll x,y,p; cin >> x >> y >> p;
        P[i] = Point(x,y,p);
        ys[i] = y;
    }
    sort(P.begin(),P.end());
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    
    P.push_back(Point(LINF,LINF,LINF));
    for(int i = 0; i < ys.size();i++){
        for(int j = i; j < ys.size(); j++){
            ll upper = ys[j],lower = ys[i];
            ll l = 0, r = 0;
            ll sum  = 0;
            ll pcnt = 0;
            
            while(true){
                while(r < N && sum <= B){
                    res = max(res,pcnt);
                    while(true){
                        if(lower <= P[r].y && P[r].y <= upper){ sum += P[r].p; pcnt++;}
                        r++;
                        if(P[r-1].x != P[r].x) break;
                    }
                }
                if(sum <= B) break;
                while(true){
                    if(lower <= P[l].y && P[l].y <= upper){ sum -= P[l].p; pcnt--;}
                    l++;
                    if(P[l-1].x != P[l].x) break;
                }
            }
            if(sum <= B) res = max(res,pcnt);
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
