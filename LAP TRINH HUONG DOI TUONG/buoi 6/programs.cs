using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
 
        static void Main(string[] args)
        {
           // phansoM a=new phansoM(1,2);
           // phansoM b = new phansoM(2,4);
           // //phansoM c = a + b;//operator
           //// c.xuat();
           // a++;
           // a.xuat();
            //List<phansoM> list = new List<phansoM>(5);
            //for (int i = 0; i < 3; i++)
            //{
            //    Console.WriteLine("Nhap phan tu thu {0}:", i);
            //    list.Add(a.nhap());
            //}
            //foreach (phansoM i in list)
            //    i.xuat();
            //Console.WriteLine();
            //list.Insert(3, new phansoM(8, 3));
            //foreach (phansoM i in list)
            //    i.xuat();
            //list.Clear();
            //foreach (phansoM i in list)
            //    i.xuat();
            string a = "10";
            int kq;
            var i = int.TryParse(a, out kq);
            Console.WriteLine(kq+1);
            int b = Convert.ToInt32(a);
            double c = Convert.ToDouble(a);
            Console.WriteLine("{0:00}",c);
            //Console.WriteLine(b+1);

                Console.ReadLine();
        }
        
   
    }
}
