#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/contest/1203/problem/F1>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,r; cin >> n >> r;
    
    vector<pii> pos,neg;
    for(int i = 0; i < n;i++){
        int a,b; cin >> a >> b;
        if(b >= 0) pos.emplace_back(a,b);
        else neg.emplace_back(a,b);
    }
    
    int cnt = 0;
    sort(pos.begin(),pos.end());
    for(auto p:pos){
        if(r >= p.first){
            cnt++;
            r += p.second;
        }
    }
    
    sort(neg.begin(),neg.end(),[](const pii& l,const pii& r){
        return l.first+l.second > r.first + r.second;
    });
    
    // cout << ab << endl;
    
    
    auto dp = make_v<int>(neg.size()+1,60001);
    fill_v(dp,-1);
    dp[0][r] = cnt;
    for(int i = 0; i < (int)neg.size();i++){
        for(int j = 0; j <= 60000; j++){
            if(dp[i][j] == -1) continue;
            // 使わない
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            
            if(neg[i].first <= j && j+neg[i].second >= 0){
                dp[i+1][j+neg[i].second] = max(dp[i+1][j+neg[i].second],dp[i][j]+1);
            }
        }
    }
    
    res = *max_element(dp[neg.size()].begin(),dp[neg.size()].end()) == n ? "YES" : "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
