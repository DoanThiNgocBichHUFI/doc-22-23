using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLCP
{

    interface IHotroKP
    {
        double hotrokinhphi();
    }
    abstract class Caphe
    {
        string maloai, tencaphe;

        public string Tencaphe
        {
            get { return tencaphe; }
            set { tencaphe = value; }
        }

        public string Maloai
        {
            get { return maloai; }
            set { maloai = value; }
        }
        double sl, dg;

        public double Dg
        {
            get { return dg; }
            set { dg = value; }
        }

        public double Sl
        {
            get { return sl; }
            set { sl = value; }
        }
        public abstract double tinhtien();
        public virtual void nhap()
        {
            Console.WriteLine("Nhap ma loai:");
            Maloai = Console.ReadLine();
            Console.WriteLine("Nhap ten:");
            Tencaphe = Console.ReadLine();
            Console.WriteLine("Nhap so luong:");
            Sl = double.Parse(Console.ReadLine());
            Console.WriteLine("Nhap don gia:");
            Dg = double.Parse(Console.ReadLine());
        }
        public abstract void xuat();
    }
    class Caphehat : Caphe, IHotroKP
    {
        public override double tinhtien()
        {
            return Sl * Dg;
        }
        public double hotrokinhphi()
        {
            return Sl * 10;
        }
        public override void nhap()
        {
            base.nhap();
        }
        public override void xuat()
        {
            Console.WriteLine("{0}  {1}  {2}  {3}  {4}  {5}", Maloai, Tencaphe, Sl, Dg, tinhtien(), hotrokinhphi());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Caphehat a = new Caphehat();
            a.nhap();
            a.xuat();
            Console.ReadLine();

        }
    }
}