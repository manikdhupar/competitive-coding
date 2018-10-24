#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int rem = num % 10;
    int smallOutputSize = keypad(num / 10, output);

    if (rem == 2)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'a', 'b', 'c'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }
        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 3)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'d', 'e', 'f'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 4)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'g', 'h', 'i'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 5)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'j', 'k', 'l'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 6)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'m', 'n', 'o'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 7)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'p', 'q', 'r', 's'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else if (rem == 8)
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'t', 'u', 'v'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = temp + arr[j];
                tempCount++;
            }
        }
        return tempCount;
    }
    else
    {
        int tempCount = 0;
        int i = 0;
        string arr = {'w', 'x', 'y', 'z'};
        string *tempArray = new string[smallOutputSize];

        for (int t = 0; t < smallOutputSize; t++)
        {
            tempArray[t] = output[t];
        }

        for (int i = 0; i < smallOutputSize; i++)
        {
            string temp = tempArray[i];
            for (int j = 0; j < 3; j++)
            {
                output[tempCount] = arr[j] + temp;
                tempCount++;
            }
        }
        return tempCount;
    }
}

int main()
{
    int num;
    cin >> num;
    int timer = 0;
    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
