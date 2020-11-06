#include "File.hpp"
File::File() {
    this->sleepTime = 0;
}
bool File::record() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    ofstream write("record.txt");
    cout << "#Kayit basladi. 'ALT GR' tusuna basilana kadar kayit devam edecektir." << endl;
    Cursor* cursor = new Cursor();
    while (true) {
        if (GetKeyState(VK_RMENU) & 0x8000) {
            break;
        }
        if (GetCursorPos(&(cursor->point))) {
            if (GetAsyncKeyState(VK_LBUTTON)) {
                while (GetAsyncKeyState(VK_LBUTTON)) {
                    Console::clearBuffer();
                    GetCursorPos(&(cursor->point));
                    write << "LC " << cursor->point.x << "," << cursor->point.y << endl;
                    //cout << "LC " << cursor->point.x << "," << cursor->point.y << endl;
                    Sleep(sleepTime);
                }
                GetCursorPos(&(cursor->point));
                write << "LR " << cursor->point.x << "," << cursor->point.y << endl;
                //cout << "LR " << cursor->point.x << "," << cursor->point.y << endl;
                Sleep(sleepTime);
            }
            else if (GetAsyncKeyState(VK_RBUTTON)) {
                while (GetAsyncKeyState(VK_RBUTTON)) {
                    Console::clearBuffer();
                    GetCursorPos(&(cursor->point));
                    write << "RC " << cursor->point.x << "," << cursor->point.y << endl;
                    //cout << "RC " << cursor->point.x << "," << cursor->point.y << endl;
                    Sleep(sleepTime);
                }
                write << "RR " << cursor->point.x << "," << cursor->point.y << endl;
                //cout << "RR " << cursor->point.x << "," << cursor->point.y << endl;
                Sleep(sleepTime);
            }
            else {
                write << "XX " << cursor->point.x << "," << cursor->point.y << endl;
                //cout << "XX " << cursor->point.x << "," << cursor->point.y << endl;
                Sleep(sleepTime);
            }
        }
    }
    delete cursor;
    write.close();
    cout << "#KAYIT BASARILI." << endl;
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "#Islem " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]'de tamamlandi." << endl;
    return true;
}
bool File::start() {
    cout << "Imitator basladi." << endl;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    ifstream read;
    string line;
    string x, y;
    string command;
    read.open("record.txt");
    if (read.is_open()) {
        Cursor* cursor = new Cursor();
        while (!read.eof()) {
            if (GetKeyState(VK_RMENU) & 0x8000) {
                cout << "#IMITATOR DURDURULDU." << endl;
                return true;
            }
            getline(read, line);
            stringstream line_text(line);
            getline(line_text, command, ' ');
            if (command == "XX") {
                getline(line_text, x, ',');
                cursor->point.x = stoi(x);
                getline(line_text, y);
                cursor->point.y = stoi(y);
                //cout << "XX " << cursor->point.x << "," << cursor->point.y << endl;
                SetCursorPos(cursor->point.x, cursor->point.y);
                Sleep(sleepTime);
            }
            else if (command == "LC") {
                mouse_event(MOUSEEVENTF_LEFTDOWN, cursor->point.x, cursor->point.y, 0, 0);
                do {
                    getline(read, line);
                    stringstream line_text(line);
                    getline(line_text, command, ' ');
                    getline(line_text, x, ',');
                    cursor->point.x = stoi(x);
                    getline(line_text, y);
                    cursor->point.y = stoi(y);
                    SetCursorPos(cursor->point.x, cursor->point.y);
                    //cout << "LC " << cursor->point.x << "," << cursor->point.y << endl;
                    Sleep(sleepTime);
                } while(command != "LR");
                //cout << "LR " << cursor->point.x << "," << cursor->point.y << endl;
                mouse_event(MOUSEEVENTF_LEFTUP, cursor->point.x, cursor->point.y, 0, 0);
                Sleep(sleepTime);
            }
            else if (command == "RC") {
                mouse_event(MOUSEEVENTF_RIGHTDOWN, cursor->point.x, cursor->point.y, 0, 0);
                do {
                    getline(read, line);
                    stringstream line_text(line);
                    getline(line_text, command, ' ');
                    getline(line_text, x, ',');
                    cursor->point.x = stoi(x);
                    getline(line_text, y);
                    cursor->point.y = stoi(y);
                    SetCursorPos(cursor->point.x, cursor->point.y);
                    //cout << "RC " << cursor->point.x << "," << cursor->point.y << endl;
                    Sleep(sleepTime);
                } while (command != "RR");
                //cout << "RR " << cursor->point.x << "," << cursor->point.y << endl;
                mouse_event(MOUSEEVENTF_RIGHTUP, cursor->point.x, cursor->point.y, 0, 0);
                Sleep(sleepTime);
            }
        }
        delete cursor;
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "#Islem " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]'de tamamlandi." << endl;
    return true;
}
