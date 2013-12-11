#include <utility>
#include <string>
#include <cassert>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include "streamcorr.h"

#include <sstream>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;

bool author_messages = false;

/* Wrapper for author message printing so that they are only printed in
 * case the author_messages option was given.  If the validator should
 * always print author messages, you can just call
 * report_feedback(authormessage, ...) directly.
 */
void author_message(const char *s) {
    if (author_messages) {
        report_feedback(authormessage, s);
    }
}

/* Raise permutation a to the k-th power */
vi pow(vi &a, int k) {
    vi res(a.size());
    vector<bool> seen(a.size());
    for (size_t i = 0; i < a.size(); i++) if (!seen[i])
    {
        vi cyc;
        size_t u = i;
        do
        {
            seen[u] = true;
            cyc.push_back(u);
            u = a[u];
        } while (u != i);
        int l = k % cyc.size();
        for (size_t j = 0; j < cyc.size(); j++)
            res[cyc[j]] = cyc[(j + l) % cyc.size()];
    }
    return res;
}

/* Check one test case.  Returns false if there were no more test
 * cases to check. */
bool check_case() {
    int n, k;
    judge_in >> n >> k;
    vi target(n);
    for(int i = 0; i < n; ++i) {
        judge_in >> target[i];
        target[i]--;
    }

    string t;
    judge_ans >> t;
    if (t == "Impossible")
    {
        if (!(author_out >> t))
            report_error("Can't read answer");
        if (t != "Impossible")
            report_error("Wrong answer, it is impossible");
    }
    else
    {
        vi b(n);
        if (!(author_out >> t))
            report_error("Can't read answer");
        if (t == "Impossible")
            report_error("Team thinks there is no solution");

        vector<bool> seen(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (!sscanf(t.c_str(), "%d", &b[0]))
                    report_error("Can't read answer");
            }
            else if (!(author_out >> b[i]))
                report_error("Can't read answer");
            b[i]--;
            if (b[i] < 0 || b[i] >= n || seen[b[i]])
                report_error("The answer is not a permutation");
            // if (b[i] == i)
            //     report_error("Self loops are not allowed.");
            seen[b[i]] = true;
        }

        b = pow(b, k);
        if (b != target)
            report_error("Permutation's k-th power is not the same as the target permutation.");
    }

    return true;
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    /* Check if the author_messages option is given. */
    for (int i = 4; i < argc; ++i)
        if (!strcmp(argv[i], "author_messages"))
            author_messages = true;

    check_case();

    /* Check for trailing output in author file. */
    string trash;
    if (author_out >> trash) {
        author_message("Trailing output after last test case");
        report_error("Trailing output");
    }

    /* Yay! */
    author_message("Thank you for your great code. It was fantastic.");
    accept();
}
