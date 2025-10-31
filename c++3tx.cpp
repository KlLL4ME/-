#include <iostream>
using namespace std;

// 1. Сортировка выбором (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 3. Сортировка вставками (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 4. Сортировка слиянием (Merge Sort)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 7. Пирамидальная сортировка (Heap Sort)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 9. Бинарный поиск (Binary Search)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// 10. Интерполяционный поиск (Interpolation Search)
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    cout << "1. Сортировка выбором" << endl;
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Исходный массив: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    selectionSort(arr1, n1);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    cout << "3. Сортировка вставками" << endl;
    int arr3[] = {12, 11, 13, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Исходный массив: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    insertionSort(arr3, n3);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
cout << endl << endl;

    cout << "4. Сортировка слиянием" << endl;
    int arr4[] = {38, 27, 43, 3, 9, 82, 10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Исходный массив: ";
    for (int i = 0; i < n4; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;
    mergeSort(arr4, 0, n4 - 1);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n4; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl << endl;

    cout << "7. Пирамидальная сортировка" << endl;
    int arr7[] = {12, 11, 13, 5, 6, 7};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    cout << "Исходный массив: ";
    for (int i = 0; i < n7; i++) {
        cout << arr7[i] << " ";
    }
    cout << endl;
    heapSort(arr7, n7);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n7; i++) {
        cout << arr7[i] << " ";
    }
    cout << endl << endl;

    cout << "9. Бинарный поиск" << endl;
    int arr9[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n9 = sizeof(arr9) / sizeof(arr9[0]);
    int target9 = 7;
    cout << "Массив: ";
    for (int i = 0; i < n9; i++) {
        cout << arr9[i] << " ";
    }
    cout << endl;
    cout << "Цель: " << target9 << endl;
    int result9 = binarySearch(arr9, 0, n9 - 1, target9);
    if (result9 != -1)
        cout << "Элемент найден на позиции: " << result9 << endl;
    else
        cout << "Элемент не найден" << endl;
    cout << endl;

    cout << "10. Интерполяционный поиск" << endl;
    int arr10[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n10 = sizeof(arr10) / sizeof(arr10[0]);
    int target10 = 18;
    cout << "Массив: ";
    for (int i = 0; i < n10; i++) {
        cout << arr10[i] << " ";
    }
    cout << endl;
    cout << "Цель: " << target10 << endl;
    int result10 = interpolationSearch(arr10, n10, target10);
    if (result10 != -1)
        cout << "Элемент найден на позиции: " << result10 << endl;
    else
        cout << "Элемент не найден" << endl;

    return 0;
}
