#include <iostream>
using namespace std;
typedef float datatype;
#define RIGHT(x) (x<<1)+1
#define LEFT(x) (x<<1)
class HeapSort
{
   private:
    datatype *data;
    int datalength;
   public:
    HeapSort(datatype *tempdata, int templength);
    void max_heap(datatype *data, int i);
    void build_max_heap();
    void heap_sort();
    void swap_data(datatype *a, datatype *b)
    {
        float temp_swap = *a;
        *a = *b;
        *b = temp_swap;
    }
};
HeapSort::HeapSort(datatype *tempdata, int templength)
{
    data = tempdata;
    datalength = templength;
}
void HeapSort::max_heap(datatype *tempdata, int i)
{
   int left_index = LEFT(i)-1;
   int right_index = RIGHT(i)-1;
   float largest = tempdata[i-1];
   int key = i-1;

   if(datalength >= 2*i && largest < tempdata[left_index])  //datalength要访问到左子节点
   {
     largest = tempdata[left_index];
     key = left_index;
   }
   if(datalength >=  2*i+1 && largest < tempdata[right_index]) //datalength 要访问到右子节点
   {
     largest = tempdata[right_index];
     key = right_index;
   }
   if(key != i-1)
   {
     swap_data(&tempdata[i-1], &tempdata[key]);
     key++;
     max_heap(tempdata, key);
   }
}
void HeapSort::build_max_heap()
{
    for(int j = (datalength)/2; j > 0; j--)
      max_heap(data, j);
}
void HeapSort::heap_sort()
{
    build_max_heap();
    for(int j = datalength; j > 0; j--)
    {
        swap_data(&data[0], &data[j-1]);
        datalength--;
        max_heap(data, 1);
    }

}
int main(int args, char *argv[])
{
    datatype c[6] = {7.0, 2.5, 3.3, 9.7, 4.7, 8.1};
    HeapSort mysort = HeapSort(c, 6);
    mysort.heap_sort();
    for(int i = 0; i < 6; i++)
        cout << c[i] << endl;
    return 0;
}
