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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string s; cin >> s;
    int n = (int)s.length();

    auto cusum = make_v<int>(n+1,26);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < 26;j++){
            cusum[i+1][j] = cusum[i][j];
        }
        cusum[i+1][s[i]-'a']++;
    }

    int q; cin >> q;
    while(q--){
        ll l,r; cin >> l >> r;
        if(l == r){
            cout << "Yes" << endl;
            continue;
        }
        vector<pair<char,int>> alpha;
        for(int i = 0; i < 26;i++){
            if(cusum[r][i]-cusum[l-1][i] != 0){
                alpha.emplace_back('a'+i,cusum[r][i]-cusum[l-1][i]);
            }
        }

        // cout << alpha << endl;
        if(alpha.size() == 1){
            cout << "No" << endl;
        }else{
            if(s[l-1] != s[r-1]){
                cout << "Yes" << endl;
                continue;
            }
            if(alpha.size() >= 3){
                cout << "Yes" << endl;
                continue;
            }
            cout << "No" << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
