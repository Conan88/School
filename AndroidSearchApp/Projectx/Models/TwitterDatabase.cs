
using System.Collections.Generic;

namespace Projectx
{
    public class Tweets
    {
        public List<Statuses> statuses { get; set; }
        public Search_metadata search_metadata { get; set; }
    }

    public class Statuses
    {
        public string created_at { get; set; }
        public ulong id { get; set; }
        public string id_str { get; set; }
        public string text { get; set; }
        public bool truncated { get; set; }
        // public Entities entities { get; set; }
        // public Extended_entities extended_entities { get; set; }
        // public Metadata metadata { get; set; }
        public string source { get; set; }
        //public ulong in_reply_to_status_id { get; set; } <----------gives error
        public string in_reply_to_status_id_str { get; set; }
        //public ulong in_reply_to_user_id { get; set; } <----------gives error
        public string in_reply_to_user_id_str { get; set; }
        public string in_reply_to_screen_name { get; set; }
        public User user { get; set; }
        //public ulong geo { get; set; } <----------gives error
        //public ulong coordinates { get; set; } <----------gives error
        public string place { get; set; }
        public string contributors { get; set; }
        // public Retweeted_status retweeted_status { get; set; }
        //public bool is_quote_status { get; set; }
        public ulong retweet_count { get; set; }
        public ulong favorite_count { get; set; }
        //public bool favorited { get; set; }
        //public bool retweeted { get; set; }
        //public bool possibly_sensitive { get; set; }
        public string lang { get; set; }
    }

    public class Search_metadata
    {
        public double completed_in { get; set; }
        public ulong max_id { get; set; }
        public string max_id_str { get; set; }
        public string next_results { get; set; }
        public string query { get; set; }
        public string refresh_url { get; set; }
        public ulong count { get; set; }
        public ulong since_id { get; set; }
        public string since_id_str { get; set; }
    }

    public class Entities
    {
        public List<Hashtags> hashtags { get; set; }
        public string[] symbols { get; set; }
        public List<User_mentions> user_mentions { get; set; }
        public string[] urls { get; set; }
        public List<Media> media { get; set; }
        public Description description { get; set; }
    }

    public class Hashtags
    {
        public string text { get; set; }
        public ulong[] indices { get; set; }
    }

    public class User_mentions
    {
        public string screen_name { get; set; }
        public string name { get; set; }
        public ulong id { get; set; }
        public string id_str { get; set; }
        public ulong[] indices { get; set; }
    }

    public class Media
    {
        public ulong id { get; set; }
        public string id_str { get; set; }
        public ulong[] indices { get; set; }
        public string media_url { get; set; }
        public string media_url_https { get; set; }
        public string url { get; set; }
        public string display_url { get; set; }
        public string expanded_url { get; set; }
        public string type { get; set; }
        public Sizes sizes { get; set; }
        public ulong source_status_id { get; set; }
        public string source_status_id_str { get; set; }
        public ulong source_user_id { get; set; }
        public string source_user_id_str { get; set; }
    }

    public class Sizes
    {
        public Large large { get; set; }
        public Small small { get; set; }
        public Thumb thumb { get; set; }
        public Medium medium { get; set; }
    }

    public class Large
    {
        public ulong w { get; set; }
        public ulong h { get; set; }
        public string resize { get; set; }
    }

    public class Small
    {
        public ulong w { get; set; }
        public ulong h { get; set; }
        public string resize { get; set; }
    }

    public class Thumb
    {
        public ulong w { get; set; }
        public ulong h { get; set; }
        public string resize { get; set; }
    }

    public class Medium
    {
        public ulong w { get; set; }
        public ulong h { get; set; }
        public string resize { get; set; }
    }

    public class Extended_entities
    {
        public Media media { get; set; }
    }

    public class Metadata
    {
        public string iso_language_code { get; set; }
        public string result_type { get; set; }
    }

    public class User
    {
        public string screen_name { get; set; }
        public string name { get; set; }
        public ulong id { get; set; }
        public string id_str { get; set; }
        public string location { get; set; }
        public string description { get; set; }
        public string url { get; set; }
        /*//public Entities entities { get; set; }
        //public bool @protected { get; set; }
        public ulong followers_count { get; set; }
        public ulong friends_count { get; set; }
        public ulong listed_count { get; set; }
        public string created_at { get; set; }
        public ulong favorites_count { get; set; }
        public ulong utc_offset { get; set; }
        public string timezone { get; set; }
        //public bool geo_enabled { get; set; }
        //public bool verified { get; set; }
        public ulong statuses_count { get; set; }
        public string lang { get; set; }
        //public bool contributers_enabled { get; set; }
        //public bool is_translator { get; set; }
        //public bool is_translation_enabled { get; set; }
        public string profile_background_color { get; set; }
        public string profile_background_image_url { get; set; }
        public string profile_background_image_url_https { get; set; }
        public string profile_background_title { get; set; }
        public string profile_image_url { get; set; }
        public string profile_image_url_https { get; set; }
        public string profile_banner_url { get; set; }
        public string profile_link_color { get; set; }
        public string profile_sidebar_border_color { get; set; }
        public string profile_sidebar_fill_color { get; set; }
        public string profile_text_color { get; set; }
        /*public bool profile_use_background_image { get; set; }
        public bool has_extended_profile { get; set; }
        public bool default_profile { get; set; }
        public bool default_profile_image { get; set; }
        public bool following { get; set; }
        public bool follow_request_sent { get; set; }
        public bool notification { get; set; }
        public string translator_type { get; set; }*/
    }

    public class Retweeted_status
    {
        public string created_at { get; set; }
        public ulong id { get; set; }
        public string id_str { get; set; }
        public string text { get; set; }
        public bool truncated { get; set; }
        public Entities entities { get; set; }
        public Extended_entities extended_entities { get; set; }
        public Metadata metadata { get; set; }
        public string source { get; set; }
        public ulong in_reply_to_status_id { get; set; }
        public string in_reply_to_status_id_str { get; set; }
        public ulong in_reply_to_user_id { get; set; }
        public string in_reply_to_user_id_str { get; set; }
        public string in_reply_to_screen_name { get; set; }
        public User user { get; set; }
        public ulong geo { get; set; }
        public ulong coordinates { get; set; }
        public string place { get; set; }
        public string contributors { get; set; }
        public bool is_quote_status { get; set; }
        public ulong retweet_count { get; set; }
        public ulong favorite_count { get; set; }
        public bool favorited { get; set; }
        public bool retweeted { get; set; }
        public bool possibly_sensitive { get; set; }
        public string lang { get; set; }
    }

    public class Description
    {
        public string[] urls { get; set; }
    }
}