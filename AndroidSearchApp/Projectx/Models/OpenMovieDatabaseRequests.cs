using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;

/*
    This file containes the request classes, that actualy sends the requests. 
    If we have time we should unit test this one.
 */
namespace Projectx
{
    public class Requests
    {
        const string omdbUrl = "http://www.omdbapi.com/?apikey='YOUR KEY'";
        public string omdbKey;
        public Movie newMovie;
        public SearchResultMovies searchResultMovies;

        /*
            This class gets all the info about a movie, and its ratings. Uses imdbId for getting the correct movie.
         */

         
        public async Task<Movie> GetMovie(string imdbId)
        {
            using (var client = new HttpClient())
            {
                try
                {
                    var serializer = new DataContractJsonSerializer(typeof(Movie));
                    var streamTask = await client.GetStreamAsync(omdbUrl + "i=" + imdbId);
                    HttpResponseMessage response = await client.GetAsync(omdbUrl + "i=" + imdbId);
                    Movie movie = null;
                    movie = serializer.ReadObject(streamTask) as Movie;
                    return movie;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return null;
                }
            }
        }

        /*
            This function gets a list of movies, and limited information about it.
         */
        public async Task<List<Movie>> GetMovieList(string query, string page = "1")
        {
            using (var client = new HttpClient())
            {
                try
                {
                    var serializer = new DataContractJsonSerializer(typeof(SearchResultMovies));
                    var streamTask = await client.GetStreamAsync(omdbUrl + "s=" + query + "&page=" + page);
                    SearchResultMovies movie = null;
                    movie = serializer.ReadObject(streamTask) as SearchResultMovies;
                    return movie.Search;
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