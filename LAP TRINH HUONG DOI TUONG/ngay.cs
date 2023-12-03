using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class ngayt
    {
        public int ngay;
        public int thang;
        public int nam;
        public bool namnhuan()
        {
            if (nam % 400 == 0 || (nam % 100 != 0 && nam % 4 == 0))
                return true;
            else
                return false;
        }
        public ngayt(int ngay,int thang,int nam)
        {
            this.ngay = ngay;
            this.thang = thang;
            this.nam = nam;
        }
        //public int namnhuan()
        //{
        //    if (nam % 400 == 0 || (nam % 100 != 0 && nam % 4 == 0))
        //        return 1;
        //    else
        //        return 0;
        //}
        public void ngaytruoc()
        {
            ngay--;
            if(ngay==0)
            {
                thang--;
                if(thang==0)
                {
                    ngay = 31;
                    thang = 12;
                    nam--;
                }
                if(thang==2)
                {
                    if (namnhuan())
                        ngay = 29;
                    else
                        ngay = 28;
                 }
                else if (thang==4||thang==6||thang==9||thang==11)
                {
                    ngay=30;
                }
                else 
                {
                    ngay = 31;
                }
            }
        }
        public void ngaysau()
        {
            ngay++;
            if (thang == 2)
            {
                if ((namnhuan() && ngay == 30) || (!namnhuan() && ngay == 29))
                {
                    thang++;
                    ngay = 1;
                }
            }
            else if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay == 31)
            {
                ngay = 1;
                thang++;

            }
            else if (thang == 12 && ngay == 32)
            {
                thang = 1;
                ngay = 1;
                nam++;
            }
            else if ((thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10) && ngay == 32)
            {
                thang++;
                ngay = 1;
            }
           
        }
    }
}
