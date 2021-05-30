#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_z>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<vector<int>> G(N+1);
    for(int i = 0; i < N-1;i++){
        int A,B; cin >> A >> B;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    vector<int> ans1,ans2;
    auto dfs = [&](auto self,int n,int pre,int turn,bool flag) -> void{
        if(turn){
            (flag?ans1:ans2).emplace_back(n);
        }
        for(auto next:G[n]){
            if(next == pre) continue;
            self(self,next,n,!turn,flag);
        }
    };

    dfs(dfs,1,-1,0,0);
    dfs(dfs,1,-1,1,1);

    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end());

    if((ll)ans1.size() >= N/2){
        res = Type(ans1.begin(),ans1.begin()+N/2);
    }
    if((ll)ans2.size() >= N/2){
        res = Type(ans2.begin(),ans2.begin()+N/2);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<vector<ll>>() << endl;
    return 0;
}