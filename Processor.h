#pragma once

class Processor 
{
private:

	int Pn; // Pn - процент данных, сосредоточенных в блоке памяти
	int Kr; // Kr - процент команд от общего числа команд, не требующих обращений к внешней памяти. Выполняются в течение одной единицы времени
	int M; // M - время обращения к памяти
	int K; // K - количество команд в программе

	int* delay; // ожидание доступа ке памяти (задержка) - одна единица времени, будет увеличиваться в зависимости от доступа
	int* number_memory; // массив номеров блоков памяти (разрешения доступа к ним)
	int* lead_time; // время выполнения работы процессора и памяти
	int** commands; // массив команд условной программы (K)

public:

	Processor();
	Processor(int Pn, int K, int M, int Kr);
	~Processor();
	void set(); //устанавливает команды в программе равномерно
	void print();
	void commutator();
	void bus();
	int memory(int req, int num);
	int memory(int req);
	int time_function();

};
