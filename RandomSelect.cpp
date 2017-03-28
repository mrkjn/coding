#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
typedef float datatype;
typedef unsigned int indextype;
using namespace std;
class RandomSelect
{
   private:
     vector<datatype> &data;
   public:
     RandomSelect(vector<datatype> &tempdata);
     datatype randomselect(unsigned int p, unsigned int q, unsigned int i);
     unsigned int random(indextype start_index, indextype end_index)
     {
         if(end_index > start_index)
           return rand()%(end_index - start_index);
     }
     unsigned int randpartation(unsigned int start_key, unsigned int end_key);
     void showdata();
};
RandomSelect::RandomSelect(vector<datatype> &tempdata):data(tempdata)
{
}
void RandomSelect::showdata()
{
    for(auto &iv : data)
        cout << iv << endl;
}
unsigned int RandomSelect::randpartation(unsigned int start_key, unsigned int end_key)
{
    if(end_key > start_key)
    {
       decltype(data.size()) i = start_key;
       decltype(data.size()) j = start_key-1;
       for(; i != end_key; ++i)
       {
          if(data[end_key] > data[i])
          {
              ++j;
              swap(data[j], data[i]);
          }
       }
       swap(data[end_key], data[++j]);
       return j;
    }
    else
       return start_key;
}
datatype RandomSelect::randomselect(unsigned int p, unsigned int q, unsigned int i)
{
     if(q > p && i >= p && i <= q)
     {
         decltype(data.size()) mid_index = randpartation(p, q);
         decltype(data.size()) k = (p != 0)?(mid_index-p+1):(mid_index-p);
         if(k == i)
            return data[mid_index];
         else if(k > i)
            return randomselect(p, mid_index-1, i); //i
         else
            return randomselect(mid_index+1, q, i-k); //i-k error!
     }
     else
       return data[p];
}
int main(int args, char *argv[])
{
    vector <float> a ={2.7, 7.8, 3.4, 1.1, 8.9};
    RandomSelect myselect(a);
    cout << myselect.randomselect(0, 4, 2) << endl;
    return 0;
}
