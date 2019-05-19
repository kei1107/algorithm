#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://onlinejudge.u-aizu.ac.jp/problems/2824>
 問題文============================================================
 =================================================================
 解説=============================================================
 各時間tついて順番に見ていく。
 地点Lが濡れるようであれば t + D秒まで濡れるので、
 この時、現在時間以降で最大何秒目まで濡れているかの変数を1個持って使いまわしていくことで
 濡れているかどうか判定できる。
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int T,D,L;
    while(cin >> T >> D >> L,T){
        vector<int> x(T); for(auto& in:x) cin >> in;
        
        int ans = 0;
        int nure = -1;
        for(int i = 0; i < T; i++){
            if(nure >= i) ans++;
            if(x[i] >= L){
                nure = i+D;
            }
        }
        cout << ans << endl;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
