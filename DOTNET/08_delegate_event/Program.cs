// 08. Program to show use of delegate and event in C#

using System;

delegate void Notify();

class Process
{
    public event Notify ProcessCompleted;

    public void StartProcess()
    {
        Console.WriteLine("Process Started...");
        System.Threading.Thread.Sleep(1000);
        OnProcessCompleted();
    }

    protected virtual void OnProcessCompleted()
    {
        if (ProcessCompleted != null)
            ProcessCompleted();
    }
}

class Subscriber
{
    public void ShowMessage()
    {
        Console.WriteLine("Process Completed Successfully!");
    }
}

public class Program
{
    public static void Main()
    {
        Process process = new Process();
        Subscriber subscriber = new Subscriber();

        process.ProcessCompleted += subscriber.ShowMessage;

        process.StartProcess();
    }
}
