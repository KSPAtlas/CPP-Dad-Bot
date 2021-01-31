// Includes
#include<iostream>
#include<string>
#include<algorithm>

// Setting up variables
std::string findthis = "i\'m";
std::string input;
std::string falseinput;
std::string name;
bool IsWindows;
int indexvar;
std::string sub = "Hi";

// Start of "main" function
int main() {

// Check to see if the user is on Windows
#ifdef _WIN32
	std::cout << "You are running in Windows mode.\n";
	IsWindows = true;
#else
	std::cout << "You are running in Unix mode.\n";
	IsWindows = false;
#endif

    // Asking for name
	std::cout << "What name would you like me to call you? ";
	std::getline(std::cin, name);
	if (IsWindows == true) {
		system("cls");
	}
	else {
		system("clear");
	}

    // Start of ask loop
	while (true) {
        // Gets user input and makes it lowercase
        std::cout << "[" << name << "]: ";
		std::getline(std::cin, input);
		falseinput = input;
		std::for_each(falseinput.begin(), falseinput.end(), [](char& c) {
			c = ::tolower(c);
			});
        // If user asks for dad joke (d!dadjoke)
		if ((indexvar = falseinput.find("d!dadjoke")) != std::string::npos) {
			std::cout << "[Dad-Bot]: Oh no! Dad jokes are currently not available. Check back later.\n";
		}
        // If user says "shut up"
		if ((indexvar = falseinput.find("shut up")) != std::string::npos) {
			std::cout << "[Dad-Bot]: Listen here " << name << ", I will not tolerate you saying the words that consist of the letters \'s h u t  u p\' being said in this server, so take your own advice and close thine mouth in the name of the christian minecraft server owner.\n";
		}
        // If user says "I'm'
		if ((indexvar = falseinput.find(findthis)) != std::string::npos) {
			input.replace(indexvar, findthis.length(), sub);
			size_t pos = input.find("Hi");
			input.erase(0, pos);
			std::cout << "[Dad-Bot]: " << input << ", I'm dad!\n";
		}
	}
}
