#pragma once
#include "pch.h"
#include "Obj.h"
#include <Windows.h>

//������������ ������


class DynArr : public Obj {
	private:
		Obj **array;
		int len;
		bool notBusy;
	public:
		DynArr();
		virtual ~DynArr();
		void freeItems(); // ������� ��� �������� ������ ������� (���������, ��������� ���������!!!)
		int count(); // ���������� ����� �������
		Obj *get(int index); // ���������� ��������� �� index-���� �������
		int search(Obj * target); // ���������� ������ �������� � �������(�������� ��������� �� ������� �������)
		bool add(Obj* source); // �������� ����� ������� � ������
		void delById(int index); // ������� ������� �� ���������� ������� �� ������� (�� �� ������, ������ � �������!!!)
		int del(Obj* target); // ������� ��������� ������� �� ������� (�������� ��������� �� ������� �������) (�� �� ������, ������ � �������!!!)
	private:
		bool waitThreadQueue();
};

