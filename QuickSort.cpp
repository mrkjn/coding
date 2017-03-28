#include <iostream>
#include <vector>
using namespace std;
typedef float datatype;

class QuickSort
{
   private:
      vector<datatype> data;
   public:
      QuickSort(vector<datatype> tempdata);
      unsigned int find_midnum(unsigned int start_index, unsigned int end_index);
      void swap_element(unsigned int i, unsigned int j)
      {
           datatype tempelement = data[i];
           data[i] = data[j];
           data[j] = tempelement;
      }
      void quicksort(unsigned int p, unsigned int q);
      void showdata();
      unsigned int getsort_length();
};
QuickSort::QuickSort(vector<datatype> tempdata)
{
    data = tempdata;
}
void QuickSort::showdata()
{
    for(auto &v : data)
        cout << v << endl;
}
unsigned int QuickSort::getsort_length()
{
    if(data.size() != 0)
        return data.size()-1;
    else
        return data.size();
}
unsigned int QuickSort::find_midnum(unsigned int start_index, unsigned int end_index)
{
    decltype(data.size()) j = start_index-1;
    decltype(data.size()) i = j+1;
    if(end_index > start_index)
    {
      datatype key = data[end_index];
      for(; i != end_index; ++i)
      {
         if(data[i] < key)
         {
             ++j;
             swap_element(i, j);
         }
      }
      swap_element(i, ++j);
      return j;
    }
    else
        return start_index;
}
void QuickSort::quicksort(unsigned int p, unsigned int q)
{
    if(q > p)
    {
      decltype(data.size()) mid_index = find_midnum(p, q);
      if(mid_index > p)
        quicksort(p, mid_index-1);
      if(q > mid_index)
        quicksort(mid_index+1, q);
    }
}
int main(int args, char *argv[])
{
    vector<float> a = {1.2, 2.45, 6.4, 0.2, 4.7, 1.43, 12};
    QuickSort mysort(a);
    mysort.quicksort(0, mysort.getsort_length());
    mysort.showdata();
    return 0;
}
