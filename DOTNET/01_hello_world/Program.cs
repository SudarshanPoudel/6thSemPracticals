// 01. Program to show basic structure of a C# program

using System;

class Program
{
    static void Main(string[] args)
    {
        string name;
        Console.Write("Enter your name: ");
        name = Console.ReadLine();
        Console.WriteLine("Hello, " + name + "!");
        Console.WriteLine("Welcome to C# programming.");
    }
}