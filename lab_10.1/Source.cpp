#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int Count_aa_bb_cc()
{
    ifstream t("t.txt");

    string S;

    int k = 0;

    while (getline(t, S))
    {
        for (int i = 0; i < S.length(); i++)
        {
            if ((S[i] == 'a' && S[i + 1] == 'a')
                ||
                (S[i] == 'b' && S[i + 1] == 'b')
                ||
                (S[i] == 'c' && S[i + 1] == 'c'))

                k++;
        }
    }
    return k;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " ≥льк≥сть пар сус≥дн≥х букв УaaФ або УbbФ або УccФ в файл≥ t.txt: " << Count_aa_bb_cc() << endl;
    return 0;
}