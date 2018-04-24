
/*

ダブリング
n次先の要素をlogNで求める

コード元
<http://satanic0258.hatenablog.com/entry/2017/02/23/222647>

参照urlを逐一見に行ってもいいが、面倒なので一応ここに置いておく

その他、ダブリングに関する使用できそうなテクニックも追記しておく
*/



int N; // 全体の要素数

/* ====　初期化1 ==== */
int LOG_N; // = floor(log2(N)) // = floor(log2(N)+1e-9))

/* ==== 初期化2 ==== */
ll LOG_N = 0;
while(N >= (1<<LOG_N)) LOG_N++;


// next[k][i]で、i番目の要素の「2^k個次の要素」を指す
// (なお、i番目の要素に対して「2^k個次の要素」が存在しないとき、
//  next[k][i]が指し示す要素番号を-1とします)
std::vector<std::vector<int>> next(LOG_N + 1, std::vector<int>(N));
// next[0]を計算
for (int i = 0; i < N; ++i){
    next[0][i] = (iの次の要素);
}
// nextを計算
for (int k = 0; k < LOG_N; ++k){
    for (int i = 0; i < N; ++i){
        if (next[k][i] == -1) {
            // 2^k個次に要素が無い時、当然2^(k+1)個次にも要素はありません
            next[k + 1][i] = -1;
        }
        else {
            // 「2^k個次の要素」の2^k個次の要素は、2^(k+1)個次の要素です
            next[k + 1][i] = next[k][next[k][i]];
        }
    }
}


// ----ここまで準備----

/* ==== 取得方法1 ==== */
// p番目の要素の「Q個次の要素」を求めることを考えます
for (int k = LOG_N; k >= 0; --k){
    if (p == -1) {
        // pがすでに存在しない要素を指していたら、
        // それ以降で存在する要素を指すことはないためループを抜けます
        break;
    }
    if ((Q >> k) & 1) {
        // Qを二進展開した際、k番目のビットが立っていたら、
        // pの位置を2^kだけ次にずらします
        p = next[k][p];
    }
}

/* ==== 所得方法2 ==== */
ll get(ll i,ll d,vector<vector<ll>>& next){
    if(d == 0) return i;
    ll k = 0;
    while(d >= (1<<k)) k++;
    return get(next[k-1][i],d - (1<<(k-1)),next);
}
