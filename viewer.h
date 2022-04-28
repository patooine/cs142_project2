// Viewer.h

#ifndef _viewer_h_
#define _viewer_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "buffer.h"

const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's

class Viewer {
public:
private:
	void display_main();
	void display_search();
	void main_execute(char command, bool& done);
	void search_execute(char command, bool& done);
	void run();
	void run_search();
	std::string error_message_;

	Buffer buffer_;

};

#endif