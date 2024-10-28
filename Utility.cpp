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

    int difx1 = randomx - 0, difx2 = 4 - randomx;
    int dify1 = randomy - 0, dify2 = 6 - randomy;
    int minimum = min({difx1, difx2, dify1, dify2});
    int position[20] = {0}, j = 0;

    if (ar[randomx][randomy] != 9)
    {
        if (ar[randomx][randomy] == 1)
        {
            suck++;
        }
        ar[randomx][randomy] = 5;
        position[j++] = randomx;
        position[j++] = randomy;
    }

    if (difx2 == minimum)
    {
        while (randomx != 4)
        {
            if (ar[randomx + 1][randomy] == 1)
            {
                suck++;
                ar[randomx + 1][randomy] = 5;
                position[j++] = randomx + 1;
                position[j++] = randomy;
            }
            else if (ar[randomx + 1][randomy] == 9)
            {
                extra_move++;
                if (ar[randomx + 1][randomy - 1] != 9)
                {
                    --randomy;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    --randomx;
                }
                else if (ar[randomx + 1][randomy + 1] != 9)
                {
                    ++randomy;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    --randomx;
                }
            }
            else if (ar[randomx + 1][randomy] == 0)
            {
                ar[randomx + 1][randomy] = 5;
                position[j++] = randomx + 1;
                position[j++] = randomy;
            }
            move++;
            randomx++;
        }
    }
    else if (difx1 == minimum)
    {
        while (randomx != 0)
        {
            if (ar[randomx - 1][randomy] == 1)
            {
                suck++;
                ar[randomx - 1][randomy] = 5;
                position[j++] = randomx - 1;
                position[j++] = randomy;
            }
            else if (ar[randomx - 1][randomy] == 9)
            {
                extra_move++;
                if (ar[randomx - 1][randomy - 1] != 9)
                {
                    --randomy;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    ++randomx;
                }
                else if (ar[randomx + 1][randomy + 1] != 9)
                {
                    ++randomy;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    ++randomx;
                }
            }
            else if (ar[randomx - 1][randomy] == 0)
            {
                ar[randomx - 1][randomy] = 5;
                position[j++] = randomx - 1;
                position[j++] = randomy;
            }
            move++;
            --randomx;
        }
    }
    else if (dify2 == minimum)
    {
        while (randomx != 6)
        {
            if (ar[randomx][randomy + 1] == 1)
            {
                suck++;
                ar[randomx][randomy + 1] = 5;
                position[j++] = randomx;
                position[j++] = randomy + 1;
            }
            else if (ar[randomx][randomy + 1] == 9)
            {
                extra_move++;
                if (ar[randomx - 1][randomy + 1] != 9)
                {
                    --randomx;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    randomy--;
                }
                else if (ar[randomx + 1][randomy + 1] != 9)
                {
                    ++randomx;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    --randomy;
                }
            }
            else if (ar[randomx][randomy + 1] == 0)
            {
                ar[randomx][randomy + 1] = 5;
                position[j++] = randomx;
                position[j++] = randomy + 1;
            }
            move++;
            randomy++;
        }
    }
    else if (dify1 == minimum)
    {
        while (randomy != 0)
        {
            if (ar[randomx][randomy - 1] == 1)
            {
                suck++;
                ar[randomx][randomy - 1] = 5;
                position[j++] = randomx;
                position[j++] = randomy - 1;
            }
            else if (ar[randomx][randomy - 1] == 9)
            {
                extra_move++;
                if (ar[randomx - 1][randomy - 1] != 9)
                {
                    --randomx;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    ++randomy;
                }
                else if (ar[randomx + 1][randomy - 1] != 9)
                {
                    ++randomx;
                    ar[randomx][randomy] = 5;
                    position[j++] = randomx;
                    position[j++] = randomy;
                    ++randomy;
                }
            }
            else if (ar[randomx][randomy - 1] == 0)
            {
                ar[randomx][randomy - 1] = 5;
                position[j++] = randomx;
                position[j++] = randomy - 1;
            }
            move++;
            --randomy;
        }
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

    for (int i = 0; i < 20; i += 2)
    {
        if (position[i] == 0 && position[i + 1] == 0)
        {
            continue;
        }
        else
        {
            cout << '(' << position[i] << ',' << position[i + 1] << "),";
        }
    }
    cout << endl;
    cout << "total move:" << move << ", extra move:" << extra_move << ", total suck:" << suck << endl;
    cout << "performance:" << float(move + suck) / (move) * 100 << '%' << endl;
    return 0;
}