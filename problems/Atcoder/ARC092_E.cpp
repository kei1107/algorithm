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
 <url:https://beta.atcoder.jp/contests/arc092/tasks/arc092_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 組み合わせの値として候補になりうるグループは、
 indexに注目すると、偶数のみor奇数のみとなる。
 よって、偶数or奇数のグループのみで作られる最大値が答えの値
 （ただし、全て0以下の時がコーナー)
 
 生成方法については、
 両端のいらない部分を消しておき、
 その後、 ある場所が不要でかつ　両端が必要 or 両端が不要な　箇所を消していけば良い
 
 ================================================================
 */

void solve(){
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    vector<int> flag(N);
    bool minusflag = true;
    for(int i = 0; i < N;i++){
        if(a[i] > 0) minusflag = false;
    }
    if(minusflag){
        ll idx = max_element(a.begin(), a.end()) - a.begin();
        flag[idx] = 1;
        cout << a[idx] << endl;
        cout << N-1 << endl;
        while(flag.size()!=1){
            if(flag[0] == 0){
                cout << 1 << endl;
                flag.erase(flag.begin());
            }else{
                cout << flag.size() << endl;
                flag.erase(flag.begin()+flag.size()-1);
            }
        }
    }else{
        ll even = 0,odd = 0;
        for(int i = 0; i < N;i++){
            if(a[i] > 0){
                if(i%2) odd += a[i];
                else even += a[i];
            }
        }
        if(even >= odd){
            for(int i = 0; i < N;i++){
                if(a[i] > 0){
                    if(i%2 == 0) flag[i] = 1;
                }
            }
        }else{
            for(int i = 0; i < N;i++){
                if(a[i] > 0){
                    if(i%2) flag[i] = 1;
                }
            }
        }
        
        cout << max(even,odd) << endl;
        vector<ll> com;
        while(*flag.begin() == 0){
            com.push_back(1);
            flag.erase(flag.begin());
        }
        while(*flag.rbegin() == 0){
            com.push_back(flag.size());
            flag.erase(flag.begin()+flag.size()-1);
        }
        
        while(true){
            bool update = false;
            for(int i = 1; i < flag.size()-1;i++){
                if(flag[i] == 0){
                    if(flag[i-1] == 1 && flag[i+1] == 1){
                        a[i-1] += a[i+1];
                        a.erase(a.begin()+i,a.begin()+i+2);
                        com.push_back(i+1);
                        flag.erase(flag.begin()+i,flag.begin()+i+2);
                        //flag.erase(flag.begin()+i);
                        update = true;
                        break;
                    }
                    if(flag[i-1] == 0 && flag[i+1] == 0){
                        a[i-1] += a[i+1];
                        a.erase(a.begin()+i,a.begin()+i+2);
                        com.push_back(i+1);
                        flag.erase(flag.begin()+i,flag.begin()+i+2);
                        //flag.erase(flag.begin()+i);
                        update = true;
                        break;
                    }
                }
            }
            if(update) continue;
            break;
        }
        
        cout << com.size() << endl;
        for(auto v :com){
            cout << v << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
