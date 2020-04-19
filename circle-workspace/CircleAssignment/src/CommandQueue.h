#pragma once

#include <string>
#include <queue>
#include <mutex>
#include <memory>

//#include "Commands.h"
class DrawingSurface;

class DrawingCommand {
public:
	virtual void executeCommand(DrawingSurface &surfacestring);
	virtual ~DrawingCommand() {
	}

};

class CommandStart: DrawingCommand {
	std::string_view name;
	unsigned width;
	unsigned height;

public:

	CommandStart(std::string_view name_, const unsigned width_,
			const unsigned height_) {
		name = name_;
		width = width_;
		height = height_;

	}

	void executeCommand(DrawingSurface &surfacestring);
};

class CommandCircle: DrawingCommand {
	unsigned radius;
	unsigned centerX;
	unsigned centerY;

public:
	CommandCircle(const unsigned radius_, const unsigned centerX_,
			const unsigned centerY_) {
		radius = radius_;
		centerX = centerX_;
		centerY = centerY_;
	}

	void executeCommand(DrawingSurface &surfacestring);
};

class CommandExit: DrawingCommand {
public:
	void executeCommand(DrawingSurface &surfacestring);
};

class CommandQueue {

	std::mutex queueMutex;
	std::queue<std::unique_ptr<DrawingCommand>> commandQueue;

public:
	void push(std::unique_ptr<DrawingCommand> command) {
		std::lock_guard<std::mutex> lockGuard(queueMutex);

		commandQueue.push(std::move(command));
	}

	std::unique_ptr<DrawingCommand> pop() {
		std::lock_guard<std::mutex> lockGuard(queueMutex);

		std::unique_ptr<DrawingCommand> returnValue = std::move(commandQueue.front());
		commandQueue.pop();

		return returnValue;
	}
};
