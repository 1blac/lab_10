#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int Count_words()
{
    int k = 0;

    ifstream t("t.txt");
    string s;

    int i;
    while (getline(t, s))
    {
        for (i = 0; i < s.length(); i++)
            if (s[i] != ' ')
                break;
                for (int j = i + 1; j < s.length(); j++)
                    if(s[j] == s[i] && s[j + 1] == ' ')
               
                    {
                        k++;
                    }
    }
    return k;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Кількість слів у файлі t.txt: " << Count_words() << endl;

    return 0;
}