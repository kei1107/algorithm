struct RH {
    vector<unsigned long long> p,hash;
    void init(const string s) {
        unsigned long long m=1000000007,q=1,n=s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){p[i+1]=p[i]*m;hash[i+1]=s[i]+hash[i]*m;}
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{return h(j)-h(i)*p[j-i];}
};

// 
// =========================================================================== //
// ちょっと遅いかも。こどふぉだと上が間に合って、下が間に合わない場合があるから注意

struct RH {
    vector<unsigned long long> p,hash;
    unsigned long long base,m;
    // m : 1000000007, 1000000009, 1000000021...
    RH(){base=10007;m=1000000007;}
    void init(const string s) {
        unsigned long long q=1,n=s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
};
