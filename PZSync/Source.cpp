#include <iostream>
#include <filesystem>
#include <string>
#include <windows.h>
#include <Lmcons.h>

int main()
{
	std::string SaveFileName;
	std::string SavesFolderPath;


	char UserName[100];
	DWORD UserNameSize = sizeof(UserName);
	
	GetUserNameA(UserName, &UserNameSize);

	SavesFolderPath = "C:\\Users\\" +(std::string)UserName +"\\Zomboid\\";

	std::cout <<SavesFolderPath;
	return 0;
}