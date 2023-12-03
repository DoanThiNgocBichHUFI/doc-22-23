using System;
namespace nhanvien{
    internal class Program
    {
        private static void Main(string[] args)
        {
            phongBan BaoChi = new phongBan();
            BaoChi.nhapTuFile("data.xml");
            BaoChi.xuatdsnv();
            Console.ReadLine();
        }
    }
}
    