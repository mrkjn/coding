#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
class CountSort
{
   private:
     vector<int> data;
   public:
     CountSort(vector<int> tempdata);
     void countsort();
     int max_num() const;
};
CountSort::CountSort(vector<int> tempdata)
{
    data = tempdata;
}
int CountSort::max_num() const
{
    int max_num_temp = 0;
    for(auto &iv : data)
    {
        if(iv > max_num_temp)
            max_num_temp = iv;
    }
    return max_num_temp;
}
void CountSort::countsort()
{
    const int C_length = max_num()+1;
    int *C = (int*)calloc(C_length,sizeof(int));
    int *B = (int*)calloc(data.size(), sizeof(int));
    for(vector<int>::iterator iv = data.begin(); iv != data.end(); ++iv)
        C[*iv] += 1;
    for(int i =1; i != C_length; ++i)
        C[i] += C[i-1];
    for(auto &iv : data)
    {
        B[C[iv]-1] = iv;
        --C[iv];
    }
    for(int i = 0; i != data.size(); ++i)
        cout << B[i] << endl;
}
int main()
{
    vector<int> a = {7, 1, 8, 9, 0, 0, 1, 1, 2, 2, 12, 8, 15};
    CountSort mysort(a);
    mysort.countsort();
    return 0;
}
