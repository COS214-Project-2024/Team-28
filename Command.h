#include <exception>
using namespace std;

#ifndef __Command_h__
#define __Command_h__

// #include "Government.h"

class Government;
class Command;

class Command
{
	private: CommandReceiver _receiver;
	public: Government* _unnamed_Government_;

	public: void execute();

	public: void undo();
};

#endif
