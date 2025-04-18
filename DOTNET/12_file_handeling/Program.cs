// 12. Program to show file handling in C#

using System;
using System.IO;

class Program
{
    public static void Main()
    {
        string filePath = "example.txt";

        // Create a new file and write text to it
        WriteToFile(filePath);

        // Read the contents of the file
        ReadFromFile(filePath);

        // Append new content to the file
        AppendToFile(filePath);

        // Read the contents again after appending
        ReadFromFile(filePath);
    }

    public static void WriteToFile(string filePath)
    {
        string content = "Hello, I am Sudarshan Poudel, hope everything is cool.";
        try
        {
            File.WriteAllText(filePath, content);
            Console.WriteLine("File written successfully.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error writing to file: {ex.Message}");
        }
    }

    public static void ReadFromFile(string filePath)
    {
        try
        {
            string content = File.ReadAllText(filePath);
            Console.WriteLine("File content:");
            Console.WriteLine(content);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error reading from file: {ex.Message}");
        }
    }

    public static void AppendToFile(string filePath)
    {
        string contentToAppend = "\nThis is additional text being appended to the file.";
        try
        {
            File.AppendAllText(filePath, contentToAppend);
            Console.WriteLine("Content appended successfully.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error appending to file: {ex.Message}");
        }
    }
}
