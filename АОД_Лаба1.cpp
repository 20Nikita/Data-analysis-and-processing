﻿#include <iostream>
using namespace std;

const int n = 7;		//колличество наблюдений на каждом уровне
const int m1 = 2;		//колличество уровней на 1 факторе
const int m2 = 3;		//колличество уровней на 2 факторе

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");				//экран белый, буквы черные
    double y[m1][m2][n] = { 4.190, 5.990, 6.490, 7.490, 9.490, 11.490, 32.000,
                            4.630, 7.290, 8.490, 9.990, 11.490, 16.490, 27.000,
                            7.690, 11.990, 16.990, 20.990, 22.790, 23.990, 32.990,

                            4.990, 5.190, 7.990, 9.990, 10.999, 11.699, 13.490,
                            5.890, 6.690, 7.690, 8.990, 9.790, 15.999, 19.099,
                            7.190, 10.999, 14.499, 16.999, 19.999, 21.799, 34.499 };
   /* double y[m1][m2][n] = { 4190, 5990, 6490, 7490, 9490, 11490, 32000,
                            4630, 7290, 8490, 9990, 11490, 16490, 27000,
                            7690, 11990, 16990, 20990, 22790, 23990, 32990,

                            4990, 5190, 7990, 9990, 10999, 11699, 13490,
                            5890, 6690, 7690, 8990, 9790, 15999, 19099,
                            7190, 10999, 14499, 16999, 19999, 21799, 34499 };*/

    double I_мат_ожид[m1] = { 0 };
    double J_мат_ожид[m2] = { 0 };
    double IJ_мат_ожид[m1][m2] = { 0 };
    double мат_ожид = 0;

    double дисперсия = 0;
    double I_дисперсия = 0;
    double J_дисперсия = 0;
    double IJ_дисперсия = 0;
    double Ост_дисперсия = 0;

    cout << "\tТАБУЛИРОВАНИЕ ДАННЫХ\n";
    for (int i = 0; i < m1; i++)
    {
        if (i==0) cout << "Микроволновые печи с немеханическим типом управления\n";
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                /*cout << y[i][j][k] << " ";
                if (y[i][j][k] < 10000) cout << " ";*/
                printf("%.3f ", y[i][j][k]);
                if (y[i][j][k] < 10) cout << " ";
            }
            cout << "\n";
        }
        if (i == 0) cout << "\nМикроволновые печи с механическим типом управления\n";
    }
    cout << endl;
    cout << "\tОЦЕНКИ МАТЕМАТИЧЕСКИХ ОЖИДАНИЙ\n";
    cout << endl;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < n; k++)
                I_мат_ожид[i] += y[i][j][k];
        I_мат_ожид[i] = I_мат_ожид[i] / m2 / n;
        cout << "Оценка МО выходной переменной при группировке по 1 фактороу " << i+1 << " уровня =  " << I_мат_ожид[i] << "\n";
    }
    
    cout << endl;
    for (int j = 0; j < m2; j++)
    {
        for (int i = 0; i < m1; i++)
            for (int k = 0; k < n; k++)
                J_мат_ожид[j] += y[i][j][k];
        J_мат_ожид[j] = J_мат_ожид[j] / m1 / n;
        cout << "Оценка МО выходной переменной при группировке по 1 фактороу " << j+1 << " уровня =  " << J_мат_ожид[j] << "\n";
    }

    cout << endl;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < n; k++)
                IJ_мат_ожид[i][j] += y[i][j][k];
            IJ_мат_ожид[i][j] = IJ_мат_ожид[i][j] / n;
            cout << "Оценки внутригрупповых МО выходной переменной при группировке по уровням факторов " << i + 1 << "-" << j + 1 << " = " << IJ_мат_ожид[i][j] << "\n";
        }
    }

    cout << endl;
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < n; k++)
                мат_ожид += y[i][j][k];
    мат_ожид = мат_ожид / m1 / m2 / n;
    cout << "Общее математическое ожидание =  " << мат_ожид << "\n";

    cout << endl;
    cout << "\tПРОВЕРКА ОСНОВНОГО ТОДЖЕСТВА ВАРИАЦИИ ДИСПЕРСИОННОГО АНАЛИЗА:\n";
    cout << endl;

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < n; k++)
                дисперсия = дисперсия + (y[i][j][k] - мат_ожид) * (y[i][j][k] - мат_ожид);
    cout << "Общая вариация =  " << дисперсия << "\n";

    for (int i = 0; i < m1; i++)
        I_дисперсия = I_дисперсия + (I_мат_ожид[i] - мат_ожид) * (I_мат_ожид[i] - мат_ожид);
    I_дисперсия = I_дисперсия * m2 * n;
    cout << "Факторная вариация 1 =  " << I_дисперсия << "\n";

    for (int j = 0; j < m2; j++)
        J_дисперсия = J_дисперсия + (J_мат_ожид[j] - мат_ожид) * (J_мат_ожид[j] - мат_ожид);
    J_дисперсия = J_дисперсия * m1 * n;
    cout << "Факторная вариация 2 =  " << J_дисперсия << "\n";

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < m2; j++)
            IJ_дисперсия = IJ_дисперсия + (IJ_мат_ожид[i][j] - I_мат_ожид[i] - J_мат_ожид[j] + мат_ожид)
            * (IJ_мат_ожид[i][j] - I_мат_ожид[i] - J_мат_ожид[j] + мат_ожид);
    IJ_дисперсия = IJ_дисперсия * n;
    cout << "Факторная вариация взаимодействия =  " << IJ_дисперсия << "\n";

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < n; k++)
                Ост_дисперсия = Ост_дисперсия + (y[i][j][k] - IJ_мат_ожид[i][j]) * (y[i][j][k] - IJ_мат_ожид[i][j]);
    cout << "Остаточная вариация взаимодействия =  " << Ост_дисперсия << "\n";
    cout << дисперсия << " = " << Ост_дисперсия + IJ_дисперсия + J_дисперсия + I_дисперсия;

    cout << endl << endl;
    cout << "\tОЦЕНКИ ДИСПЕРСИЙ:\n";
    cout << endl;

    дисперсия = дисперсия / (m1 * m2 * n - 1);
    I_дисперсия = I_дисперсия / (m1 - 1);
    J_дисперсия = J_дисперсия / (m2 - 1);
    IJ_дисперсия = IJ_дисперсия / ((m1 - 1) * (m2 - 1));
    Ост_дисперсия = Ост_дисперсия / (m1 * m2 * n - m1 * m2);

    cout << "Общая дисперсия =  " << дисперсия << "\n";
    cout << "Факторная дисперсия 1 =  " << I_дисперсия << "\n";
    cout << "Факторная дисперсия 2 =  " << J_дисперсия << "\n";
    cout << "Факторная дисперсия взаимодействия =  " << IJ_дисперсия << "\n";
    cout << "Остаточная дисперсия взаимодействия =  " << Ост_дисперсия << "\n";
    cout << endl << endl;
    cout << "\tГИПОТЕЗЫ:\n";
    cout << endl;
    cout << "Uвз =  " << IJ_дисперсия / Ост_дисперсия << "\tчисло степеней свободы числителя = " << (m1 - 1) * (m2 - 1) 
        << " число степеней свободы знаменателя = " << m1*m2*n - m1 * m2 << "\n";
    cout << "U1 =  " << I_дисперсия / Ост_дисперсия << "\t\tчисло степеней свободы числителя = " << m1 - 1
        << " число степеней свободы знаменателя = " << m1 * m2 * n - m1 * m2 << "\n";
    cout << "U2 =  " << J_дисперсия / Ост_дисперсия << "\t\tчисло степеней свободы числителя = " << m2 - 1
        << " число степеней свободы знаменателя = " << m1 * m2 * n - m1 * m2 << "\n";

}
