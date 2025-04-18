// 06. Program to show use of enum and struct in C#

using System;

enum Level
{
    Admin,
    Moderator,
    User,
    Guest
}

struct User
{
    public string Name;
    public Level Level;

    public void Display()
    {
        Console.WriteLine($"User Name: {Name}");
        Console.WriteLine($"Level: {Level}");
    }
}

public class Program
{
    public static void Main()
    {
        User user;

        user.Name = "Sudarshan Poudel";
        user.Level = Level.Moderator;

        user.Display();
    }
}
