#include "Module.h"

Module::Module() {
	this->loop = true;
}

void Module::endProcess() {
	this->loop = false;
}

bool Module::isContinue() {
	return this->loop;
}