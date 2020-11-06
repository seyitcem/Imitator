#include "Console.hpp"
void Console::printChoices() {
    cout << "########################" << endl;
    cout << "'ALT + 1' - Mouse pozisyonunu kaydetmeye basla" << endl;
    cout << "'ALT + 2' - Hareketleri tekrarla" << endl;
    cout << "'ALT + 3' - Cikis" << endl;
    cout << "Not: Kaydi bitirmek veya Imitator'u durdurmak icin 'ALT GR' tusuna basmaniz gerekmektedir." << endl;
    cout << "########################" << endl;
}
void Console::clearBuffer() {
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
