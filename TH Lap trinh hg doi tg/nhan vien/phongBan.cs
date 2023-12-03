using System;
using System.Xml;

namespace nhanvien{
    class phongBan{
        string tenPHG;
        string vitri;

        List<nhanVien> dsnv= new List<nhanVien>();
        public string TenPHG{
            get =>tenPHG;
            set => tenPHG = value;
        }
        public string ViTri{
            get=>vitri;
            set =>vitri = value;
        }

        internal List<nhanVien>lst{
            get =>lst;
            set =>lst = value;
        }

        List<phongBan> pb= new List<phongBan>();

        public void nhapTuFile(string file){
            XmlDocument read= new XmlDocument();
            read.Load(file);
            XmlNodeList listPHG = read.SelectNodes("/phongbans/phongban");
            foreach(XmlNode node in listPHG){
                phongBan a= new phongBan();
                a.tenPHG= node["tenphong"].InnerText;
                a.vitri = node["vitri"].InnerText;

                XmlNodeList listNV= node["dsnv"].ChildNodes;
                foreach(XmlNode node1 in listNV){
                    nhanVien nv= new nhanVien();
                    nv.MaNV= node1["manv"].InnerText;
                    nv.Hoten = node1["hoten"].InnerText;
                    nv.SoNC= int.Parse(node1["snc"].InnerText);
                    nv.Hsl = double.Parse(node1["hsl"].InnerText);
                    nv.TrinhDo= node1["trinhdo"].InnerText;
                    nv.ChucVu = node1["chucvu"].InnerText;
                    a.dsnv.Add(nv);
                }
                pb.Add(a);
            }
        }
        public void xuatdsnv(){
            Console.WriteLine("Xuat danh sach nhan vien cua phong ban {0}: ",tenPHG);
            foreach(phongBan a in pb){
                Console.WriteLine("{0,-15} {1,-7}",a.tenPHG,a.vitri);
                foreach(nhanVien nv in a.dsnv)
                    nv.xuatNV();
            }
        }
    }
}   