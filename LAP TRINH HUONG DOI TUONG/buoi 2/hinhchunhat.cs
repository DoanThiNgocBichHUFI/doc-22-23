using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class hinhchunhat
    {
        private double cd, cr;

        public double Cr
        {
            get { return cr; }
            set { 
                if(value<0)
                    cr = 0;
                else
                    cr = value;
            }
        }

        public double Cd
        {
            get { return cd; }
            set
            {
                if (value < 0)
                    cd = 0;
                else
                    cd = value;
            }
        }
        public hinhchunhat()
        {
            this.cd = 0;
            this.cr=0;
        }
        public hinhchunhat(double cd,double cr)
        {
            this.Cd=cd;
            this.Cr=cr;
        }
        public hinhchunhat(hinhchunhat a)
        {
            this.cd=a.cd;
            this.cr=a.cr;
        }
        ~hinhchunhat()
        {

        }
        public double tinhcv()
        {
            return (cd+cr) * 2;
        }
        public double tinhdt()
        {
            return cd*cr ;
        }
        public void nhap()
        {
            do
            {
                Console.WriteLine("Nhap chieu dai:");
                this.Cd = double.Parse(Console.ReadLine());
                Console.WriteLine("Nhap chieu rong:");
                this.Cr = double.Parse(Console.ReadLine());
            } while (Cd <= 0 || Cr <= 0);
        }
        public void xuat()
        {
            Console.WriteLine("Chieu dai: {0},chieu rong: {1}Chu vi:{2},Dien tich: {3},Dcheo:{4}", cd,cr, tinhcv(), tinhdt(),duongcheo());
        }
        public double duongcheo()
        {
            return Math.Sqrt(Math.Pow(cd, 2) + Math.Pow(cr, 2));
        }
        public void changesize(int tx,int ty,int type)
        {
            if(type==0)
            {
                this.cr = this.cr - tx;
                this.cd = this.cd - ty;
            }
            else
            {
                this.cr = this.cr + tx;
                this.cd = this.cd + ty;
            }
        }
    }
}
