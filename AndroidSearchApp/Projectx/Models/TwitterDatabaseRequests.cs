
using System;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Runtime.Serialization.Json;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;


namespace Projectx
{
    public class RequestTwitter
    {
        const string baseUrl = "https://api.twitter.com/1.1/search/tweets.json";
        const string oauth_consumer_key = "YOUR KEY";
        const string oauth_consumer_secret = "YOUR KEY";
        const string oauth_token = "YOUR KEY";
        const string oauth_token_secret = "YOUR KEY";
        const string bearer = "YOUR KEY";
        const string oauth_signature_method = "HMAC-SHA1";
        const string oauth_version = "1.0";

        //This class gets all them tweets
        public async Task<Tweets> GetTweets(string twitterSearch)
        {
            var client = new HttpClient();
            var serializer = new DataContractJsonSerializer(typeof(Tweets));

            var timespan = DateTime.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc);
            var oauth_timestamp = Convert.ToInt64(timespan.TotalSeconds).ToString();

            var oauth_nonce = Convert.ToBase64String(
                new ASCIIEncoding().GetBytes(DateTime.Now.Ticks.ToString())
            );


            var baseFormat = "oauth_consumer_key={0}&oauth_nonce={1}&oauth_signature_method={2}" +
                "&oauth_timestamp={3}&oauth_token={4}&oauth_version={5}&query={6}";


            var urlParameters = string.Format(baseFormat,
                            oauth_consumer_key,
                            oauth_nonce,
                            oauth_signature_method,
                            oauth_timestamp,
                            oauth_token,
                            oauth_version,
                            twitterSearch
                            );

            var twitterUrl =
            "oauth_consumer_key=" + oauth_consumer_key
            + "&oauth_token=" + oauth_token
            + "&oauth_signature_method=" + oauth_signature_method
            + "&oauth_timestamp=" + oauth_timestamp
            + "&oauth_nonce=" + oauth_nonce
            + "&oauth_version=" + oauth_version
            + "&q=" + twitterSearch;

            twitterUrl = string.Concat(Uri.EscapeDataString(baseUrl),
                         "&", Uri.EscapeDataString(twitterUrl));


            //This will be the key used later in the HMAC-SHA1 hashing algorithm, and consists of the secret consumer key and the secret token key
            var compositeKey = string.Concat(Uri.EscapeDataString(oauth_consumer_secret), "&", Uri.EscapeDataString(oauth_token_secret));

            //Concaternation of all request elements sorted lexicographically (basically alphabetically) on the parameter name
            var signatureBaseString = string.Concat(
                "GET&",
                Uri.EscapeDataString(baseUrl),
                "&oauth_consumer_key=", Uri.EscapeDataString(oauth_consumer_key),
                "&oauth_nonce=", Uri.EscapeDataString(oauth_nonce),
                "&oauth_signature_method=", Uri.EscapeDataString(oauth_signature_method),
                "&oauth_timestamp=", Uri.EscapeDataString(oauth_timestamp),
                "&oauth_token=", Uri.EscapeDataString(oauth_token)
            );

            signatureBaseString = Uri.EscapeDataString(signatureBaseString);

            //HMAC-SHA1 hashing algorithm converts signatureBaseString to a hashed string, with compositeKey
            string hashed;
            using (HMACSHA1 hasher = new HMACSHA1(ASCIIEncoding.ASCII.GetBytes(compositeKey)))
            {
                hashed = Convert.ToBase64String(
                    hasher.ComputeHash(ASCIIEncoding.ASCII.GetBytes(signatureBaseString)));
            }

            string oauth_signature = Uri.EscapeDataString(hashed);

            twitterUrl = RequestTwitter.baseUrl + "?"
             + "oauth_consumer_key=" + oauth_consumer_key
             + "&oauth_token=" + oauth_token
             + "&oauth_signature_method=" + oauth_signature_method
             + "&oauth_timestamp=" + oauth_timestamp
             + "&oauth_nonce=" + oauth_nonce
             + "&oauth_version=" + oauth_version
             + "&oauth_signature=" + oauth_signature
             + "&q=" + twitterSearch;

            client.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", bearer);
            client.DefaultRequestHeaders.Add("Accept", "application/json");

            var streamTask = await client.GetStreamAsync(twitterUrl);

            //HttpResponseMessage response = await client.GetAsync(twitterUrl);

            Tweets tweets = null;
            Console.WriteLine("\n\n" + twitterUrl + "\n\n");
            try
            {
                tweets = serializer.ReadObject(streamTask) as Tweets;
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
            return tweets;
        }
    }
}