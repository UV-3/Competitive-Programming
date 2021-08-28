struct SegmentTree{
    int n;
    vector<int>t;
    void init(int n){
        this->n=n;
        t.resize(4*n,0);
    }
    // v=1 , tl=0, and tr=n−1.
    void build(vector<int>&a,int v, int tl, int tr){
        if(tl==tr){
            t[v]=a[tl];
        }
        else{
            int tm=(tl+tr)/2;
            build(a,2*v,tl,tm);
            build(a,2*v+1,tm+1,tr);
            t[v]= t[2*v]+ t[2*v+1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r){
        if(l>r){
            return 0;
        }
        if(l==tl && r==tr){
            return t[v];
        }
        int tm=(tl+tr)/2;
        return sum(2*v,tl,tm,l,min(r,tm))+ sum (2*v+1,tm+1,tr, max(l,tm+1),r);
    }
    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl==tr){
            t[v]=new_val;
        }
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm){
                update(2*v,tl,tm,pos,new_val);
            }
            else{
                update(2*v+1,tm+1,tr,pos,new_val);
            }
            t[v]= t[2*v]+ t[2*v+1];
        }
    }
};
