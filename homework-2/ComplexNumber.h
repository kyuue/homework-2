#pragma once

#include <string>

#include <vector>


class ComplexNumber
{
private:
	double a, b;

public:
	ComplexNumber() : a(0), b(0) {}

	ComplexNumber(int number) : a(number), b(0) {}

	ComplexNumber(double number) : a(number), b(0) {}

	ComplexNumber(const std::string& str);

	ComplexNumber(double a, double b) : a(a), b(b) {}

	void SetRealPart(double number);

	double GetRealPart() const;

	void SetImagPart(double number);

	double GetImagPart() const;

	ComplexNumber operator + (ComplexNumber const &obj);

	ComplexNumber operator - (ComplexNumber const &obj);

	ComplexNumber operator / (ComplexNumber const &obj);

	void Show();

	////

	static ComplexNumber parse(const std::string& str);

	static void sortAndPrint(std::vector<ComplexNumber> &numbers);
};
