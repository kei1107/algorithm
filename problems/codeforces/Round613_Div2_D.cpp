//#include "bits/stdc++.h"
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//const int INF = 1e9;
//const ll LINF = 1e18;
//inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
//inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
//template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
//template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
//template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
//template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
//template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
//template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
//template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
//template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
///*
// <url:>
// 問題文============================================================
// =================================================================
// 解説=============================================================
// ================================================================
// */
//
//template<class Type>
//Type solve(Type res = Type()){
//    ll n; cin >> n;
//    vector<ll> a(n); for(auto& in:a) cin >> in;
//
//    sort(a.begin(),a.end());
//
//    res = *max_element(a.begin(), a.end());
//
//
//    function<void(ll,ll,vector<ll>&)> dfs = [&](ll b,ll S,vector<ll>& a){
//        vector<ll> L,R;
//        if(b == -1){
//            res = min(res,S);
//            return;
//        }
//
//        for(int i = 0; i < (int)a.size(); i++){
//            if((a[i]>>b)&1){
//                L.push_back(a[i]-(1LL<<b));
//            }else{
//                R.push_back(a[i]);
//            }
//        }
//
//        if(L.size() && R.empty()){
//            dfs(b-1,S,L);
//        }else if(L.empty() && R.size()){
//            dfs(b-1,S,R);
//        }else{
//            // 1
//            dfs(b-1,S+(1LL<<b),L);
//            // 0
//            dfs(b-1,S+(1LL<<b),R);
//        }
//    };
//    dfs(31,0,a);
//
//    return res;
//}
//int main(void) {
//    cin.tie(0); ios_base::sync_with_stdio(false);
//    // solve(0);
//    cout << fixed << setprecision(15) << solve<ll>() << endl;
//    return 0;
//}
