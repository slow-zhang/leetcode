#include <iostream>
#include <vector>
using namespace std;


struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};
class Bipartition
{
public:
    double mean_sx(vector<Point> &v, int s)
    {
        double sum = 0;
        for (auto vdx : v)
        {
            sum += vdx.x;
        }
        return sum / 4;
    }
    double mean_sy(vector<Point> &v, int s)
    {
        double sum = 0;
        for (auto vdx : v)
        {
            sum += vdx.y;
        }
        return sum / 4;
    }
    vector<double> getBipartition(vector<Point> A, vector<Point> B)
    {
        // write code here
        double p1x = mean_sx(A, 0);
        double p1y = mean_sy(A, 1);
        double p2x = mean_sx(B, 0);
        double p2y = mean_sy(B, 1);
        cout<<"mean of ab"<<p1x<<","<<p1y<<" "<<p1x<<","<<p2y<<endl;
        /// for y = b x + a
        /// a = y - b x
        double b = ((p1y - p2y) / (p1x - p2x));
        double a = p2y - p2x * b;
        return {b, a};
    }
};

void simple_test(){
    Bipartition b;
    vector<Point> P
    {
        {1, 3}, {2, 3}, {3, 3}, { 4, 3 }
    };
    cout<<b.mean_sy(P,0)<<endl;
}

int main(){
    simple_test();

    return 0;
    vector<Point> A,B;
    for(int i=0;i<4;i++){
        int x,y;
        cin>>x>>y;
        A.emplace_back(x,y);
        cin >> x >> y;
        B.emplace_back(x, y);
    }
    Bipartition b;
    auto ans=b.getBipartition(A,B);
    cout<<ans[0]<<" "<<ans[1]<<endl;
} //[(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]