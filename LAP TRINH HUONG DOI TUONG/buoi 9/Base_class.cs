using System;

namespace buoi9{
    public class Base_class{
        protected int _x;
        public Base_class(){
            _x= 0;
            Console.WriteLine("Khoi tao mac dinh cua Base duoc goi.");
        }

        public void xuat(){
            Console.WriteLine("Gia tri _x= {0}", _x);
        }

        public Base_class(int x){
            this._x = x;
            Console.WriteLine("Khoi tao co tham so cua Base duoc goi.");
        }
    }

    public class Devired_class:Base_class{
        int _y;
        public Devired_class(){
            _y =0;
            Console.WriteLine("Khoi tao mac dinh cua Devired_class duoc goi");
        }

        public Devired_class(int x,int y): base(x){
            Console.WriteLine("Khoi tao 2 tham so cua Devired_class duoc goi.");
            this._y = y;
        }

        public void Xuat(){
            Console.WriteLine("Gia tri _y= {0}", _y);
        }
    }
}