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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_k>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    using Item = tuple<int,int,ll>;
    vector<Item> Tasks(N);
    for(int i = 0; i < N;i++){
        int D,C; ll S; cin >> D >> C >> S;
        Tasks[i] = Item(D,C,S);
    }
    sort(Tasks.begin(),Tasks.end());

    auto dp = make_v<ll>(5001,N+1);
    for(int i = 0; i < 5000; i++){
        for(int j = 0; j <= N;j++){
            // なにもせず１日すごす
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);

            if(j < N){
                // 今見ているタスクを放棄する
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]);

                // 今見ているタスクが実行可能か見る
                int D,C; ll S;
                tie(D,C,S) = Tasks[j];
                if(i+C <= D){
                    dp[i+C][j+1] = max(dp[i+C][j+1],dp[i][j] + S);
                }
            }
        }
    }
    res = dp[5000][N];
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}