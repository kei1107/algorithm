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

struct RH {
public:
    vector<unsigned long long> p,hash;
    int n;
    unsigned long long base,m,q;
    // m : 1000000007, 1000000009, 1000000021...
    RH(){
        base=10007;
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
    void apply(const char c){
        if(m == 0){
            p.push_back(p[n]*base);
            hash.push_back(c+hash[n]*base);
        }else{
            p.push_back(p[n]*base%m);
            hash.push_back((c+hash[n]*base)%m);
        }
        n++;
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
    unsigned long long bach_h(int i)const { return h(n-i,n); }
};
