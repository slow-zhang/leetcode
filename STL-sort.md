# sort alg usage

## cmp usage
    <tamplate a>
    bool cmp()
    // qsort cmp: int cmp()


## simple
    #include <algorithm>
    // for exist array / vector :arra
    #include <algorithm>
    #define size 100
    sort(arra,arra+size)

## whth cmp
    #include <algorithm>
    // for exist array / vector :arra
    #include <algorithm>
    #define size 100

    // return  true 代表不用交换位置，所以这里代表降序
    bool cmp(int a,int b){
        return a>b;
    }

    // in main
    sort(arra,arra+size)


## sort with struct
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

### example
- modn sort
class ModN{
priviate: unsigned n;
public:
    ModN(unsigned _n):n(_n){}
    bool operator()(unsigned& a1,unsigned& a2){
        return (a1%n)<(a2%n);
    }
}

sort(a,a+100,ModN(10))

- 


