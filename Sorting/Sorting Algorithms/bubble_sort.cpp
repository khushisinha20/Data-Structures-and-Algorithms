//Works by repeatedly swapping the adjacent elements if they are in the wrong order

//Time Complexity O(n ^ 2)

//Space Complexity O(1)

//Stable

class Solution {
public:
    void bubbleSort(int arr[], int n) {
        for (int i = n - 1; i >= 0; --i) {
            bool swapped = false;
            for (int j = 0; j < i; ++j) { 
                if (arr[j] > arr[j + 1]) { 
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            if (!swapped)
                break;
        }
    }
};