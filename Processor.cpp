#include "Processor.h"
#include <iostream>

using namespace std;

enum
{
	DENIED,
	ALLOWED,
	ACCESSED
};

enum
{
	REQUEST,
	FREEING
};

const int N = 4; //кол-во блоков процессоров-памяти
int ACCESS = DENIED; //переменная доступа к блоку памяти-процессора

Processor::Processor()
{
	this->Pn = 0;
	this->K = 0;
	this->M = 0;
	this->Kr = 0;
	lead_time = new int[N];
	delay = new int[N];
	number_memory = new int[N];
	commands = new int* [N];

	for (int i = 0; i < N; i++)
	{
		number_memory[i] = ALLOWED;
		lead_time[i] = 0;
		delay[i] = 1;
		commands[i] = new int[K];
	}
}

Processor::Processor(int Pn, int K, int M, int Kr)
{
	this->Pn = Pn;
	this->K = K;
	this->M = M;
	this->Kr = Kr;
	lead_time = new int[N];
	delay = new int[N];
	number_memory = new int[N];
	commands = new int* [N];

	for (int i = 0; i < N; i++)
	{
		number_memory[i] = ALLOWED;
		lead_time[i] = 0;
		delay[i] = 1;
		commands[i] = new int[K];
	}
}

Processor::~Processor()
{
	for (int i = 0; i < N; i++)
	{
		delete commands[i];
	}
	delete commands[];
	delete lead_time[];
	delete number_memory[];
}

void Processor::set()
{
	for (int i = 0; i < N; i++)
	{
		int delta_K = K - ((K * Kr) / 100); //K - Kr, где Kr - проценты от К
		int delta_K_percent = delta_K * Pn / 100; //процент в программе Р команд К-Кr
		int number_memory = 0; //номер блока памяти

		for (int j = 0; j < K; j++)
		{

		}
	}
}

void Processor::commutator()
{
	int access;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (commands[j][i])
			{
				cout << "Data transfer request" << "\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
				while (1)
				{
					access = memory();
					if (access == ACCESSED)
					{
						cout << "Access allowed" << "\t\t\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
						lead_time[j] += M * 50;
						break;
					}
					else
					{
						lead_time[j] += 200 * delay[j];
						delay[j]++;
						cout << "Waiting memory" << "\t\t\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
						memory();
					}
				}
			}
			else
			{
				lead_time[j] += 100;
				cout << "Without memory request" << "\t\t|\t-\t|\tProc" << j + 1 << "\t|" << endl;
			}
		}
		for (int i = 0; i < N; i++)
		{
			number_memory[i] = ALLOWED;
			delay[i] = 1;
		}
	}
	cout << "Commutator: " << time_function() << endl;
}

void Processor::bus()
{
	int access;
	int delay = 1;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (commands[j][i])
			{
				cout << "Data transfer request" << "\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
				while (1)
				{
					access = memory();
					if (access == ACCESSED)
					{
						cout << "Access allowed" << "\t\t\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
						lead_time[j] += M * 50;
						break;
					}
					else
					{
						lead_time[j] += 200 * delay;
						delay++;
						cout << "Waiting memory" << "\t\t\t|\t" << "P" << commands[j][i] << "\t|\tProc" << j + 1 << "\t|" << endl;
						memory();
					}
				}
			}
			else
			{
				lead_time[j] += 100;
				cout << "Without memory request" << "\t\t|\t-\t|\tProc" << j + 1 << "\t|" << endl;
			}
		}
		delay = 1;
	}
	cout << "Bus: " << time_function() << endl;
}

int Processor::memory(int req, int num)
{
	ACCESS = number_memory[num - 1];
	if (ACCESS == ALLOWED && req == REQUEST)
	{
		ACCESS = DENIED;
		number_memory[num - 1] = DENIED;
		return ACCESSED;
	}
	else
	{
		if (ACCESS == DENIED && req == REQUEST)
		{
			return DENIED;
		}
		else
		{
			if (ACCESS == DENIED && req == FREEING)
			{
				ACCESS = ALLOWED;
			}
		}
	}

	number_memory[num - 1] = ALLOWED;
	return ACCESS;
}

int Processor::memory(int req) 
{
	if (ACCESS == ALLOWED && request == REQUEST) 
	{
		ACCESS = DENIED;
		return ACCESSED;
	}
	else
	{
		if (ACCESS == DENIED && request == FREEING)
		{
			ACCESS = ALLOWED;
		}
	}
	return ACCESS;
}

int Processor::time_function()
{
	int time_func = 0;
	for (int i = 0; i < N; i++)
	{
		if (lead_time[i] > time_func)
		{
			time_func = lead_time[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		lead_time[i] = 0;
	}

	return time_func / 50;
}
