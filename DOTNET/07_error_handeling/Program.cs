// 07. Program to show error handling and custom exception in C#

using System;

class InvalidAgeError : Exception
{
    public InvalidAgeError(string message) : base(message) { }
}

class Person
{
    public string Name;
    public int Age;

    public void SetAge(int age)
    {
        if (age < 0 || age > 150)
        {
            throw new InvalidAgeError("Age must be between 0 and 150.");
        }
        Age = age;
    }

    public void Display()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}

public class Program
{
    public static void Main()
    {
        Person person = new Person();
        person.Name = "Sudarshan";

        try
        {
            Console.Write("Enter age: ");
            int inputAge = int.Parse(Console.ReadLine() ?? "0");
            person.SetAge(inputAge);
            person.Display();
        }
        catch (InvalidAgeError e)
        {
            Console.WriteLine($"Custom Error: {e.Message}");
        }
        catch (Exception e)
        {
            Console.WriteLine($"System Error: {e.Message}");
        }
        finally
        {
            Console.WriteLine("Execution completed.");
        }
    }
}
