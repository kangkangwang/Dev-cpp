#include <iostream>
#include <queue>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
    int x;
    int y;
    int index;
};

int m, n, sum;
node p[5];
int dist[5][5];
char map[20][20];
int sa[20][20];

void distance(int map[][20], node s)
{
    queue<node> q;
    q.push(s);
    map[s.x][s.y] = 0;

    while (!q.empty())
    {
        node item = q.front();
        q.pop();

        if (item.x<m-1)
        {
            if (map[item.x][item.y] + 1 < map[item.x + 1][item.y] )
            {
                node temp;
                temp.x = item.x + 1;
                temp.y = item.y;
                map[temp.x][temp.y] = map[item.x][item.y] + 1;
                q.push(temp);
            }
        }
        if (item.x > 0 )
        {
            if (map[item.x][item.y] + 1 < map[item.x - 1][item.y] )
            {
                node temp;
                temp.x = item.x - 1;
                temp.y = item.y;
                map[temp.x][temp.y] = map[item.x][item.y] + 1;
                q.push(temp);
            }
        }
        if ( item.y > 0)
        {
            if (map[item.x][item.y] + 1 < map[item.x][item.y - 1] )
            {
                node temp;
                temp.x = item.x ;
                temp.y = item.y - 1;
                map[temp.x][temp.y] = map[item.x][item.y] + 1;
                q.push(temp);
            }
        }
        if (item.y < n - 1)
        {
            if (map[item.x][item.y] + 1 < map[item.x][item.y + 1] )
            {
                node temp;
                temp.x = item.x ;
                temp.y = item.y + 1;
                map[temp.x][temp.y] = map[item.x][item.y] + 1;
                q.push(temp);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        dist[s.index][i] = map[p[i].x][p[i].y];
    }
    

}

int mindis(node s, bool vi[],int len)
{
    bool visit[5];
    memcpy(visit, vi, sizeof(visit));
    visit[s.index] = true;
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        flag = flag && visit[i];

        if (visit[i] == false)
        {
            mindis(p[i], visit, len + dist[s.index][p[i].index]);
        }
    }
    if (flag)
    {
        if (sum>len)sum = len;
    }
    return 0;
}

int main(int argc, char** argv)
{

    while (cin >> m >> n)
    {

        int index = 0;

        sum = 99999;

        p[index].x = 0;
        p[index].y = 0;
        p[index].index = index;

        index++;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
                if ( map[i][j] == 'B')
                {
                    p[index].x = i;
                    p[index].y = j;
                    p[index].index = index;
                    index++;
                }
            }
        }



        for (int k = 0; k < 5; k++)
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    if (map[i][j] != '*')
                    {
                        sa[i][j] = 99999;
                    }
                    else if (map[i][j]=='*')
                    {
                        sa[i][j] = -1;
                    }

                }
            distance(sa, p[k]);
        }

        bool visit[5]{false, false, false, false, false};

        mindis(p[0], visit, 0);

        cout << sum << endl;

    }
    return 0;

}
