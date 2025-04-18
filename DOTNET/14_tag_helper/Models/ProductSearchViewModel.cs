namespace ProductSearchApp.Models
{
    public class ProductSearchViewModel
    {
        public string? SearchProduct { get; set; }
        public List<string> Products { get; set; } = new();
    }
}
