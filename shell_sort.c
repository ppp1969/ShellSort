/*
		셸 정렬(shell sort) 알고리즘의 개념 요약

	‘Donald L. Shell’이라는 사람이 제안한 방법으로, 삽입정렬을 보완한 알고리즘이다.

	삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠른 것에 착안
	삽입 정렬의 최대 문제점: 요소들이 삽입될 때, 이웃한 위치로만 이동
	즉, 만약 삽입되어야 할 위치가 현재 위치에서 상당히 멀리 떨어진 곳이라면 많은 이동을 해야만 제자리로 갈 수 있다.
	삽입 정렬과 다르게 셸 정렬은 전체의 리스트를 한 번에 정렬하지 않는다.

	과정 설명

	1. 먼저 정렬해야 할 리스트를 일정한 기준에 따라 분류

	2. 연속적이지 않은 여러 개의 부분 리스트를 생성

	3. 각 부분 리스트를 삽입 정렬을 이용하여 정렬

	4. 모든 부분 리스트가 정렬되면 다시 전체 리스트를 더 적은 개수의 부분 리스트로 만든 후에 알고리즘을 반복

	5. 위의 과정을 부분 리스트의 개수가 1이 될 때까지 반복


	셸 정렬(shell sort) 알고리즘의 구체적인 개념

	정렬해야 할 리스트의 각 k번째 요소를 추출해서 부분 리스트를 만든다. 이때, k를 ‘간격(gap)’ 이라고 한다.

	간격의 초깃값: (정렬할 값의 수)/2

	생성된 부분 리스트의 개수는 gap과 같다.

	각 회전마다 간격 k를 절반으로 줄인다. 즉, 각 회전이 반복될 때마다 하나의 부분 리스트에 속한 값들의 개수는 증가한다.

	간격은 홀수로 하는 것이 좋다.

	간격을 절반으로 줄일 때 짝수가 나오면 +1을 해서 홀수로 만든다.

	간격 k가 1이 될 때까지 반복한다.

						출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html
*/

# include <stdio.h>
# define MAX 10

void inc_insertion_sort(int list[], int first, int last, int interval){
	int i, j, key;

	for(i=first+interval; i<=last; i=i+interval){
		key = list[i];
		for(j=i-interval; j>=first && list[j]>key; j=j-interval){
	   		list[j+interval] = list[j]; 
 	    }

    list[j+interval] = key;
  }
}

void shell_sort(int list[], int n){
	int interval;

	for(interval=n/2; interval>0; interval/=2){
		if((interval%2) == 0){
    		interval++; 
    	}
   		for(int i=0; i<interval; i++){
			inc_insertion_sort(list, i, n-1, interval);
    	}
    }
}

int main(void){
	int n;
	printf("정렬 할 데이터 개수 : ");	scanf("%d",&n);
	int list[n];
	for(int i=0; i<n;i++){
		scanf("%d",&list[i]);
	} 
	
	printf("정렬 전 데이터 :");
	for(int i=0; i<n; i++){
 	   printf("%d ", list[i]);
	}
	printf("\n");

	shell_sort(list, n);
	printf("정렬 후 데이터 :");
	for(int i=0; i<n; i++){
 	   printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
