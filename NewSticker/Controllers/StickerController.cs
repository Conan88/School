using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using NewSticker.Data;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace NewSticker
{
    [Route("api/[controller]")]
    public class StickerController : Controller
    {
        private readonly ApplicationDbContext db;

        public StickerController(ApplicationDbContext db)
        {
            this.db = db;
        }
        // GET api/values
        [HttpGet]
        public IEnumerable<News> Get()
        {
            return db.news.ToList();
        }

        // GET api/values/5
        [HttpGet("{id}")]
        public string Get(int id)
        {
            return "value";
        }

        // POST api/values
        [HttpPost]
        public void Post([FromBody]News value)
        {
           db.news.Add(value);
           db.SaveChanges(); 
        }

        // PUT api/values/5
        [HttpPut("{id}")]
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE api/values/5
        [HttpDelete("{id}")]
        public void Delete(int id)
        {
        }
    }
}
