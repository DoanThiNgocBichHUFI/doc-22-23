using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
namespace QLSV
{
    class DSSV
    {
         List<sinhvien> listSV = new List<sinhvien>();
       
        int autoID()
        {
            int max;
            if (listSV.Count == 0)
                max = 0;
            else
            {
                int a = listSV.Count;
                max = listSV[a-1].Id;
            }
            return ++max;
        }
        public void NhapSV()
        {
            sinhvien sv = new sinhvien();
            sv.Id = autoID();
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
            listSV.Add(sv);
        }
        public void Docfile()
        {
            XmlDocument read = new XmlDocument();
            read.Load("danhsach.xml");//("d:\\danhsach.xml")
            XmlNodeList nodelist = read.SelectNodes("/DANHSACH/SV");
            if (nodelist == null)
            {
                Console.WriteLine("No users found");
                Environment.Exit(1);
            }
            foreach(XmlNode node in nodelist)
            {
                sinhvien sv = new sinhvien();
                sv.Id = int.Parse(node["ID"].InnerText);
               sv.Name = node.ChildNodes[1].InnerText;
                //sv.Name = node["NAME"].InnerText;
                sv.Toan = double.Parse(node["TOAN"].InnerText);
                sv.Ly = double.Parse(node["LY"].InnerText);
                sv.Hoa = double.Parse(node["HOA"].InnerText);
                sv.Tb = sv.trungbinh();
                sv.Xl = sv.Xeploai();
                listSV.Add(sv);

            }
            //listSV.ForEach(Hienthi());
        }
        //public void doc()
        //{
        //    XmlTextReader read = new XmlTextReader("danhsach.xml");//("E:\\books.xml"))
        //    read.Read();
        //    while (read.Read())
        //    {
        //        sinhvien sv = new sinhvien();
        //        read.MoveToElement();
        //        sv.Id = int.Parse(read.ReadString("ID"));
        //    }
        //}
        private void createNode(string id, string pName, string toan,string ly,string hoa, XmlTextWriter writer)
        {
            writer.WriteStartElement("SV");
            writer.WriteStartElement("ID");
            writer.WriteString(id);
            writer.WriteEndElement();
            writer.WriteStartElement("NAME");
            writer.WriteString(pName);
            writer.WriteEndElement();
            writer.WriteStartElement("TOAN");
            writer.WriteString(toan);
            writer.WriteEndElement();
            writer.WriteStartElement("LY");
            writer.WriteString(ly);
            writer.WriteEndElement();
            writer.WriteStartElement("HOA");
            writer.WriteString(hoa);
            writer.WriteEndElement();
            writer.WriteEndElement();
        }
        public void ghi()
        {
            XmlTextWriter writer = new XmlTextWriter("danhsach1.xml", System.Text.Encoding.UTF8);
            writer.WriteStartDocument(true);
            writer.Formatting = Formatting.Indented;
            writer.Indentation = 2;
            writer.WriteStartElement("DANHSACH");
            foreach (sinhvien i in listSV)
            {
                string id, name, toan, ly, hoa;
                id = i.Id.ToString();
                name = i.Name;
                toan = i.Toan.ToString();
                ly = i.Ly.ToString();
                hoa = i.Hoa.ToString();
                createNode(id,name,toan,ly,hoa,writer);//("1", "Product 1", "1000", writer);
                
              
            }
            writer.WriteEndElement();
            writer.WriteEndDocument();
            writer.Close();

        }
        public void Hienthi(sinhvien sv) 
        {
            Console.WriteLine("{0,-10} {1,-30} {2:0.00}  {3:0.00}  {4:0.00}  {5:0.00} {6,-10}",sv.Id,sv.Name,sv.Toan,sv.Ly,sv.Hoa,sv.Tb,sv.Xl);
        }
        public void HienthiDSSV()
        {
            foreach (sinhvien i in listSV)
                Hienthi(i);
        }
        public void Saptang()
        {
            listSV=listSV.OrderBy(t => t.Xl).ThenByDescending(t=>t.Toan).ToList();
        }
        public void Sapgiam()
        {
            listSV=listSV.OrderByDescending(t => t.Xl).ThenBy(t => t.Toan).ToList();
        }
        public List<sinhvien> SVkha()
        {
            List<sinhvien> result = new List<sinhvien>();
            result = listSV.Where(t => t.Xl == "Khá").ToList();
            return result;
        }
        //public List<sinhvien> LocXL(string xl)
        //{
        //    List<sinhvien> result = new List<sinhvien>();
        //    result = listSV.Where(t => t.Xl == xl).ToList();
        //    return result;
        //}
        public List<sinhvien> locDTB()
        {
            List<sinhvien> result = new List<sinhvien>();
            result = listSV.Where(t => t.Tb > 7).ToList();
            return result;
        }
        //public List<sinhvien> locDTB(double dtb)
        //{
        //    List<sinhvien> result = new List<sinhvien>();
        //    result = listSV.Where(t => t.Tb > dtb).ToList();
        //    return result;
        //}
        public sinhvien findID()
        {
            sinhvien result = null;
            foreach (sinhvien i in listSV)
            {
                if (i.Id == 1)
                    result = i;
            }            
            return result;
        }
        public List<sinhvien> timtheoten(string s)
        {
            List<sinhvien> a = new List<sinhvien>();
            a = listSV.Where(t => t.Name.ToUpper().Contains(s.ToUpper())).ToList();//equals
            return a;
        }
        public void Xoasv()
        {
            sinhvien i = findID();
            if (i != null)
                listSV.Remove(i);

        }
        public sinhvien findName(string s)
        {
            sinhvien result = null;
            foreach (sinhvien i in listSV)
            {
                if (i.Name .ToUpper().Contains(s.ToUpper()))
                    result = i;
            }
            return result;
        }
        public void xoaten(string s)
        {
           
           for (int i = 0; i < listSV.Count; i++)
            {
                if (listSV[i].Name.ToUpper().Contains(s.ToUpper()))
                    listSV.Remove(listSV[i]);
            }
        }
    }
}
