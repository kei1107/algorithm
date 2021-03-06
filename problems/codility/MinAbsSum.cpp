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


int dp[2000001];
int solution(vector<int> &A){
    int ret = INT_MAX;
 
    map<int,int> mp;
    for(auto& a:A){ a = abs(a); mp[a]++; }
    int S = accumulate(A.begin(),A.end(),0);
    
    fill(dp,dp+S+1,-1);
    dp[0] = 0;
    for(int i = 0; i <= 100; i++){
        int mpi = mp[i];
        if(mpi == 0) continue;
        for(int j = 0; j <= S;j++){
            if(dp[j] >= 0){
                dp[j] = mpi;
            }else if(j >= i && dp[j-i] > 0){
                dp[j] = dp[j-i] - 1;
            }
        }
    }
    for(int i = 0; i <= S/2+1;i++) if(dp[i]>=0) ret = min(ret,abs(2*i-S));
    return ret;
}
