/* Tyler Eccles
 * CSC413 Course Project, Due March 29th, 2023.
 * Find the inversions of the array contained in the integers.txt file.
 * Then, sort the array using a divide-and-conquer algorithm.
 */
#include <iostream>
#include <fstream>
#include <ctime>

int main(){
    int size = 100000;
    long long inversions = 0;
    int numArray[size];
    int inversionsOnIteration = 0;
    std::ifstream inFile;
    clock_t startClock = clock();
    
    inFile.open("IntegerArray.txt");
    
    for(int i = 0; i < size; i++)
    {
        inFile >> numArray[i];
    }

    
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(numArray[i] > numArray[j])
            {
                inversions++;
                inversionsOnIteration++;
            }
        }
        std::cout << "For i = " << i << " there were " << inversionsOnIteration << " inversions.\n";
        inversionsOnIteration = 0;
    }
    std::cout << "\nInversions: " << inversions << "\n Calculated in " << (clock() - startClock)/CLOCKS_PER_SEC << "seconds" <<'\n';
    
    inFile.close();
    
    return 0;
}