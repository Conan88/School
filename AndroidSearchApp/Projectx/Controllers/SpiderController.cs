using System;
using System.Collections.Generic;
using System.Runtime.Serialization.Json;
using System.Net.Http;
using Microsoft.AspNetCore.Mvc;
using Projectx.Data;
using System.Threading.Tasks;
using Projectx.Models;
using System.Linq;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace Projectx
{


    [Route("api/[controller]")]
    public class ArtistDetailController : Controller
    {
        

        [HttpGet]
        public Artist Get(string artistid, string offset = "0", string limit = "20")
        {
            RequestSpotify rs = new RequestSpotify();
            Artist artist = new Artist();
            artist = rs.OneArtist(artistid).Result;
            return artist;
        }
    }

    /*
    ArtistDetailController
    get one artist given artist id
     */
    [Route("api/[controller]")]
    public class GameController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public GameController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public List<Game> Get(string search, string offset = "0", string limit = "20")
        {
            RequestIgdb ri = new RequestIgdb();
            List<Game> listGames = new List<Game>();
            listGames = ri.GetGameList(search, offset, limit).Result;
            return listGames;
        }
    }

    /*
    ArtistController
    Searchs for artists given a search term.
    Option parameters:
        offset: offset of search results
        limit: how many results to return
     */
    [Route("api/[controller]")]
    public class ArtistController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public ArtistController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public ArtistSearch Get(string search, string offset = "0", string limit = "20")
        {
            RequestSpotify rs = new RequestSpotify();
            ArtistSearch artist = new ArtistSearch();
            artist = rs.SearchArtists(search: search, offset: offset, limit: limit);
            return artist;
        }
    }

    /*
    AlbumController
    Searchs for albums given a search term.
    Option parameters:
        offset: offset of search results
        limit: how many results to return
     */
    [Route("api/[controller]")]
    public class AlbumController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public AlbumController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public AlbumSearch Get(string search, string offset = "0", string limit = "20")
        {
            RequestSpotify rs = new RequestSpotify();
            AlbumSearch albums = new AlbumSearch();
            albums = rs.SearchAlbums(search: search, offset: offset, limit: limit);
            return albums;
        }
    }

    /*
    TrackController
    Searchs for tracks given a search term.
    Option parameters:
        offset: offset of search results
        limit: how many results to return
     */
    [Route("api/[controller]")]
    public class TrackController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public TrackController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public SongSearch Get(string search, string offset = "0", string limit = "20")
        {
            RequestSpotify rs = new RequestSpotify();
            SongSearch tracks = new SongSearch();
            tracks = rs.SearchTracks(search: search, offset: offset, limit: limit);
            return tracks;
        }
    }

    /*
    MovieController
    Searchs for movies given a search term.
    Option parameters:
        offset: offset of search results
        limit: how many results to return
     */
    [Route("api/[controller]")]
    public class MovieController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public MovieController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public List<Movie> Get(string search, string page = "1")
        {
            Requests rs = new Requests();
            List<Movie> movielist = new List<Movie>();
            movielist = rs.GetMovieList(search, page).Result;
            return movielist;

        }
    }

    public class Everything
    {
        public ArtistHolder artistholder { get; set; }
        public List<Movie> movieslist { get; set; }
        public List<Game> gamelist { get; set; }
        public Tweets tweetlist { get; set; }
    }

    [Route("api/[controller]")]
    public class TwitterController : Controller
    {
        [HttpGet]
        public Tweets Get(string input)
        {
            Tweets listTweets = new Tweets();
            RequestTwitter rt = new RequestTwitter();
            return rt.GetTweets(input).Result;
        }
    }

    // Return Json of all the songs from an album
    // takes in albumid from spotify
    [Route("api/[controller]")]
    public class MusicController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public MusicController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public List<Song> Get(string albumid)
        {
            RequestSpotify rs = new RequestSpotify();
            List<Song> alb = new List<Song>();
            alb = rs.GetFullAlbum(albumid).Result;
            return alb;

        }
    }

    // Returns Json of albums of an artist, 20 at a time
    // takes in id of artist and optionally higher limit and offset
    [Route("api/[controller]")]
    public class ArtistAlbumController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public ArtistAlbumController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public ArtistAlbumsHolder Get(string id, string offset = "0", string limit = "20")
        {
            RequestSpotify rs = new RequestSpotify();
            ArtistAlbumsHolder holder = new ArtistAlbumsHolder();
            holder = rs.GetArtistAlbums(id, offset, limit).Result;
            return holder;

        }
    }

    // Returns Json of an artists top ten tracks
    // takes in artistid
    [Route("api/[controller]")]
    public class TopTracksController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public TopTracksController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpGet]
        public List<Song> Get(string artistid)
        {
            RequestSpotify rs = new RequestSpotify();
            List<Song> holder = new List<Song>();
            holder = rs.GetTopTracks(artistid).Result;
            return holder;

        }
    }

    //two get request possible here
    [Route("api/[controller]")]
    public class SpiderController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public SpiderController(ApplicationDbContext db)
        {
            this.db = db;
        }

        // GET api/values
        // returns general search of all categories
        [HttpGet]
        public Everything Get(string input, string selection = null)
        {

            this.search = input;

            Everything everything = new Everything();
            List<Movie> listMovies = new List<Movie>();
            ArtistHolder listArtists = new ArtistHolder();
            List<Game> listGames = new List<Game>();
            //Tweets listTweets = new Tweets();

            SpotifyToken token = new SpotifyToken();

            Requests requests = new Requests();
            RequestSpotify rs = new RequestSpotify();
            RequestIgdb ri = new RequestIgdb();


            listMovies = requests.GetMovieList(input).Result;
            listArtists = rs.GetAll(input).Result;

            //RequestTwitter rt = new RequestTwitter();

            listMovies = requests.GetMovieList(input).Result;
            listArtists = rs.GetAll(input).Result;
            listGames = ri.GetGameList(input).Result;
            //listTweets = rt.GetTweets(input).Result;


            everything.artistholder = listArtists;
            everything.movieslist = listMovies;
            everything.gamelist = listGames;
            //everything.tweetlist = listTweets;

            return everything;
        }

        // GET api/values/5
        // returns details for 1 movie, given imdb id
        [HttpGet("{id}")]
        public Movie Get(string id)
        {
            Requests requests = new Requests();
            //GetMovieList tar inn en string, ikke en int
            var movie = requests.GetMovie(id).Result;
            return movie;
        }

        // POST api/values
        [HttpPost]
        public void Post([FromBody]string value)
        {

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

    [Route("api/[controller]")]
    public class ComplaintController : Controller
    {
        private readonly ApplicationDbContext db;
        private string search;
        public ComplaintController(ApplicationDbContext db)
        {
            this.db = db;
        }

        [HttpPost]
        public Models.AppModels.UserComplaint Post(Models.AppModels.UserComplaint m)
        {
            //var blog = db.Blogposts.First(a=> a.id == m.id);

            if (ModelState.IsValid)
            {

                db.UserComplaints.Add(m);

                db.SaveChanges();

                return m;
            }
            else
            {
                return null;
            }

        }

        [HttpGet]
        public List<Models.AppModels.UserComplaint> Get(Models.AppModels.UserComplaint m)
        {
            //var blog = db.Blogposts.First(a=> a.id == m.id);

            var compaints = db.UserComplaints.AsQueryable();
            return compaints.ToList();

        }


    }
}
