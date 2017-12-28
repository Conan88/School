
using System.Collections.Generic;

namespace Projectx
{
    public class SpotifyToken
    {
        public string access_token { get; set; }
        public string token_type { get; set; }
        public int expires_in { get; set; }

    }
    public class ArtistHolder
    {
        public ArtistSearch artists { get; set; }
        public AlbumSearch albums { get; set; }
        public SongSearch tracks { get; set; }
    }

    public class ArtistSearch
    {
        public string href { get; set; }
        public int limit { get; set; }
        public string next { get; set; }
        public int offset { get; set; }
        public string previous { get; set; }
        public int total { get; set; }
        public List<Artist> items { get; set; }
    }
    public class AlbumSearch
    {
        public string href { get; set; }
        public int limit { get; set; }
        public string next { get; set; }
        public int offset { get; set; }
        public string previous { get; set; }
        public int total { get; set; }
        public List<Album> items { get; set; }
    }

    public class SongSearch
    {
        public string href { get; set; }
        public int limit { get; set; }
        public string next { get; set; }
        public int offset { get; set; }
        public string previous { get; set; }
        public int total { get; set; }
        public List<Song> items { get; set; }
    }
    public class Artist
    {
        public string name { get; set; }
        public int popularity { get; set; }
        public string type { get; set; }
        public string uri { get; set; }
        public string id { get; set; }
        public string href { get; set; }
        public External_Urls external_urls { get; set; }
        public Followers followers { get; set; }
        public List<string> genres { get; set; }

        public List<ImageArtist> images { get; set; }
    }

    public class External_Urls
    {
        public string spotify { get; set; }
    }

    public class Followers
    {
        public string href { get; set; }
        public int total { get; set; }
    }

    public class Album
    {
        public string name { get; set; }
        public string id { get; set; }
        public string href { get; set; }
        public string uri { get; set; }
        public string album_type { get; set; }
        public List<Artist> artists { get; set; }
        public List<Song> tracks { get; set; }
        public string release_date { get; set; }
        public List<ImageAlbum> images { get; set; }
        public External_Urls external_urls { get; set; }
    }

    public class CopyRights
    {
        public string text { get; set; }
        public string type { get; set; }
    }

    public class Song
    {
        public string name { get; set; }
        public string id { get; set; }
        public string type { get; set; }
        public string href { get; set; }
        public string albumid { get; set; }
        public Album album { get; set; }
        public List<Artist> artists { get; set; }
        public List<ImageSong> images { get; set; }
        public External_Urls external_urls { get; set; }
        public string preview_url { get; set; }
        public bool? Explicit { get; set; }
        public int duration_ms { get; set; }
    }
    public class ImageArtist
    {
        public string height { get; set; }
        public string width { get; set; }
        public string url { get; set; }
    }
    public class ImageAlbum
    {
        public string height { get; set; }
        public string width { get; set; }
        public string url { get; set; }
    }
    public class ImageSong
    {
        public string height { get; set; }
        public string width { get; set; }
        public string url { get; set; }
    }

    public class ArtistAlbumsHolder
    {
        public string href { get; set; }
        public int limit { get; set; }
        public int offset { get; set; }
        public string next { get; set; }
        public string previous { get; set; }
        public int total { get; set; }
        public List<Album> items { get; set; }
    }
}