## count sort
```c++
void count_sort(vector<int> &a){
    vector<long long int> c(3,0);
    for(int i=0;i<a.size();i++){
        c[a[i]]++;
    } 
    int k=0;
    for(int i=0;i<c.size();i++){
        while(c[i]>0){
            a[k++]=i;
            c[i]--;
        }
    }
}
```

## bit sort
```c++
const int Size=1000000000;
void bit_sort(vector<int> &a){
    bitset<Size> b;
    for(int i=0;i<a.size();i++){
        b.set([a[i],1);
    }
    int k=0;
    for(int i=0;i<Size;i++){
        if(b.test(i)){
            a[k++]=i;
        }
    }

}
```

## 基数排序 - 桶排序
