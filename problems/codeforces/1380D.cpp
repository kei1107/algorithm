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
 <url:https://codeforces.com/problemset/problem/1380/D>
 問題文============================================================
 D. Berserk And Fireball
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    ll x,k,y; cin >> x >> k >> y;
    vector<int> a(n);
    for(auto& in:a){ cin >> in; in--; }
    vector<int> b(m);
    for(auto& in:b){ cin >> in; in--; }
    
    vector<int> id(n);
    for(int i = 0; i < n;i++){
        id[a[i]] = i;
    }
    
    for(int i = 1; i < m;i++){
        if(id[b[i-1]] > id[b[i]]) return -1;
    }
    
    
    
    auto calc = [&](int l,int r){
        if(l > r) return true;
        
        int maxv = *max_element(a.begin()+l, a.begin()+r+1);
        int len = r-l+1;
        
        bool ok = false;
        if(l-1 >= 0 && a[l-1] > maxv){
            ok = true;
        }
        if(r+1 <= n-1 && a[r+1] > maxv){
            ok = true;
        }
        
        if(len < k && !ok) return false; // 無理
        
        vector<ll> dp(len+1,LINF);
        dp[0] = 0;
        for(int i = 0; i < len;i++){
            // ファイアーボール
            if(i+k<=len){
                dp[i+k] = min(dp[i+k],dp[i]+x);
            }
            // ベルセルク
            if(a[i+l] == maxv && !ok){
                // pass
                // ベルセルクで消せない。ファイアーボール必須
            }else{
                dp[i+1] = min(dp[i+1],dp[i]+y);
            }
        }
        
        res += dp[len];
        return true;
    };
    int l = -1;
    int bid = 0;
    for(int r = 0; r < n;r++){
        if(b[bid] != a[r]) continue;
        
        if(!calc(l+1,r-1)){
            return -1;
        }
        
        l = r;
        bid++;
        if(bid == m) break;
    }
    if(!calc(l+1,n-1)) return -1;
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
