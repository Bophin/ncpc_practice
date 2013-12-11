//Solution by lukasP (Lukáš Poláček)
//Wrong answer because it takes gcd(k, len) instead of a different function
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    static int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int inverse(int x, int mod)
    {
        if (mod == 1) return 1;
        if (gcd(x, mod) > 1) return -1;
        return Enumerable.Range(1, mod - 1).Where(y => y * x % mod == 1).First();
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);

        string[] ss = reader.ReadLine().Split();
        int n = int.Parse(ss[0]), k = int.Parse(ss[1]);
        List<int> a = reader.ReadLine().Split().Select(x => int.Parse(x) - 1).ToList();

        var cycles = Enumerable.Range(0, n).Select(x => new List<List<int>>()).ToArray();
        bool[] seen = new bool[n];
        foreach (int i in Enumerable.Range(0, n)) if (!seen[i])
        {
            List<int> cyc = new List<int> ();
            int u = i;
            do {
                cyc.Add(u);
                seen[u] = true;
                u = a[u];
            } while (u != i);
            cycles[cyc.Count].Add(cyc);
        }

        List<int> res = Enumerable.Repeat(-1, n).ToList();
        foreach (var group in cycles) if (group.Count > 0)
        {
            int len = group.First().Count;
            int need = gcd(len, k);

            if (group.Count % need == 0)
                for (int i = 0; i < group.Count; i += need)
                {
                    List<int> cyc = new List<int> ();
                    foreach (int l in Enumerable.Range(0, len))
                        foreach (int j in Enumerable.Range(0, need))
                            cyc.Add(group[i + j][l]);

                    int move = inverse(k / need % len, len);
                    if (move != -1) foreach (int j in Enumerable.Range(0, cyc.Count))
                        res[cyc[j]] = cyc[(j + move) % cyc.Count];
                }
        }

        if (res.Any(x => x == -1))
            Console.WriteLine("Impossible");
        else
            Console.WriteLine(string.Join(" ", res.Select(x => x + 1)));
    }
}
