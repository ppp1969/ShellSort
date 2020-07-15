/*
		�� ����(shell sort) �˰����� ���� ���

	��Donald L. Shell���̶�� ����� ������ �������, ���������� ������ �˰����̴�.

	���� ������ ��� ���� ���ĵ� �迭�� ���ؼ��� ����� ���� �Ϳ� ����
	���� ������ �ִ� ������: ��ҵ��� ���Ե� ��, �̿��� ��ġ�θ� �̵�
	��, ���� ���ԵǾ�� �� ��ġ�� ���� ��ġ���� ����� �ָ� ������ ���̶�� ���� �̵��� �ؾ߸� ���ڸ��� �� �� �ִ�.
	���� ���İ� �ٸ��� �� ������ ��ü�� ����Ʈ�� �� ���� �������� �ʴ´�.

	���� ����

	1. ���� �����ؾ� �� ����Ʈ�� ������ ���ؿ� ���� �з�

	2. ���������� ���� ���� ���� �κ� ����Ʈ�� ����

	3. �� �κ� ����Ʈ�� ���� ������ �̿��Ͽ� ����

	4. ��� �κ� ����Ʈ�� ���ĵǸ� �ٽ� ��ü ����Ʈ�� �� ���� ������ �κ� ����Ʈ�� ���� �Ŀ� �˰����� �ݺ�

	5. ���� ������ �κ� ����Ʈ�� ������ 1�� �� ������ �ݺ�


	�� ����(shell sort) �˰����� ��ü���� ����

	�����ؾ� �� ����Ʈ�� �� k��° ��Ҹ� �����ؼ� �κ� ����Ʈ�� �����. �̶�, k�� ������(gap)�� �̶�� �Ѵ�.

	������ �ʱ갪: (������ ���� ��)/2

	������ �κ� ����Ʈ�� ������ gap�� ����.

	�� ȸ������ ���� k�� �������� ���δ�. ��, �� ȸ���� �ݺ��� ������ �ϳ��� �κ� ����Ʈ�� ���� ������ ������ �����Ѵ�.

	������ Ȧ���� �ϴ� ���� ����.

	������ �������� ���� �� ¦���� ������ +1�� �ؼ� Ȧ���� �����.

	���� k�� 1�� �� ������ �ݺ��Ѵ�.

						��ó : https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html
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
	printf("���� �� ������ ���� : ");	scanf("%d",&n);
	int list[n];
	for(int i=0; i<n;i++){
		scanf("%d",&list[i]);
	} 
	
	printf("���� �� ������ :");
	for(int i=0; i<n; i++){
 	   printf("%d ", list[i]);
	}
	printf("\n");

	shell_sort(list, n);
	printf("���� �� ������ :");
	for(int i=0; i<n; i++){
 	   printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
