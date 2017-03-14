#include <iostream>
using namespace std;
typedef float datatype;
typedef int lengthtype;
#define MAX_NEG_NUM -100000.0;

struct maxnumtem
{
    datatype max_num;
    int min_key;
    int max_key;
};
class Maxnumsubarray
{
    private:
     datatype *data;
     lengthtype datalength;
     maxnumtem find_max_cross_subarray(datatype *tempdata, lengthtype p, lengthtype mid, lengthtype q);
    public:
     Maxnumsubarray(datatype *inidata, lengthtype inilength);
     maxnumtem find_max_subarray(datatype *tempdata, lengthtype p, lengthtype q);
};
Maxnumsubarray::Maxnumsubarray(datatype *inidata, lengthtype inilength)
{
    data = inidata;
    datalength = inilength;
}
maxnumtem Maxnumsubarray::find_max_subarray(datatype *tempdata, lengthtype p , lengthtype q )
{
    if(p == q)
    {
        maxnumtem sigle_max;
        sigle_max.max_key = q;
        sigle_max.min_key = p;
        sigle_max.max_num = tempdata[p];
        return sigle_max;
    }
    else
    {
        int mid  = (q+p)/2;
        maxnumtem left_max = find_max_subarray(tempdata, p, mid);
        maxnumtem right_max = find_max_subarray(tempdata, mid+1, q);
        maxnumtem mid_max = find_max_cross_subarray(tempdata, p, mid, q);
        if(left_max.max_num >= right_max.max_num && left_max.max_num >= mid_max.max_num)
            return left_max;
        if(right_max.max_num >= left_max.max_num && right_max.max_num >= mid_max.max_num)
            return right_max;
        if(mid_max.max_num >= left_max.max_num && mid_max.max_num >= right_max.max_num)
            return mid_max;
    }
}
maxnumtem Maxnumsubarray::find_max_cross_subarray(datatype *tempdata, lengthtype p, lengthtype mid,
                                                  lengthtype q)
{
    maxnumtem retrntep;
    datatype leftmax = MAX_NEG_NUM;
    datatype rightmax = MAX_NEG_NUM;
    datatype left_tempsum = 0.0;
    datatype right_tempsum = 0.0;
    int leftkey = -1;
    int rightkey = -1;

    for(int i = mid; i >= p; i--)
    {
        left_tempsum += tempdata[i];
        if(left_tempsum > leftmax)
        {
           leftmax = left_tempsum;
           leftkey = i;
        }
    }
    for(int i = mid+1; i <= q; i++)
    {
       right_tempsum += tempdata[i];
       if(right_tempsum > rightmax)
       {
          rightmax = right_tempsum;
          rightkey = i;
       }
    }
    retrntep.min_key = leftkey;
    retrntep.max_key = rightkey;
    retrntep.max_num = leftmax + rightmax;
    return retrntep;
}
int main(int argc, char *argv[])
{
   datatype a[6] = {1, -1, 2, -1, 5, 4};
   maxnumtem maxnumarray;
   Maxnumsubarray mymaxnumsubarray = Maxnumsubarray(a, 6);
   maxnumarray = mymaxnumsubarray.find_max_subarray(a, 0, 5);
   cout << maxnumarray.min_key << endl << maxnumarray.max_key <<endl;
   return 0;
}
