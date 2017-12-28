#include <iostream>


int main(){
	
	/// I. POINTERS
	
	int age = 30;
	const double Pi = 3.1416;
	
	std::cout << "Integer age is located at: 0x" << &age << std::endl;
	std::cout << "Double Pi is located at: 0x" << &Pi << std::endl;
	
	int* pointsToInt = &age; // pointer initialized to &age
	std::cout << "Integer age is at: 0x" << pointsToInt << std::endl;
	
	/*
	Integer age is located at: 0x0000009D90CFF994
	Double Pi is located at: 0x0000009D90CFF9B8
	Integer age is at: 0x0000009B5251FCD4
	*/
	
	
	/// II. POINTER REASSIGNMENT
	int eaglesAge = 9;
	int* pointstoInt = &eaglesAge;  // reassignment
	std::cout << "pointstoInt now points to: 0x" << pointsToInt << std::endl;
	
	/*
	pointstoInt now points to: 0x0000007B98CFF714
	*/
	
	
	/// III. ACCESS POINTED DATA
	std::cout << pointstoInt << std::endl;
	std::cout << *pointstoInt << std::endl;
	std::cout << &pointstoInt << std::endl;
	
	
	return 0;
	
}