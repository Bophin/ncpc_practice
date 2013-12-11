//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

class Problem
{
    static int max_cuts = 500;

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

        string[] ss = reader.ReadLine().Split();
        double t = double.Parse(ss[0]);

        List<int> w = reader.ReadLine().Split().Select(x => int.Parse(x)).OrderBy(x => x).ToList();
        int res = max_cuts + 47, left = int.Parse(ss[1]);
        foreach (int q in w)
        {
            for (int i = 1; i <= max_cuts; i++)
            {
                double big = q / (double)i;
                var cut = w.Select(x => new {Count = Math.Ceiling(x / big), Length = x});
                if (cut.Min(y => y.Length / y.Count) >= t * big)
                {
                    double cnt = cut.Sum(y => y.Count - 1);
                    if (cnt < res) res = (int)cnt;
                }
            }
            left--;
        }
        Console.WriteLine(res);
    }
}
