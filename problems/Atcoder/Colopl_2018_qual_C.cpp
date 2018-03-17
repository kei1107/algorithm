#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_c>
問題文============================================================
 目当ての「マタタビ」を手に入れたあなたは、「すぬけそだて」を本格的に遊び始めました。
 
 都市の道端とはいえやはり自然は弱肉強食の世界で、拾われたばかりのすぬけ君は弱りきっていました。
 あなたは、ゲーム内アイテムを食べさせてあげることで、すぬけ君の体力を回復させようとしています。
 
 さて、すぬけ君は好物が整数の書かれたカードであるという変わったねこです。
 カードをすぬけ君に与えると、
 あなたはむしゃむしゃと幸せそうにカードを食べるすぬけ君の愛らしい姿を眺めることができます。
 しかし、カードを与えているうちに、あなたはカードを食べてもすぬけ君が喜ばないことがあることに気付きました。
 また、以下の性質を発見しました。
 
 すぬけ君は、その日にこれまでに食べたどのカードに書かれた整数とも互いに素である整数の書かれたカードを食べたとき、
 喜ぶ。そうでないとき、悲しむ。
 今日のカードショップには A 以上 B 以下の整数の書かれたカードが 1 枚ずつ売られています。
 あなたは、このうちの 0 枚以上の任意の枚数を購入し、すべてのカードをすぬけ君に与えることにしました。
 このとき、すぬけ君を 1 度でも悲しませてはいけません。
 
 カードの買い方は何通りあるでしょうか。
 
 制約
 1≤A≤B≤10^18
 B−A≤35

=================================================================

解説=============================================================

 B-Aが35であり、偶数同士は必ず互いに素にならないので、実質の探索経路は 2^18通りとなり
 貪欲に探索して間に合う
 
================================================================
*/

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

void dfs(ll n,const ll A,const ll B,vector<ll> have,ll &ret){
    if(n > B){
        ret++;
        return ;
    }
    dfs(n+1,A,B,have,ret);
    bool update = [&]{
        for(auto h:have){
            if(gcd(h,n)!=1)return false;
        }
        have.push_back(n);
        return true;
    }();
    if(update) dfs(n+1,A,B,have,ret);
    return ;
}

ll solve(){
    ll ret = 0;
    ll A,B; cin >> A >> B;
    dfs(A,A,B,vector<ll>(),ret);
    return ret;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
