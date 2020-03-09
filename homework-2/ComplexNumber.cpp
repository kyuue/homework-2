#pragma once

#include "ComplexNumber.h"

#include "UtilFuncs.h"

#include <iostream>

#include <algorithm>


ComplexNumber::ComplexNumber(const std::string& str) : a(0), b(0)
{
	ComplexNumber complexNumber = ComplexNumber::parse(str);

	this->a = complexNumber.a;

	this->b = complexNumber.b;
}



ComplexNumber ComplexNumber::parse(const std::string & strParameter)
{
	ComplexNumber complexNumber(0, 0);

	double imag = 0, real = 0;

	std::string str(strParameter);

	str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end()); // remove spaces

	try
	{
		size_t indexOfImag = str.find('i');

		if (indexOfImag == std::string::npos)
			throw;

		size_t middleOperatorIndex = str.rfind('+', indexOfImag);

		if (middleOperatorIndex == std::string::npos)
			middleOperatorIndex = str.rfind('-', indexOfImag);


		if (middleOperatorIndex == std::string::npos) // i, 5i, 30i
		{
			if (str[0] == 'i') // i
			{
				imag = 1;
			}
			else // 5i
			{
				std::string imagStr = str.substr(0, indexOfImag);

				imag = std::stod(imagStr);
			}
		}
		else // contains operator
		{
			std::string realStr = str.substr(0, middleOperatorIndex);

			if (realStr.size() != 0) // if doesn't contain a real part
				real = std::stod(realStr);

			std::string imagStr = str.substr(middleOperatorIndex, str.size() - middleOperatorIndex);

			if (imagStr[1] == 'i') // +i, -i 
			{
				imagStr[1] = '1';
			}
			else // +5i, -5i
			{
				imagStr.erase(std::remove(imagStr.begin(), imagStr.end(), 'i'), imagStr.end());
			}

			imag = std::stod(imagStr);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "Could not parse the complex number! Message: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Could not parse the complex number!" << std::endl;
	}

	complexNumber.SetRealPart(real);

	complexNumber.SetImagPart(imag);

	return complexNumber;
}


void ComplexNumber::sortAndPrint(std::vector<ComplexNumber> &numbers)
{
	int len = numbers.size();

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (numbers[j].a > numbers[i].a)
			{
				ComplexNumber temp = numbers[j];

				numbers[j] = numbers[i];

				numbers[i] = temp;
			}
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (numbers[j].b > numbers[i].b)
			{
				ComplexNumber temp = numbers[j];

				numbers[j] = numbers[i];

				numbers[i] = temp;
			}
		}
	}



	for (int i = 0; i < len; i++)
	{
		numbers[i].Show();

		std::cout << std::endl;
	}
}

void ComplexNumber::SetRealPart(double number)
{
	this->a = number;
}

double ComplexNumber::GetRealPart() const
{
	return this->a;
}

void ComplexNumber::SetImagPart(double number)
{
	this->b = number;
}

double ComplexNumber::GetImagPart() const
{
	return this->b;
}


ComplexNumber ComplexNumber::operator+(const ComplexNumber& obj)
{
	return ComplexNumber(a + obj.a, b + obj.b);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& obj)
{
	return ComplexNumber(a - obj.a, b - obj.b);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& obj)
{
	return ComplexNumber(a / obj.a, b / obj.b);
}

void ComplexNumber::Show()
{
	std::cout << ((a != 0) ? std::to_string(a) : "") << ((b > 0) ? "+" : "") << ((b != 0) ? std::to_string(b) : "") << (b != 0 ? "i" : "");
}
