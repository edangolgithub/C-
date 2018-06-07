using EvanDangolCLI;
using System;
using System.Runtime.InteropServices;

namespace CppCSharp
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //CppBLBridge b = new CppBLBridge();
            //b.add(20, 30);
            //b.add(2, 3);
            FileHandleCli f = new FileHandleCli();
            f.WriteFile();
            f.ReadFile();
          Console.WriteLine( f.returnstring());
            //f.add();
            //Console.WriteLine(f.GetCin());
           
        }
    }
}