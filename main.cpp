#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n, totalSum = 0, bigSum, smallSum;
    cin>>n;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin>>coins[i];
        totalSum += coins[i];
    }
    selectionSort(coins, n);

    int j;
    bigSum = coins[n - 1];
    smallSum = totalSum - bigSum;
    for(j = 2; j <= n && bigSum <= smallSum; j++){
            bigSum += coins[n - j];
            smallSum = totalSum - bigSum;
    }
    cout<<j - 1;

    return 0;
}
