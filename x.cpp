int solution(vector<int> nums, int src, int dest){
    map<int,int> vA,vB;
    int start = nums[src];
    int curr = 1;
    set<int> s; 
    
    for(auto &x: nums){
        s.insert(x);
    }
    while(vA[start] == 0){
        vA[start] = curr; 
        curr++;
        start = nums[start];
        if(start == -1){
            break; 
        }
    }
    start = nums[dest];
    while(vB[start] == 0){
        vB[start] = curr;
        curr++;
        start = nums[start];
        if(start == -1){
            break;
        }
    }
    vector<pair<int,int>> v;
    for(auto &x: s){
        if(vA[x] != 0 && vB[x] != 0){ 
            pair<int,int> p = {vA[x] + vB[x], x};
            v.push_back(p);
        }
    }

    sort(v.begin(), v.end());
    return v[0].second;
}