#pragma once

class Processor 
{
private:

	int Pn; // Pn - ������� ������, ��������������� � ����� ������
	int Kr; // Kr - ������� ������ �� ������ ����� ������, �� ��������� ��������� � ������� ������. ����������� � ������� ����� ������� �������
	int M; // M - ����� ��������� � ������
	int K; // K - ���������� ������ � ���������

	int* delay; // �������� ������� �� ������ (��������) - ���� ������� �������, ����� ������������� � ����������� �� �������
	int* number_memory; // ������ ������� ������ ������ (���������� ������� � ���)
	int* lead_time; // ����� ���������� ������ ���������� � ������
	int** commands; // ������ ������ �������� ��������� (K)

public:

	Processor();
	Processor(int Pn, int K, int M, int Kr);
	~Processor();
	void set(); //������������� ������� � ��������� ����������
	void print();
	void commutator();
	void bus();
	int memory(int req, int num);
	int memory(int req);
	int time_function();

};
