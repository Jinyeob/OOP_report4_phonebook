//PhoneClass.h
/*
�ѱ���������_��ǻ�Ͱ��а�_2015154007_������
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Phone { //Phone Ŭ����
private:
	string name;
	string address;
	string number;
public:
	map<string, vector<string>> contact; //�̸� �ּ� ��ȭ��ȣ
	map<string, vector<string>> ::iterator itcontact; //map�� ���� ������ itcontact����

	Phone() { //������. ���� ó���� ���� �����

		cout << "��ȭ��ȣ ���� ���α׷��� �����մϴ�. ���Ϸ� �����մϴ�.\n\n";

		ifstream fin("phonebook.dat"); //���� ������ phonebook.dat ���� �о��
		if (!fin) {
			cout << "phonebook.dat ������ �� �� �����ϴ�.\n";
		}
		else {
			string line;
			vector<string> word;
			while (getline(fin, line)) { word.push_back(line); } 
			int size = word.size();
			for (int i = 0; i < size; i++) {
				//�� �� �� �о�� ������� contact map�� �� key�� value (vector)�� ����
				if (i % 3 == 0) {  
					name = word[i]; //ù°��, ��°�� (���� �̸��� �����ϱ�)
					address = word[i + 1]; //�� ���� ���� �ּ�
					number = word[i + 2]; //�� ���� ���� ��ȭ��ȣ
					contact[name]= vector<string>{ address,number }; //������ ������ ������ map����.
				}
			}
			cout << "-----���� phonebook.dat ����-----\n";
			if (contact.size() == 0) { cout<< "������ ����� ������ �����ϴ�. \n���� �Է� ���ּ���~ ^^\n"; }
			else {
				for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) { //���� ���� ����ϴ� �ݺ���
					//iterator�� �̿��Ͽ� map�� key, value (vector) ���
					cout << itcontact->first << endl; //key (�̸�) ���
					cout << itcontact->second[0] << endl; //value (�ּ�) ���
					cout << itcontact->second[1] << endl; //value (��ȭ��ȣ) ���
				}
			}
			cout << "---------------------------------\n\n";
			system("phonebook.dat");

			
			fin.close();
		}
	}
	void insert() { //0
		cout << "�̸�>>"; cin >> name; //key�� �Է¹���
		cin.get(); //���� �ٷ� �ȸ����� ���ִ� ����
		if (contact.find(name) != contact.end()) {
			cout << "�̹� �ִ� �̸��Դϴ�.\n";
		}
		//key�� �˻��ؼ� ������,
		else {
			cout << "�ּ�>>";
			getline(cin, address);//�ּҿ�
			cout << "��ȭ��ȣ>>";
			getline(cin, number); //��ȭ��ȣ�� �Է¹޴´�.
			contact[name] = vector<string>{ address,number }; //value vector �� �ּҿ� ��ȭ��ȣ ����.
		}
	}
	void del() { //1
		cout << "�̸�>>"; cin >> name; //�����Ϸ��� key��
		if (contact.find(name) == contact.end()) cout << "��ϵǾ� ���� ���� �̸��Դϴ�.\n";
		//key�� �˻��ؼ� ������,
		else {
			contact.erase(name);//����.
			cout << name << "�� �����Ǿ����ϴ�.\n";
		}
	}
	void search() { //2
		cout << "�̸�>>"; cin >> name; //ã������ key��
		if (contact.find(name) != contact.end()) { //ã������
			cout << name << " " << contact[name][0] << " " << contact[name][1] << endl; //key, value ���
		}
		else cout << name << "�� ��ϵ��� ���� ����Դϴ�.\n";
	}
	void show() { //3
		for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) {
			//iterator�� �̿��Ͽ� map�� key, value (vector)
			cout << itcontact->first << " "; //key (�̸�)
			cout << itcontact->second[0] << " "; //value (�ּ�)
			cout << itcontact->second[1] << " \n"; //value (��ȭ��ȣ)
		}
	}
	void save() { //4
		ofstream fout("phonebook.dat");
		if (!fout) { // ������а˻�
			cout << "phonebook.dat ���� �����Ͽ����ϴ�.\n";
		}
		else {
			for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) {
				//iterator�� �̿��Ͽ� map�� key, value (vector) ����
				fout << itcontact->first << endl; //key (�̸�) ����
				fout << itcontact->second[0] << endl; //value (�ּ�) ����
				fout << itcontact->second[1] << endl; //value (��ȭ��ȣ) ����
			}
		}
		fout.close();
	}
};
