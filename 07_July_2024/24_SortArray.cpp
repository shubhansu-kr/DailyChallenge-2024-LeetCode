// https://leetcode.com/problems/sort-an-array/?envType=daily-question&envId=2024-07-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

void swapValue(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
	return;
}

void InsertionSort(int arr[], int *begin, int *end)
{
	int left = begin - arr;
	int right = end - arr;

	for (int i = left+1; i <= right; i++)
	{
		int key = arr[i];
		int j = i-1;

		while (j >= left && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
}

return;
}

int* Partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;

			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (arr + i + 1);
}

int *MedianOfThree(int * a, int * b, int * c)
{
	if (*a < *b && *b < *c)
		return (b);

	if (*a < *c && *c <= *b)
		return (c);

	if (*b <= *a && *a < *c)
		return (a);

	if (*b < *c && *c <= *a)
		return (c);

	if (*c <= *a && *a < *b)
		return (a);

	if (*c <= *b && *b <= *c)
		return (b);
}

void IntrosortUtil(int arr[], int * begin, int * end, int depthLimit)
{
	int size = end - begin;

	if (size < 16)
	{
		InsertionSort(arr, begin, end);
		return;
	}

	if (depthLimit == 0)
	{
		make_heap(begin, end+1);
		sort_heap(begin, end+1);
		return;
	}

	int * pivot = MedianOfThree(begin, begin+size/2, end);

	swapValue(pivot, end);

	int * partitionPoint = Partition(arr, begin-arr, end-arr);
	IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1);
	IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

	return;
}

void Introsort(int arr[], int *begin, int *end)
{
	int depthLimit = 2 * log(end-begin);
	IntrosortUtil(arr, begin, end, depthLimit);
	return;
}

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}