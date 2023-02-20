#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>


using namespace std;


int** parse_file(string filename)
{
    // initialize a pointer array of size 10 x 5
    int **arr = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[5];
    }

    ifstream file(filename);
    string line;
    int i = 0;
    if (!file.is_open())
        throw runtime_error("Could not open file");
    while(getline(file, line))
    {
        int j = 0;
        stringstream ss(line);
        string item;
        while(getline(ss, item, ' '))
        {
            arr[i][j] = stoi(item);
            j++;
        }
        i++;
    }
    return arr;
}


int main()
{
    int programmer1pref[5], programmer2pref[5], programmer3pref[5], programmer4pref[5], programmer5pref[5];
    int department1pref[5], department2pref[5], department3pref[5], department4pref[5], department5pref[5];

    int **arr = parse_file("matching-data.txt");
    for (int i = 0; i < 5; i++)
    {
        department1pref[i] = arr[i][0];
        department2pref[i] = arr[i][1];
        department3pref[i] = arr[i][2];
        department4pref[i] = arr[i][3];
        department5pref[i] = arr[i][4];
        programmer1pref[i] = arr[i + 5][0];
        programmer2pref[i] = arr[i + 5][1];
        programmer3pref[i] = arr[i + 5][2];
        programmer4pref[i] = arr[i + 5][3];
        programmer5pref[i] = arr[i + 5][4];
    }


    // check if department1pref has any conflicts with other departments

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (department1pref[i] == department2pref[j] || department1pref[i] == department3pref[j] || department1pref[i] == department4pref[j] || department1pref[i] == department5pref[j])
            {
                for (int k = 0; k < 5; k++) {
                    if (programmer1pref[k] == 1) {
                        cout << "Department 1 will get Programmer #1" << endl;
                        memset(programmer1pref, 0, sizeof(programmer1pref));
                        goto preference2;
                    } else if (programmer2pref[k] == 1) {
                        cout << "Department 1 will get Programmer #2" << endl;
                        memset(programmer2pref, 0, sizeof(programmer2pref));
                        goto preference2;
                    } else if (programmer3pref[k] == 1) {
                        cout << "Department 1 will get Programmer #3" << endl;
                        memset(programmer3pref, 0, sizeof(programmer3pref));
                        goto preference2;
                    } else if (programmer4pref[k] == 1) {
                        cout << "Department 1 will get Programmer #4" << endl;
                        memset(programmer4pref, 0, sizeof(programmer4pref));
                        goto preference2;
                    } else if (programmer5pref[k] == 1) {
                        cout << "Department 1 will get Programmer #5" << endl;
                        memset(programmer5pref, 0, sizeof(programmer5pref));
                        goto preference2;
                    }
                }
            } else {
                cout << "Department 1 will get Programmer #" << department1pref[i] << endl;
                department1pref[i] = 0;
                goto preference2;
            }
        }
    }
    preference2:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (department2pref[i] == department1pref[j] || department2pref[i] == department3pref[j] || department2pref[i] == department4pref[j] || department2pref[i] == department5pref[j])
            {
                for (int k = 0; k < 5; k++) {
                    if (programmer1pref[k] == 2) {
                        cout << "Department 2 will get Programmer #1" << endl;
                        memset(programmer1pref, 0, sizeof(programmer1pref));
                        goto preference3;
                    } else if (programmer2pref[k] == 2) {
                        cout << "Department 2 will get Programmer #2" << endl;
                        memset(programmer2pref, 0, sizeof(programmer2pref));
                        goto preference3;
                    } else if (programmer3pref[k] == 2) {
                        cout << "Department 2 will get Programmer #3" << endl;
                        memset(programmer3pref, 0, sizeof(programmer3pref));
                        goto preference3;
                    } else if (programmer4pref[k] == 2) {
                        cout << "Department 2 will get Programmer #4" << endl;
                        memset(programmer4pref, 0, sizeof(programmer4pref));
                        goto preference3;
                    } else if (programmer5pref[k] == 2) {
                        cout << "Department 2 will get Programmer #5" << endl;
                        memset(programmer5pref, 0, sizeof(programmer5pref));
                        goto preference3;
                    }
                }
            } else {
                cout << "Department 2 will get Programmer #" << department2pref[i] << endl;
                department2pref[i] = 0;
                goto preference3;
            }
        }
    }
    preference3:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (department3pref[i] == department1pref[j] || department3pref[i] == department2pref[j] || department3pref[i] == department4pref[j] || department3pref[i] == department5pref[j])
            {
                for (int k = 0; k < 5; k++) {
                    if (programmer1pref[k] == 3) {
                        cout << "Department 3 will get Programmer #1" << endl;
                        memset(programmer1pref, 0, sizeof(programmer1pref));
                        goto preference4;
                    } else if (programmer2pref[k] == 3) {
                        cout << "Department 3 will get Programmer #2" << endl;
                        memset(programmer2pref, 0, sizeof(programmer2pref));
                        goto preference4;
                    } else if (programmer3pref[k] == 3) {
                        cout << "Department 3 will get Programmer #3" << endl;
                        memset(programmer3pref, 0, sizeof(programmer3pref));
                        goto preference4;
                    } else if (programmer4pref[k] == 3) {
                        cout << "Department 3 will get Programmer #4" << endl;
                        memset(programmer4pref, 0, sizeof(programmer4pref));
                        goto preference4;
                    } else if (programmer5pref[k] == 3) {
                        cout << "Department 3 will get Programmer #5" << endl;
                        memset(programmer5pref, 0, sizeof(programmer5pref));
                        goto preference4;
                    }
                }
            } else {
                cout << "Department 3 will get Programmer #" << department3pref[i] << endl;
                department3pref[i] = 0;
                goto preference4;
            }
        }
    }
    preference4:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (department4pref[i] == department1pref[j] || department4pref[i] == department2pref[j] || department4pref[i] == department3pref[j] || department4pref[i] == department5pref[j])
            {
                for (int k = 0; k < 5; k++) {
                    if (programmer1pref[k] == 4) {
                        cout << "Department 4 will get Programmer #1" << endl;
                        memset(programmer1pref, 0, sizeof(programmer1pref));
                        goto preference5;
                    } else if (programmer2pref[k] == 4) {
                        cout << "Department 4 will get Programmer #2" << endl;
                        memset(programmer2pref, 0, sizeof(programmer2pref));
                        goto preference5;
                    } else if (programmer3pref[k] == 4) {
                        cout << "Department 4 will get Programmer #3" << endl;
                        memset(programmer3pref, 0, sizeof(programmer3pref));
                        goto preference5;
                    } else if (programmer4pref[k] == 4) {
                        cout << "Department 4 will get Programmer #4" << endl;
                        memset(programmer4pref, 0, sizeof(programmer4pref));
                        goto preference5;
                    } else if (programmer5pref[k] == 4) {
                        cout << "Department 4 will get Programmer #5" << endl;
                        memset(programmer5pref, 0, sizeof(programmer5pref));
                        goto preference5;
                    }
                }
            } else {
                cout << "Department 4 will get Programmer #" << department4pref[i] << endl;
                department4pref[i] = 0;
                goto preference5;
            }
        }
    }
    preference5:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (department5pref[i] == department1pref[j] || department5pref[i] == department2pref[j] || department5pref[i] == department3pref[j] || department5pref[i] == department4pref[j])
            {
                for (int k = 0; k < 5; k++) {
                    if (programmer1pref[k] == 5) {
                        cout << "Department 5 will get Programmer #1" << endl;
                        memset(programmer1pref, 0, sizeof(programmer1pref));
                        goto end;
                    } else if (programmer2pref[k] == 5) {
                        cout << "Department 5 will get Programmer #2" << endl;
                        memset(programmer2pref, 0, sizeof(programmer2pref));
                        goto end;
                    } else if (programmer3pref[k] == 5) {
                        cout << "Department 5 will get Programmer #3" << endl;
                        memset(programmer3pref, 0, sizeof(programmer3pref));
                        goto end;
                    } else if (programmer4pref[k] == 5) {
                        cout << "Department 5 will get Programmer #4" << endl;
                        memset(programmer4pref, 0, sizeof(programmer4pref));
                        goto end;
                    } else if (programmer5pref[k] == 5) {
                        cout << "Department 5 will get Programmer #5" << endl;
                        memset(programmer5pref, 0, sizeof(programmer5pref));
                        goto end;
                    }
                }
            } else {
                cout << "Department 5 will get Programmer #" << department5pref[i] << endl;
                department5pref[i] = 0;
                goto end;
            }
        }
    }
    end:


    return 0;
}