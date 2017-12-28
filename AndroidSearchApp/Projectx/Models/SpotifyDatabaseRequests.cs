
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Runtime.Serialization.Json;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace Projectx
{
    public class RequestSpotify
    {
        const string encodedToken = "YOUR KEY";
        const string spotifyRefreshTokenUrl = "https://accounts.spotify.com/api/token";
        const string spotifyUrl = "https://api.spotify.com/v1/search?q=";
        string spotifyKey = "YOUR KEY";

        public async Task<string> GetToken()
        {
            var client = new HttpClient();
            var serializer = new DataContractJsonSerializer(typeof(SpotifyToken));
            SpotifyToken toke = null;
            client.DefaultRequestHeaders.Add("postman-token", "YOUR KEY");
            client.DefaultRequestHeaders.Add("cache-control", "no-cache");
            client.DefaultRequestHeaders.TryAddWithoutValidation("content-type", "application/x-www-form-urlencoded");
            client.DefaultRequestHeaders.Add("authorization", "YOUR KEY");
            //IRestResponse response = client.Execute(request);
            //client.PostAsync(HttpContent)
            var content = new FormUrlEncodedContent(new[]
            {
                new KeyValuePair<string, string>("grant_type", "client_credentials")
            });
            HttpResponseMessage response = await client.PostAsync("https://accounts.spotify.com/api/token", content);
            string responseBody = await response.Content.ReadAsStringAsync();
            toke = JsonConvert.DeserializeObject<SpotifyToken>(responseBody);
            Console.WriteLine(toke.access_token);
            string newtoke = "Bearer " + toke.access_token;
            spotifyKey = newtoke;
            return newtoke;

        }

        public async Task<ArtistHolder> GetAll(string artistSearch)
        {
            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    var serializer = new DataContractJsonSerializer(typeof(ArtistHolder));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync(spotifyUrl + artistSearch + "&type=track,artist,album");

                    ArtistHolder artist = null;

                    artist = serializer.ReadObject(streamTask) as ArtistHolder;

                    return artist;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return new ArtistHolder();
                }
            }
        }


        public async Task<ArtistHolder> Getter(string search, string offset = "0", string limit = "20", string type = "artist")
        {
            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    string url = "https://api.spotify.com/v1/search?query=" + search + "&type=" + type + "&offset=" + offset + "&limit=" + limit;

                    var serializer = new DataContractJsonSerializer(typeof(ArtistHolder));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync(url);

                    HttpResponseMessage response = await client.GetAsync(url);
                    ArtistHolder holder = null;
                    holder = serializer.ReadObject(streamTask) as ArtistHolder;
                    return holder;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }
        }



        public ArtistSearch SearchArtists(string search, string offset = "0", string limit = "20")
        {
            return Getter(search: search, offset: offset, limit: limit, type: "artist").Result.artists;
        }

        public AlbumSearch SearchAlbums(string search, string offset = "0", string limit = "20")
        {
            return Getter(search: search, offset: offset, limit: limit, type: "album").Result.albums;
        }

        public SongSearch SearchTracks(string search, string offset = "0", string limit = "20")
        {
            return Getter(search: search, offset: offset, limit: limit, type: "track").Result.tracks;
        }

        public class tracklistholder
        {
            public string href { get; set; }
            public List<Song> items { get; set; }
        }

        public async Task<List<Song>> GetFullAlbum(string albumid)
        {

            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    var serializer = new DataContractJsonSerializer(typeof(tracklistholder));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync("https://api.spotify.com/v1/albums/" + albumid + "/tracks");

                    HttpResponseMessage response = await client.GetAsync("https://api.spotify.com/v1/albums/" + albumid + "/tracks");
                    tracklistholder album = null;
                    album = serializer.ReadObject(streamTask) as tracklistholder;
                    return album.items;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }
        }



        public async Task<ArtistAlbumsHolder> GetArtistAlbums(string id, string offset = "0", string limit = "20")
        {
            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    string apilink = "https://api.spotify.com/v1/artists/" + id + "/albums?offset=" + offset + "&limit=" + limit + "&album_type=single,album,compilation,appears_on,ep";

                    var serializer = new DataContractJsonSerializer(typeof(ArtistAlbumsHolder));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync(apilink);

                    HttpResponseMessage response = await client.GetAsync(apilink);
                    ArtistAlbumsHolder holder = null;
                    holder = serializer.ReadObject(streamTask) as ArtistAlbumsHolder;
                    return holder;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }
        }

        public class TopTracksHolder
        {
            public List<Song> tracks { get; set; }
        }

        public async Task<List<Song>> GetTopTracks(string artistid, string region = "NO")
        {
            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    string apilink = "https://api.spotify.com/v1/artists/" + artistid + "/top-tracks?country=" + region;

                    var serializer = new DataContractJsonSerializer(typeof(TopTracksHolder));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync(apilink);

                    HttpResponseMessage response = await client.GetAsync(apilink);
                    TopTracksHolder holder = null;
                    holder = serializer.ReadObject(streamTask) as TopTracksHolder;
                    return holder.tracks;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }

        }

        public async Task<Artist> OneArtist(string artistid)
        {
            using (var client = new HttpClient())
            {
                try
                {
                    spotifyKey = GetToken().Result;
                    string apilink = "https://api.spotify.com/v1/artists/" + artistid;

                    var serializer = new DataContractJsonSerializer(typeof(Artist));
                    client.DefaultRequestHeaders.Add("Authorization", spotifyKey);
                    var streamTask = await client.GetStreamAsync(apilink);

                    HttpResponseMessage response = await client.GetAsync(apilink);
                    Artist holder = null;
                    holder = serializer.ReadObject(streamTask) as Artist;
                    return holder;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }

        }



    }
}