using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLCP
{
    abstract class Monhoc
    {
        string mamh, tenmh;

        public string Tenmh
        {
            get { return tenmh; }
            set { tenmh = value; }
        }

        public string Mamh
        {
            get { return mamh; }
            set { mamh = value; }
        }
        int stc;

        public int Stc
        {
            get { return stc; }
            set { stc = value; }
        }
        public abstract double DTB();
        public abstract void xuat();
        public char Diemchu()
        {
            if (DTB() < 4)
                return 'F';
            else if (DTB() <= 4.9)
                return 'D';
            else if (DTB() <= 6.5)
                return 'C';
            else if (DTB() <= 7.9)
                return 'B';
            else
                return 'A';
        }
        public virtual void nhap()
        {
            Console.WriteLine("Nhap ma mon hoc: ");
            Mamh = Console.ReadLine();
            Console.WriteLine("Nhap ten mon hoc: ");
           Tenmh = Console.ReadLine();
            Console.WriteLine("Nhapso tin chi: ");
            Stc = int.Parse(Console.ReadLine());
        }
       
    }
    class LT:Monhoc
    {
        double dtl, dck;

        public double Dck
        {
            get { return dck; }
            set { dck = value; }
        }

        public double Dtl
        {
            get { return dtl; }
            set { dtl = value; }
        }
        public override double DTB()
        {
            return Dtl * 0.3 + Dck * 0.7;
        }
        public override void nhap()
        {
            base.nhap();
            Console.WriteLine("Nhap diem tieu luan: ");
            Dtl = double.Parse(Console.ReadLine());
            Console.WriteLine("Nhap diem cuoi ky: ");
            Dck = double.Parse(Console.ReadLine());
        }
        public override void xuat()
        {
            Console.WriteLine("{0}  {1}  {2}  {3}  {4} {5}  {6}",Mamh,Tenmh,Stc,Dtl,Dck,DTB(),Diemchu());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Monhoc a = new LT();
       //     Monhoc b = new Monhoc();//mon hoc là lớp trừu tượng
            a.nhap();
            a.xuat();
            Console.ReadLine();

        }
    }
}
