#include "RecurveList.h"

int main()
{
	List test;
	int finished;
	cout << "���뽨�������־���� ��";
	cin >> finished; //���뽨�������־����
	cout << "Input your data: " << endl; //��ʾ
	test.NewList(finished); //��������
	cout << "The List is : " << endl;
	test.PrintList(); //��ӡ����
	cout << endl;
	cout << "The Max is : " << test.GetMax() << endl;
	cout << "The Num is : " << test.GetNum() << endl;
	cout << "The Ave is : " << test.GetAvg() << endl;
	return 0;
}