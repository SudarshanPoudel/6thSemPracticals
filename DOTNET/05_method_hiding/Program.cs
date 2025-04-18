// 05. Program to show method hiding and overloading in C#


using System;

class Animal
{
    public void Speak()
    {
        Console.WriteLine("Animal speaks...");
    }
}

class Dog : Animal
{
    public new void Speak()
    {
        Console.WriteLine("Dog barks!");
    }

    public void Speak(string sound)
    {
        Console.WriteLine($"Dog says: {sound}");
    }

    public void Speak(int times)
    {
        for (int i = 0; i < times; i++)
        {
            Console.WriteLine("Bark!");
        }
    }
}

public class Program
{
    public static void Main()
    {
        Animal a = new Animal();
        a.Speak();

        Dog d = new Dog();
        d.Speak();
        d.Speak("Woof!");
        d.Speak(3);

        Animal ad = new Dog();
        ad.Speak();
    }
}
