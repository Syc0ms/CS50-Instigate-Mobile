#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

void print_array(std::vector<int> arr, int size);
void generate_array(const int size, std::vector<int>* arr);
void bubleSort(std::vector< int> *arr, int size);
void selectionSort(std::vector<int> *arr,int size);

int main()
{
        const int s1 = 100;
        const int s2 = 500;
        const int s3 = 1000;

        std::vector<int> arr1;
        std::vector<int> arr2;
        std::vector<int> arr3;

        generate_array(s1, &arr1);
        generate_array(s2, &arr2);
        generate_array(s3, &arr3);

        bubleSort(&arr1, s1);
        print_array(arr1, s1);

        bubleSort(&arr2, s2);
        print_array(arr2, s2);

        bubleSort(&arr3, s3);
        print_array(arr3, s3);

        selectionSort(&arr1, s1);
        print_array(arr1, s1);
        selectionSort(&arr2, s2);
        print_array(arr2, s2);
        selectionSort(&arr3, s3);
        print_array(arr3, s3);

}

void print_array(std::vector<int> arr, int size)
{
        clock_t time;
        time = clock();
        for (int i = 0; i < size; i++) {
                std::cout << arr.at(i) << "\n";
        }
        time = clock() - time;
        cout << "\nThe time that the computer needs to solve the problem is: "
        << std::fixed << std::setprecision(6) << (float)time/CLOCKS_PER_SEC
        << " seconds" << endl;
}

void generate_array(const int size, std::vector<int>* arr)
{
        int value;
        for (int i = 0; i < size; i++) {
                value = rand() % size;
                arr->push_back(value);
        }

}

void bubleSort(std::vector<int> *arr,int size)
{
        int temp;
        bool swapped = false;
        for(int i = 0; i < size; i++)
        {
                for(int j = i+1; j < size; j++)
                {
                        if(arr->at(j) < arr->at(i))
                        {
                               temp = arr->at(i);
                               arr->at(i)= arr->at(j);
                               arr->at(j) = temp;
                        }
        
                }        
        }
}

void selectionSort(std::vector<int> *arr,int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        int smallestPosition = i;
        for (int j = i + 1; j < size; j++){
                if (arr->at(j) < arr->at(smallestPosition))
                {
                        smallestPosition = j;
                }
        }
        if(smallestPosition!=i){
                int temp;
                temp = arr->at(smallestPosition);
                arr->at(smallestPosition) = arr->at(i);
                arr->at(i) = temp;

        }
    }
}
