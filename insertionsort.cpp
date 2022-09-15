#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int arr[4] = {2,1,4,3};
    for(int i = 1;i<4;i++)
    {
        int value = arr[i];
        int hole = i ;
        while(hole>0 && arr[hole-1] > arr[hole])
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
    for(int i = 0;i<4;i++)
    cout<<arr[i]<<" ";
    return 0;
}
