/*
 Rolling hash
 */
struct RH {
public:
    vector<unsigned long long> p,hash;
    unsigned long long m,q;
    int n;
    void init(const string s) {
        // m=1000000007;
        m = 67280421310721;
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){p[i+1]=p[i]*m;hash[i+1]=s[i]+hash[i]*m;}
    }
    void apply(const char c){
        p.push_back(p[n]*m);
        hash.push_back(c+hash[n]*m);
        n++;
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{return h(j)-h(i)*p[j-i];}
    unsigned long long bach_h(int i)const { return h(n) - h(n-i)*p[n-(n-i)]; }
};

// 高速(こどふぉ基準)
// ハッシュ衝突が危険
// =========================================================================== //
// 基本は下を使う。(ハッシュ衝突が怖いため）
// TLE等のやむを得ない場合は上

/*
 Rolling hash
 */
typedef unsigned long long ull;
const ull bases[64] = {259, 261, 264, 269, 270, 280, 281, 284, 285, 286, 288, 295, 298, 304, 307, 309, 310, 311, 312, 316, 318, 319, 322, 323, 328, 330, 348, 350, 352, 353, 355, 359, 360, 367, 378, 380, 381, 382, 384, 390, 393, 394, 395, 397, 398, 399, 402, 410, 412, 413, 414, 416, 417, 424, 434, 435, 438, 440, 442, 449, 450, 462, 463, 464};
struct RH {
public:
    vector<ull> p,hash;
    int n;
    const static ull base;
    ull m,q;
    RH(){
        // m : 1000000007, 1000000009, 1000000021...
        m=1000000007;
    }
    void init(const string s) {
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    void apply(const char& c){
        if(m == 0){
            p.push_back(p[n]*base);
            hash.push_back(c+hash[n]*base);
        }else{
            p.push_back(p[n]*base%m);
            hash.push_back((c+hash[n]*base)%m);
        }
        n++;
    }
    ull h(int i)const{return hash[i];}
    ull h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
    ull bach_h(int i)const { return h(n-i,n); }
    int LCP(const RH &b,int l1,int r1,int l2,int r2){
        int len = min(r1-l1,r2-l2);
        int l = -1,r = len+1;
        while(r-l>1){
            int m = (l+r)/2;
            if(this->h(l1,l1+m) == b.h(l2,l2+m)){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }
};
const ull RH::base = bases[chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() & 63];
