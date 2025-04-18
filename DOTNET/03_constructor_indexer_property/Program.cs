// program to illustrate encapsulation with properties and indexers and constructor.

class Student
{
    private string name;
    private int age;
    private readonly string[]? subject;
    // Constructor
    public Student(string name, int age, string[] subject)
    {
        this.name = name;
        this.age = age;
        this.subject = subject;
    }
    // Properties
    public string Name
    {
        get { return name; }
        set
        {
            if (!string.IsNullOrEmpty(value) && value.Length > 0)
            {
                name = value;
            }
        }
    }
    public int Age
    {
        get { return age; }
        set
        {
            if (value > 18)
            {
                age = value;
            }
            else
            {
                Console.WriteLine("Age must be greater than 18.");
            }
        }
    }
    // Indexer
    public string this[int index]
    {
        get
        {
            if (subject == null || index < 0 || index >= subject.Length)
            {
                return "Index is out of range.";
            }
            return subject[index];
        }
        set
        {
            if (subject != null && index >= 0 && index < subject.Length)
            {
                subject[index] = value;
            }
        }
    }
}
public class Program
{
    public static void Main()
    {
        // Creating an instance of Student
        string[] subjects = { "Dotnet", "CDC", "SE" };
        Student student = new Student("Sudarshan Poudel", 20, subjects);
        // Access properties
        Console.WriteLine($"Name: {student.Name}");
        Console.WriteLine($"Age: {student.Age}");
        // Access indexer
        Console.WriteLine($"Subject at index 1: {student[1]}");
        student[1] = "DSA";
        Console.WriteLine($"Updated Subject at index 1: {student[1]}");
        student[2] = "DAA";
        Console.WriteLine($"Added Subject at index 2: {student[2]}");
        Console.WriteLine($"Subject at index 0: {student[0]}");
        Console.WriteLine($"Subject at index 1: {student[1]}");
    }
}