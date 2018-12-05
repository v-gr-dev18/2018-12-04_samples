#include <vector>
#include <map>
#include <random>
#include <ctime>
using namespace std;

using namespace std;
void generate_skipped_vector(vector<unsigned> &v, size_t v_size, size_t sv_size)
{
    map<unsigned, bool> skipped;
    vector<bool> exists(v_size + sv_size, false);
    default_random_engine generator;
    uniform_int_distribution<unsigned> distribution(0, v_size - 1 + sv_size);
    generator.seed(time(0));
    generator();
    for (int i = 0; i < sv_size; ++i)
        skipped[distribution(generator)] = true;
    for (unsigned i = 0; i < v_size; ++i)
    {
        unsigned next;
        while (true)
        {
            next = distribution(generator);
            if (!skipped[next] && !exists[next])
            {
                exists[next] = true;
                break;
            }
        }
        v.push_back(next);
    }
}
