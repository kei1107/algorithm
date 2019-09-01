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
 <url:https://atcoder.jp/contests/abc139/tasks/abc139_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 最悪をした。定数倍高速化しつつ貪欲にペア作っていけば間に合う(1762ms)

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<vector<int>> A(N,vector<int>(N-1));
    for(auto& vec:A) for(auto& in:vec){ cin >> in; in--; }

    for(int i = 0; i < N;i++){
        reverse(A[i].begin(),A[i].end());
    }

    vector<int> checked(N,-1);
    while(true){
        bool update = false;
        for(int i = 0; i < N;i++){
            if(checked[i] == res) continue;
            checked[i] = res;
            if(A[i].empty()) continue;
            
            int t = A[i].back();

            if(checked[t] == res) continue;
            if(A[t].empty()) return -1;

            if(A[t].back() == i){
                update = true;
                checked[t] = res;

                A[i].pop_back();
                A[t].pop_back();
            }

        }
        if(!update){
            for(int i = 0; i < N;i++){
                if(A[i].empty()) continue;
                return -1;
            }
            break;
        }
        res++;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<int>() << endl;
    return 0;
}
