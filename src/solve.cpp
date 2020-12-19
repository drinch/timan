#include "solve.h"
#include "task.h"

void inputmodule(std::priority_queue<task> &t,std::priority_queue<task> &r) {
	task task_;
	std::ifstream in("list.txt", std::ios::in);
	while(in>>task_.name>>task_.level>>task_.ddl.tm_year>>task_.ddl.tm_mon>>task_.ddl.tm_mday>>task_.description) {
		t.push(task_);
	}
	in.close();
	std::ifstream in_("reminds.txt", std::ios::in);
	while(in_>>task_.name>>task_.level>>task_.ddl.tm_year>>task_.ddl.tm_mon>>task_.ddl.tm_mday>>task_.description) {
		r.push(task_);
	}
	in_.close();
	std::cout<<"System is ready.\n";
}
void outputmodule(std::priority_queue<task> &t,std::priority_queue<task> &r) {
	std::ofstream out("list.txt", std::ios::out);
	task task_;
	while(!t.empty()) {
		task_=t.top();
		task_.outf(out);
		t.pop();
	}
	std::ofstream out_("reminds.txt", std::ios::out);
	while(!r.empty()) {
		task_=r.top();
		task_.outf(out_);
		r.pop();
	}
}

//command
bool processing_command(std::string command,std::priority_queue<task> &t,std::priority_queue<task> &r) {
	if(command=="exit") return 0;
	else if(command=="add") {
		add(t,r);
	} else if(command=="check") {
		check(t);
	} else if(command=="list") {
		list(t);
	} else if(command=="remind") {
		remind(r);
	} else {
		std::cout<<"wrong\n";
	}
	return 1;
}
void add(std::priority_queue<task> &t,std::priority_queue<task> &r) {
	std::cout<<"Task[t] or reminds[r]?";
	std::string s;
	std::cin>>s;
	if(s=="t"||s=="r") {
		task task_;
		std::cout<<"Please write down the task:\nname level deadline(year month day)\n";
		task_.in();
		if(s=="t")t.push(task_);
		else r.push(task_);
	} else {
		std::cout<<"wrong\n";
		return;
	}
}
void check(std::priority_queue<task> &t) {
	if(t.empty()) std::cout<<"You have no task.\n";
	else {
		task task_=t.top();
		task_.out();
		std::string c;
		std::cout<<"\nsolved?\n[y],[n]\n";
		std::cin>>c;
		if(c=="y") t.pop();
	}
}
void list(std::priority_queue<task> &t) {
	std::priority_queue<task> qq;
	task task_;
	while(!t.empty()) {
		task_=t.top();
		t.pop();
		task_.out();
		putchar('\n');
		qq.push(task_);
	}
	while(!qq.empty()) {
		t.push(qq.top());
		qq.pop();
	}
}
void remind(std::priority_queue<task> &r) {
	list(r);
}
