#include "main.hpp"
int main() {
	Keyboard::RegisterKeys();
	File* file = new File();
	bool printControl = true;
	MSG msg;
	do {
		if (printControl) {
			Console::printChoices();
			printControl = false;
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) //Clear Message Queue
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if (GetMessage(&msg, 0, 0, 0) != 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			switch (msg.message) {
			case WM_HOTKEY:
				if (msg.wParam == 0) {
					// Maybe New Feature
				}
				else if (msg.wParam == 1) {
					printControl = file->record();
				}
				else if (msg.wParam == 2) {
					printControl = file->start(); 
				}
			}
		}
	} while (msg.wParam != 3);
	delete file;
	return 0;
}
