#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://beta.atcoder.jp/contests/abc030/tasks/abc030_c>
問題文============================================================

 (略)
 
=================================================================

解説=============================================================

 a -> b へは　X時間
 b -> a へは　Y時間　要する
 
 最大往復回数は、各便の移動時間が固定なため、単純に考えて、
 飛行機に乗れる場合はすぐ乗った方が良い
 
 最初の時刻を now = 0 としたとき、
 now以上で有り、もっともnowに近い aiを探すには, Indexを共通の変数　aIdx等を保持して使い回すか
 O(log N)必要となるが、lower_bound を用いれば楽
 
 時時刻は next_time = (now以上でもっとも小さいai) + X
 
 b -> aに乗るときも同様
 この時に往復回数をカウントしておけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    ll X,Y; cin >> X >> Y;
    vector<ll> a(N),b(M);
    for(auto &in:a) cin >> in;
    for(auto &in:b) cin >> in;
    
    int now_time = 0;
    int ans = 0;
    bool f = false;
    while(true){
        if(f == false){
            auto it = lower_bound(a.begin(), a.end(), now_time);
            if(it == a.end()){
                break;
            }
            now_time = *it + X; f = true;
        }else{
            auto it = lower_bound(b.begin(),b.end(),now_time);
            if(it == b.end()){
                break;
            }
            now_time = *it + Y; f= false;
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}
