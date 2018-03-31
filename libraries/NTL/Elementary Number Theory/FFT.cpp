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

/* FFT : reference < https://satanic0258.github.io/snippets/math/FFT.html >*/
/*
 Example of use
 // 列a, bを用意
 std::vector<int> a, b;
 
 // a，bを畳み込んだ結果をcとする
 std::vector<int> c(FFT::mul(a, b));
 */

// Description: 列a[i],b[i]から列c[k]=sum{a[i]*b[k-i]}を生成する.O(NlogN).
namespace FFT {
    typedef long long TYPE;
    const double pi = std::acos(-1);
    std::vector<std::complex<double>> tmp;
    size_t sz = 1;
    
    std::vector<std::complex<double>> fft(std::vector<std::complex<double>> a, bool inv = false) {
        size_t mask = sz - 1, p = 0;
        for (size_t i = sz >> 1; i >= 1; i >>= 1) {
            auto& cur = (p & 1) ? tmp : a;
            auto& nex = (p & 1) ? a : tmp;
            std::complex<double> e = std::polar(1., 2 * pi * i * (inv ? -1 : 1) / sz); // (絶対値,偏角)の極形式指定
            std::complex<double> w = 1;
            for (size_t j = 0; j < sz; j += i) {
                for (size_t k = 0; k < i; ++k) {
                    nex[j + k] = cur[((j << 1) & mask) + k] + w * cur[(((j << 1) + i) & mask) + k];
                }
                w *= e;
            }
            ++p;
        }
        if (p & 1) std::swap(a, tmp);
        if (inv) for (size_t i = 0; i < sz; ++i) a[i] /= sz;
        return a;
    }
    std::vector<TYPE> mul(std::vector<TYPE> a, std::vector<TYPE> b) {
        size_t m = a.size() + b.size() - 1;
        sz = 1;
        while (m > sz) sz <<= 1;
        tmp.clear(); tmp.resize(sz);
        std::vector<std::complex<double>> A(sz), B(sz);
        for (size_t i = 0; i < a.size(); ++i) A[i].real(a[i]);
        for (size_t i = 0; i < b.size(); ++i) B[i].real(b[i]);
        A = fft(A); B = fft(B);
        for (size_t i = 0; i < sz; ++i) A[i] *= B[i];
        A = fft(A, true);
        a.clear(); a.resize(m);
        for (size_t i = 0; i < m; ++i) a[i] = std::round(A[i].real());
        return a;
    }
};

/* https://atc001.contest.atcoder.jp/tasks/fft_c */
void solve_ATC001_C(){
    ll N; cin >> N;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    auto c = FFT::mul(A,B);
    cout << 0 << endl;
    for(auto v:c) cout << v << endl;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve_ATC001_C();
    return 0;
}
