#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Homework_6.hpp"


int main()
{
	setlocale(LC_ALL, "ru");
	
	float radius;
	float a, b, c;

	float mass_1[MAX_SIZE] = { 6, -10.5, 32, -0.5, 45, 100, 16, -7.4, 98.3 };
	
	float mass_2[ROW_MASS][COL_MASS] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int size = 9;

	std::cout << mass::cntNegativeElement(mass_1, size) << std::endl;

	std::cout << mass::maxElement(mass_1, size) << std::endl;

	std::cout << mass::sumElementBelowDiagonal(mass_2, ROW_MASS, COL_MASS) << std::endl;

	std::cout << "������� ������ �����: ";
	std::cin >> radius;
	std::cout << std::endl;
	std::cout << "������� ����� = ";
	std::cout << s�ircle(radius) << std::endl;

	std::cout << "������� ������������ ����������� ���������: \n";
	std::cin >> a >> b >> c;
	std::cout << std::endl;
	std::cout << "����� ����������� ���������: \n";
	roots(a, b, c);

	return 0;
}

namespace mass 
{
	int cntNegativeElement(float mass[MAX_SIZE], int size)
	{
		int cnt = 0;

		for (int i = 0; i < size; i++)
		{
			if (mass[i] < 0)
				cnt++;
		}

		return cnt;
	}

	float maxElement(float mass[MAX_SIZE], int size)
	{
		int max = mass[0];

		for (int i = 1; i < size; i++)
		{
			if (mass[i - 1] < mass[i])
				max = mass[i];
		}
		return max;
	}

	float sumElementBelowDiagonal(float  mass[ROW_MASS][COL_MASS], int row, int col)
	{
		float sum = 0;
		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < i; j++)
			{
				sum += mass[i][j];
			}
		}

		return sum;
	}
}

float s�ircle(float R) 
{
	return M_PI * R * R;
}


void roots(float a, float b, float c)
{
	float D;

	D = b * b - 4 * a * c;

	if (D < 0)
		std::cout << "������ ���" << std::endl;
	else if (D == 0)
		std::cout << "������ ��������� = " << (((-1) * b) / (2 * a)) << std::endl;
	else {
		std::cout << "������ ������ = " << ((((-1) * b) + sqrt(D)) / (2 * a)) << std::endl;
		std::cout << "������ ������ = " << ((((-1) * b) - sqrt(D)) / (2 * a)) << std::endl;
	}
}