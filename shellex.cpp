#include <iostream>
#include <Windows.h>
#define true 1
class GameLauncher {
public:
    void launch(const wchar_t* gamePath, const wchar_t* gameName) {
        int result = (int)ShellExecuteW(NULL, L"open", gamePath, NULL, NULL, SW_SHOWNORMAL);
        if (result <= 32) {
            std::cerr << "Error launching " << gameName << std::endl;
        }
    }
};

int main() {
    GameLauncher launcher;
    int lib_var;

    std::wcout << L"Enter a number to launch a game:\n"
                 L"1 - Little Witch Nobeta\n"
                 L"2 - NFS: Most Wanted\n"
                 L"3 - GTA SanAndreas\n"
                 L"4 - Honkai: Star Rail\n"
                 L"5 - Evenicle\n"
                 L"6 - HagguViewer\n";
                 L"7 - Exit the program\n";

    while (true) {
        std::wcin >> lib_var;

        switch (lib_var) {
        case 1:
            launcher.launch(L"D:\\Games\\LittleWitchNobeta\\LittleWitchNobeta.exe", L"Little Witch Nobeta");
            break;
        case 2:
            launcher.launch(L"D:\\Games\\NFS_MostWanted\\NFS13.exe", L"NFS: Most Wanted");
            break;
        case 3:
            launcher.launch(L"D:\\Games\\GTA_SanAndreas\\gta_sa.exe", L"GTA SanAndreas");
            break;
        case 4:
            launcher.launch(L"D:\\StarRail\\Games\\StarRail.exe", L"Honkai: Star Rail");
            break;
        case 5:
            launcher.launch(L"D:\\VisualNovels\\Evenicl\\Evenicle.exe", L"Evenicle");
            break;
        case 6:
            launcher.launch(L"D:\\.Studies\\Coding\\C++\\GUI_C++\\HagguViewer\\x64\\Debug\\HagguViewer.exe", L"HagguViewer");
            break;
        case 7:
            exit(1);
        default:
            std::wcerr << L"Invalid input. Try again." << std::endl;
            break;
        }
    }
    return 0;
}
