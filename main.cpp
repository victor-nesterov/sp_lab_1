// ������� 3

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

const char letters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" }; // 26 * 2 = 52 �������
const char vowel_letters[] = { "AEIOUYaeiouy" }; // 6 * 2 = 12 ��������

bool isLetter(char a)
{
    for (int i = 0; i < 52; ++i)
        if (a == letters[i])
            return true;
    return false;
}

bool isVowelLetter(char a)
{
    for (int i = 0; i < 12; ++i)
        if (a == vowel_letters[i])
            return true;
    return false;
}

int main()
{
    // ��������� ����:
    ifstream fin;
    fin.open("C:\\Users\\Victor\\source\\repos\\Lab1\\input.txt");
    if (!fin)
    {
        cout << "Cannot open the file" << endl;
        return 1;
    }
    // ������ ����� �� �������:
    set<string> res; // ����� ����
    string word = "";
    bool word_ok = true; // ����� �� ��������� ����� � �������
    char t;
    while (fin.get(t))
    {
        if (isLetter(t) && word_ok)
            if (isVowelLetter(t))
                word.push_back(t);
            else
                word_ok = false;
        else if (!isLetter(t))
        {
            if (word_ok && word != "")
                res.insert(word);
            else if (!word_ok)
                word_ok = true;
            word = "";
        }
    }
    // ���� ���� ������������� �� �����:
    if (word_ok && word != "")
        res.insert(word);
    else if (!word_ok)
        word_ok = true;
    word = "";
    // ��������� ����, ������� �����:
    fin.close();
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}