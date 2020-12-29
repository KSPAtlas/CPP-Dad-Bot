#include<iostream>
#include<string>
#include<algorithm>
std::string findthis = "i\'m";
std::string input;
std::string falseinput;
std::string name;
bool IsWindows;
int index;
std::string sub = "Hi";
int main() {
#ifdef _WIN32
	std::cout << "You are running in Windows mode.\n";
	IsWindows = true;
#else
	std::cout << "You are running in Unix mode.\n";
	IsWindows = false;
#endif
	std::cout << "What name would you like me to call you? ";
	std::getline(std::cin, name);
	if (IsWindows == true) {
		system("cls");
	}
	else {
		system("clear");
	}
	while (true) {
		std::getline(std::cin, input);
		falseinput = input;
		std::for_each(falseinput.begin(), falseinput.end(), [](char& c) {
			c = ::tolower(c);
			});
		if ((index = falseinput.find("d!dadjoke")) != std::string::npos) {
			std::cout << "Oh no! Dad jokes are currently not available. Check back later.\n";
		}
		if ((index = falseinput.find("shut up")) != std::string::npos) {
			std::cout << "Listen here " << name << ", I will not tolerate you saying the words that consist of the letters \'s h u t  u p\' being said in this server, so take your own advice and close thine mouth in the name of the christian minecraft server owner.\n";
		}
		if ((index = falseinput.find(findthis)) != std::string::npos) {
			input.replace(index, findthis.length(), sub);
			size_t pos = input.find("Hi");
			input.erase(0, pos);
			std::cout << input << ", I'm dad!\n";
		}
	}
}