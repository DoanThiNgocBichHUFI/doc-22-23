using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace demau
{
    //lớp trừu tượng sách
    abstract class sach //lớp trừu tượng
    {
        string masach, tensach, tentg;

        
        double giaban;
        int sotrang;
        public static double tilethue=0.03;
        public string Tentg
        {
            get { return tentg; }
            set { tentg = value; }
        }

        public string Masach
        {
            get { return masach; }
            set { masach = value; }
        }       

        public int Sotrang
        {
            get { return sotrang; }
            set { sotrang = value; }
        }

        public string Tensach
        {
            get { return tensach; }
            set { tensach = value; }
        }
        public double Giaban
        {
            get{return giaban;}
            set
            {
                if (value >= 10000)
                    giaban = value;
                else
                {
                    Console.WriteLine("Sai du liệu.");
                    giaban = 0;
                }
                    
            }
        }

        public double loinhuan()
        {
            return giaban - chiphi() - thueSX() - tiennhuanbut();
        }
        public double tiennhuanbut()
        {
            return 0.2 * giaban;
        }
        public double thueSX()
        {
            return giaban * tilethue;
        }
        public abstract double chiphi(); //phương thức trừu tượng
      
        public sach()
        {
            this.masach = "S001";
            this.Tensach = "Hướng đối tượng";
            this.tentg = "Nguyễn Cửu Đàm";
            this.sotrang = 100;
            this.giaban = 40000;
        }
        public void xuat()
        {
            Console.WriteLine("{0,-10}{1,-20}{2,-20}{3,-10}{4,-10}",masach,Tensach1,tentg,sotrang,giaban);
        }
    }
    interface dichvudikem //interface
    {
        double phibaobia();
        double phiuopthom();
    }
    //lớp sách đồ họa
    class sachdohoa:sach,dichvudikem //kế thừa từ sách và dichvudikem
    {
        int sohinhve;
        bool mausac;
        public int Sohinhve
        {
            get { return sohinhve; }
            set { sohinhve = value; }
        }      

        public bool Mausac
        {
            get { return mausac; }
            set { mausac = value; }
        }
        public override double chiphi()
        {
            if (mausac == true)
                return sohinhve * 2000;
            else
                return sohinhve * 1200;
        }
        public double phibaobia()
        {
            return 50000;
        }
        public double phiuopthom()
        {
            return Sotrang * 200;
        }
        public void nhap()
        {
            Console.WriteLine("NHap ma sach:");
            Masach = Console.ReadLine();
            Console.WriteLine("NHap ten sach:");
            Tensach = Console.ReadLine();
            Console.WriteLine("NHap ten tac gia:");
            Tentg = Console.ReadLine();
            Console.WriteLine("NHap so trang:");
            Sotrang = int.Parse(Console.ReadLine());
            Console.WriteLine("NHap gia ban:");
            Giaban = double.Parse(Console.ReadLine());
            Console.WriteLine("NHap so hinh ve:");
            Sohinhve= int.Parse(Console.ReadLine());
            Console.WriteLine("NHap mau sac:");
            Mausac = bool.Parse(Console.ReadLine());
        }
        public void xuat()
        {
            Console.WriteLine("{0,-10}{1,-20}{2,-20}{3,-10}{4,-10}{5,-6}{6,-6}{7,-15}{8,-15}", Masach, Tensach, Tentg, Sotrang, Giaban,Sohinhve,Mausac,chiphi(),loinhuan() );
        }
    }
    //lớp sách văn bản
    class sachvanban:sach //kế thừa sách
    {
        double chiphithietke;

        public double Chiphithietke
        {
            get { return chiphithietke; }
            set { chiphithietke = value; }
        }
        public override double chiphi()
        {
            return 0.4 * Giaban + chiphithietke;
        }
    }
    //lớp sách cao cấp
    class sachcaocap : sach, dichvudikem //kế thừa từ sách và dichvudikem
    {
        string chatlieu;
        double chiphithuelambia;
        public string Chatlieu
        {
            get { return chatlieu; }
            set { chatlieu = value; }
        }      

        public double Chiphithuelambia
        {
            get { return chiphithuelambia; }
            set { chiphithuelambia = value; }
        }
        public override double chiphi()
        {
            return chiphithuelambia + 0.5 * Giaban;
        }
        public double phibaobia()
        {
            return 80000;
        }
        public double phiuopthom()
        {
            return Sotrang * 300;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.Unicode;
            Console.InputEncoding = Encoding.Unicode;
            sachdohoa sdh = new sachdohoa();
            sdh.nhap();
            sdh.xuat();
            Console.ReadLine();
        }
    }
}
