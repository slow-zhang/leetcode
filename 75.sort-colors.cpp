/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.52%)
 * Total Accepted:    298.3K
 * Total Submissions: 718.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution
{
  public:
    void bublesort(vector<int> &a)
    {
        int len = a.size();
        //   if (a.size() <= 1)
        //       return;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            }
        }
    }

    void selectsort(vector<int> &a)
    {
        int len = a.size();
        for (int t = len - 1; t > 0; t--)
        {
            int maxp = 0;
            for (int i = 1; i <= t; i++)
            {
                if (a[i] > a[maxp])
                    maxp = i;
            }
            swap(a[maxp], a[t]);
        }
        return;
    }

    void shellsort(vector<int> &a)
    {
        int len = a.size();
        for (int jump = 31; jump >= 1; jump = jump / 2)
        {
            for (int i = 0; i < len - jump; i++)
            {
                if (a[i] > a[i + jump])
                {
                    swap(a[i], a[i + jump]);
                    int p = i - jump;
                    while (p >= 0 && a[p] > a[p + jump])
                    {
                        swap(a[p], a[p + jump]);
                        p -= jump;
                    }
                }
            }
        }
        return;
    }

    int mid_of_three(vector<int> &a, int i, int j)
    {
        int mid = (j - i) / 2 + i;
        if (a[i] >= a[mid])
        {
            if (a[j] >= a[i])
                return i;
            else if (a[mid] > a[j])
                return mid;
            else
                return j;
        }
        else
        {
            if (a[j] >= a[mid])
                return mid;
            else if (a[i] > a[j])
                return i;
            else
                return j;
        }
    }

    int partition1(vector<int> &a, int i, int j)
    {
        if (i == j)
            return i;
        int p = mid_of_three(a, i, j);
        swap(a[i], a[p]);
        int v = a[i];
        p = i;
        while (i < j)
        {
            while (j > i && a[j] > v)
                j--;
            if (j > i)
                a[i] = a[j];
            while (i < j && a[i] <= v)
                i++;
            if (j > i)
                a[j] = a[i];
        }
        a[i] = v;
        return i;
    }
    void print_arr(vector<int> &a){
        for_each(a.begin(), a.end(), [](int t) { cout << t << " "; });
        cout<<endl;
    }

    // [i,j]
    void quick_sort(vector<int> &a, int i, int j)
    {
        if (i >= j)
            return;
        int p = partition1(a, i, j);
        quick_sort(a, i, p - 1);
        quick_sort(a, p + 1, j);
        return;
    }

    //  [s,m] [m+1,e]
    void merge_arr(vector<int> &a,int s,int m,int e){
        // cout << "merging" << s << "," << m << "," << e << endl;
        vector<int> tmp(e-s+1,0);
        if(m>e) m=e;
        int i=s,j=m+1,k=0;
        // print_arr(a);
        while(i<=m && j<=e){
            if(a[i]<=a[j]){
                tmp[k++]=a[i++];
            }else{
                tmp[k++]=a[j++];
            }
        }
       
        while(i<=m){
            tmp[k++]=a[i++];
        }
        while(j<=e)
            tmp[k++]=a[j++];

        for(int i=0;i<e-s+1;i++){
            a[s+i]=tmp[i];
        }

        // print_arr(a);
        // print_arr(tmp);
        return;
    }
    void merge_sort1(vector<int> &a,int i,int j){
        if(i>=j) return ;

        int mid=(j-i)/2+i;

        merge_sort1(a,i,mid);
        merge_sort1(a,mid+1,j);
        merge_arr(a,i,mid,j);
        return ;
    }
    //  [s,m] [m+1,e]
    void merge_arr2(vector<int> &a, int s, int m, int e,vector<int> &tmp)
    {
        // cout << "merging" << s << "," << m << "," << e << endl;
        // vector<int> tmp(e - s + 1, 0);
        if (m > e)
            m = e;
        int i = s, j = m + 1, k = 0;
        // print_arr(a);
        while (i <= m && j <= e)
        {
            if (a[i] <= a[j])
            {
                tmp[k++] = a[i++];
            }
            else
            {
                tmp[k++] = a[j++];
            }
        }

        while (i <= m)
        {
            tmp[k++] = a[i++];
        }
        while (j <= e)
            tmp[k++] = a[j++];

        for (int i = 0; i < e - s + 1; i++)
        {
            a[s + i] = tmp[i];
        }

        // print_arr(a);
        // print_arr(tmp);
        return;
    }
    void down_to_up_merge_sort(vector<int> &a,int i,int j,vector<int> &tmp){

        int range=2;
        while(range<=2*(j-i+1)){
            cout<<range<<endl;
            for(int i=0;i<j;i+=range){
                int e=min(j,i+range-1);
                merge_arr2(a,i,range/2-1+i,e,tmp);
            }
            range*=2;
            // print_arr(a);
           
        }
        return ;
    }
    #define left(t) ((t)*2)
    #define right(t) ((t)*2+1)
    //  [1,len] 
    void adjust(vector<int> &a,int t,int len){
        while(t<len){
            int l=left(t);
            int r=right(t);
            int max=t;
            if(l<=len && a[l] > a[t]) max=left(t);
            if(r<=len && a[r] > a[max]) max=right(t);
            if(t==max) break;
            swap(a[t],a[max]);
            t=max;
        }
    }

    void my_sort(vector<int> &a,int len){
        print_arr(a);
        cout<<len<<endl;
       for(int i=len/2;i>=1;i--){
           adjust(a,i,len);
           print_arr(a);
       }
       print_arr(a);
       for(int i=len;i>=1;i--){
           swap(a[i],a[1]);
           adjust(a,1,i-1);
           print_arr(a);
       }
       a.erase(a.begin());
    }

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

    void sortColors(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return;
        //vector<int> tmp(nums.size()+1);
        // nums.insert(nums.begin(),3);
        count_sort(nums);
    }
};
