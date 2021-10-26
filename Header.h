#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdio>
using namespace std;
class image
{
    int M, N;
    int** data;
public:
    image() { //конструктор по умолчанию
        this->M = 0;
        this->N = 0;
        data = nullptr;
    }
    image(int M, int N)//конструктор с параметрами
    {
        if ((M < 0) || (N < 0)) throw"Invalid Index";
        this->M = M;
        this->N = N;
        data = new int* [M];
        for (int i = 0; i < M; i++)
            data[i] = new int[N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                data[i][j] = 0;
    };
    image(const image& _A)//конструктор копирования
    {
        M = _A.M;
        N = _A.N;
        data = new int* [M];
        for (int i = 0; i < M; i++)
            data[i] = new int[N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                data[i][j] = _A.data[i][j];
    }
    int GetMij(int i, int j)
    {
        if ((M >= 0) && (N >= 0))
            return data[i][j];
        else
            return 0;
    }
    void SetMij(int i, int j, int value)
    {
        if ((value == 1) || (value == 0))
        {
            if ((i < 0) || (i >= M))
                return;
            if ((j < 0) || (j >= N))
                return;
            data[i][j] = value;
        }
        else return;
    }
    ~image()//деструктор
    {
        if (N > 0)
        {
            for (int i = 0; i < M; i++)
                delete[] data[i];
        }
        if (M > 0)
            delete[] data;
    }
    image operator!() { // обратное изображение
        image result(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
            {
                result.data[i][j] = data[i][N - 1 - j];
            }
        }
        return result;
    }
    bool can_multiply(const image& other) {// возможность объединения/ перемножения двух изображений по размеру
        return ((M == other.M) && (N == other.N));
    }
    image operator+ (image m2)//сложение изображений
    {
        if (!(can_multiply(m2))) { // если не подходят по размеру
            cout << "The images are of different sizes, they can not be combined";
            image empty;
            return empty;// пустое изображение
        }
        else
        {
            image m3(M, N);
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    m3.data[i][j] = data[i][j] + m2.data[i][j];
                }
            }
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (m3.data[i][j] == 2)
                        m3.data[i][j] = 1;
                }
            }
            return m3;
        }
    }
    image operator* (image m2)
    {
        if (!(can_multiply(m2))) {
            image empty;
            return empty;
        }
        else {
            image m3(M, N);
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    m3.data[i][j] = data[i][j] + m2.data[i][j];
                }
            }
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (m3.data[i][j] != 2)
                        m3.data[i][j] = 0;
                    else
                        m3.data[i][j] = 1;
                }
            }
            return m3;
        }

    }
    double coefficient()
    {
        double a1 = 0;
        double all = M * N;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (data[i][j] == 1)
                    a1++;
            }
        }
        if (a1 == 0)
            return 0;
        else
        {
            return a1 / all;
        }
    }
   image operator=(const image& other) { // оператор присваивания
        image result(other);
        return result;
    }
    void print()
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (data[i][j] == 0)
                    cout << "." << " ";
                else
                    cout << "1" << " ";
            }cout << endl;
        }

    }
    int rows() const { // строки
        return M;
    }
    int cols() const { // столбцы
        return N;
    }
    bool draw() { // выполнение рисунка вручную, с клавиатуры
        if (data == nullptr) {
            cout << "Memory is not available";
            return false;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << "[" << i << "]" << "[" << j << "] = ";
                cin >> data[i][j];
            }
        }
        return true;
    }
};
image random(int rows, int cols) { // составление случайного изображения
    image image(rows, cols);
    for (int i = 0; i < image.rows(); ++i) {
        for (int j = 0; j < image.cols(); ++j) {
            image.SetMij(i, j, rand() % 2);
        }
    }
    return image;
}
