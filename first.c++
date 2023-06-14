// Given a sequence of M and N, form smallest possible number under following condition -> M denotes the sequence is decreasing, N denotes the sequence is increasing.
// Constraints / Assumptions: 
//     1] Digits must not repeat.
//     2] Allowable digits are 1-9.
//     3] Maximum length of input sequence will be 8 characters.
//     4] No characters other than M & N will be there in the input.
// Example:
//     Input: M        Output: 21
//     Input: N        Output: 12
//     Input: MM       Output: 321
//     Input: NN       Output: 123
//     Input: MNMN     Output: 21435
//     Input: NNMMM    Output: 126543
//     Input: MMNMMNNM Output: 321654798
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxNum = n + 1;
    int minNum = 1;
    vector<int> ans(n + 1);
    bool check = false;

    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if (ch == 'N')
        {
            check = true;
            ans[i + 1] = minNum;
            minNum++;
            int j = i;
            while (j >= 0 && arr[j] == 'M')
            {
                ans[j] = minNum;
                minNum++;
                j--;
            }
        }
    }

    if (check == false)
    {
        for (int i = 0; i <= n; i++)
            ans[i] = maxNum--;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }

    return 0;
}

