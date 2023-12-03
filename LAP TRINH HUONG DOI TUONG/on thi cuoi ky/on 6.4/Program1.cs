using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLNV
{

    class nhanvien
    {
        public static int lcb = 1210;
        string manv, hoten, phongban;

        public string Phongban
        {
            get { return phongban; }
            set { phongban = value; }
        }

        public string Hoten
        {
            get { return hoten; }
            set { hoten = value; }
        }

        public string Manv
        {
            get { return manv; }
            set { manv = value; }
        }
        int snlv;

        public int Snlv
        {
            get { return snlv; }
            set { snlv = value; }
        }
        double hsl;

        public double Hsl
        {
            get { return hsl; }
            set { hsl = value; }
        }
        public string xeploai()
        {
            if (Snlv > 25)
                return "A";
            else if (Snlv > 22)
                return "B";
            else
                return "C";
        }
        public double HSTD()
        {
            if (xeploai() == "A")
                return 1.0;
            else if (xeploai() == "B")
                return 0.75;
            else
                return 0.5;
        }
        public double luong()
        {

            return 1210 * hsl * HSTD();

        }
        public void nhap()
        {
            Console.WriteLine("Nhap ma nhan vien:");
            manv = Console.ReadLine();
            Console.WriteLine("Nhap ten nhan vien:");
            hoten = Console.ReadLine();
            Console.WriteLine("Nhap he so luong:");
            hsl = double.Parse(Console.ReadLine());
            Console.WriteLine("Nhap phong ban:");
            phongban = Console.ReadLine();
            Console.WriteLine("Nhap so ngay lam:");
            snlv = int.Parse(Console.ReadLine());
            
        }
        public void xuat()
        {
            Console.WriteLine("{0,-12}{1,-25}{2,-10}{3,-20}{4,-10}{5,-15}"
                ,manv,hoten,hsl,phongban,snlv,luong());
        }
    }
    class canbo:nhanvien
    {
        string chucvu;

        public string Chucvu
        {
            get { return chucvu; }
            set { chucvu = value; }
        }
        double hscv;

        public double Hscv
        {
            get { return hscv; }
            set { hscv = value; }
        }
        public void nhap()
        {
            base.nhap();
            Console.WriteLine("NHap chuc vu:");
            chucvu = Console.ReadLine();
            Console.WriteLine("Nhap he so chuc vu:");
            hscv = double.Parse(Console.ReadLine());
        }
        public new double luong()
        {
            return base.luong() + hscv * 1100;
        }
        public new void xuat()
        {
            Console.WriteLine("{0,-12}{1,-25}{2,-10}{3,-20}{4,-10}{5,-15}{6,-10}{7,-10}"
                , Manv,Hoten, Hsl, Phongban, Snlv, luong(),chucvu,hscv);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            nhanvien a = new nhanvien();
            //a.nhap();
            //a.xuat();
            canbo b = new canbo();
            b.nhap();
            a.xuat();
            b.xuat();
            Console.ReadLine();
        }
    }
}
