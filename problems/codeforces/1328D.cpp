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
 <url:https://codeforces.com/problemset/problem/1328/D>
 問題文============================================================
 D. Carousel
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> a(n); for(auto& in:a) cin >> in;
    
    set<int> st;
    
    st = set<int>(a.begin(),a.end());
    if(st.size() == 1){
        cout << 1 << endl;
        cout << vector<int>(n,1) << endl;
    }else{
        if(n%2 == 0){
            cout << 2 << endl;
            for(int i = 0; i < n;i++){
                cout << (i%2 + 1) << " ";
            }cout << endl;
        }else{
            bool ok = false;
            a.emplace_back(a.front());
            for(int i = 0; i < n;i++){
                if(a[i] == a[i+1]) ok = true;
            }
            if(ok){
                cout << 2 << endl;
                
                int now = 0;
                bool updated = false;
                for(int i = 0; i < n;i++){
                    if(!updated && a[i] == a[i+1]){
                        updated = true;
                        cout << now+1 << " ";
                        if(i+1<n) cout << now+1 << " ";
                        i++;
                    }else{
                        cout << now+1 << " ";
                    }
                    now = !now;
                }cout << endl;
            }else{
                cout << 3 << endl;
                for(int i = 0; i < n-1;i++){
                    cout << (i%2 + 1) << " ";
                }cout << 3 << endl;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t; while(t--) solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
