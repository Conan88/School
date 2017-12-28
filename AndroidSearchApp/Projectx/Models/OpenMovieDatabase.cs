using System.Runtime.Serialization;
using System;
using System.Globalization;
using System.Collections.Generic;
/*
    Model for open movie database
    NB, do not change the names in this file, they corresponds to the api names from the open movie database
 */
namespace Projectx
{
    //SearchResult contains a list of Movies
    public class SearchResultMovies
    {
        public List<Movie> Search { get; set; }

        public int totalResult { get; set; }

        public string Response { get; set; }
    }

    //Movies contains a list of MovieRatings
    public class Movie
    {
        public List<MovieRatings> Ratings { get; set; }
        public string Title { get; set; }
        public string Year { get; set; }
        public string Rated { get; set; }
        public string Released { get; set; }
        public string Runtime { get; set; }
        public string Genre { get; set; }
        public string Director { get; set; }
        public string Writer { get; set; }
        public string Actors { get; set; }
        public string Plot { get; set; }
        public string Language { get; set; }
        public string Country { get; set; }
        public string Awards { get; set; }
        public string Poster { get; set; }
        public string Metascore { get; set; }
        public string imdbRating { get; set; }
        public string imdbVotes { get; set; }
        public string imdbID { get; set; }
        public string Type { get; set; }
        public string Response { get; set; }
    }

    public class MovieRatings
    {
        public string Source { get; set; }
        public string Value { get; set; }

    }
}