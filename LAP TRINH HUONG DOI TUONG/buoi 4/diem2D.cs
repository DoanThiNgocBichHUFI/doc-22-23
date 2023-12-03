using System;

namespace buoi4{
    class diem2D{
    int x, y;

    public int Y{
        get{return y;}
        set{y = value;}
    }

    public int X{
        get{return x;}
        set{x = value;}
    }

    public double tinhKC(){
        return Math.Sqrt(X*X +Y*Y);
    }

    public void nhap(){
        Console.WriteLine("Nhap toa do x: ");
        X= int.Parse(Console.ReadLine());
        Console.WriteLine("Nhap toa do y:");
        Y= int.Parse(Console.ReadLine());
    }

    public void xuat(){
        Console.WriteLine("toa do x:" +X+ "Toa do y" +y);
        Console.WriteLine("toa do x: {0} toa do y: ",X,y);
    }

    }
}