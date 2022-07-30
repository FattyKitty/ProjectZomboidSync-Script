#include <iostream>
#include <filesystem>
#include <string>
#include <filesystem>
#include <windows.h>
#include <Lmcons.h>
#include <sys/stat.h>

int main()
{
	std::string SaveFileName;
	std::string SavesFolderPath;

	struct stat buffer;

	int BackupChoice;

	char UserName[100];
	DWORD UserNameSize = sizeof(UserName);

	GetUserNameA(UserName, &UserNameSize);

	SavesFolderPath = "C:\\Users\\" + (std::string)UserName + "\\Zomboid\\Saves\\";

	if (stat(SavesFolderPath.c_str(), &buffer) != 0)
	{
		std::cout << "There is no Project Zomboid Saves Folder on your PC\n";
		return -1;
	}

	std::cout << "Please, enter what gamemode you want to backup?\n1.Apocalypse\n2.Builder\n3.Multiplayer\n4.Sandbox\n";
	std::cout << "Your choice: ";

	std::cin >> BackupChoice;
	std::cout << "\n\n";

	switch (BackupChoice)
	{
	case 1:
		SavesFolderPath += "Apocalypse\\";
		break;
	case 2:
		SavesFolderPath += "Builder\\";
		break;
	case 3:
		SavesFolderPath += "Multiplayer\\";
		break;
	case 4:
		SavesFolderPath += "SandBox\\";
		break;
	default:
		std::cout << "Invalid input!\n";
	}

	std::cout << "Please enter the name of PZ GameWorld you want to backup\n";
	std::cout << "SaveFile name: ";
	std::cin >> SaveFileName;

	SavesFolderPath += SaveFileName;

	if (stat((SavesFolderPath).c_str(), &buffer) != 0)
	{
		std::cout << "There is no such file in folder";
		return -2;
	}

	std::cout << "In progress. Please, don't close the console tab";
	if (stat((SavesFolderPath+"Backup").c_str(), &buffer) == 0)
	{
		std::filesystem::remove_all(SavesFolderPath+"Backup");
	}

	std::filesystem::copy(SavesFolderPath, SavesFolderPath+ "Backup");

	std::cout << "Done!";
	system("pause");
	return 0;
}