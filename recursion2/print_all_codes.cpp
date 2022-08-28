#include <string.h>
using namespace std;

void helper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    char firstchar = 'a' + int(input[0] - 48) - 1;
    helper(input.substr(1), output + firstchar);
    if (input[1] != '\0')
    {
        int no = (input[0] - 48) * 10 + (input[1] - 48);
        if (no <= 27)
        {
            char secondchar = 'a' + no - 1;
            helper(input.substr(2), output + secondchar);
        }
    }
}
void printAllPossibleCodes(string input)
{
    string output;
    helper(input, output);
}