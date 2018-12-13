#include <algorithm>
// for exist array / vector :arra
#include <algorithm>
#define size 3

struct Point{
    int x;
    int y;
    Point(int a,int b):x(a),y(b){}
    void show_point(){
        printf("%d %d\n",x,y);
    }
};
template<typename T>
bool cmp(const T &a1,const T &a2){

}
// return  true 代表不用交换位置，所以这里代表降序
bool cmp(struct Point a,struct Point b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y<b.y;
}
int main(){
    // in main
    struct Point arra[3]={Point(1,2),Point(4,1),Point(1,3)};
    std::sort(arra,arra+size,cmp);
    for(int i=0;i<3;i++){
        arra[i].show_point();
    }
}
