#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


int* generateArray(int size, int arr[]);
int* copyArray (int size, int arr[], int newArr[]);
void printArray(int size, int arr[]);
void printTime (time_t startTime, time_t endTime, clock_t time);
void init();
void initBubbleSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA);
void initSelectionSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA); 
void initInsertionSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA);
void initMergeSort(int arr[], int start, int end, int size, int newArr[], clock_t timeA);
void initQuickSort(int arr[], int start, int end, int size, int newArr[], clock_t timeA);
void bubleSort(int size, int arr[]);
void selectionSort(int size, int arr[], time_t startTime, time_t endTime);
void insertionSort (int size, int arr[], time_t startTime, time_t endTime);
void mergeSort(int arr[], int start, int end, int size);
void merge (int arr[], int start, int mid, int end, int size);
void quickSort (int arr[], int start, int end, int size);
int devide(int arr[], int start, int end, int size); 
void swap(int *a, int *b);


int main() {
        init();
}

void init() {

        const int SIZEOFARRAY1 = 10000;
        const int SIZEOFARRAY2 = 50000;
        const int SIZEOFARRAY3 = 100000;

        int arr1[SIZEOFARRAY1];
        int arr2[SIZEOFARRAY2];
        int arr3[SIZEOFARRAY3];

        int newArr1[SIZEOFARRAY1];
        int newArr2[SIZEOFARRAY2];
        int newArr3[SIZEOFARRAY3];
        
        time_t startTime, endTime;
        clock_t timeA;

        generateArray(SIZEOFARRAY1, arr1);
        generateArray(SIZEOFARRAY2, arr2);
        generateArray(SIZEOFARRAY3, arr3);

        cout << "\n" << "Bubble sort is working, wait..." << "\n";
        initBubbleSort(SIZEOFARRAY1, arr1, newArr1, 0, 0, timeA); 
        initBubbleSort(SIZEOFARRAY2, arr2, newArr2, startTime, endTime, 0); 
        initBubbleSort(SIZEOFARRAY3, arr3, newArr3, startTime, endTime, 0); 

        cout << "\n" << "Selection sort is working, wait..." << "\n";
        initSelectionSort(SIZEOFARRAY1, arr1, newArr1, 0, 0, timeA);
        initSelectionSort(SIZEOFARRAY2, arr2, newArr2, startTime, endTime, 0);
        initSelectionSort(SIZEOFARRAY3, arr3, newArr3, startTime, endTime, 0);

        cout << "\n" << "Insertion sort is working, wait..." << "\n";
        initInsertionSort(SIZEOFARRAY1, arr1, newArr1, 0, 0, timeA);
        initInsertionSort(SIZEOFARRAY2, arr2, newArr2, startTime, endTime, 0);
        initInsertionSort(SIZEOFARRAY3, arr3, newArr3, startTime, endTime, 0);

        cout << "\n" <<"Merge sort is working, wait..." << "\n";
        initMergeSort(arr1, 0, SIZEOFARRAY1 - 1, SIZEOFARRAY1, newArr1, timeA);
        initMergeSort(arr2, 0, SIZEOFARRAY2 - 1, SIZEOFARRAY2, newArr2, timeA);
        initMergeSort(arr3, 0, SIZEOFARRAY3 - 1, SIZEOFARRAY3, newArr3, timeA);

        cout << "\n" <<"Quick sort is working, wait..." << "\n";
        initQuickSort(arr1, 0, SIZEOFARRAY1 - 1, SIZEOFARRAY1, newArr1, timeA);
        initQuickSort(arr2, 0, SIZEOFARRAY2 - 1, SIZEOFARRAY2, newArr2, timeA);
        initQuickSort(arr3, 0, SIZEOFARRAY3 - 1, SIZEOFARRAY3, newArr3, timeA);

}

void initBubbleSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA) {
        if(timeA) {
                copyArray(size, arr, newArr);
                timeA = clock();
                bubleSort(size, newArr);
                timeA = clock() - timeA;
                printTime(0, 0, timeA);
        } else {
                copyArray(size, arr, newArr);
                time(&startTime);
                bubleSort(size, newArr);
                time(&endTime);
                printTime(startTime, endTime, 0);
        }
}

void initSelectionSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA) {
        if (timeA) {
                copyArray(size, arr, newArr);
                timeA = clock();
                selectionSort(size, newArr, startTime, endTime);
                timeA = clock() - timeA;
                printTime(0, 0, timeA);
        } else {
                copyArray(size, arr, newArr);
                time(&startTime);
                selectionSort(size, newArr, startTime, endTime);
                time(&endTime);
                printTime(startTime, endTime, 0);
        }
}

void initInsertionSort(int size, int arr[], int newArr[], time_t startTime, time_t endTime, clock_t timeA) {
        if (timeA){
                copyArray(size, arr, newArr);
                timeA = clock();
                insertionSort(size, newArr, startTime, endTime);
                timeA = clock() - timeA;
                printTime(0, 0, timeA);
        } else {
                copyArray(size, arr, newArr);
                time(&startTime);
                insertionSort(size, newArr, startTime, endTime);
                time(&endTime);
                printTime(startTime, endTime, 0);
        }
}
        
void initMergeSort(int arr[], int start, int end, int size, int newArr[], clock_t timeA) {
        copyArray(size, arr, newArr);
        timeA = clock();
        mergeSort(newArr, start, end, size);
        timeA = clock() - timeA;
        printTime(0, 0, timeA);

}

void initQuickSort(int arr[], int start, int end, int size, int newArr[], clock_t timeA) {
        copyArray(size, arr, newArr);
        timeA = clock();
        quickSort(newArr, start, end, size);
        timeA = clock() - timeA;
        printTime(0, 0, timeA);
}


int* generateArray(int size, int arr[]) {
        for (int i = 0; i < size; i++) {
                arr[i] = rand() % size;
        }           
        return arr;
}

int* copyArray (int size, int arr[], int newArr[]){
        for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
        }
        return newArr;
}

void printArray(int size, int newArr[]) {
	for (int i = 0; i < size; i++) {		
		cout << newArr[i] << "\n";
	}
}
void printTime (time_t startTime, time_t endTime, clock_t timeA) {
        if (timeA){
                cout << "\nThe time that the computer needs to solve the problem is: "
        << fixed << setprecision(3) << (float)timeA/CLOCKS_PER_SEC
        << " seconds" << "\n";
        } else {
                cout << "\nThe time that the computer needs to solve the problem is: " << difftime(endTime, startTime) << " seconds" << "\n";
        }
}

void bubleSort(int size, int arr[]) {       
        bool swapped = false;
        for(int i = 0; i < size; i++) {
                for(int j = i + 1; j < size; j++) {
                        if(arr[j] < arr[i]) {
                               swap(arr[i], arr[j]);
                        }

                }
        }
}

void selectionSort(int size, int arr[], time_t startTime, time_t endTime) {
        for (int i = 0; i < size - 1; i++) {
                int smallestPosition = i;
                        for (int j = i + 1; j < size; j++) {
                                if (arr[j] < arr[smallestPosition]) {
                                        smallestPosition = j;
                                }
                        }
                        if(smallestPosition!=i) {
                                swap(arr[smallestPosition], arr[i]);
                        }
         }
}

void mergeSort(int arr[], int start, int end, int size) {
        if (start + 1 < end) {
                int mid = (end + start) / 2;
                mergeSort(arr, start, mid, size);
                mergeSort(arr, mid, end, size);
                merge(arr, start, mid, end, size);
        }
}

void merge (int arr[], int start, int mid, int end, int size) {
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

void insertionSort (int size, int arr[], time_t startTime, time_t endTime) {
        for(int index = 1; index < size; index++) {  
                int indexTemp = arr[index];  
                int lastIndex = index - 1;  
                while(lastIndex >= 0 && indexTemp <= arr[lastIndex]) {  
                    arr[lastIndex+1] = arr[lastIndex];   
                    lastIndex = lastIndex - 1;
                }  
                arr[lastIndex+1] = indexTemp;  
        }  
}

int devide(int arr[], int start, int end, int size) {
        int pivot = arr[end];
        int i = (start - 1);

        for (int j = start; j < end; j++) { 
                if (arr[j] <= pivot) { 
                        i++;
                        swap(&arr[i], &arr[j]);
                
                }
        }
        swap(&arr[i + 1], &arr[end]);
        return (i + 1);
}

void quickSort (int arr[], int start, int end, int size) {
        if (start < end) {
                int pi = devide(arr, start, end, size);
                quickSort(arr, start, pi - 1, size);
                quickSort(arr, pi + 1, end, size);
        }

}

void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
}
