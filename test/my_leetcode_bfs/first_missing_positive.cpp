int first_missing_postive(vector<int>& va) {
    if(va.size()==0) return 1;
    for(int i = 0; i < va.size(); i++){
        exch_for(i,va);
    }
    for(int i=0;i<va.size();i++){
        if(va[i] != i+1) return i+1;
    }
}

void exch_for(int i, vector<int>& a){
    while(a[i] != i+1){
        // 输入原因 a[i] 可能越界重复，所以需要判断 a[i] a[a[i]-1]
        swap(a[i],a[a[i]-1]);
    }
}