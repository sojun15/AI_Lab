#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[5][7] = {0};

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 10; i++)
    {
        int randomx = (rand() % 5);
        int randomy = (rand() % 7);
        ar[randomx][randomy] = 1;
    }
    for (int i = 0; i < 5; i++)
    {
        int randomx = (rand() % 5);
        int randomy = (rand() % 7);
        while (ar[randomx][randomy] == 1 || ar[randomx][randomy] == 9)
        {
            randomx = (rand() % 5);
            randomy = (rand() % 7);
        }
        ar[randomx][randomy] = 9;
    }
    cout << "previous state:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << ar[i][j] << ' ';
        }
        cout << endl;
    }

    int randomx = 1 + (rand() % 3);
    int randomy = 1 + (rand() % 5);
    int suck = 0, move = 0, extra_move = 0;
    if (ar[randomx][randomy] != 9)
    {
        if (ar[randomx][randomy] == 1)
        {
            suck++;
        }
        ar[randomx][randomy] = 5;
    }

    while (randomx != 4)
    {
        if (ar[randomx + 1][randomy] == 1)
        {
            suck++;
            ar[randomx + 1][randomy] = 5;
        }
        else if (ar[randomx + 1][randomy] == 9)
        {
            extra_move++;
            if (ar[randomx + 1][randomy - 1] != 9)
            {
                --randomy;
                ar[randomx][randomy] = 5;
                --randomx;
            }
            else if (ar[randomx + 1][randomy + 1] != 9)
            {
                ++randomy;
                ar[randomx][randomy] = 5;
                --randomx;
            }
        }
        else if (ar[randomx + 1][randomy] == 0)
        {
            ar[randomx + 1][randomy] = 5;
        }
        move++;
        randomx++;
    }

    cout << "Final state:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << ar[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "total move:" << move << ", extra move:" << extra_move << ", total suck:" << suck << endl;
    cout << "performance:" << float(move + suck) / (move) * 100 << '%' << endl;
    return 0;
}