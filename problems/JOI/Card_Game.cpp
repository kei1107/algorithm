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
 <url:https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0523?year=2008>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n;
    while(cin >> n,n){
        vector<int> tarou(n); for(auto& in:tarou) cin >> in;
        sort(tarou.begin(),tarou.end());
        vector<int> hanako;
        for(int i = 1; i <= 2*n;i++){
            if(i == *lower_bound(tarou.begin(),tarou.end(),i)) continue;
            hanako.push_back(i);
        }
        
        int now_card = -1;
        bool turn = false;
        while(tarou.size() && hanako.size()){
            if(!turn){
                auto it = lower_bound(tarou.begin(),tarou.end(),now_card);
                if(it == tarou.end()){
                    now_card = -1;
                }else{
                    
                    now_card = *it;
                    
                    tarou.erase(it);
                }
            }else{
                auto it = lower_bound(hanako.begin(),hanako.end(),now_card);
                if(it == hanako.end()){
                    now_card = -1;
                }else{
                    
                    now_card = *it;
                    hanako.erase(it);
                }
            }
            turn = !turn;
        }
        cout << hanako.size() << endl;
        cout << tarou.size() << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
