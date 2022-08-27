#include <string.h>
using namespace std;

int getCodes(string input, string output[10000])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string output1[500];
    string output2[500];
    char firstchar = 'a' + int(input[0] - 48) - 1;
    char secondchar = '\0';
    int size1 = getCodes(input.substr(1), output1);
    int size2 = 0;
    if (input[1] != '\0')
    {
        int no = (input[0] - 48) * 10 + (input[1] - 48);
        if (no <= 26)
        {
            secondchar = 'a' + no - 1;
            size2 = getCodes(input.substr(2), output2);
        }
    }
    for (int i = 0; i < size1; i++)
    {
        output[i] = firstchar + output1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        output[i + size1] = secondchar + output2[i];
    }
    return size1 + size2;
}
