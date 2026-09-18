#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int count = 0;
    bool a = false;
    bool b = false;
    bool c = false;
    bool d = false;
    for (int i = 0; i < password.length(); i++)
    {
        if (isdigit(password[i]))
        {
            a = true;
        }
    }
    if (a == false) count++;
    for (int i = 0; i < password.length(); i++)
    {
        if (islower(password[i]))
        {
            b = true;
        }
    }

    if (b == false) count++;
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            c = true;
        }
    }
    if (c == false) count++;
    for (int i = 0; i < password.length(); i++)
    {
        if (!isalnum((password[i])))
        {
            d = true;
        }
    }
    if (d == false) count++;
    int kiTuThieu = 6 - password.length();
    if (kiTuThieu > count) return kiTuThieu;
    else return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
