#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Sort{
    public:
        virtual void sortNow(vector<int>& arr) = 0;
};

class BubbleSort : public Sort{
    public:
        void sortNow(vector<int>& arr){
            sort(arr.begin(), arr.end());
            cout<<"Sorted using bubble sort"<<endl;
            for(auto i: arr){
                cout<<i<<" ";
            }
            cout<<endl;
        }
};

class MergeSort : public Sort{
    public:
        void sortNow(vector<int>& arr){
            sort(arr.begin(), arr.end());
            cout<<"Sorted using merge sort"<<endl;
            for(auto i: arr){
                cout<<i<<" ";
            }
            cout<<endl;
        }
};

class SortingAlgoContext{
    private:
        Sort* sortingAlgo;
    public:
        SortingAlgoContext(Sort* algo){
            sortingAlgo = algo;
        }

        void setSortingAlgoInContext(Sort* algo){
            sortingAlgo = algo;
            return;
        }

        void performSortAlgo(vector<int>& arr){
            sortingAlgo->sortNow(arr);
            return;
        }
};

int main(){
    vector<int> arr1 = {9,3,5,7};
    vector<int> arr2 = {1,3,4,6,3,21,4,5};

    SortingAlgoContext* context = new SortingAlgoContext(new BubbleSort());
    context->performSortAlgo(arr1);

    context->setSortingAlgoInContext(new MergeSort());
    context->performSortAlgo(arr2);

    return 0;
}