#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>

int main()
{
    std::string namefile = "data.csv";

    std::ifstream fstr;
    fstr.open(namefile);

    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    double val = 0;
    double valnew = 0;
    double sumValues = 0;
    int i = 0;
    double mean = 0;

    std::ofstream filename2("result.csv");
    filename2 << "# N MEAN" << std::endl;

    std::ofstream filename3("interval.csv");
    filename3 << "Numbers in interval (-1,2)" << std::endl;

    while(fstr >> val)
    {

        valnew = -1 + 0.75 * (val - 1);
        filename3 << std::scientific << valnew << std::endl;


        i++;
        sumValues += val;
        mean = sumValues / i;
        filename2 << i << " " << std::scientific << mean << std::endl;  //serve solo cambiare il formato della media da inserire nel file

    }
    filename3.close();
    filename2.close();
    fstr.close();

    return 0;
}
