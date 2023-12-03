using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class phansoM
    {
        int tu, mau;

        public int Mau
        {
            get { return mau; }
            set 
            { 
               if(value==0)
                   Console.WriteLine("Mau so khong bang 0");
                else
                    mau = value; 
            }
        }

        public int Tu
        {
            get { return tu; }
            set { tu = value; }
        }
        public phansoM()
        {

        }
        public phansoM(phanso a)
        {
            this.tu = a.Tu;
            this.mau = a.Mau;
        }
        public phansoM(int tu,int mau)
        {
            this.tu = tu;
            this.mau = mau;
        }
        public void chuyendau()
        {
            if(mau<0)
            {
                mau = mau * -1;
                tu = tu * -1;
            }
            
        }
        
        int USCLN(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            while (a != b)
            {
                if (a > b)
                    a = a - b;
                else
                    b = b - a;
            }
            return a;
        }

        public void RGPS()
        {
            int usc = USCLN(tu, mau);
            tu = tu / usc;
            mau = mau / usc;
        }
        public  phansoM nhap()
        {
            phansoM a = new phansoM();
            Console.WriteLine("Nhap tu so:");
            a.Tu = int.Parse(Console.ReadLine());
            do
            {
                Console.WriteLine("Nhap mau so:");
                a.Mau = int.Parse(Console.ReadLine());
            } while (a.Mau == 0);
            a.chuyendau();
            a.RGPS();
            return a;
        }
        public phansoM tong(phansoM b)
        {
            phansoM tong = new phansoM();
           tong.tu = tu * b.mau + mau * b.tu;
           tong.mau = mau * b.mau;
           tong.chuyendau();
           tong.RGPS();
            return tong;
        }
        public static phansoM operator +(phansoM a, phansoM b)
        {
            phansoM tong = new phansoM();
            tong.tu = a.tu * b.mau + a.mau * b.tu;
            tong.mau = a.mau * b.mau;
            tong.chuyendau();
            tong.RGPS();
            return tong;
        }
        public static phansoM operator -(phansoM a, phansoM b)
        {
            phansoM hieu = new phansoM();
            hieu.tu = a.tu * b.mau + a.mau * b.tu;
            hieu.mau = a.mau * b.mau;
            hieu.chuyendau();
            hieu.RGPS();
            return hieu;
        }
        public static phansoM operator *(phansoM a, phansoM b)
        {
            phansoM tich = new phansoM();
            tich.tu = a.tu * b.tu ;
            tich.mau = a.mau * b.mau;
            tich.chuyendau();
            tich.RGPS();
            return tich;
        }
        public static phansoM operator /(phansoM a, phansoM b)
        {
            phansoM thuong = new phansoM();
            thuong.tu = a.tu * b.mau;
            thuong.mau = a.mau * b.tu;
            thuong.chuyendau();
            thuong.RGPS();
            return thuong;
        }
        public static bool operator ==(phansoM a, phansoM b)
        {

            if (a.tu * b.mau == a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static bool operator !=(phansoM a, phansoM b)
        {

            if (a.tu * b.mau != a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static bool operator >(phansoM a, phansoM b)
        {

            if (a.tu * b.mau > a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static bool operator <(phansoM a, phansoM b)
        {

            if (a.tu * b.mau < a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static bool operator >=(phansoM a, phansoM b)
        {

            if (a.tu * b.mau >= a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static bool operator <=(phansoM a, phansoM b)
        {

            if (a.tu * b.mau <= a.mau * b.tu)
                return true;
            else
                return false;
        }
        public static phansoM operator ++(phansoM a)
        {
            a.tu += a.mau;
            return a;
        }
        public static phansoM operator --(phansoM a)
        {
            a.tu += a.mau;
            return a;
        }
        public override string ToString()
        {
            return string.Format("[{0}/ {1}]", tu, mau);
        }
        public bool Equals(Object o)
        {
            if (!(o is phanso))
                return false;
            return o.ToString() == this.ToString();
        }
        public void xuat()
        {
            //Console.Write(tu+ "/" +mau +"  ");
            Console.Write("{0}/{1}  ",tu,mau);
        }
    }
}
