struct Sieve{
    int N;
    vector<int>lp,pr;
    // tell the max no till which prime factorisation needs to be calculated
    void init(int n){
        N=n;
        lp.resize(N+1,0);
        for (int i=2; i<=N; i++) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back (i);
            }
            for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; j++){
                lp[i * pr[j]] = pr[j];
            }
        }
    }
    // returns prime factors in log(n) time
    vector<int>fact(int n){
        vector<int>a;
        while(lp[n]){
            a.push_back(lp[n]);
            n/=lp[n];
        }
        return a;
    }
    bool isprime(int n){
        return lp[n]==n;
    }
};
