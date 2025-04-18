//  09. program to demonstrate use of Generics and Non-Generic Collections

using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Stack<string> nameStack = new();
        while (true)
        {
            Console.Write("Enter a name (or type 'stop' to finish): ");
            string? name = Console.ReadLine();
            if (string.Equals(name, "stop", StringComparison.OrdinalIgnoreCase))
            {
                break;
            }
            if (!string.IsNullOrWhiteSpace(name))
            {
                nameStack.Push(name);
            }
        }

        Console.WriteLine("\nPopping names from the stack:");
        while (nameStack.Count > 0)
        {
            Console.WriteLine(nameStack.Pop());
        }

        Console.WriteLine("\nDemonstrating non-generic collection (ArrayList):");
        ArrayList mixedList = new();
        mixedList.Add("Hello");
        mixedList.Add(42);
        mixedList.Add(3.14);
        mixedList.Add(true);

        foreach (var item in mixedList)
        {
            Console.WriteLine($"{item} ({item.GetType().Name})");
        }
    }
}
