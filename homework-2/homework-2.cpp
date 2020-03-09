// homework-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ComplexNumber.h"



int main()
{
	ComplexNumber test(1);

	ComplexNumber complexNumber1, complexNumber2 = 1/* conversion constructor */, complexNumber3 = 1.0, complexNumber4("34- 24i"), complexNumber5(34, -23);

	ComplexNumber complexNumber8 = std::string("34 - 24i");

	complexNumber1.SetRealPart(-5);

	complexNumber1.SetImagPart(2);

	complexNumber4.Show();

	std::cout << std::endl;

	complexNumber1 = complexNumber1 + complexNumber4;

	complexNumber1.Show();

	complexNumber1 = complexNumber1 - complexNumber2;

	complexNumber1 = complexNumber1 / complexNumber4;

	std::cout << std::endl;

	complexNumber5.Show();

	std::cout << "\n> -- list --\n";

	std::vector<ComplexNumber> numberList;

	numberList.push_back(complexNumber5);
	numberList.push_back(complexNumber4);
	numberList.push_back(complexNumber3);
	numberList.push_back(complexNumber2);
	numberList.push_back(complexNumber1);

	ComplexNumber::sortAndPrint(numberList);

}
