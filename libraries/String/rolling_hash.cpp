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
