#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int arr[], int k, int size){
 priority_queue<int> pq;
 for(int i=0;i<k;i++){
   pq.push(arr[i]);
 }

 int j=0;
 for(int i=k;i<size;i++){
   arr[j]=pq.top();
   pq.pop();
   pq.push(arr[i]);
   j++;
 }

 while(!pq.empty()){
   arr[j]=pq.top();
   pq.pop();
   j++;
 }

}

int main(){
  int arr[5]={10,12,6,7,9};
  int k=3;
  int size=5;

  kSortedArray(arr,k,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}