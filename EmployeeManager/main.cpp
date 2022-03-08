#include <iostream>
#include "Client.h"

void validateInputArg(int argc, char* argv[]) {
	if (argc != 3) { throw invalid_argument("Invalid argc"); }
}

int main(int argc, char* argv[]) {
	Client client;
	
	try {
		validateInputArg(argc, argv);
		client.readInputFile(argv[1]);
		client.parseInputFile();
		client.runAndWriteOutputFile(argv[2]);
	}
	catch (const exception& e) {
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}

	return 0;
}