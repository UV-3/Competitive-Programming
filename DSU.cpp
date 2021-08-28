struct DSU{
    vector<int>p,r;
    void init(int n){
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            r[i]=0;
        }
    }
    int find_set(int v){
        if(v==p[v]){
            return v;
        }
        return p[v]=find_set(p[v]);
    }
    void union_sets(int a, int b){
        a=fin d_set(a);
        b=find_set(b);
        if(a!=b){
            if(r[a]<r[b]){
                swap(a,b);
            }
            p[b]=a;
            if(r[a]==r[b]){
                r[a]++;
            }
        }
    }
};
