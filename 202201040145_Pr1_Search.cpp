#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<chrono>

using namespace std;
using namespace std::chrono;

int LinearSearch(long  arr[] , int size , int target){
    for(int i = 0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}


int RecursiveBinary(long arr[] , int size , int target, int start , int end){
    while(start<=end){
        long mid = start + (end - start)/2;
        if(target<arr[mid]){
           return RecursiveBinary(arr,size,target,start,mid-1);
        }else if(target>arr[mid]){
           return RecursiveBinary(arr,size,target,mid+1,end);
        }else{
            return mid;
        }
    }return -1;
}


int BinarySearch(long  arr[], int size , int target){
    long start = 0;
    long end = size-1;

    while(start<=end){
        int mid = start + (end - start) /2;
        if(target == arr[mid]){
            return mid;
        }else if(target > arr[mid]){
            start = mid+1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    srand(time(0));
    long long  size;

    cout<<"ENter the Size of array :";
    cin>>size;

    long arr[size];

    for(int i = 0 ; i < size ; i++){
        arr[i]=rand();
    }
    sort(arr,arr+size);

    // for(int i = 0 ; i < size ;i++){
    //     cout<<arr[i]<<" "<<endl;
    // }

    long start = 0;
    long end = size-1;

    long index = rand() % size;
    long target = arr[index];

    cout<<"Target "<<target<<endl;

    auto start1 = high_resolution_clock::now();
    int result1 = LinearSearch(arr,size,target);
    auto end1 = high_resolution_clock::now();

    auto TimeofLinearSearch = duration_cast<nanoseconds>(end1-start1);

    auto start2 = high_resolution_clock::now();
    int result2=BinarySearch(arr,size,target);
    auto end2 = high_resolution_clock::now();

    auto TimeofBinarySearch = duration_cast<nanoseconds>(end2 - start2);

    auto start3 = high_resolution_clock::now();
    int result3 = RecursiveBinary(arr,size,target,start,end);
    auto end3 = high_resolution_clock::now();

    auto TimeofRecursiveBS = duration_cast<nanoseconds> (end3 - start3);

    cout<<"Element found at index "<<result1<<" and time for Linear search is "<<TimeofLinearSearch.count()<<endl;
    cout<<"Element found at index "<<result2<<" and time for Binary search is "<<TimeofBinarySearch.count()<<endl;
    cout<<"Element found at index "<<result3<<" and time for the Recursive Binary search is "<<TimeofRecursiveBS.count()<<endl;

    return 0;
}