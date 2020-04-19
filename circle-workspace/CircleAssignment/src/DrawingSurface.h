#pragma once
#include <string>
#include <string_view>
#include <queue>

//#include "Commands.h"
#include "CommandQueue.h"


class DrawingSurface {
	bool dirty = false;
	std::string_view name = "Unknown";

public:
	void operator()(CommandQueue &commandQueue);
protected:
	void createDrawingSurface(std::string_view name, const unsigned width,
			const unsigned height);
	void saveDrawingSurface(std::string_view name);

	void start(std::string_view name, const unsigned width, const unsigned height);
	void save();
	void circle(const unsigned radius, const unsigned centerX,
			const unsigned centerY);

};

