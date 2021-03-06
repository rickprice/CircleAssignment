//============================================================================
// Name        : CircleAssignment.cpp
// Author      : Frederick Price
// Version     :
// Copyright   : BSD
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <thread>

//#include "Commands.h"
#include "DrawingSurface.h"
#include "HandleCommandLine.h"
#include "CommandQueue.h"

using namespace std;

int main() {
	CommandQueue commandQueue;

	HandleCommandLine commandLine = HandleCommandLine();
	DrawingSurface drawingSurface = DrawingSurface();

	cout << "Program starting" << endl;

	std::thread t1(std::ref(commandLine), std::ref(commandQueue));
	std::thread t2(std::ref(drawingSurface), std::ref(commandQueue));

	t1.join();
	t2.join();

	cout << "Program finished" << endl;

	return 0;
}
