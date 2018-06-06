using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EvanDangolCLI;
namespace CppCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            CppBLBridge b = new CppBLBridge();
            b.add(20, 30);
        }
    }
}
