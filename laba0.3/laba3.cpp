#include <iostream>
#include <cmath> 

using namespace std;
int main()
{
    char input;
    double x=0.2;
    int N=12;
    double resultMAIN;
    double resultSIGMA=0.0;
    cout << "Введите символ (f/F, w/W, d/D или 1, 2, 3): ";
    cin >> input;
    switch(input)
    {
        case 'f': 
        case 'F':
        case '1':
        {
         for(int i=4;i<=N; i++)
            {
                 resultSIGMA +=  sin (i) + pow (sin (x), 2);
                 resultMAIN = pow (sin (x), 2) + pow (resultSIGMA, 2);
            }
            cout<<"Результат:"<<resultMAIN<<endl;
            break;
        }
        case 'w': 
        case 'W':
        case '2':
        {
            int i=4;
            while (i<=N)
            {
                 resultSIGMA +=  sin (i) + pow (sin (x), 2);
                 resultMAIN = pow (sin (x), 2) + pow (resultSIGMA, 2);
                i++;
            }
            cout<<"Резульатат:"<<resultSIGMA<<endl;
            break;
        }
        case 'd': 
        case 'D':
        case '3':
        {
            int i=4;
            do
            {
                resultSIGMA +=  sin (i) + pow (sin (x), 2);
                resultMAIN = pow (sin (x), 2) + pow (resultSIGMA, 2);
                i++;
            } 
            while (i<=N);
            cout<<"Резульатат:"<<resultMAIN<<endl;
            break;
        }
        default:
        cout<<"Введен неверный символ"<<endl;
        break;
    }
    return 0;
}