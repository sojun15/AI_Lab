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

    int randomx = 1 + (rand() % 3);
    int randomy = 1 + (rand() % 5);
    int suck = 0, move = 0;

    while (randomx != 4)
    {
        if (ar[randomx][randomy] == 1)
        {
            suck++;
        }
        move++;
        randomx++;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << ar[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "total move:" << move << ", total suck:" << suck << endl;
    cout << "performance:" << float(move + suck) / move * 100 << '%' << endl;
    return 0;
}