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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/problemset/problem/1494/C>
 問題文============================================================
 C. 1D Sokoban
 =================================================================
 解説=============================================================
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    for(auto& in:a) cin>> in;
    for(auto& in:b) cin >> in;

    auto calc = [](vector<int>& ta,vector<int>& tb){
        sort(ta.begin(),ta.end());
        sort(tb.begin(),tb.end());

        vector<int> match_pos;
        set<int> st;
        for(auto a:ta) st.emplace(a);
        for(auto b:tb) if(st.count(b)) match_pos.emplace_back(b);

        int T = (int)match_pos.size();

        int pre = -1;
        int cnt = 0;

        // cout << ta << endl;
        // cout << tb << endl;
        // cout << match_pos << endl;
        for(int i = 0; i < (int)tb.size(); i++){
            int b = tb[i];
            if(b == pre + 1){
                cnt++;
            }else{
                cnt = 1;
            }
            pre = b;
            int a_cnt = distance(ta.begin(),lower_bound(ta.begin(),ta.end(),b));

            int get_cnt = distance(
                upper_bound(tb.begin(),tb.end(),b-a_cnt),
                upper_bound(tb.begin(),tb.end(),b));

            T = max(T,get_cnt + (int)distance(upper_bound(match_pos.begin(),match_pos.end(),b),match_pos.end()));

            // cout << b << " : " << cnt << " " << a_cnt << " " << (int)distance(upper_bound(match_pos.begin(),match_pos.end(),b),match_pos.end()) << endl;
        }

        return T;
    };

    {
        vector<int> ma,mb;
        for(int i = 0; i < n;i++){
            if(a[i] < 0){
                ma.emplace_back(-a[i]);
            }
        }
        for(int i = 0; i < m; i++){
            if(b[i] < 0){
                mb.emplace_back(-b[i]);
            }
        }
        int ret = calc(ma,mb);
        cerr << "minus : " << ret << endl;
        res += ret;
    }
    {
        vector<int> pa,pb;
        for(int i = 0; i < n;i++){
            if(a[i] > 0){
                pa.emplace_back(a[i]);
            }
        }
        for(int i = 0; i < m; i++){
            if(b[i] > 0){
                pb.emplace_back(b[i]);
            }
        }
        int ret = calc(pa,pb);
        cerr << "plus : " << ret << endl;
        res += ret;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    int t; cin >> t; while(t--)
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}