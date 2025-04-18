using Microsoft.AspNetCore.Mvc;

namespace SessionExampleApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            string? name = HttpContext.Session.GetString("UserName");
            ViewData["Name"] = name;
            return View();
        }

        [HttpPost]
        public IActionResult SetName(string userName)
        {
            if (!string.IsNullOrWhiteSpace(userName))
            {
                HttpContext.Session.SetString("UserName", userName);
            }
            return RedirectToAction("Index");
        }

        public IActionResult Clear()
        {
            HttpContext.Session.Clear();
            return RedirectToAction("Index");
        }
    }
}
