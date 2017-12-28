using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace Projectx.Models.AppModels
{
    public class UserComplaint
    {

        public UserComplaint()
        {
            
        }

        public UserComplaint(string name, string message, string type)
        {
            Name = name;
            Message = message;
            Type = type;
        }
        public int id { get; set; }

        [Display(Name="Name")]
        public string Name { get; set; }
        [Required, Display(Name="Blog Post")]
        public string Message { get; set; }
        
        [Required, Display(Name="Title")]
        public string Type { get; set; }

        public bool Resolved { get; set; }

        public int DeveloperID { get; set; }
    }
}
