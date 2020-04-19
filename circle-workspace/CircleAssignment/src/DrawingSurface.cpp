#include <string>
#include <string_view>
#include <queue>
#include <filesystem>
#include <memory>

//#include "Commands.h"
#include "CommandQueue.h"
#include "DrawingSurface.h"

using namespace std;


void DrawingSurface::operator()(CommandQueue &commandQueue) {

	for (;;) {
		std::unique_ptr<DrawingCommand> command = commandQueue.pop();
		/* Need to put code in here to execute the commands */

	}
}

void DrawingSurface::start(string_view name, const unsigned width,
		const unsigned height) {

	save();

	createDrawingSurface(name, width, height);
}

void DrawingSurface::save() {

	if (dirty) {
		saveDrawingSurface(name);
	}

	dirty = false;
}

void DrawingSurface::circle(const unsigned radius, const unsigned centerX,
		const unsigned centerY) {

	dirty = true;
}

void DrawingSurface::createDrawingSurface(string_view name_,
		const unsigned width, const unsigned height) {
	dirty = false;
	name = name_;
}
void DrawingSurface::saveDrawingSurface(string_view name) {
	unsigned retries = 0;

	// Here I'm checking if the file exists before I create it, but really, I should try to create and then handle
	// the exception, so I would normally modify this code to use the better approach.
	// The reason we should try and create and then handle the exception is because the file could be created after
	// we check for its existence, whereas if we create it, and handle the exception, we know that it can't be
	// created under us.
/*
	bool exists = std::filesystem::exists(std::filesystem::path::path(name));
	for (unsigned retries = 0; retries < 100; retries++) {
		std::filesystem::exists("helloworld.txt");
	}
*/
}


