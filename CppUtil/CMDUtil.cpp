#include <Windows.h>

#include "CMDUtil.h"

using namespace std;

void CMDUtil::ExcuteCommand(const string& command)
{
	string cmd = "/k " + command; // /k : ��� ������ cmd����
	auto x = ShellExecuteA(NULL, "open", "cmd.exe", cmd.c_str(), NULL, SW_HIDE);
}
