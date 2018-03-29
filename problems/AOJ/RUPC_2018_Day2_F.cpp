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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/F>
問題文============================================================

 縦線が３本のあみだくじがN個ある。
 どの線からスタートしてもスタートした線で終わるあみだくじを良いあみだくじとする。
 あみだくじを１つ以上選んで縦に自由な順序でつなぐことができる。
 良いあみだくじを作ることができるのであれば"yes"、そうでなければ"no"を出力せよ。
 
 i番目のあみだくじには横線がwi本ある。
 ai,jはあみだくじiの上からj番目の横棒が中央の縦線から左右どちらに伸びているかを表し、
 ai,jが0ならば左に、1ならば右に伸びていることを表す。
 
=================================================================

解説=============================================================

 あみだのパターンは次の6通り
  [1] 0: 123
  [2] 1: 132 2: 321 3 : 213
  [3] 4 : 312 5:231
 
 このうち[１]は存在すれば明らからにyes
 [2]はどれかが二つ存在すれば yes
 [3]はどれかが三つ存在すれば yes
 
 ここで [2]は最大でも高々1個 , [3]は高々2個までとみなせるので 7! でシミュレーションすれば良い
 
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    int check[6] = {0}; // 0: 123 / 1: 132 2: 321 3 : 213 / 4 : 312 5:231
    for(int i = 0; i < N;i++){
        ll w; cin >> w;
        ll l = 1, m = 2, r = 3;
        for(int j = 0; j < w;j++){
            ll a; cin >> a;
            if(a == 0){
                swap(l,m);
            }else{
                swap(r,m);
            }
        }
        string s = to_string(l) + to_string(m) + to_string(r);
        int x = atoi(s.c_str());
        if(x==123)check[0]++;
        if(x==132)check[1]++;
        if(x==321)check[2]++;
        if(x==213)check[3]++;
        if(x==312)check[4]++;
        if(x==231)check[5]++;
    }
    
    bool f = false;
    if(check[0]) f = true;
    if(check[1] > 1 || check[2] > 1 || check[3] > 1) f = true;
    if(check[4] > 2 || check[5] > 2) f = true;
    if(f){
        cout << "yes" << endl;
        return 0;
    }
    
    // 0: 123 / 1: 132 2: 321 3 : 213 / 4 : 312 5:231
    int n = check[1]+check[2]+check[3]+check[4]+check[5];
    vector<pair<pii,int>> h(n);
    int id = 0;
    if(check[1]) h[id++]={{1,3},2};
    if(check[2]) h[id++]={{3,2},1};
    if(check[3]) h[id++]={{2,1},3};
    
    if(check[4]-- >0) h[id++]={{3,1},2};
    if(check[4]-- >0) h[id++]={{3,1},2};
    
    if(check[5]-- >0) h[id++]={{2,3},1};
    if(check[5]-- >0) h[id++]={{2,3},1};
    
    vector<int> per(n); iota(per.begin(),per.end(),0);
    do{
        int hh[4];
        for(int i = 0; i < n;i++){
            if(i==0){
                hh[1]=h[per[i]].first.first; hh[2]=h[per[i]].first.second; hh[3]=h[per[i]].second;
            }else{
                int t1 = hh[h[per[i]].first.first], t2 = hh[h[per[i]].first.second], t3 = hh[h[per[i]].second];
                hh[1]=t1; hh[2]=t2; hh[3]=t3;
            }
            
            if(hh[1]==1&&hh[2]==2&&hh[3]==3){
                cout << "yes"<<endl;
                return 0;
            }
        }
    }while(next_permutation(per.begin(),per.end()));
    cout << "no" << endl;
	return 0;
}
