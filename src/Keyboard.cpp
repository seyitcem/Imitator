#include "Keyboard.hpp"
#define MOD_NOREPEAT 0x4000
void Keyboard::RegisterKeys() {
    int keyCodes[4] = { 0x30,           // 0
                        0x31,           // 1
                        0x32,           // 2
                        0x33 };         // 3
    for (int i = 0; i < 4; i++) {
        RegisterHotKey(NULL, i, MOD_ALT | MOD_NOREPEAT, keyCodes[i]);
        //cout << "KEY " << (char)keyCodes[i] << " OK" << endl;
    }
}
