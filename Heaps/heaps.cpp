#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &vc)
{
    for (auto i : vc)
    {
        cout << i << " ";
    }
    cout << endl;
}
// Min Heap with Min Element

// int main(){
//     vector<int> arr={1,2,3,4,5,6,7};

//     make_heap(arr.begin(),arr.end(),greater<int>());

//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"Min Element: "<<arr.front();
// }

// Max Heap with Max Element

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

//     make_heap(arr.begin(), arr.end());

//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << "Max Element: " << arr.front();
// }

//Insert an ELement

// int main(){
//     vector<int> arr= {1,2,3,4,5,6,7};
//     make_heap(arr.begin(),arr.end());

//     arr.push_back(10);
//     print(arr);
//     push_heap(arr.begin(),arr.end());
//     print(arr);
// }

//Remove an Element

// int main(){
//     vector<int> arr ={1,2,3,4,5,6,7};
//     make_heap(arr.begin(),arr.end());
//     print(arr);
//     pop_heap(arr.begin(),arr.end());
//     print(arr);
//     arr.pop_back();
//     print(arr);
//     return 0;
// }

//Sort Heap Heap Sort

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     make_heap(arr.begin(), arr.end());
//     print(arr);
//     sort_heap(arr.begin(),arr.end());
//     print(arr);
//     return 0;
// }

//is Heap
//Automatically checks for max heap but can check for min heap if we add greater<int>()
int main(){
    vector<int> arr={1,2,3,4,5};
    make_heap(arr.begin(),arr.end(),greater<int>());
    cout<<is_heap(arr.begin(),arr.end(),greater<int>());
}