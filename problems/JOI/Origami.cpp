#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day3_22.pdf>
 問題文============================================================
 
 a x b (1<= a,b <= 1000000)の台紙が与えられる。
 そこに一辺の長さが20以下である折り紙を貼っていったとき、
 最も多く折り紙が重なっている部分が何重であるか、及びその部分の面積を求めよ
 
 =================================================================
 解説=============================================================
 
 座標圧縮したらMLEする。
 折り紙の一辺の長さは20以下のため、mapを用いて貪欲探索でok
 ================================================================
 */

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll a,b; cin >> a >> b;
    map<pii,int> m;
    int max_cnt = 0;
    ll res = 0;
    for(int i = 0; i <N;i++){
        int p,q,r,s; cin >> p >> q >> r >> s;
        for(int x = p; x <= r; x++){
            for(int y = q; y <= s; y++){
                int t_cnt = (++m[{x,y}]);
                if(t_cnt > max_cnt){
                    res = 1;
                    max_cnt = t_cnt;
                }else if(t_cnt == max_cnt){
                    res++;
                }
            }
        }
    }
    cout << max_cnt << endl;
    cout << res << endl;
    return 0;
}
