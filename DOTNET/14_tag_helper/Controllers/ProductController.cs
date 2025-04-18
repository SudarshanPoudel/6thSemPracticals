using Microsoft.AspNetCore.Mvc;
using ProductSearchApp.Models;
using System;
using System.Collections.Generic;
using System.Linq;

namespace ProductSearchApp.Controllers
{
    public class ProductController : Controller
    {
        private readonly List<string> _allProducts = new()
        {
            "Laptop", "Phone", "Tablet", "Smart Phone", "Mouse", "Keyboard"
        };

        public IActionResult Index(string? searchProduct)
        {
            var filtered = string.IsNullOrWhiteSpace(searchProduct)
                ? _allProducts
                : _allProducts.Where(p => p.Contains(searchProduct, StringComparison.OrdinalIgnoreCase)).ToList();

            var viewModel = new ProductSearchViewModel
            {
                SearchProduct = searchProduct,
                Products = filtered
            };

            return View(viewModel);
        }
    }
}
