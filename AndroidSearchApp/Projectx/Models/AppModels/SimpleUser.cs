using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace Projectx.Models.AppModels
{
    public class SimpleUser
    {

        public SimpleUser()
        {
            
        }

        public SimpleUser(string email, string firstname, string lastname)
        {
            FirstName = firstname;
            Email = email;
            LastName = lastname;
        }
        public int id { get; set; }

        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }

        
    }
}
