// 수 정렬하기 2
/* 합병정렬을 사용해서 정렬함 */
#include <iostream>

// 두 배열을 합쳐나가며 정렬하는 함수
void merge(int *arr, int *arr2, int left, int right) {

	int low = left;
	int mid = (left + right) / 2;
	int high = mid + 1;
	int x = left;

	while (low <= mid && high <= right) {

		if (arr[low] <= arr[high]) {
			arr2[x] = arr[low];
			low++;
		}
		else {
			arr2[x] = arr[high];
			high++;
		}
		x++;
	}
	if (low > mid) {
		for (int i = high; i <= right; i++) {
			arr2[x++] = arr[i];
		}
	}
	else {
		for (int i = low; i <= mid; i++) {
			arr2[x++] = arr[i];
		}
	}
	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

// 배열을 2개로 나눈 후 각각의 배열을 재귀적으로 계속 나눠 정렬한 후, 2배열을 합친다
void mergeSort(int *arr, int *arr2, int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, arr2, left, mid);
		mergeSort(arr, arr2, mid + 1, right);
		merge(arr, arr2, left, right);
	}
}

int main() {
	int N;

	scanf_s("%d", &N);

	int *data = new int[N];
	int *sorted = new int[N];
	for (int i = 0; i < N; i++)
		scanf_s("%d", &data[i]);

	mergeSort(data, sorted, 0, N - 1);
	for (int i = 0; i < N; i++)
		printf("%d\n", data[i]);

	return 0;
}