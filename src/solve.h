#ifndef SOLVE
#define SOLVE

#include<queue>

#include "task.h"

void inputmodule(std::priority_queue<task> &t,std::priority_queue<task> &r);
void outputmodule(std::priority_queue<task> &t,std::priority_queue<task> &r);
//command
bool processing_command(std::string command,std::priority_queue<task> &t,std::priority_queue<task> &r);
void add(std::priority_queue<task> &t,std::priority_queue<task> &r);
void check(std::priority_queue<task> &t);
void list(std::priority_queue<task> &t);
void remind(std::priority_queue<task> &r);

#endif
