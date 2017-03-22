#include <iostream>
#include <vector>
using namespace std;
typedef float datatype;
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)+1
#define PARENT(x) (x>>1)

const float min_num = -100000.0;
class Heap
{
   private:
    vector<datatype> data;
    decltype(data.size()) datalength;
   public:
    Heap(vector<datatype> tempdata, decltype(data.size())templength);
    void showdata()
    {
        for(auto &i : data)
            cout << i << endl;
    }
    void max_heap(vector<datatype> &tempdata, decltype(data.size()) i);
    void swap_data(decltype(data.size()) i, decltype(data.size()) j)
    {
        float temp_swap = data[i];
        data[i] = data[j];
        data[j] = temp_swap;
    }

    void build_max_heap();
    friend class PriorityQueue;
};

Heap::Heap(vector<datatype> tempdata, decltype(data.size())templength)
{
    data = tempdata;
    datalength = templength;
}

void Heap::max_heap(vector<datatype> &tempdata, decltype(data.size())i)
{
   decltype(data.size()) left_index = LEFT(i)-1;
   decltype(data.size()) right_index = RIGHT(i)-1;
   float largest = tempdata[i-1];
   decltype(data.size()) key = i-1;

   if(datalength >= 2*i && largest < tempdata[left_index])
   {
     largest = tempdata[left_index];
     key = left_index;
   }
   if(datalength >=  2*i+1 && largest < tempdata[right_index])
   {
     largest = tempdata[right_index];
     key = right_index;
   }
   if(key != i-1)
   {
     swap_data(i-1, key);
     key++;
     max_heap(tempdata, key);
   }
}
void Heap::build_max_heap()
{
    for(decltype(data.size()) j = (datalength)/2; j != 0; --j)
       max_heap(data, j);
}
class PriorityQueue
{
   private:
     Heap *heap;
   public:
     PriorityQueue(Heap *data);
     void Insert(datatype x);
     datatype MaxMum();
     void Extract_Max();
     void Increase_key(datatype x, int k);
     void showqueue()
     {
         heap -> showdata();
     }
};
PriorityQueue::PriorityQueue(Heap *data)
{
    heap = data;
}
datatype PriorityQueue::MaxMum()
{
    if(heap->datalength < 1)
    {
        cout << "empty" << endl;
        return -1;
    }
    else
        return heap->data[0];
}
void PriorityQueue::Extract_Max()
{
    if(heap->datalength < 1)
        cout << "empty" << endl;
    else
    {
        heap->swap_data(0, heap->datalength-1);
        (heap->datalength)--;
        heap->max_heap(heap->data, 1);
    }
}
void PriorityQueue::Increase_key(datatype x, int k)
{
    if(x < heap->data[k-1])
        cout << "too small" << endl;
    else
    {
        heap->data[k-1] = x;
        while(k > 1 && heap->data[k-1] > heap->data[PARENT(k)-1])
        {
            heap->swap_data(k-1, PARENT(k)-1);
            k = PARENT(k);
        }
    }
}
void PriorityQueue::Insert(datatype x)
{
    (heap->datalength)++;
    heap->data.push_back(min_num);
    Increase_key(x, heap->datalength);
}

int main(int args, char *argv[])
{
    vector<float> a = {1, 2, 3, 4, 5};
    Heap myheap(a, a.size());
    myheap.build_max_heap();
    PriorityQueue myqueue(&myheap);
    myqueue.showqueue();
    cout << myqueue.MaxMum() << endl;
    myqueue.Insert(3.4);
    myqueue.showqueue();
    myqueue.Insert(12);
    myqueue.showqueue();
    return 0;
}
