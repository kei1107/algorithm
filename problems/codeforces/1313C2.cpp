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
 <url:https://codeforces.com/problemset/problem/1313/C2>
 問題文============================================================
 C2. Skyscrapers (hard version)
 =================================================================
 解説=============================================================
 ================================================================
 */

struct Rectangle {
    ll h;
    ll p;  // position from left
    Rectangle(ll h,ll p): h(h),p(p){}
};

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<ll> m(n); for(auto& in:m) cin >> in;
    
    // ldp[i] := i番目の要素から左肩下がりとなる場合に得られる最大値
    // rdp[i] := i番目の要素から右肩下がりとなる場合に得られる最大値
    vector<ll> ldp(n+1),rdp(n+1);
    
    auto calc_dp = [&](vector<ll>& dp){
        stack<Rectangle> S;
        
        Rectangle banpei(0,0);
        S.push(banpei);
        
        for (int i = 0; i < n; i++) {
            Rectangle rect(m[i],i+1);

            if(S.top().h < rect.h){
                S.push(rect);
                dp[i+1] = dp[i] + rect.h;
            }else{
                while (S.top().h >= rect.h) {
                    S.pop();
                }
                dp[i+1] = dp[S.top().p] + (i-S.top().p+1) * rect.h;
                S.push(rect);
            }
        }
        // cout << dp << endl;
    };
    calc_dp(ldp); // calc ldp
    
    reverse(m.begin(),m.end());
    calc_dp(rdp); // calc rdp
    
    // calc ans
    reverse(m.begin(),m.end());
    ll max_v = -1;
    for(int i = 0; i < n; i++){
        ll val = ldp[i+1]+rdp[n-i]-m[i];
        max_v = max(max_v,val);
        
        // cout << i << " " << val << endl;
    }
    
    res.resize(n);
    for(int i = 0; i < n;i++){
        ll val = ldp[i+1]+rdp[n-i]-m[i];
        if(val == max_v){
            
            res[i] = m[i];
            for(int j = i-1; j >= 0; j--){
                res[j] = min(m[j],res[j+1]);
            }
            for(int j = i+1; j < n; j++){
                res[j] = min(m[j],res[j-1]);
            }
            break;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<ll>>() << endl;
    return 0;
}
