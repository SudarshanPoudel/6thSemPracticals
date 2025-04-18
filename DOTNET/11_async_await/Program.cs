// 11. Program to show asynchronous programming in C# with async and await

using System;
using System.Threading.Tasks;

class Program
{
    public static async Task Main(string[] args)
    {
        Console.WriteLine("Program started.");

        Task task1 = LongRunningTask("Task 1", 3000);
        Task task2 = LongRunningTask("Task 2", 2000);
        
        await Task.WhenAll(task1, task2);

        Console.WriteLine("Program completed.");
    }

    public static async Task LongRunningTask(string taskName, int delay)
    {
        Console.WriteLine($"{taskName} started.");
        await Task.Delay(delay);
        Console.WriteLine($"{taskName} completed after {delay / 1000} seconds.");
    }
}
