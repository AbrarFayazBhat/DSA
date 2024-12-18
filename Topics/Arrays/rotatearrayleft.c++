#include <iostream>
using namespace std;
//Rotate Array using Reversal Algorithm
// void Reverse(int arr[], int start, int end)
// {
//   while (start <= end)
//   {
//     int temp = arr[start];
//     arr[start] = arr[end];
//     arr[end] = temp;
//     start++;
//     end--;
//   }
// }
// // Function to Rotate k elements to left
// void Rotateeletoleft(int arr[], int n, int k)
// {
//   // Reverse first k elements
//   Reverse(arr, 0, k - 1);
//   // Reverse last n-k elements
//   Reverse(arr, k, n - 1);
//   // Reverse whole array
//   Reverse(arr, 0, n - 1);
// }
void Rotatetoleft(int arr[], int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = 0; i < k; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < n - k; i++)
  {
    arr[i] = arr[i + k];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = temp[i - n + k];
  }
}
int main()
{
  int n = 7;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int k = 2;
  Rotatetoleft(arr, n, k);
  cout << "After Rotating the elements to left " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}