using EvanDangolCLI;
using Microsoft.Office.Interop.Word;
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using System.Linq;

namespace CppCSharp
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            ReadWordDoc();
        }

        private static void ReadWordDoc()

        {
            Application wordApp = new Application();
            try
            {
              

                // File Path

                string strFilePath = "E:\\new menu beverage1.docx";

                // Create obj filename to pass it as paremeter in open 
                object objFile = strFilePath;
                object objNull = System.Reflection.Missing.Value;

                object objReadOnly = true;//Open Document
                Microsoft.Office.Interop.Word.Document Doc = wordApp.Documents.Open(ref objFile, ref objNull, ref objReadOnly, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull, ref objNull);

                // To read each line consider each line as paragraph Docuemnt

                string menucategoryname="";
                List<string> menus = new List<string>();
                List<string> headers = new List<string>();
               
                Dictionary<string, decimal> menuitem = new Dictionary<string, decimal>();
                Dictionary<string, Dictionary<string, decimal>> main = new Dictionary<string, Dictionary<string, decimal>>();

                List<MenuCategory> MenuCategories = new List<MenuCategory>();
                List<MenuItem> MenuItems = new List<MenuItem>();
                int MenuCategoryid = 0;
                foreach (Microsoft.Office.Interop.Word.Paragraph objParagraph in Doc.Paragraphs)
                {
                    string pricestring = "";
                    decimal price = 0;
                    var item = objParagraph.Range.Text;
                    // Console.WriteLine(objParagraph.Range.Bold);
                    if (objParagraph.Range.Bold == -1 && !string.IsNullOrWhiteSpace(objParagraph.Range.Text))
                    {
                        MenuCategoryid++;
                        var category = new string(item.Where(a => char.IsLetter(a)).ToArray());
                        menucategoryname = category;
                        //headers.Add(objParagraph.Range.Text);
                        ////Console.WriteLine(objParagraph.Range.Text);
                        MenuCategory mc = new MenuCategory();
                        mc.MenuCategoryId = MenuCategoryid;
                        mc.MenyCategoryName = category;
                        MenuCategories.Add(mc);
                    }
                    else
                    {
                     
                        if (string.IsNullOrWhiteSpace(item))
                        {
                            continue;
                        }
                        pricestring = Regex.Match(item, @"\d+").Value;
                        var menu = new string(item.Where(a => char.IsLetter(a)).ToArray());
                        if (decimal.TryParse(pricestring, out price) && menu.Length < 1)
                        {
                            throw new Exception("In valid file " + "\nafter " );
                        }
                        //menuitem.Add(menu, price);
                        //main.Add(headers.Last(),menuitem);
                        MenuItem m = new MenuItem();
                        m.MenuCategoryId = MenuCategoryid;
                        m.MenuItemName = menu;
                        m.MenuCategoryName = menucategoryname;
                        m.Price = price;
                        MenuItems.Add(m);
                    }

                }
                string previousmenu = "";
               // int j = 0;
                //foreach (var item in menus)
                //{

                //    if (string.IsNullOrWhiteSpace(item))
                //    {
                //        continue;
                //    }
                //    pricestring = Regex.Match(item, @"\d+").Value;
                //    var v = new string(item.Where(a => char.IsLetter(a)).ToArray());
                //    if (decimal.TryParse(pricestring, out price) && v.Length < 1)
                //    {
                //        throw new Exception("In valid file " + "\nafter " + previousmenu);
                //    }
                //    menuitem.Add(v, price);
                //    previousmenu = item;
                //    main.Add(headers[j], menuitem);
                //    j++;
                //}
                var v1 = main;

                List<MenuCategory> mainmenu = new List<MenuCategory>();
                foreach (var item in MenuItems.GroupBy(a=>a.MenuCategoryId).Distinct())
                {
                    var v = item;
                   
                }
               
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                wordApp.Quit();
                wordApp = null;
                GC.Collect();
            }
        }
    }
    public class MenuCategory
    {
        public int MenuCategoryId { get; set; }
        public string MenyCategoryName { get; set; }
        public List<MenuItem> MenuItems { get; set; }
    }
    public class MenuItem
    {
        public int MenuItemId { get; set; }
        public string MenuItemName { get; set; }
        public int MenuCategoryId { get; set; }
        public string MenuCategoryName { get; set; }
        public decimal Price { get; set; }
    }
}