//main.cpp
/*
�ѱ���������_��ǻ�Ͱ��а�_2015154007_������
*/
#include "PhoneClass.h"

int main() {
	Phone a; //��ü
	int i; //�޴� �Է½� ���
	bool done = true; //���� �Է½� �����

	while (done) {
		cout << "0: ����. 1:����, 2:ã��, 3:��ü����,4 :��������, 5:����>>";
		cin >> i;
		switch (i) {
		case 0:
			a.insert(); //����
			break;
		case 1:
			a.del(); //����
			break;
		case 2:
			a.search(); //ã��
			break;
		case 3:
			a.show(); //���� �ҷ��ͼ� ��ü����
			break;
		case 4:
			a.save(); //���� ����
			break;
		case 5:
			done = false; //����
			break;
		default:
			cout << "�ٽ� �Է����ּ��� ~ ^^\n";
			cin.get();
			break;
		}
	}

}