//#include <stdio.h>
//#include <stdlib.h>
//
//
//// ���� Ž�� �Լ� (��� ����)
//int binarySearch(int arr[], int low, int high, int k) {
//    int mid = (low + high) / 2;
//    int temp;
//    if (low > high)
//        return high;
//
//    if (k == arr[mid]) {
//        return mid;
//    }
//    else if (k < arr[mid]) {
//        ;
//       return binarySearch(arr, low,mid-1, k);
//    }
//    else if (k > arr[mid]) {
//        
//        return binarySearch(arr, mid + 1, high, k);
//    }
//   
//
//    
//}
//
//int main() {
//    int n, k;
//
//
//    scanf("%d", &n);
//
//    int* arr = (int*)malloc(n * sizeof(int));
//
//    if (arr == NULL) {
//        printf("�޸� �Ҵ� ����\n");
//        return 1;
//    }
//
//    scanf("%d", &k);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//
//    int result = binarySearch(arr, 0, n - 1, k);
//
//    printf("%d", result);
//
//    free(arr);
//
//    return 0;
//}