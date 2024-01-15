// Вариант 3

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

const char letters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" }; // 26 * 2 = 52 символа
const char vowel_letters[] = { "AEIOUYaeiouy" }; // 6 * 2 = 12 символов

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
    // Открываем файл:
    ifstream fin;
    fin.open("C:\\Users\\Victor\\source\\repos\\Lab1\\input.txt");
    if (!fin)
    {
        cout << "Cannot open the file" << endl;
        return 1;
    }
    // Читаем текст по символу:
    set<string> res; // Набор слов
    string word = "";
    bool word_ok = true; // будем ли добавлять слово в словарь
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
    // Если файл заканчивается на слове:
    if (word_ok && word != "")
        res.insert(word);
    else if (!word_ok)
        word_ok = true;
    word = "";
    // Закрываем файл, выводим ответ:
    fin.close();
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}