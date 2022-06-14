#include <Windows.h>
#include <codecvt>

#include "SubordinateTester.h"
#include "MemoryTest.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	MessageBox(
		NULL,
		std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(SubordinateTester(hInstance, nCmdShow).test()).c_str(),
		L"subordinate tester",
		NULL
	);

	MessageBox(
		NULL,
		std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(MemoryTest().test()).c_str(),
		L"memory test",
		NULL
	);

	return 0;
}
