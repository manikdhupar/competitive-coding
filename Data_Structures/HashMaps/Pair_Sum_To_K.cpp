#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
  int arr[7]={-2,-2,12,8,4,6,2};
  unordered_map<int,int> result;
  for(int i=0;i<7;i++){
    result[arr[i]]++;
    int temp=10-arr[i];
    if(result[temp]!=0){
      int count1=result[temp];
      int count2=result[arr[i]];
      int counter=count1*count2;
      while(counter>0){
      cout<<arr[i]<<" "<<temp<<endl;
      counter--;
      }
      result[arr[i]]=0;
      result[temp]=0;
    }
  }

}