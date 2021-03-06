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
 <url:https://codeforces.com/problemset/problem/1344/B>
 問題文============================================================
 B. Monopole Magnets
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    auto masu = make_v<char>(n,m);
    auto white = make_v<bool>(n,m);
    for(auto& vec: masu) for(auto& in:vec) cin >> in;
    
    vector<int> yoko = vector<int>(n);
    vector<int> tate = vector<int>(m);
    
    for(int i = 0; i < n;i++){
        int pre_c = 0;
        int cnt = 0;
        for(int j = 0; j < m;j++){
            if(masu[i][j] == '#'){
                yoko[i]++;
                if(pre_c == 0) cnt++;
                pre_c = 1;
            }else{
                pre_c = 0;
            }
            if(cnt >= 2) return -1;
        }
    }
    for(int j = 0; j < m;j++){
        int pre_c = 0;
        int cnt = 0;
        for(int i = 0; i < n;i++){
            if(masu[i][j] == '#'){
                tate[j]++;
                
                if(pre_c == 0) cnt++;
                pre_c = 1;
            }else{
                pre_c = 0;
            }
            if(cnt >= 2) return -1;
            
        }
    }
    
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(masu[i][j] == '#') white[i][j] = true;
        }
    }


    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(yoko[i] == 0 && tate[j] == 0) white[i][j] = true;
        }
    }
    
    for(int i = 0; i < n;i++){
        bool ok = false;
        for(int j = 0; j < m;j++){
            if(white[i][j]) ok = true;
        }
        if(!ok) return -1;
    }
    for(int j = 0; j < m; j++){
        bool ok = false;
        for(int i = 0; i < n;i++){
            if(white[i][j]) ok = true;
        }
        if(!ok) return -1;
    }
    
    int group_num = 0;
    auto group = make_v<int>(n,m); fill_v(group,-1);
    int dir[4] = {1,0,-1,0};
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(masu[i][j] == '.') continue;
            if(group[i][j] != -1) continue;
            queue<pii> q; q.emplace(i,j);
            while(q.size()){
                int ni,nj; tie(ni,nj) = q.front(); q.pop();
                if(group[ni][nj] == group_num) continue;
                group[ni][nj] = group_num;
                
                for(int k = 0; k < 4;k++){
                    int nexti = ni + dir[k];
                    int nextj = nj + dir[k^1];
                    if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
                    if(group[nexti][nextj] != -1) continue;
                    if(masu[nexti][nextj] == '.') continue;

                    q.emplace(nexti,nextj);
                }
            }
            group_num++;
        }
    }
    
    res = group_num;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
