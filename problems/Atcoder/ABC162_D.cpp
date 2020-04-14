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
    ll N; cin >> N;
    string S; cin >> S;
    vector<vector<ll>> RGB(3);
    for(ll i = 0; i < N;i++){
        if(S[i] == 'R'){
            RGB[0].emplace_back(i);
            S[i] = 0;
        }
        if(S[i] == 'G'){
            RGB[1].emplace_back(i);
            S[i] = 1;
        }
        if(S[i] == 'B'){
            RGB[2].emplace_back(i);
            S[i] = 2;
        }
    }

    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            if(S[i] == S[j]) continue;
            set<ll> st{S[i],S[j]};

            for(int k = 0; k < 3;k++){
                if(st.find(k) != st.end()) continue;

                ll L = upper_bound(RGB[k].begin(),RGB[k].end(),j) - RGB[k].begin();

                auto it = lower_bound(RGB[k].begin(),RGB[k].end(),j+(j-i));

                bool flag = false;
                if(it != RGB[k].end()){
                    if(*it == j+(j-i)){
                        flag = true;
                    }
                }
                ll D = RGB[k].size() - L;
                if(flag) D--;
                res += D;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
