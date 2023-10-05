
#include <bits/stdc++.h>

using namespace std;


void merge(vector<int> & input, int begin, int mid,  int end){
  vector<int> responseBuildHelper;

  int arrOneTracker, arrTwoTracker;

  arrOneTracker = begin;
  arrTwoTracker = mid + 1;
  

// ordinary merge sort 
  while(arrOneTracker <= mid && arrTwoTracker <= end){
    if( input[arrOneTracker] == 0 || input[arrTwoTracker] == 0 ){
      if(input[arrOneTracker] == 0){
          responseBuildHelper.push_back(input[arrTwoTracker]);
          arrTwoTracker++;
      } else {
          responseBuildHelper.push_back(input[arrOneTracker]);
          arrOneTracker++;
      }
    } else {
        if(input[arrOneTracker] < input[arrTwoTracker]){
            responseBuildHelper.push_back(input[arrOneTracker]);
            arrOneTracker++;
    } else {
        responseBuildHelper.push_back(input[arrTwoTracker]);
        arrTwoTracker++;
        }
    }
  }

  while(arrOneTracker <= mid){
    responseBuildHelper.push_back(input[arrOneTracker]);
    arrOneTracker++;
  }
  while(arrTwoTracker <= end){
    responseBuildHelper.push_back(input[arrTwoTracker]);
    arrTwoTracker++;
  }


  for(int k = 0, i = begin; i <= end; k++, i++){
    input[i] = responseBuildHelper[k];
  }
}

void mergesort(vector<int> & input, int begin, int end){
  int mid = (begin + end)/2;

  if(begin<end){
    mergesort(input, begin, mid);
    mergesort(input, mid+1, end);
    merge(input, begin, mid, end);
  }
}

  
int main()
{
    vector<int> input = {0, -1, 23,1,12,0};
    mergesort( input, 0, input.size() -1);
    
    cout<< "Vetor Ordenado: " <<endl;
    for(int i = 0; i <  input.size() ; i++){
        cout<< " " << input[i];
    }
}
