#include <iostream>

using namespace std;


// �ݹ���ص������ʣ�1.�߼��������� 2.��ģ���ϱ�С 3.ע��һ����ֹ����

// ����� {1,2,3,...,n} ��ȫ����
void fullPermutation(int arra[], int n, int k){			// arra[]:����Ҫ���е������������š�
														// n����ʾҪ���м�������
														// k����ʾ��ǰ���е�״̬���е��ڼ�������

	if (k == n-1) {		// �ݹ���ֹ��������Ϊ�ǽ������Ե�n-1����ʱ��͵����ź���ȫ����
		for (int i = 0; i < n; ++i)
			cout << arra[i] << " ";

		cout << endl;
	}
	else {
		for (int i = k; i < n; ++i) {

			// ����Ԫ�صĲ���
			int temp = arra[i];
			arra[i] = arra[k];
			arra[k] = temp;
			// �ݹ���ã��Ժ���Ԫ�ص�ȫ�����ڵݹ���������
			fullPermutation(arra, n, k + 1);
			
			// ���ý�����Ҫ��Ԫ�طŻ�ԭ����λ��
			temp = arra[i];						// ע����һ�������٣���Ϊtemp�е�ֵ�ڵݹ���ú�仯��Ҫ��arra[i]��ֵ���¸���temp;
			arra[i] = arra[k];
			arra[k] = temp;

		}
	}
}

int main(){
	int arra[6] = {1,2,3,4,5,6};
	fullPermutation(arra, 5, 0);

	system("pause");

}


