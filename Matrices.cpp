#include <iostream>
#include <vector>
#include <cmath>
bool is_orthogonal(const std::vector<double> & M, const double eps);
int main(void)
{
const int N = 4;
std::vector<double> A = {1, 0, 0, 0,
						            0, 0.8, 0.3, -0.52,
						            0, -0.6, 0.4, -0.69,
						            0, 0, 0.86, 0.5};
std::cout << is_orthogonal(A, 0.001) << std::endl;
std::cout << is_orthogonal(A, 0.012) << std::endl;
std::cout << is_orthogonal(A, 0.1) << std::endl;

return 0;
}

bool is_orthogonal(const std::vector<double> & M, const double eps)
{

	bool x = true;
	std::vector<double> T = {M[0],M[4],M[8],M[12],
							 M[1],M[5],M[9],M[13],
							 M[2],M[6],M[10],M[14],
							 M[3],M[7],M[11],M[15]};


	std::vector<double> R(16);
	double sum;
	  for(int ii=0; ii<16;++ii)
        {
            sum = 0;
            for(int jj=0; jj<=3; ++jj)
                {
                    sum += M[jj+ii/4*4]*T[4*jj+ii%4];
                    R[ii] = sum;
                }
        }

    std::vector<double> I = {1.0,0.0,0.0,0.0,
							 0.0,1.0,0.0,0.0,
							 0.0,0.0,1.0,0.0,
							 0.0,0.0,0.0,1.0};

  for(int i = 0; i < 16; ++i)
    {
	  if(fabs(I[i]-R[i]) > eps)
        {
	  		x = false;

        }
	}
	return x;
}
