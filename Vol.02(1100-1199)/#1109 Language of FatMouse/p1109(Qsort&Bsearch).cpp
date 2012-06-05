// Quicksort + Binary Search
// Average O(N*logN + M*logN) 
// 10s TLE 

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct record {
  string key;
  string word;
};

int partition(vector<record>& A, int l, int r) {
  string p = A[l].key;
  int i = l, j = r + 1;
  record temp;
  do {
    do {i++;} while(A[i].key < p);
    do {j--;} while(A[j].key > p);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  } while(i < j);
  temp = A[i];
  A[i] = A[j];
  A[j] = A[l];
  A[l] = temp;
  return j;
}

void quickSort(vector<record>& A, int l, int r) {
  if(l < r) {
    int s = partition(A, l, r);
    quickSort(A, l, s - 1);
    quickSort(A, s + 1, r);
  }
}

int binarySearch(vector<record> A, int n, string key) {
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = (l + r) / 2;
    if(key == A[m].key)
      return m;
    else if(key < A[m].key)
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

int main() {
  vector<record> dictionary;
  dictionary.resize(100006);
  string temp;
  int N = 0;
  while(getline(cin, temp)) {
    if(!temp.size()) 
      break;
    int pos = temp.find(' ');
    dictionary[N].key = temp.substr(pos + 1);
    dictionary[N].word = temp.substr(0,pos);
    N++;
  }
  dictionary[N].key = "~~";                 // A maximum string as Sentinel
  quickSort(dictionary, 0, N - 1);
  while(cin >> temp) {
    int n = binarySearch(dictionary, N, temp);
    if(n == -1) cout << "eh" << endl;
    else cout << dictionary[n].word << endl;
  }
} 
