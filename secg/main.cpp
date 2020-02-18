#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

bool is_num(const std::string &s)
{
    size_t offset = 0;
    if (s[offset] == '-')
        ++offset;
    return s.find_first_not_of("0123456789", offset) == std::string::npos;
}

std::string if_correct(std::string str, int f)
{
    while (true)
    {
        if (!is_num(str))
        {
            system("cls");
            std::cout << "Incorrect input. Please, make a valid input." << std::endl;
            if (f == 0)
            {
                std::cout << "Vertices in 1st graph: ";
            }
            if (f == 1)
            {
                std::cout << "Vertices in 2nd graph: ";
            }
            std::cin >> str;
        }
        else
        {
            break;
        }
    }
    return str;
}

bool isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

bool stob(std::string str)
{
    int tmp = stoi(str);
    if (tmp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string input;
    int N1 = 0, N2 = 0;

    std::cout << "Vertices in 1st graph: ";
    std::cin >> input;
    N1 = std::stoi(if_correct(input, 0));

    std::cout << "Vertices in 2nd graph: ";
    std::cin >> input;
    N2 = std::stoi(if_correct(input, 1));

    system("cls");
    std::cout << "Please, input " << N1 << " by " << N1 << " adjacency matrix. 1 - if i-th and j-th vertices are adjacent and 0 - otherwise." << std::endl;

    bool adj_matrix_1[N1][N1];
    bool adj_matrix_2[N2][N2];

    int i = 0, j = 0;

    while (i < N1)
    {
        j = 0;
        while (j < N1)
        {
            std::cin >> input;
            if (isNumber(input))
            {
                switch (stoi(input))
                {
                case 0:
                    adj_matrix_1[i][j] = stoi(input);
                    break;

                case 1:
                    adj_matrix_1[i][j] = stoi(input);
                    break;

                default:
                    system("cls");
                    std::cout << "Please, input a binary number. 1 - if i-th and j-th vertices are adjacent and 0 - otherwise." << std::endl;
                    continue;
                    break;
                }
            }
            else
            {
                system("cls");
                std::cout << "Please, input a binary number. 1 - if i-th and j-th vertices are adjacent and 0 - otherwise." << std::endl;
                continue;
            }
            j++;
        }
        i++;
    }
    i = 0;
    std::cout << std::endl
              << "Now please input second " << N2 << " by " << N2 << " matrix." << std::endl
              << std::endl;
    while (i < N2)
    {
        j = 0;
        while (j < N2)
        {
            std::cin >> input;
            if (isNumber(input))
            {
                switch (stoi(input))
                {
                case 0:
                    adj_matrix_2[i][j] = stoi(input);
                    break;

                case 1:
                    adj_matrix_2[i][j] = stoi(input);
                    break;

                default:
                    system("cls");
                    std::cout << "Please, input a binary number. 1 - if i-th and j-th vertices are adjacent and 0 - otherwise." << std::endl;
                    continue;
                    break;
                }
            }
            else
            {
                system("cls");
                std::cout << "Please, input a binary number. 1 - if i-th and j-th vertices are adjacent and 0 - otherwise." << std::endl;
                continue;
            }
            j++;
        }
        i++;
    }

    std::ofstream g1;
    g1.open("g1.dot");
    g1 << "graph{\n";
    for (int i = 0; i < N1; ++i)
    {
        for (int j = 0; j < N1; ++j)
        {
            if (j <= i)
                continue;
            if (adj_matrix_1[i][j])
            {
                g1 << i << " -- " << j << ";\n";
            }
        }
    }
    g1 << "}";
    g1.close();
    system("cd C:\\Users\\79266\\Documents\\GitHub\\FLITA\\secg");
    system("dot.exe -Tpng g1.dot -o C:\\Users\\79266\\Desktop\\Graphs\\G1.png");

    std::ofstream g2;
    g2.open("g2.dot");
    g2 << "graph{\n";
    for (int i = 0; i < N2; ++i)
    {
        for (int j = 0; j < N2; ++j)
        {
            if (j <= i)
                continue;
            if (adj_matrix_2[i][j])
            {
                g2 << i << " -- " << j << ";\n";
            }
        }
    }
    g2 << "}";
    g2.close();
    system("cd C:\\Users\\79266\\Documents\\GitHub\\FLITA\\secg");
    system("dot.exe -Tpng g2.dot -o C:\\Users\\79266\\Desktop\\Graphs\\G2.png");

    std::cout << std::endl
              << "Resulting graph:" << std::endl;

    int Nr = max(N1, N2);
    bool adj_matrix_3[Nr][Nr];
    std::ofstream fout;
    fout.open("graph.dot");
    fout << "graph {\n";

    for (int i = 0; i < Nr; ++i)
    {
        for (int j = 0; j < Nr; ++j)
        {
            if (j <= i)
                continue;
            if ((i >= N1) or (i >= N2) or (j >= N1) or (j >= N2))
            {
                adj_matrix_3[i][j] = 0;
                std::cout << adj_matrix_3[i][j] << " ";
                continue;
            }
            if ((adj_matrix_1[i][j] == 1) and (adj_matrix_2[i][j] == 1))
            {
                adj_matrix_3[i][j] = 1;
                fout << i << " -- " << j << ";\n";
            }
            else
                adj_matrix_3[i][j] = 0;
            std::cout << adj_matrix_3[i][j] << " ";
        }
        std::cout << std::endl;
    }
    fout << "}";
    fout.close();
    system("cd C:\\Users\\79266\\Documents\\GitHub\\FLITA\\secg");
    system("dot.exe -Tpng graph.dot -o C:\\Users\\79266\\Desktop\\Graphs\\Result.png");
    system("pause");
    return 0;
}