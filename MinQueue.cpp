struct MinQueue{
    stack<pair<int,int>>s1,s2;
    int removed_element=0;
    void add_el(int x){
        int mn= s1.empty()? x : min(x,s1.top().second);
        s1.push({x,mn});
    }
    void rem_el(){
        if(s2.empty()){
            while(!s1.empty()){
                int v= s1.top().first;
                s1.pop();
                int mn= s2.empty() ? v: min(v,s2.top().second);
                s2.push({v,mn});
            }
        }
        removed_element=s2.top().first;
        s2.pop();
    }
    int getmin(){
        int ans=0;
        if(s1.empty() || s2.empty()){
            ans= s1.empty() ? s2.top().second : s1.top().second;
        }
        else{
            ans=min(s1.top().second,s2.top().second);
        }
        return ans;
    }
};
