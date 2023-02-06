#include <iostream>


extern "C"
{
	int  __stdcall getmin(int* arr, int length);
	int  __stdcall getmax(int* arr, int length);
}

int main()
{
	int arr[] = { 1,2,3,0,5,-5,7,8,9,10 };
	
	std::cout << "getmin + getmax = " << getmin(arr, (sizeof(arr) / sizeof(int))) + getmax(arr, (sizeof(arr) / sizeof(int)));
}