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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/problemset/problem/1428/D>
 問題文============================================================
 D. Bouncing Boomerangs
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> a(n); for(auto& in:a) cin >> in;
    vector<pii> ans;
    stack<int> st,st2;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == 1){
            st.emplace(i);
            ans.emplace_back(i,i);
        }if(a[i] == 2){
            if(st.empty()){
                cout << -1 << endl;
                return res;
            }
            int p = st.top(); st.pop();

            ans.emplace_back(p,i);
            st2.emplace(i);
        }else if(a[i] == 3){
            if(st.empty() && st2.empty()){
                cout << -1 << endl;
                return res;
            }
            ans.emplace_back(i,i);
            if(!st2.empty()){
                int p = st2.top(); st2.pop();
                ans.emplace_back(i,p);
            }else {
                int p = st.top(); st.pop();
                ans.emplace_back(i,p);
            }
            st2.emplace(i);
        }
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;
    for(auto a:ans) cout << a.first+1 << " " << a.second+1 << endl;

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}