/*
 行列累乗
 */

typedef vector<ll> vec;
typedef vector<vec> mat;

/*
 行列累乗
 X = A^M*B
 A ( N*N行列)
 
 O(N^3 logM)
 */
mat mul(mat&A,mat&B,const ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
            if(A[i][k] == 0) continue;
            for(int j = 0; j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n,const ll M){
    mat B(A.size(),vec(A.size()));
    for(int i = 0; i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B= mul(B,A,M);
        A = mul(A,A,M);
        n>>=1;
    }
    return B;
}

// ============================================================ //

/*
 kitamasa法
 F(x) = Σ_{i=1..N} A(x,i)*F(i)
 
 F(K)をO(N^2 logK)で求める
 
 calc関数で
 F_K = A0*F0 + A1*F1 + ... A_K-1*F_K-1 => return F_N
 を返す
 
 自分メモ
 普段頭の中では以下の形で行列を考えているので、代入値に注意
 (A0,A1,....,A_K-1) |F_K-1  |
 |...    |
 |F1     |
 |F0     |
 
 */
struct kitamasa{
    vector<ll> mul(const vector<ll>& v1,const vector<ll>& v2,const vector<ll>& A,const ll M){
        int N =(int)v1.size();
        vector<ll> ret(2*N,0);
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N;j++){
                if(v1[i] == 0 && v2[j] == 0) continue;
                (ret[i+j] += v1[i]*v2[j]%M + M)%=M;
            }
        }
        for(int i = 2*N-2; i>= N;i--){
            if(ret[i] == 0) continue;
            for(int j = 1; j <= N; j++){
                if(A[N-j] == 0) continue;
                (ret[i-j] += A[N-j]*ret[i]%M + M)%=M;
            }
        }
        ret = vector<ll>(ret.begin(),ret.begin()+N);
        return ret;
    }
    vector<ll> pow(ll N,const vector<ll>& A,const ll M){
        int _n = (int)A.size();
        vector<ll> ret(_n,0),v(_n,0);
        ret[0] = v[1] = 1;
        while(N > 0){
            if(N&1) ret = this->mul(ret,v,A,M);
            v = this->mul(v,v,A,M);
            N>>=1;
        }
        return ret;
    }
    
    // F_K = A0*F0 + A1*F1 + ... A_K-1*F_K-1 => return F_N
    ll calc(ll N,const vector<ll>& F,const vector<ll>& A,const ll M){
        ll ret = 0;
        vector<ll> PowA = this->pow(N,A,M);
        for(int i = 0; i < F.size();i++) (ret += F[i]*PowA[i]%M + M)%=M;
        return ret;
    }
};

// ============================================================ //

