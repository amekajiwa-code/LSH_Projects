#include <iostream>

int* sorted;
// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
void merge(int data[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	//한쪽 리스트가 비워질때까지 비교해서 정렬될 리스트에 채워넣음
	while (i <= mid && j <= right) {
		if (data[i] <= data[j]) {
			sorted[k++] = data[i++];
		}
		else {
			sorted[k++] = data[j++];
		}
	}
	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = data[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = data[l];
	}
	//값에 의한 복사
	for (int l = left; l <= right; l++) {
		data[l] = sorted[l];
	}
}

void merge_sort(int data[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(data, left, mid);
		merge_sort(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}



int main()
{
	int i;
	int list[] = { 21, 10, 12, 20, 25, 13, 15, 22 };
	sorted = (int*)malloc(sizeof(int));
	// 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
	merge_sort(list, 0, 7);

	// 정렬 결과 출력
	for (i = 0; i < 7; i++) {
		printf("%d\n", list[i]);
	}
	//free(sorted);
	//sorted = NULL;
}