struct point{
    int x,y;
};

bool cmp(const point &a, const point &b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    else{
        return a.x<b.x;
    }
}

bool cmp2(const point &a, const point &b){
    return (a.x==b.x && a.y==b.y);
}

int orientation(point a, point b, point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    //ORIENTATION
    // <0   -> COUNTER CLOCKWISE / LEFT TURN / DOWN HALF
    // >0   -> CLOCKWISE / RIGHT TURN / UP HALF
    // ==0  -> COLLINEAR / BOTH HALFS
}

void convex_hull(vector<point>&p){
    int n=p.size();
    if(n<=2){
        return;
    }
    sort(p.begin(),p.end(),cmp);
    point p1=p[0] , p2= p[n-1];
    // p1 -> bottom most & left most point
    // p2 -> rightmost  & uppermost point
    vector<point>up,down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1;i<n;i++){
        // p[i] is in up half
        if(orientation(p1, p[i], p2) >=0 || i==n-1){
            while(up.size()>=2 && orientation( up[up.size()-2] , up[up.size()-1],p[i])<0 ){
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        // p[i] is in down half
        if(orientation(p1, p[i], p2) <=0 || i==n-1){
            while(down.size()>=2 && orientation( down[down.size()-2], down[down.size()-1], p[i])>0 ){
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    p.clear();
    for(int i=0;i<up.size();i++){
        p.push_back(up[i]);
    }
    for(int i=0;i<down.size();i++){
        p.push_back(down[i]);
    }
    sort(p.begin(),p.end(),cmp);
    p.resize(unique(p.begin(),p.end(),cmp2)-p.begin());
}
