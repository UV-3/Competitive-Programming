const int N=2e5+5;

vector<int>g[N];

vector<vector<int>>par(32,vector<int>(N,-1));
vector<int>d(N,0);
vector<bool>vis(N,0);

int walk(int i, int j){
    for(int k=0;k<=31 && i!=-1 ; k++){
        if( (1<<k) & j){
            i= par[k][i];
        }
    }
    return i;
}

int lca(int i, int j){
    if(d[i]>d[j]){
        i=walk(i,d[i]-d[j]);
    }
    if(d[j]>d[i]){
        j=walk(j,d[j]-d[i]);
    }
    if(i==j){
        return i;
    }
    for(int k=31;k>=0;k--){
        if(par[k][i]!= par[k][j]){
            i=par[k][i];
            j=par[k][j];
        }
    }
    return par[0][i];
}

int dist(int i, int j){
    return d[i] + d[j] - 2*d[lca(i,j)];
}

void preprocess(int n){
    for(int k=1;k<=31;k++){
        for(int i=1;i<=n;i++){
            int mid= par[k-1][i];
            if(mid!=-1){
                par[k][i]=par[k-1][mid];
            }
        }
    }
}

void bfs(int s){
    queue<int>q;
    vis[s]=1;
    d[s]=0;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto u:g[v]){
            if(!vis[u]){
                vis[u]=1;
                d[u]=d[v]+1;
                par[0][u]=v;
                q.push(u);
            }
        }
    }
}
