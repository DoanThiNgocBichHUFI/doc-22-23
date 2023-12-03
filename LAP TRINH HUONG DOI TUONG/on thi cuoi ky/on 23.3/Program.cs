using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
namespace QLSV
{
    class Program
    {
       static void menu()
        {
            Console.WriteLine("1. Doc file");
            Console.WriteLine("2. Nhap du lieu");
            Console.WriteLine("3. Xuat du lieu");
            Console.WriteLine("4. Sap tang");
            Console.WriteLine("5. Sap giam");
            Console.WriteLine("6. Loc");
        }
        static void Main(string[] args)
        {

            DSSV dssv=new DSSV();
            List<sinhvien> result = new List<sinhvien>();
            int chon;
            do
            {
                menu();
                Console.WriteLine("Nhap lua chon: ");
                chon = int.Parse(Console.ReadLine());
                switch (chon)
                {
                    case 1:
                        dssv.Docfile();
                        break;
                    case 2:
                        dssv.NhapSV();
                        break;
                    case 3:
                        dssv.HienthiDSSV();
                        break;
                    case 4:
                        dssv.Saptang();
                        break;
                    case 5:
                        dssv.Sapgiam();
                        break;
                    case 6:
                        result = dssv.SVkha();
                        foreach (sinhvien i in result)
                            dssv.Hienthi(i);
                        break;
                    case 7:
                        result = dssv.locDTB();
                        foreach (sinhvien i in result)
                            dssv.Hienthi(i);
                        break;
                    case 8:
                        dssv.Xoasv();
                        break;
                    case 9:

                        dssv.xoaten("le");

                        break;
                    case 10:
                        dssv.ghi();
                        break;
                    case 11:
                        result = dssv.timtheoten("le");
                        foreach (sinhvien i in result)
                            dssv.Hienthi(i);
                        break;

                }
            } while (chon != 0);

           
            //XDocument doc = new XDocument(new XElement("body",
            // new XElement("level1",
            //  new XElement("level2", "text"),
            //  new XElement("level2", "other text"))));
            //doc.Save("H:\\document.xml"); 
        
            Console.ReadLine();
        }
    }
}
