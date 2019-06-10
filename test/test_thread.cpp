#include <iostream>
#include <thread>

using namespace std;

mutex m1;
mutex m2;
char i=1;


void producer(int t){
    while(i<26){
        m1.lock();
        printf("%d,%c%d\n",t,'A'+i-1,i);
        i++;
        m2.unlock();
    }
}

void consumer(int t)
{
    m2.lock();
    while (i < 26)
    {;
        m2.lock();
        printf("%d,%c%d\n", t, 'A' + i - 1, i);
        i++;
        m1.unlock();
    }
}

const int maxn=1;
int main(){
    // thread td[maxn];
    // for(int i=0;i<maxn;i++){
    //     td[i]=thread(jobn,i);
    // }

    // for(int i=0;i<maxn;i++)
    //     td[i].join();


    thread t1=thread(producer,1);
    thread t2=thread(consumer,2);
    t1.join();
    t2.join();

    return 0;

    
}