#include "my_heap.h"
#include "build_free.h"
#include "update.h"
#include "checker.h"
#include "construct_solution.h"
#include "fastds-pure.h"
#include "parse_cmd.h"
#include <sstream>

int main(int argc, char *argv[])
{
    Parameters* para = new Parameters(argc, argv);
    string instanceName = para->getParameterValue("--i");
    seed = atoi(para->getParameterValue("--s").c_str());
    cutoff_time = atoi(para->getParameterValue("--t").c_str());
    floor0 = atoi(para->getParameterValue("--f0").c_str());
    floor1 = atoi(para->getParameterValue("--f1").c_str());
    insTimes = atoi(para->getParameterValue("--it").c_str());
    ceilingTimes = atoi(para->getParameterValue("--ct").c_str());
    delete para;

    BuildInstance(instanceName);
    //等bigcnt改好这里去掉
    if (!CheckGraphIsConnected())
    {
        cout << "Running is interrupted: Graph is not connected" << endl;
        FreeMemory();
        return 0;
    }
    srand(seed);
    start = chrono::steady_clock::now();
    constructInitialSolution();
    // localSearchFramework1();
    localSearchFramework2();

    if (!CheckSolutionIsConnected())
    {
        cout << "Solution is not Connected." << endl;
    }

    if (running_is_interrupted)
    {
        cout << "Running is interrupted: Time is not enough." << endl;
    }
    cout << "best_c_size:" << best_c_size << endl << "best_comp_time:" << best_comp_time << endl;
    cout << "best_weight:" << bestWeight << endl;
    cout << "step:" << step << endl;
    //    string outfile = argv[1];
    //    string seednum = argv[3];
    //outfile="/home/libh/CDStuning11_6/20w_1b_2_10/sample/"+outfile;
    //freopen(outfile.data(),"a+",stdout);
    //fclose(stdout);
    FreeMemory();
    return 0;
}
