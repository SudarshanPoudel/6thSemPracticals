// 02. Program to show creation and use of class and object in c#

using System;
class Student
{
    public string Name;
    public int Age;

    public void DisplayInfo()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}
class Program
{
    static void Main(string[] args)
    {
        Student student1 = new Student();
        student1.Name = "Studarshan Poudel";
        student1.Age = 20;

        Student student2 = new Student();
        student2.Name = "Karma";
        student2.Age = 22;

        student1.DisplayInfo();
        student2.DisplayInfo();
    }
}