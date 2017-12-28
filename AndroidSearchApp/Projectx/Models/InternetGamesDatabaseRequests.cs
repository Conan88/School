
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Runtime.Serialization.Json;
using System.Threading.Tasks;

/*
    This file containes the request classes, that actualy sends the requests. 
    If we have time we should unit test this one.
 */
namespace Projectx
{
    public class RequestIgdb
    {
        const string gamesUrl = "https://igdbcom-internet-game-database-v1.p.mashape.com/games/?fields=name%2Cslug%2Curl%2Csummary%2Cstoryline%2Crating%2Crating_count%2Caggregated_rating%2Cdevelopers%2Cpublishers%2Cgame_engines%2Ccategory%2Ckeywords%2Cgenres%2Cstatus%2Ccover%2Cscreenshots%2Cpegi%2Cfirst_release_date%2Cwebsites&search=";
        const string gamesTokenKey = "YOUR KEY";

        /*
            This class gets all the info about a game.
        */
        public async Task<List<Game>> GetGameList(string gameSearch, string offset = "0", string limit = "20")
        {
            using (var client = new HttpClient())
            {
                try
                {
                    var serializer = new DataContractJsonSerializer(typeof(List<Game>));

                    client.DefaultRequestHeaders.Add("X-Mashape-Key", gamesTokenKey);
                    client.DefaultRequestHeaders.Add("Accept", "application/json");

                    var streamTask = await client.GetStreamAsync(gamesUrl + gameSearch + "&offset=" + offset + "&limit=" + limit);

                    HttpResponseMessage response = await client.GetAsync(gamesUrl + gameSearch);
                    List<Game> games = null;
                    games = serializer.ReadObject(streamTask) as List<Game>;
                    return games;
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
