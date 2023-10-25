// HelloWin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
The code includes necessary header files: <Windows.h> for Windows API functions and <stdio.h> for standard input/output functions.

The program defines a preprocessor directive PCH_H to ensure that the header file is only included once.

In the main function:

It declares a variable si of type SYSTEM_INFO to hold system information.
Calls the GetNativeSystemInfo function to retrieve system information and stores it in the si variable.
It uses printf to display various pieces of system information:

Number of Logical Processors.
Page size in bytes.
Processor Mask in hexadecimal format.
Minimum process address.
Maximum process address.
Finally, the program returns 0 to indicate that it has executed successfully.

In summary, this program provides a basic demonstration of accessing and printing system information using the Windows API.
*/

/*
PROCESS MASK

The "Processor Mask" is a concept in computing that involves the use of binary digits to represent which processors or cores in a multi-core system are available for use. 
It is a bit mask where each bit represents the availability of a specific processor.

For example, in a system with 4 processors, the processor mask might look like this in binary: 1111, which in hexadecimal notation would be 0xF. 
This means that all four processors are available for use.

In the provided code, si.dwActiveProcessorMask is a member of the SYSTEM_INFO structure returned by the GetNativeSystemInfo function. 
It provides information about which processors are currently configured for use in the system. This information can be used to optimize tasks in a multi-threaded application by distributing workloads across available processors.
*/

#include "pch.h"

int main() {
	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);

	printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
	printf("Page size: %d Bytes\n", si.dwPageSize);
	printf("Processor Mask: 0x%p\n", (PVOID)si.dwActiveProcessorMask);
	printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
	printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);

	return 0;
}
