#pragma once
#include <iostream> //������ͷ�ļ�"RecurveList.h"��
#include <algorithm>
using namespace std;
class List;
class ListNode 
{ //��������
	friend class List;
private:
	int data; //�������
	ListNode *link; //���ָ��
	ListNode(const int item) : data(item), link(nullptr) { } //���캯��
};
class List { //������
private:
	ListNode *first, *current;
	int tmp;//��ʱ����
	int Max(ListNode *f);
	int Num(ListNode *f);
	float Avg(ListNode *f, int& n);
public:
	List() : first(NULL), current(NULL), tmp(0) { } //���캯��
	~List() { } //��������
	ListNode* NewNode(const int item); //����������, ��ֵΪ item
	void NewList(const int retvalue); //��������, ������ retvalue ����
	void PrintList(); //����������н������
	int GetMax() { return Max(first); } //�������������ݵ����ֵ
	int GetNum() { return Num(first); } //�����������ݸ���
	float GetAvg() { return Avg(first, tmp); } //�������������ݵ�ƽ��ֵ
};