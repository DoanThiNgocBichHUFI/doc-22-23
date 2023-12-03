using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLSV
{
    //class sinhvien
    //{
    //    int id;

    //    public int Id
    //    {
    //        get { return id; }
    //        set { id = value; }
    //    }
    //    string name;

    //    public string Name
    //    {
    //        get { return name; }
    //        set { name = value; }
    //    }
    //    double toan, ly, hoa, tb;

    //    public double Tb
    //    {
    //        get { return tb; }
    //        set { tb = value; }
    //    }

    //    public double Hoa
    //    {
    //        get { return hoa; }
    //        set { hoa = value; }
    //    }

    //    public double Ly
    //    {
    //        get { return ly; }
    //        set { ly = value; }
    //    }

    //    public double Toan
    //    {
    //        get { return toan; }
    //        set { toan = value; }
    //    }
    //    string xl;

    //    public string Xl
    //    {
    //        get { return xl; }
    //        set { xl = value; }
    //    }
        
    //}
    class sinhvien
    {
        public int Id
        {
            get;
            set;
        }
        //    int id;

        //    public int Id
        //    {
        //        get { return id; }get=>id;
        //        set { id = value; }set=>id;
        //    }
        public string Name
        {
            get;
            set;
        }
        public double Toan
        {
            get;
            set;
        }
       

        public double Hoa
        {
            get;
            set;
        }

        public double Ly
        {
            get;
            set;
        }
        public double Tb
        {
            get;
            set;
        }

        public string Xl
        {
            get;
            set;
        }
        public double trungbinh()
        {
            return (Toan + Ly + Hoa) / 3;
        }
        public string Xeploai()
        {
            double tb = trungbinh();
            if (tb >= 8)
                return "Giỏi";
            else if (tb >= 6.5)
                return "Khá";
            else if (tb >= 5)
                return "Trung bình";
            else
                return "Yếu";
        }
       public sinhvien NhapSV()
        {
            //sv.Id = autoID();

            sinhvien sv = new sinhvien();
            Console.WriteLine("Nhap maSV: ");
            sv.Id = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap ho ten: ");
            sv.Name = Console.ReadLine().ToUpper();
            Console.WriteLine("Nhap Toan: ");
            sv.Toan = double.Parse(Console.ReadLine());
            Console.WriteLine("Nhap Ly: ");
            sv.Ly = double.Parse(Console.ReadLine());
            Console.WriteLine("Nhap Hoa: ");
            sv.Hoa = Convert.ToDouble(Console.ReadLine());
            sv.Tb = sv.trungbinh();
            sv.Xl = sv.Xeploai();
            return sv;
        }
       public void Hienthi()
       {
           Console.WriteLine("{0,-10} {1,-30} {2:0.00}  {3:0.00}  {4:0.00}  {5:0.00} {6,-10}", Id,Name, Toan, Ly, Hoa, Tb, Xl);
       }
    }
}
