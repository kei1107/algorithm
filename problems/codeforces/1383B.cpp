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
 <url:https://codeforces.com/problemset/problem/1383/B>
 問題文============================================================
 B. GameGame
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<ll> a(n); for(auto& in:a) cin >> in;
    
//    cout << " ======= " << endl;
//    cout << a << endl;
//    for(int i = 0; i < n;i++){
//        cout << a[i] << " : " << bitset<8>(a[i]) << endl;
//    }

    ll XOR = 0;
    for(auto v:a) XOR ^= v;
    
    if(XOR == 0){
        return "DRAW";
    }
    
    for(int i = 30; i >= 0; i--){
        if((XOR>>i)&1){
            int num = 0;
            for(int j = 0; j < n;j++){
                if((a[j]>>i)&1) num++;
            }
            int left = n - num;
            if(num%4 == 3 && left%2 == 0) return "LOSE";
            else return "WIN";
        }
    }
    return "DRAW";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t; while(t--)
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}