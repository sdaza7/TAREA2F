#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;
using namespace std;

int main()
{
    const double eps = 0.001;
    Matrix <double, 4, 4> f1;
    f1 << 1.0, 0.0, 0.0, 0.0,
        0.0, 0.8, 0.3, -0.52,
        0.0, -0.6, 0.4, -0.69,
        0.0, 0.0, 0.86, 0.5;

    Matrix <double, 4, 4> f2;
    f2 = f1.transpose();

    Matrix <double, 4, 4> f3;
    f3 = f1*f2;

    Matrix <double, 4, 4> f4;
    f4 << 1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0;

    bool x = true;
    for (int ii = 0; ii <= 3; ii++)
    {
        for (int jj = 0; jj <= 3; jj++)
        {
            if ((fabs(f4(ii,jj)-f3(ii,jj))) > eps)
            {
                x = false;
            }

        }
    }

    cout << f3(1,1) << "\n";
    cout << f3 << "\n";
    cout << x << "\n";

    return 0;
}
