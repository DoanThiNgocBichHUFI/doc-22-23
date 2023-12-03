using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class hinhtron
    {
        private double bankinh; 


        public double Bankinh
        {
            get { return bankinh; }
            set { 
                if(value<0)
                {
                    bankinh = 0;

                }
                else
                    bankinh = value; 
            }
        }
        public hinhtron()
        {
            this.bankinh = 0;
        }
        public hinhtron(double bankinh)
        {
            this.Bankinh = bankinh;
        }
        public hinhtron(hinhtron a)
        {
            this.bankinh = a.bankinh;
        }
        ~hinhtron()
        {

        }
        public double tinhcv()
        {
            return this.bankinh * 3.14 * 2;
        }
        public double tinhdt()
        {
            return this.bankinh *this.bankinh* 3.14 ;
        }
        public void nhap()
        {
            Console.WriteLine("Nhap ban kinh:");
            this.Bankinh =double.Parse (Console.ReadLine());
        }
        public void xuat()
        {
            Console.WriteLine("Ban kinh: {0},Chu vi:{1},Dien tich: {2}", bankinh, tinhcv(), tinhdt());
        }
    }
}
