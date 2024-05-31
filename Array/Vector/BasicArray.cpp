#include <bits/stdc++.h>
using namespace std;

// Largest Element
//  int main(){
//      int size;
//      cout<<"Size of the array: ";
//      cin>>size;
//      int arr[size];
//      for(int i=0;i<size;i++){
//          cin>>arr[i];
//      }
//      sort(arr,arr+size);
//      cout<<"Largest Element: "<<arr[size-1];
//      return 0;
//  }

// K Largest
//  int main()
//  {
//      int size;
//      cout << "Size of the array: ";
//      cin >> size;
//      int arr[size];
//      for (int i = 0; i < size; i++)
//      {
//          cin >> arr[i];
//      }
//      cout<<"K=";
//      int k;
//      cin>>k;
//      sort(arr, arr + size);
//      cout << k<<" Largest Element: " << arr[size - k];
//      return 0;
//  }

// Check If array is sorted
// int main()
// {
//     vector<int> v;
//     int input;
//     while (cin >> input && input != -1)
//     {
//         v.push_back(input);
//     }
//     bool flag = true;
//     for (int i = 0; i < v.size()-1; i++)
//     {
//         if (v[i] > v[i+1])
//         {
//             flag = false;
//             break;
//         }
//     }
//     cout << flag;
//     return 0;
// }

//Remove Duplicates from sorted array

// int remove_duplicates(int arr[],int n){
//     int i=0;
//     for(int j=1;j<n;j++){
//         if(arr[i]!=arr[j]){
//             i++;
//             arr[i]=arr[j];
//         }
//     }
//     return i+1;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k = remove_duplicates(arr,n);
//     for(int i=0;i<k;i++){
//         cout<<arr[i]<<" ";
//     }
// }

//Remove Duplicates of an vector with preserving the order

vector<int> remove_duplicates(vector<int> &arr){
    unordered_set<int> seen;
    vector<int> unique;

    for (const int &element : arr){
        if (seen.insert(element).second){ // If the element was successfully inserted (not a duplicate)
            unique.push_back(element);
        }
    }
    return unique;
}

int main(){
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    vector<int> arr;
    
    cout << "Enter the elements of the vector:" << endl;
    for (int i = 0; i < size; i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }

    vector<int> result = remove_duplicates(arr);

    cout << "The vector after removing duplicate elements is: ";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}