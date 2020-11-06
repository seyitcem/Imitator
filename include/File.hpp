#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <chrono>
#include "Cursor.hpp"
#include "Console.hpp"
class File
{
public:
	File();
	int sleepTime;
	bool record();
	bool start();
};