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
 <url:https://codeforces.com/problemset/problem/1367/E>
 問題文============================================================
 E. Necklace Assembly
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    vector<int> alpha(26);
    set<char> st;
    for(auto c:s){
        alpha[c-'a']++;
        st.emplace(c);
    }
    sort(alpha.begin(),alpha.end());
    for(int x = n; x > 0; x--){
        if(k%x == 0){
            res = x;
            break;
        }else{
            int y = k%x;
            
            ll GCD = gcd(x,y);
            if(GCD != 1){
                ll need = x/GCD;
                ll cnt = x/need;
                auto beta = alpha;
                
                while(beta.size()){
                    if(cnt){
                        if(beta.back() >= need){
                            cnt--;
                            *beta.rbegin() -= need;
                        }else{
                            beta.pop_back();
                        }
                    }else{
                        break;
                    }
                }
                if(cnt == 0){
                    res = x;
                    break;
                }
            }else{
                if(alpha.back() >= x){
                    res = x;
                    break;
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t; while(t--) cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
