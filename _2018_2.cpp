#include <fstream>

using namespace std;

struct slidininkas
{
    string name = "Error";
    int time = 0;
    bool finished = false;
};

void my_sort(slidininkas dalyviai[30]);
void write(slidininkas dalyviai[30]);

int main()
{
    slidininkas dalyviai[30];
    ifstream duom("Duomenys.txt");
    int n;
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        duom.ignore();
        char temp[21];
        duom.get(temp, 21);
        dalyviai[i].name = temp;
        int h, m, s;
        duom >> h >> m >> s;
        dalyviai[i].time = h * 60 * 60 + m * 60 + s;
    }
    int n2;
    duom >> n2;
    for (int i = 0; i < n2; i++)
    {
        duom.ignore();
        char temp[21];
        duom.get(temp, 21);
        int h, m, s;
        duom >> h >> m >> s;
        for (int j = 0; j < n; j++)
        {
            if (dalyviai[j].name == temp)
            {
                dalyviai[j].time -= h * 60 * 60 + m * 60 + s;
                dalyviai[j].time *= -1;
                dalyviai[j].finished = true;
            }
        }
    }
    my_sort(dalyviai);
    write(dalyviai);
    duom.close();
    return 0;
}

void write(slidininkas dalyviai[30])
{
    ofstream rez("Rezultatai.txt");
    for (int i = 0; i < 30; i++)
    {
        if (dalyviai[i].finished)
        {
            rez << dalyviai[i].name << ' ' << dalyviai[i].time / 60 << ' ' << dalyviai[i].time % 60 << '\n';
        }   
    }
    rez.close();
}

void my_sort(slidininkas dalyviai[30])
{
    for (int i = 0; i < 30; i++)
    {
        if (dalyviai[i].finished)
        {
            for (int j = i; j < 30; j++)
            {
                if (dalyviai[j].finished)
                {
                    if (dalyviai[i].time > dalyviai[j].time)
                    {
                        swap(dalyviai[i], dalyviai[j]);
                    }
                    else if(dalyviai[i].time == dalyviai[j].time)
                    {
                        if (dalyviai[i].name > dalyviai[j].name)
                        {
                            swap(dalyviai[i], dalyviai[j]);
                        }
                    }
                }
            }
        }
    }
}