#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}

/*
 <url:https://onlinejudge.u-aizu.ac.jp/problems/2749>
 問題文============================================================
 =================================================================
 解説=============================================================
 この問題は、そのままだと布団の数が増減するため考えるのが難しい。
 しかし、布団はいちど並べ方を定めたら、取り方の順番さえ守れば自由に数を増減させることができる。
 
 ここで、あらかじめぬくもり需要をソートしておくと、布団の数はそのままにするか布団を増やすか
 の２択しか考えなくてよくなる。
 
 これは、自由に順番に布団を追加していく問題として考えることができ、bitDPを用いて解くことができる
 
 dp[i日目][追加した布団の状態] := 最小の不快度
 ================================================================
 */
ll dp[101][1<<17];
ll val[1<<17];
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N,M;
    while(cin >> N >> M,N){
        fill(*dp,*dp+101*(1<<17),LLONG_MAX);
        fill(val,val+(1<<17),0);
        
        vector<int> s(N),d(M);
        for(auto& in:s) cin >> in;
        for(auto& in:d) cin >> in;
        
        sort(s.begin(),s.end());
        sort(d.begin(),d.end());
        
        for(int i = 0; i < (1<<N);i++){
            ll v = 0;
            for(int j = 0; j < N;j++){
                if((i>>j)&1){
                    v += s[j];
                }
            }
            val[i] = v;
        }
        
        dp[0][0] = 0;
        for(int i = 0; i < M;i++){
            for(int j = 0; j < (1<<N);j++){
                if(dp[i][j] == LLONG_MAX) continue;
                
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + abs(val[j]-d[i]));
                
                for(int k = 0; k < N;k++){
                    if((j>>k)&1) continue;
                    dp[i+1][j|(1<<k)] = min(dp[i+1][j|(1<<k)],dp[i][j]+abs(val[j]-d[i]));
                    
                    dp[i][j|(1<<k)] = min(dp[i][j|(1<<k)],dp[i][j]);
                }
            }
        }
        cout << *min_element(dp[M], dp[M]+(1<<17)) << endl;
    }
    return 0;
}
