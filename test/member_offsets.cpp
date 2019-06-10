#include <cstdio>



int main(){
    {
        class A {
          public:
            // virtual ~A(){}
            int x, y, z;
        };
        int A::*p = 0;
        int A::*p2 = &A::x;
        printf(p == p2 ? "p1 p2 the same\n" : "p1 p2 differ\n");
        printf("%x,%x\n", p, p2);

        printf("member:\n");
        printf("%d\n", &A::x);
        printf("%d\n", &A::y);
        printf("%d\n", &A::z);
    }
    {
        printf("test2\n");
        struct A{
            int v1;
        };
        struct B{
            int v2;
        };
        struct C:A,B{
            int v3;
        };
        printf("%d\n", &A::v1);
        printf("%d\n", &B::v2);
        printf("%d\n", &C::v1);
        printf("%d\n", &C::v2);
        printf("%d\n", &C::v3);
    }
    return 0;
}