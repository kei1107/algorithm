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
 <url:https://codeforces.com/problemset/problem/1311/D>
 問題文============================================================
 D. Three Integers
 =================================================================
 解説=============================================================
 ================================================================
 */

// nの約数を列挙する
vector<int> getdivisor(int n){
    vector<int> res;
    for(int i = 1; i*i <= n;i++){
        if(n%i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

template<class Type>
Type solve(Type res = Type()){
    int a,b,c; cin >> a >> b >> c;
    int min_cost = INF;
    vector<int> ans{};
    
    for(int B = 1; B <= 20000; B++){
        int min_a = INF;
        int a_val = -1;
        for(auto cand_a:getdivisor(B)){
            if(min_a > abs(cand_a-a)){
                min_a = abs(cand_a-a);
                a_val = cand_a;
            }
        }
        
        int min_c = INF;
        int c_val = -1;
        vector<int> cand_cs = {c/B*B,(c+B-1)/B*B};
        for(auto cand_c:cand_cs){
            if(min_c > abs(cand_c-c)){
                min_c = abs(cand_c-c);
                c_val = cand_c;
            }
        }
        
        if(min_a + min_c + abs(B-b) < min_cost){
            min_cost = min_a + min_c + abs(B-b);
            ans = vector<int>{a_val,B,c_val};
        }
    }
    cout << min_cost << endl;
    cout << ans << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t; while(t--) solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
