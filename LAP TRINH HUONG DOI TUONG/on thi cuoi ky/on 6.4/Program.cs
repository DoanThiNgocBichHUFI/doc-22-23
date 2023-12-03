using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLNV
{

    class hanghoa
    {
        public bool isnumber(string a)
        {
            foreach (Char c in a)
            {
                if (!Char.IsDigit(c))
                    return false;
            }
            return true;
        }
        string mahh, tenhh;

        public string Tenhh
        {
            get { return tenhh; }
            set { tenhh = value; }
        }

        public string Mahh
        {
            get { return mahh; }
            set 
            {
                string a = value.Substring(3);
                if (value.Length == 5 && value.StartsWith("HH") && isnumber(a))
                    mahh = value;
                else
                    mahh = "HH001";
            }
        }
        public hanghoa()
        {
            mahh = "";
            tenhh = "";
        }
        public hanghoa(string mahh, string tenhh)
        {
            this.mahh = mahh;
            this.tenhh = tenhh;
        }
         public hanghoa(string mahh)
        {
            this.mahh = mahh;
            
        }
         public void nhap() //public vitual void nhap()
        {
            Console.WriteLine("Nhap ma hang:");
            string a = Console.ReadLine();
            Mahh = a.ToUpper();
            Console.WriteLine("Nhap ten hang:");
            Tenhh = Console.ReadLine();
        }
        public virtual void xuat()
        {
            Console.WriteLine("{0,-12}{1,-25}",mahh,tenhh);
        }
    }
    class NGK:hanghoa
    {
        string dvt;
        static double tlck=0.1;
        public string Dvt
        {
            get { return dvt; }
            set 
            {
                if (!(value == "Thung" || value.Equals("Chai") || value.Equals("Lon") || value.Equals("Ket")))
                    dvt = "ket";
                else
                    dvt = value; 
            }
        }
        int sl;

        public int Sl
        {
            get { return sl; }
            set { sl = value; }
        }
        double dongia;

        public double Dongia
        {
            get { return dongia; }
            set { dongia = value; }
        }
       public NGK()
        {

        }
        public NGK(string mahh,string tenhh,string dvt,int sl,double dg)
        :base(mahh,tenhh)
       {
           this.dvt = dvt;
           this.sl = sl;
           this.dongia=dg;

       }
        public void nhap()//public override void nhap()
        {
            base.nhap();
            Console.WriteLine("Nhap dvt:");
            string a = Console.ReadLine();
            Dvt = a.ToLower();
            Console.WriteLine("Nhap so luong:");
            sl =int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap dongia:");
            dongia = double.Parse(Console.ReadLine());
        }
        public override void xuat()
        {
            base.xuat();
            Console.WriteLine("{0,-6}{1,-5}{2,-10}{3,-15}",dvt,sl,dongia,Tongtien());
        }
        public double thanhtien()
        {
            double tien=0;
            if (dvt.Equals("thung") || dvt.Equals("ket"))
                tien = sl * dongia;
            else if (dvt.Equals("chai"))
                tien = sl * dongia / 20;
            else
                tien = sl * dongia / 24;
            return tien;
        }
        public double Tongtien()
        {
            return thanhtien() * (1-tlck);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            NGK a = new NGK();
           a.nhap();
           a.xuat();
            Console.ReadLine();
        }
    }
}
