void mergeSort(vector<int> * vector, int start, int end, int size){ // recursive merge sort O(N.log(N)) for time, space depends on the call stack
  int mid = (start + end) / 2;
  if(start < end){
    mergeSort( vector, start, mid, size );
    mergeSort( vector, mid + 1, end, size );
    merge( vector, start, mid, end);
  };
}

void merge(vector<int>* vet, int start, int mid, int end){ // merge sub arrays
  

  int firstArrayTracker, secondArrayTracker, originalArrayTracker;
  firstArrayTracker = start;
  secondArrayTracker = mid + 1;
  originalArrayTracker = 0;
  vector<int> aux_vector;
  while(firstArrayTracker <= mid && secondArrayTracker <= end){
    if(vet[firstArrayTracker] == 0 && vet[secondArrayTracker] != 0){ // validate for entry[i] == 0

    } else if(vet[secondArrayTracker] == 0 && vet[firstArrayTracker] != 0) { // validate for entry[i + 1] == 0 ( maybe not needed )

    } if(vet[firstArrayTracker] < vet[secondArrayTracker]){ // normal sorting
      aux_vector[originalArrayTracker] = vet[firstArrayTracker];
      firstArrayTracker++;
    } else{
      aux_vector[originalArrayTracker] = vet[secondArrayTracker];
      secondArrayTracker++;
    }
    originalArrayTracker++;
  }
}