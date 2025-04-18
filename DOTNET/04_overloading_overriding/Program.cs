// 04. Program to show inheritance, method overloading and overriding in C#

class Vehicle
{
    public virtual void Display()
    {
        Console.WriteLine("This is a Vehicle class.");
    }
}

class Car : Vehicle
{
    private string brand;
    private int year;

    public Car(string brand, int year)
    {
        this.brand = brand;
        this.year = year;
    }

    public Car(string brand)
    {
        this.brand = brand;
        this.year = DateTime.Now.Year; 
    }

    public override void Display()
    {
        Console.WriteLine($"This is a car of brand {brand} manufactured in {year}.");
    }
}

public class Program
{
    public static void Main()
    {
        Vehicle vehicle = new Vehicle();
        vehicle.Display();

        Car car1 = new Car("Toyota", 2020);
        car1.Display();

        Car car2 = new Car("Honda");
        car2.Display();
    }
}
