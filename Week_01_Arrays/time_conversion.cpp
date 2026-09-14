#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string format24;
    string hai_so_dau = s.substr(0, 2);
    string phan_con_lai = s.substr(2, 6);
    int gio = stoi(hai_so_dau);
    if (s.find("AM") != string::npos && gio != 12)
    {
        format24 = s.substr(0, 8);
        return format24;
    }
    if (s.find("AM") != string::npos && gio == 12)
    {
        format24 = "00" + phan_con_lai;
        return format24;
    }
    if (s.find("PM") != string::npos)
    {
        if (gio != 12)
        {
            gio = gio + 12;
            format24 = to_string(gio) + phan_con_lai;
            return format24;
        }
        else
        {
            format24 = s.substr(0, 8);
            return format24;
        }
    }
    return format24;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
