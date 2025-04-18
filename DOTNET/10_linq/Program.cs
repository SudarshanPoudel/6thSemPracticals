// 10. Program to show use of LINQ in C#

using System;
using System.Collections.Generic;
using System.Linq;

class Student
{
    public string Name { get; set; }
    public int Marks { get; set; }
}

class Program
{
    static void Main()
    {
        List<int> numbers = new() { 5, 12, 3, 21, 8, 1, 30 };
        var evenNumbers = numbers.Where(n => n % 2 == 0).OrderBy(n => n);
        Console.WriteLine("Even Numbers:");
        foreach (var num in evenNumbers)
        {
            Console.WriteLine(num);
        }

        List<Student> students = new()
        {
            new Student { Name = "Sudarshan", Marks = 85 },
            new Student { Name = "Luffy", Marks = 92 },
            new Student { Name = "Chetan", Marks = 67 },
            new Student { Name = "Deepa", Marks = 74 }
        };

        var topStudents = students.Where(s => s.Marks >= 75).OrderByDescending(s => s.Marks);
        Console.WriteLine("\nTop Students (Marks >= 75):");
        foreach (var student in topStudents)
        {
            Console.WriteLine($"{student.Name} - {student.Marks}");
        }
    }
}
