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
 <url:https://codeforces.com/problemset/problem/1370/E>
 問題文============================================================
 E. Binary Subsequence Rotation
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    
    if(count(s.begin(),s.end(),'0') != count(t.begin(),t.end(),'0')) return -1;
    
    set<int> e1,e2;
    for(int i = 0; i < n;i++){
        if(s[i] == t[i]) continue;
        if(s[i] == '0') e1.emplace(i);
        else e2.emplace(i);
    }
    
//    for(auto e:e1) cout << e << " "; cout << endl;
//    for(auto e:e2) cout << e << " "; cout << endl;
    
    while(e1.size() || e2.size()){
        
        if(e1.size() && e2.size()){
            
            int idx = -1;
            int status = -1;
            
            if(*e1.begin() < *e2.begin()){
                idx = *e1.begin();
                e1.erase(e1.begin());
                status = 0;
            }else{
                idx = *e2.begin();
                e2.erase(e2.begin());
                status = 1;
            }
            
            while(true){
                // cout << idx << endl;
                if(status){
                    auto it = e1.upper_bound(idx);
                    if(it == e1.end()) break;
                    idx = *it;
                    e1.erase(it);
                    status = 0;
                }else{
                    auto it = e2.upper_bound(idx);
                    if(it == e2.end()) break;
                    idx = *it;
                    e2.erase(it);
                    status = 1;
                }
            }
            res++;
        }else if(e1.size()){
            res += e1.size();
            e1.clear();
        }else{
            res += e2.size();
            e2.clear();
        }
//        cout << " ---- " << endl;
//        for(auto e:e1) cout << e << " "; cout << endl;
//        for(auto e:e2) cout << e << " "; cout << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
