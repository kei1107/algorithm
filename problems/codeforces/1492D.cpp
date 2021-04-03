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
 <url:https://codeforces.com/problemset/problem/1492/D>
 問題文============================================================
 D. Genius's Gambit
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
void solve()
{
    string x="1",y="1";
    b--;
    
    x+='1';
    y+='0';
    a--,b--;
    
    for(int i=1;i<k;i++)
    {
        if(a>0)
        {
            a--;
            x+='0';
            y+='0';
        }
        else if(b>0)
        {
            b--;
            x+='1';
            y+='1';
        }
    }
    
    x+='0';
    y+='1';
    
    while(a--)
    {
        x+='0';
        y+='0';
    }
    while(b--)
    {
        x+='1';
        y+='1';
    }
    
    cout<<"Yes\n"<<x<<'\n'<<y<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

*/

template<class Type>
Type solve(Type res = Type()){
    ll a,b,k; cin >> a >> b >> k;

    if(k == 0){
            cout << "Yes" << endl;
            cout << string(b,'1') + string(a,'0') << endl;
            cout << string(b,'1') + string(a,'0') << endl;
    }else if(a == 0 || b == 1){
        if(k != 0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
            cout << string(b,'1') + string(a,'0') << endl;
            cout << string(b,'1') + string(a,'0') << endl;
        }
    }else{
        if(k <= a + b - 2){
            cout << "Yes" << endl;

            string s = "1",t = "1";
            b--;
            s += "1"; t += "0";
            a--; b--;

            for(int i = 1; i < k; i++){
                if(a > 0){
                    a--;
                    s += "0";
                    t += "0";
                }else if(b > 0){
                    b--;
                    s += "1";
                    t += "1";
                }
            }
            s += "0";
            t += "1";

            while(a--){
                s+="0";
                t+="0";
            }
            while(b--){
                s+="1";
                t+="1";
            }
            cout << s << endl;
            cout << t << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}