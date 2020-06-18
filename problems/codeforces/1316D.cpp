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

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const char D[4] = {'D','R','U','L'};
template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<vector<char>> ans(n,vector<char>(n,'#'));
    vector<vector<pii>> info(n,vector<pii>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            int x,y; cin >> x >> y;
            if(x != -1){
                x--; y--;
                if(x == i && y == j){
                    ans[i][j] = 'X';
                }
            }
            info[i][j] = make_pair(x,y);
        }
    }
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            int x,y; tie(x,y) = info[i][j];
            if(x == -1){
                bool ok = false;
                for(int k = 0; k < 4;k++){
                    int nexti = i + dx[k];
                    int nextj = j + dy[k];
                    if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= n) continue;
                    if(info[nexti][nextj].first == -1){
                        ans[i][j] = D[k];
                        ok = true;
                        break;
                    }
                }
                if(!ok){
                    cout << "INVALID" << endl;
                    return res;
                }
            }else{
                if(ans[x][y] != 'X'){
                    cout << "INVALID" << endl;
                    return res;
                }
                if(ans[i][j] == 'X'){
                    queue<pii> q;
                    q.emplace(i,j);
                    //cout << i << " " << j << endl;
                    while(q.size()){
                        int ni,nj; tie(ni,nj) = q.front();
                        q.pop();
                        
                        for(int k = 0; k < 4;k++){
                            int nexti = ni + dx[k];
                            int nextj = nj + dy[k];
                            if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= n) continue;
                            if(ans[nexti][nextj] != '#') continue;
                            if(info[nexti][nextj].first == i && info[nexti][nextj].second == j){
                                ans[nexti][nextj] = D[(k+2)%4];
                                q.emplace(nexti,nextj);
                            }
                        }
                    }
                }
                
            }
        }
    }
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(ans[i][j] == '#'){
                cout << "INVALID" << endl;
                return res;
            }
        }
    }
    
    
    cout << "VALID" << endl;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cout << ans[i][j];
        }cout << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
