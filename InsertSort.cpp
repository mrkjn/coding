#include <iostream>

using namespace std;

class Insertsort
{
private:
    float *data;
    int datalength;
public:
    Insertsort(float *tempdata, int length);
    void sortdata();
    void showsort();
};
Insertsort::Insertsort(float *tempdata, int length)
{
    data = tempdata;
    datalength = length;
}
void Insertsort::sortdata()
{
    for(int i = 1; i < datalength; i++)
    {
        float key = data[i];
        int n = i;
        while(n > 0 && key < data[n-1])
        {
            data[n] = data[n-1];
            n--;
        }
        data[n] = key;
    }
}
void Insertsort::showsort()
{
    cout << "the sort result:" << endl;
    for(int i = 0; i < datalength; i++)
        cout << data[i] << endl;
}
int main(int argc, char *argv[])
{
  float a[10] = {1.0, 4.0, 2.0, 5.0, 7.0, 10.0, 21.0, 3.0, 15.0, 15.0};
  Insertsort mysort = Insertsort(a, sizeof(a)/sizeof(float));
  mysort.sortdata();
  mysort.showsort();
  return 0;
}
