#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdio>
#include "Header.h"
using namespace std;
int main_menu(int checker)
{
    if (checker != 0)
    {
        printf("\n");
        printf(" Fold images - 4\n Multiply images - 5\n Invert images - 6\n Exit - 7\n");
        while (true)
        {
            int key;
            cin >> key;
            if ((key == 4) || (key == 5) || (key == 6)  || (key == 7)) return key;
        }
    }
    printf("\n");
    cout<<" Perform operations with random images - 1 \n Create image yourself- 2\n Exit - 3\n"<<endl;
    while (true)
    {
        int key;
        cin >> key;
        if ((key == 1) || (key == 2) || (key == 3)) return key;
    }
}
int main() {
    int M; int a; int b;
    int N;
    image IM1;
    image IM2;
    int checker = 0;
    int repeat = 1;
    while (repeat != 0)
    {
        int m = main_menu(checker);
        try
        {
            if (m == 1)
        {
            cout << "\n A few examples with randomly created images:\n";
            srand(time(0));
            
                image image1 = random(10, 10);
                image image2 = random(10, 10);
                image image3 = random(10, 10);
                cout << "1.\n";
                image1.print();

                cout << "Reverse image:\n";
                (!image1).print();

                cout << "Summing up images:\n";
                cout << "1.\n";
                image1.print();
                cout << "2.\n";
                image2.print();

                cout << "\n1+2:\n" << endl;
                (image1 + image2).print();

                cout << "The product of images:\n";
                cout << "2.\n";
                image2.print();
                cout << "3.\n";
                image3.print();

                cout << "2*3:\n";
                (image3 * image2).print();

                cout << "Fill factor in percent :\n";
                cout << "3.\n";
                image3.print();
                cout << "\n" << image3.coefficient() << "%";
                checker = 0;
            }
            if (m == 2)
            {
                int M, N;
                cout << "\nFirst image\n";
                cout << "\nHow many lines ?\nM=";
                cin >> M;
                cout << "How many columns ?\nN=";
                cin >> N;
                image IM1(M, N);
                IM1.draw();
                IM1.print();
                cout << "Fullness of image:\n";
                cout << IM1.coefficient();
                int a; int b;
                cout << "\nSecond image\n";
                cout << "\nHow many lines ?\nM=";
                cin >> a;
                cout << "How many columns ?\nN=";
                cin >> b;
                image IM2(a, b);
                IM2.draw();
                IM2.print();
                cout << "Fullness of image:\n";
                cout << IM2.coefficient();
                checker++;
                while (checker != 0)
                {


                    m = main_menu(checker);
                    if (m == 4)
                    {
                        cout << "Summing up images:\n";
                        cout << "1.\n";
                        IM1.print();
                        cout << "2.\n";
                        IM2.print();
                        cout << "\n1+2:\n" << endl;
                        (IM1 + IM2).print();

                    }
                    if (m == 5)
                    {
                        cout << "The product of images:\n";
                        IM1.print();
                        cout << "\n";
                        IM2.print();
                        cout << "1*2:\n";
                        (IM1 * IM2).print();

                    }
                    if (m == 6)
                    {
                        IM1.print();
                        cout << "Reverse first image:\n";
                        (!IM1).print();
                        IM2.print();
                        cout << "Reverse first image:\n";
                        (!IM2).print();

                    }
                    if (m == 7)checker = 0;
                }

            }
            if (m == 3) repeat = 0;
            }
            catch (const char* err)
            {
                cout << err;
            }       
                       
    }
    return 0;
}