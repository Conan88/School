
using System.Collections.Generic;

namespace Projectx
{
    public class Gamelist
    {
        public List<Game> games { get; set; }
    }
    public class Game
    {
        public ulong id { get; set; }
        public string name { get; set; }
        public string slug { get; set; }
        public string url { get; set; }
        public long created_at { get; set; }
        public long updated_at { get; set; }
        public string summary { get; set; }
        public string storyline { get; set; }
        public double rating { get; set; }
        public double aggregated_rating { get; set; }
        public List<int> developers { get; set; }
        public List<int> publishers { get; set; }
        public List<int> game_engines { get; set; }
        public int category { get; set; }
        public List<int> keywords { get; set; }
        public List<int> genres { get; set; }
        public long first_release_date { get; set; }
        public string releasedatestring { get; set;}
        public List<GameScreenshots> screenshots { get; set; }
        public GameCover cover { get; set; } 
        public GamePegi pegi { get; set; }
        public List<GameWebsites> websites { get; set; }  
    }

    public class GameScreenshots{
        public string url { get; set; }
        public string cloudinary_id { get; set; }
        public int width { get; set; }
        public int height { get; set; }
    }

    public class GameCover{
        public string url { get; set; }
        public string cloudinary_id { get; set; }
        public int width { get; set; }
        public int height { get; set; }
    }

    public class GamePegi{
        public int rating { get; set; }
        public string synopsis { get; set; }
    }

    public class GameWebsites{
        public int category { get; set; }
        public string url { get; set; }
    }

}