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
 <url:https://codeforces.com/problemset/problem/1294/F>
 問題文============================================================
 F. Three Paths on a Tree
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<vector<int>> T(n);
    for(int i = 0; i < n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        
        T[a].emplace_back(b);
        T[b].emplace_back(a);
    }
    
    vector<pii> ps1(n);
    vector<int> ps2(n);
    vector<int> val1(n,-1),val2(n,-1); // val1 : two point , val2 : one point
    
    function<void(int,int)> dfs = [&](int n,int pre){
        vector<pii> tmp;
        for(auto next:T[n]){
            if(next == pre) continue;
            dfs(next,n);
            if(val1[n] < val1[next] + 1){
                val1[n] = val1[next] + 1;
                ps1[n] = ps1[next];
            }
            tmp.emplace_back(val2[next]+1,ps2[next]);
        }
        sort(tmp.rbegin(),tmp.rend());
        
        if(tmp.size() >= 2){
            if(val1[n] < tmp[0].first + tmp[1].first){
                val1[n] = tmp[0].first + tmp[1].first;
                ps1[n] = make_pair(tmp[0].second,tmp[1].second);
            }
        }
        if(tmp.size() >= 1){
            if(val2[n] < tmp[0].first){
                val2[n] = tmp[0].first;
                ps2[n] = tmp[0].second;
            }
        }
        
        if(val1[n] == -1){
            val1[n] = 0;
            ps1[n] = pii(n,n);
        }
        if(val2[n] == -1){
            val2[n] = 0;
            ps2[n] = n;
        }
    };
    dfs(0,-1);
    
//    cout << ps1 << endl;
//    cout << val1 << endl;
//
//    cout << ps2 << endl;
//    cout << val2 << endl;
    
    vector<pii> ans(n);
    vector<int> ans_val(n);
//    ans[0] = ps1[0];
//    ans_val[0] = val1[0];
    
    function<void(int,int,pii,int,int,int)> dfs2 = [&](
        int n,int par,pii p1,int v1,int p2,int v2
        ){
        
        using Item1 = tuple<int,pii,int>;
        vector<Item1> tmp1;
        
        using Item2 = tuple<int,int,int>;
        vector<Item2> tmp2;
        
        tmp1.emplace_back(v1+1,p1,par);
        tmp2.emplace_back(v2+1,p2,par);
        
        for(auto next:T[n]){
            if(next == par) continue;
            tmp1.emplace_back(val1[next]+1,ps1[next],next);
            tmp2.emplace_back(val2[next]+1,ps2[next],next);
        }
        sort(tmp1.rbegin(),tmp1.rend());
        sort(tmp2.rbegin(),tmp2.rend());
        
        {// update
            
//            cout << " ==== " << endl;
//            cout << n << endl;
//            cout << get<0>(tmp1[0]) << " " << get<1>(tmp1[0]) << endl;
//            for(auto item:tmp1){
//                cout << get<0>(item) << " x " << get<1>(item) << " x " <<get<2>(item) << endl;
//            }
            if(ans_val[n] < get<0>(tmp1[0])){
                ans_val[n] = get<0>(tmp1[0]);
                ans[n] = get<1>(tmp1[0]);
            }
            
            if(tmp2.size() >= 2){
                if(ans_val[n] < get<0>(tmp2[0]) + get<0>(tmp2[1])){
                    ans_val[n] = get<0>(tmp2[0]) + get<0>(tmp2[1]);
                    ans[n] = make_pair(get<1>(tmp2[0]),get<1>(tmp2[1]));
                }
            }
        }
        
        for(auto next:T[n]){
            if(next == par) continue;
            
            pii next_p1 = pii(-1,-1);
            int next_v1 = -1;
            int next_p2 = -1;
            int next_v2 = -1;
            
            { // p1,v1
                for(int j = 0; j <= min(1,(int)tmp1.size());j++){
                    if(get<2>(tmp1[j]) == next) continue;
                    
                    next_v1 = get<0>(tmp1[j]);
                    next_p1 = get<1>(tmp1[j]);
                    
                    break;
                }
                // p2,v2から2個とる
                vector<int> tv,tp;
                for(int j = 0; j < min(3,(int)tmp2.size());j++){
                    if(get<2>(tmp2[j]) == next) continue;

                    tv.emplace_back(get<0>(tmp2[j]));
                    tp.emplace_back(get<1>(tmp2[j]));
                }
                if(tv.size() >= 2){
                    if(next_v1 < tv[0] + tv[1]){
                        next_v1 = tv[0] + tv[1];
                        next_p1 = pii(tp[0],tp[1]);
                    }
                }
            }
            { // p2,v2
                for(int j = 0; j <= min(1,(int)tmp2.size()); j++){
                    if(get<2>(tmp2[j]) == next) continue;
                    
                    next_v2 = get<0>(tmp2[j]);
                    next_p2 = get<1>(tmp2[j]);
                    
                    break;
                }
            }
            
            // cout << next_p1 << " " << next_v1 << " " << next_p2 << " " << next_v2 << endl;
            dfs2(next,n,next_p1,next_v1,next_p2,next_v2);
        }
    };
    dfs2(0,-1,pii(0,0),-1,0,-1);
    
//    cout << ans << endl;
//    cout << ans_val << endl;
    
    int max_val = *max_element(ans_val.begin(), ans_val.end());
    for(int i = 0; i < n;i++){
        if(ans_val[i] == max_val){
            cout << ans_val[i] << endl;
            set<int> id;
            id.emplace(i+1);
            id.emplace(ans[i].first+1);
            id.emplace(ans[i].second+1);
//            cout << i+1 << " " << ans[i].first+1 << " " << ans[i].second+1 << endl;
            
            for(int j = 0; j < n;j++){
                if(id.size() == 3) break;
                id.emplace(j+1);
            }
            for(auto v:id) cout << v << " "; cout << endl;
            break;
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
