var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews();
builder.Services.AddSession(); // Add session support

var app = builder.Build();

app.UseStaticFiles();
app.UseRouting();

app.UseSession(); // Enable session middleware

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
