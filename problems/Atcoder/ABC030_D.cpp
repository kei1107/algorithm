#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://beta.atcoder.jp/contests/abc030/tasks/abc030_d>
問題文============================================================

 (略)
 
=================================================================

解説=============================================================
 
 手で書いたりして、実験すれば、辿って行く辞書はある地点からループに入ることがわかる
 
 まず、どの場所からループに入り、どの長さ（何個の辞書をたどって）一つのループになるか
 調べれる
 
 この時、kが最初からループの開始点に到達するまでの長さよりも短ければ、
 たかだか10^5までシミュレーションすればよく、
 長ければ
 最終的な場所は　(k - (最初からループの開始点までの長さ）) % (ループの長さ) + (最初からループの開始点までの長さ)
 
 となる、
 
 ここで kは最大でも 10^100000なので、文字列で持っておき、
 一文字ずつ　(k - (最初からループの開始点までの長さ）) % (ループの長さ) を計算して行く
 
 L83.の
 (kmod + roop_sec*roop_start - roop_start)%roop_sec;
 の roop_sec*roop_start は カッコの中身が負となるのを防ぐため
 
===============================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,a; cin >> N >> a;
    string k; cin >> k;
    vector<ll> b(N+1,0);
    for(int i = 1; i<= N;i++) cin >> b[i];
    
    vector<ll> checked(N+1,-1);
    ll step = 1;
    checked[b[a]] = step;
    step++;
    ll next = b[b[a]];
    
    ll roop_start = 0,roop_sec = 0;
    while(true){
        if(checked[next] != -1){
            roop_start = checked[next];
            roop_sec = step - checked[next];
            break;
        }else{
            checked[next] = step;
            next = b[next];
            step++;
        }
    }

    if(k.length() < 6){
        ll numk = atoi(k.c_str());
        if(numk < roop_start){
            ll next = a;
            for(int i = 0; i < numk;i++){
                next = b[next];
            }
            cout << next << endl;
            return 0;
        }
    }
    
    ll kmod = 0;
    for(int i = 0; i < k.length();i++){
        kmod = (kmod*10 + (k[i] - '0'))%roop_sec;
    }
    
    kmod = (kmod + roop_sec*roop_start - roop_start)%roop_sec;
    for(int i = 0; i < kmod;i++){
        next = b[next];
    }
    cout << next << endl;
    
	return 0;
}
