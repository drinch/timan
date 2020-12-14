#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

#include "task.h"
#include "solve.h"

std::priority_queue<task>t,r;
int main() {
	inputmodule(t,r);
	processing_command("remind",t,r);
	std::string command;
	do{
		std::cout<<">";
		std::cin>>command;
	}while(processing_command(command,t,r));
	outputmodule(t,r);
	return 0;
}
