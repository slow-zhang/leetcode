#include <iostream>
#include <string>

using namespace std;

void testMemcpy(void *dst, const void *src, size_t size)
{
    if (!dst || !src)
        return;

    char *pDst = static_cast<char *>(dst);
    const char *pSrc = static_cast<const char *>(src);

    if (pDst <= pSrc || pSrc + size <= pDst)
    {
        while (size--)
        {
            *pDst++ = *pSrc++;
        }
    }
    else
    {
        pDst += size - 1;
        pSrc += size - 1;
        while (size--)
        {
            *pDst-- = *pSrc--;
        }
    }
}

int main()
{
    char test[100] = "aaaaaa";
    char test2[100];
    testMemcpy(test2, test, sizeof(test));
    std::cout << test2 << std::endl;
    testMemcpy(test2,test2+1,sizeof(test));
    std::cout<< test2 << std::endl;
    return 0;
}
