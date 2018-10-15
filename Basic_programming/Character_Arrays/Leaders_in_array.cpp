#include<iostream>
#include<climits>
using namespace std;

void Leaders(int* arr,int len)
{
    int i;
   for(i=0;i<len;i++){
    int j=i+1;
     if(i==len-1){
       cout<<arr[len-1];
       break;
     }
    while(arr[i]>=arr[j]){
        if(j==len-1){
            cout<<arr[i]<<" ";
          break;
        }
     	j++;
    }
   }
}

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
