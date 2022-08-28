#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    int k;
    for (int i = 0; input[i] != '\0'; i++)
    {
        char c = input[i];
        string output1[1000];
        string s = input.substr(0, i) + input.substr(i + 1);
        k = returnPermutations(s, output1);
        for (int j = 0; j < k; j++)
        {
            output[j + (k * i)] = c + output1[j];
        }
    }
    int len = input.length();
    return len * k;
}
