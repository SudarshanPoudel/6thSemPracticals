using Microsoft.AspNetCore.Mvc;
using StudentMvcApp.Models;
using System.Collections.Generic;

namespace StudentMvcApp.Controllers
{
    public class StudentController : Controller
    {
        public IActionResult Index()
        {
            List<Student> students = new List<Student>
            {
                new Student { Name = "Sudarshan Poudel", Marks = 86 },
                new Student { Name = "Sushant Poudel", Marks = 50 },
                new Student { Name = "Thomus Muller", Marks = 99 }
            };
            return View(students);
        }
    }
}
