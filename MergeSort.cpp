#include <iostream>
#include <malloc.h>

using namespace std;

class MergeSort
{
   private:
     float *data;
     int datalength;
     //void mergesubsort(float *subtempdata, int p, int mid, int q);
   public:
     MergeSort(float *tempdata, int length);
     void sortdata(float *data, int p, int q);
     void mergesubsort(float *subtempdata, int p, int mid, int q);
     void showsort();
};
MergeSort::MergeSort(float *tempdata, int length)
{
     data = tempdata;
     datalength = length;
}
void MergeSort::mergesubsort(float *subtempdata, int p, int mid, int q)
{
     float *L = (float*)malloc(sizeof(float)*(mid-p+1));
     float *R = (float*)malloc(sizeof(float)*(q-mid));
     int indexsubdata = p;
     int indexL, indexR;
     for(indexL = 0; indexL < mid-p+1; indexL++)
     {
        L[mid-p-indexL] = subtempdata[indexsubdata];
        indexsubdata++;
     }
     for(indexR = 0; indexR < q-mid; indexR++)
     {
        R[q-mid-1-indexR] = subtempdata[indexsubdata];
        indexsubdata++;
     }
     for(indexsubdata = p; indexsubdata < q+1; indexsubdata++)
     {
        if(L[indexL-1] > R[indexR-1]){
          subtempdata[indexsubdata] = L[indexL-1];
          indexL--;
        }
        else{
          subtempdata[indexsubdata] = R[indexR-1];
          indexR--;
        }
        if(0 == indexL || 0 == indexR)
            break;
     }
     if(0 == indexL){
        for(int i = indexsubdata+1; i < q+1; i++){
           subtempdata[i] = R[indexR-1];
           indexR--;
        }
     }
     else{
         for(int i = indexsubdata+1; i < q+1; i++){
           subtempdata[i] = L[indexL-1];
           indexL--;
        }
     }
}
void MergeSort::sortdata(float *data, int p, int q)
{
   if(q > p){
      int mid = (q+p)/2;
      sortdata(data, p, mid);
      sortdata(data, mid+1, q);
      mergesubsort(data, p, mid, q);
   }
}
void MergeSort::showsort()
{
    for(int i = 0; i < datalength; i++)
      cout << data[i] << endl;
}
int main(int argc, char *argv[])
{
   float a[4] = {1, 2, 3, 4};
   MergeSort mysort = MergeSort(a, 4);
   mysort.sortdata(a, 0, 3);
   mysort.showsort();
   return 0;
}
