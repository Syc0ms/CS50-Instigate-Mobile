#include <iostream>
#include <iomanip>

using namespace std;

void generate_array(int size, int arr[]);
void print_array(int size, int arr[]);
void bubleSort(int size, int arr[]);
void selectionSort(int size, int arr[]);
void mergeSort(int arr[], int start, int end);
void merge (int arr[], int start, int mid, int end);
void insertionSort (int size, int arr[]);
int devide(int arr[], int start, int end); 
void quickSort (int arr[], int start, int end);
void swap(int *a, int *b);


int main()
{
        const int sizeOfArray1 = 10000;
        const int sizeOfArray2 = 50000;
        const int sizeOfArray3 = 100000;

        int arr1[sizeOfArray1];
        int arr2[sizeOfArray2];
        int arr3[sizeOfArray3];

        generate_array(sizeOfArray1, arr1);
        generate_array(sizeOfArray2, arr2);
        generate_array(sizeOfArray3, arr3);
        
        bubleSort(sizeOfArray1, arr1);
        print_array(sizeOfArray1, arr1);
        bubleSort(sizeOfArray2, arr2);
        print_array(sizeOfArray2, arr2);
        bubleSort(sizeOfArray3, arr3);
        print_array(sizeOfArray3, arr3);

        selectionSort(sizeOfArray1, arr1);
        print_array(sizeOfArray1, arr1);
        selectionSort(sizeOfArray2, arr2);
        print_array(sizeOfArray2, arr2);
        selectionSort(sizeOfArray3, arr3);
        print_array(sizeOfArray3, arr3);

        insertionSort(sizeOfArray1, arr1);
        print_array(sizeOfArray1, arr1);
        insertionSort(sizeOfArray2, arr2);
        print_array(sizeOfArray2, arr2);
        insertionSort(sizeOfArray3, arr3);
        print_array(sizeOfArray3, arr3);

        mergeSort(arr1, 0, sizeOfArray1 - 1);
        print_array(sizeOfArray1, arr1);
        mergeSort(arr2, 0, sizeOfArray2 - 1);
        print_array(sizeOfArray2, arr2);
        mergeSort(arr3, 0, sizeOfArray3 - 1);
        print_array(sizeOfArray3, arr3);

        quickSort(arr1, 0, sizeOfArray1 - 1);
        print_array(sizeOfArray1, arr1);
        quickSort(arr2, 0, sizeOfArray2 - 1);
        print_array(sizeOfArray2, arr2);
        quickSort(arr3, 0, sizeOfArray3 - 1);
        print_array(sizeOfArray3, arr3);
}
void generate_array(int size, int arr[])
{

        for (int i = 0; i < size; i++)
        {
                arr[i]= rand() % size;
        }           
}

void print_array(int size, int arr[])
{
        clock_t time;
        time = clock();
	for (int i = 0; i < size; i++) {		
		std::cout << arr[i] << "\n";
	}
        time = clock() - time;
        cout << "\nThe time that the computer needs to solve the problem is: "
        << std::fixed << std::setprecision(6) << (float)time/CLOCKS_PER_SEC
        << " seconds" << endl;
}
void bubleSort(int size, int arr[])
{
        bool swapped = false;
        for(int i = 0; i < size; i++)
        {
                for(int j = i + 1; j < size; j++)
                {
                        if(arr[j] < arr[i])
                        {
                               swap(arr[i], arr[j]);
                        }

                }
        }
}
void selectionSort(int size, int arr[])
{
    for (int i = 0; i < size - 1; i++)
    {

        int smallestPosition = i;
        for (int j = i + 1; j < size; j++){
                if (arr[j] < arr[smallestPosition])
                {
                        smallestPosition = j;
                }
        }
        if(smallestPosition!=i){
                swap(arr[smallestPosition], arr[i]);
        }
    }
}
void mergeSort(int arr[], int start, int end) {
        if (start + 1 < end) {
                int mid = (end + start) / 2;
                mergeSort(arr, start, mid);
                mergeSort(arr, mid, end);
                merge(arr, start, mid, end);
        }
}

void merge (int arr[], int start, int mid, int end)
{
        int* merged = new int[end - start];
        int i = 0;
        int i1 = start;
        int i2 = mid;
        while(i1 < mid && i2 < end) {
                int merged_item;
                if(arr[i1] < arr[i2]) {
                        merged_item = arr[i1];
                        i1++;
                } else {
                        merged_item = arr[i2];
                        i2++;
                }
                merged[i] = merged_item;
                i++;
        }
        while(i1 < mid) {
                merged[i++] = arr[i1++];
        }
        while(i2 < end) {
                merged[i++] = arr[i2++];
        }
        for(int i = start; i < end; i++) {
                arr[i] = merged[i - start];
        }


}

void insertionSort (int size, int arr[])
{
        for(int index = 1; index < size; index++)   
        {  
                int indexTemp = arr[index];  
                int lastIndex = index - 1;  
                while(lastIndex >= 0 && indexTemp <= arr[lastIndex])  
                {  
                    arr[lastIndex+1] = arr[lastIndex];   
                    lastIndex = lastIndex - 1;
                }  
                arr[lastIndex+1] = indexTemp;  
        }  
}
int devide(int arr[], int start, int end) 
{

        int pivot = arr[end];
        int i = (start - 1);

        for (int j = start; j < end; j++) 
        {
                if (arr[j] <= pivot)
                { 
                        i++;
                        swap(&arr[i], &arr[j]);
                
                }
        }

        swap(&arr[i + 1], &arr[end]);
        return (i + 1);
}
void quickSort (int arr[], int start, int end)
{
        if (start < end) {
                int pi = devide(arr, start, end);

                quickSort(arr, start, pi - 1);
                quickSort(arr, pi + 1, end);
        }
}
void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}
