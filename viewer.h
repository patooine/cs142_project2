// Viewer.h

#ifndef _viewer_h_
#define _viewer_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's

class Viewer {
public:
private:
	void display_main();
	void display_search();
	std::string error_message_;
};

#endif