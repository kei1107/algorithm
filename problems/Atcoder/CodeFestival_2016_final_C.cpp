#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf16-final-open.contest.atcoder.jp/tasks/codefestival_2016_final_c>
問題文============================================================
 問題文
 ある星には M 種類の言語があり、1[sim]M の番号が付けられています。
 
 この星のある年のCODE FESTIVALには星中から N 人の参加者が集まりました。
 
 i(1≦i≦N) 人目の参加者は Ki 種類の言語 Li,1,Li,2,…,Li,Ki を話すことが出来ます。
 
 ある 2 人は以下のいずれかの条件を満たすときに限り、コミュニケーションを取ることが出来ます。
 
 2 人ともが話すことの出来る言語が存在する。
 ある人 X が存在して、 2 人ともが X とコミュニケーションを取ることが出来る。
 
 このとき、N 人すべての参加者が他のすべての参加者とコミュニケーションを取ることが出来るかどうかを判定してください。
 
 制約
 2≦N≦105
 1≦M≦105
 1≦Ki≦M
 Kiの総和≦105
 1≦Li,j≦M
 Li,1,Li,2,…,Li,Ki は相異なる。
=================================================================

解説=============================================================
UnionFind
 
 問題条件より、結果的に参加者達が全域木のように結ばれればいいということが分かる
 よってunion Find を用いて、コミュニケーション可能か集団の集合を構築し、
 その集合の数によって判定すれば良い
================================================================
*/

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<vector<ll>> lang(M);
    for(int i = 0; i < N;i++){
        ll K; cin >> K;
        for(int j = 0; j < K;j++){
            ll L; cin >> L;
            L--; lang[L].push_back(i);
        }
    }
    UnionFind uf(N);
    for(int i = 0; i < M;i++){
        for(int j = 0; j < (int)lang[i].size() - 1;j++){
            uf.unionSet(lang[i][j],lang[i][j+1]);
        }
    }
    set<ll> s;
    for(int i = 0; i < N;i++){
        s.insert(uf.root(i));
    }
    if(s.size() == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
