using System;

namespace buoi9{
    internal class Program
    {
        private static void Main(string[] args)
        {
            // NGK a = new NGK();
            // a.nhap();
            // a.xuat();
            // Console.ReadLine();
        
            // Devired_class dc_o = new Devired_class();
            // Console.ReadLine();

            Devired_class dc_o = new Devired_class(8,6);
            dc_o.Xuat();
            Console.ReadLine();
        }
    }

}
