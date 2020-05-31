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
 <url:https://codeforces.com/problemset/problem/1333/D>
 問題文============================================================
 D. Challenges in school №41
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    for(auto& c:s) c = (c=='L')?0:1;
    
    int min_move = 0,max_move = 0;
    int cnt = 0;
    int pre = -1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 0){
            cnt++;
        }else{
            max_move += cnt;
            min_move = max(cnt,pre+1);
            pre = min_move;
        }
    }
    if(k < min_move || k > max_move){
        cout << -1 << endl;
        return 0;
    }
    
    bool flag = false;
    vector<int> steps;
    for(int i = 0; i < k;i++){
        if(flag){
            int val = steps.back();
            steps.pop_back();
            cout << "1 " << val+1;
            s[val  ] = 0;
            s[val+1] = 1;
            if(val > 0 && s[val-1] == 1){
                steps.push_back(val-1);
            }
            if(val + 2 < n && s[val+2] == 0){
                steps.push_back(val+1);
            }
        }else{
            vector<int> tsteps;
            for(int i = 0; i < n-1;i++){
                if(s[i] == 1 && s[i+1] == 0) tsteps.push_back(i);
            }
            cout << min((int)(tsteps.size()),max_move-k+i+1) << " ";
            
            int cur = 0;
            while(k - i - 1 < max_move && cur < tsteps.size()){
                cout << tsteps[cur] + 1 << " ";
                s[tsteps[cur]] = 0;
                s[tsteps[cur]+1] = 1;
                cur++;
                max_move--;
            }
            if(max_move == k - i - 1){
                flag = true;
                vector<int> ttsteps;
                for(int i = 0; i < n-1;i++){
                    if(s[i] == 1 && s[i+1] == 0) ttsteps.push_back(i);
                }
                steps = ttsteps;
            }
        }
        cout << "\n";
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
