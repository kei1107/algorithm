#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2232>
 問題文============================================================
 =================================================================
 解説=============================================================
 制約が小さいので頑張って書く
 ================================================================
 */

int check(char c,int i,int j,int dh,int dw,int h,int w,vector<vector<char>>& masu){
    int ret = 0;
    if(c == '.') return ret;
    while(masu[i][j] == c){
        ret++;
        i += dh; j += dw;
        if(i >= h || j >= w) break;
    }
    return ret;
}
void remove(int num,int i,int j,int dh,int dw,vector<vector<char>>& masu){
    while(num--){
        masu[i][j] = '.';
        i += dh; j += dw;
    }
}
bool simulation(int h,int w,int n,vector<vector<char>> masu){
    bool update2 = true;
    while(update2){
        update2 = false;
        for(int i = h-1; i > 0; i--){
            for(int j = 0; j < w;j++){
                if((masu[i][j] == '.') && (masu[i-1][j] != '.')){
                    swap(masu[i][j],masu[i-1][j]);
                    update2 = true;
                }
            }
        }
    }
    
    bool update = true;
    while(update){
        update = false;
        auto tmp = masu;
        for(int i = 0; i < h;i++){
            for(int j = 0; j < w-n+1;j++){
                int num = check(masu[i][j],i,j,0,1,h,w,masu);
                if(num >= n){
                    remove(num,i,j,0,1,tmp);
                    update = true;
                }
            }
        }
        for(int i = 0; i < h-n+1;i++){
            for(int j = 0; j < w;j++){
                int num = check(masu[i][j],i,j,1,0,h,w,masu);
                if(num >= n){
                    remove(num,i,j,1,0,tmp);
                    update = true;
                }
            }
        }
        if(update == false) break;
        masu = tmp;
        bool update2 = true;
        while(update2){
            update2 = false;
            for(int i = h-1; i > 0; i--){
                for(int j = 0; j < w;j++){
                    if((masu[i][j] == '.') && (masu[i-1][j] != '.')){
                        swap(masu[i][j],masu[i-1][j]);
                        update2 = true;
                    }
                }
            }
        }
    }
    for(auto& vec:masu) if(count(vec.begin(),vec.end(),'.') != w) return false;
    return true;
}
string solve(){
    string res = "NO";
    int h,w,n; cin >> h >> w >> n;
    vector<vector<char>> masu(h,vector<char>(w));
    for(auto& vec:masu)for(auto& in:vec) cin >> in;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w-1;j++){
            swap(masu[i][j],masu[i][j+1]);
            if(simulation(h, w, n, masu)) return "YES";
            swap(masu[i][j],masu[i][j+1]);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
