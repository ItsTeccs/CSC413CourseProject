/* Tyler Eccles
 * CSC413 Course Project, Due March 29th, 2023.
 * Find the inversions of the array contained in the integers.txt file.
 * Then, sort the array using a divide-and-conquer algorithm.
 */
#include <iostream>
#include <fstream>

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main(){
    int size = 100000;
    unsigned long long inversions = 0;
    int numArray[size];
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open("IntegerArray.txt");
    outFile.open("WorstCaseArray.txt");
    
    for(int i = 0; i < size; i++)
    {
        inFile >> numArray[i];
    }

    /*
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(numArray[i] > numArray[j])
            {
                inversions++;
            }
        }
    }
    std::cout << "\nInversions: " << inversions << '\n';
    */

    quickSort(numArray, 0, size);

    int numArrayWorst[size];

    for(int i = size - 1; i >= 0; i--)
    {
        numArrayWorst[(size - 1) - i] = numArray[i];
    }

    for(int i = 0; i < size; i++)
    {
        outFile << numArrayWorst[i] << '\n';
    }

    inFile.close();
    outFile.close();
    
    std::cout << "halted\n";
    return 0;
}