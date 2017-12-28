import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { ApiService } from "../../providers/api-service";
import { Storage } from '@ionic/storage';
import { PopoverController, NavParams } from 'ionic-angular';

import { MoviePage } from "../itempages/movie/movie";
import { ArtistPage } from "../itempages/artist/artist";
import { AlbumPage } from "../itempages/album/album";
import { TrackPage } from "../itempages/track/track";
import { GamePage } from "../itempages/game/game";

import { MovieSearchPage } from "../singlesearch/moviesearch/moviesearch";
import { ArtistSearchPage } from "../singlesearch/artistsearch/artistsearch";
import { AlbumSearchPage } from "../singlesearch/albumsearch/albumsearch";
import { TrackSearchPage } from "../singlesearch/tracksearch/tracksearch";
import { GameSearchPage } from "../singlesearch/gamesearch/gamesearch";

import { IntroPage } from '../intro/intro';
import { ArtistPop } from "../popoverpages/artistpop/artistpop";
import { AlbumPop } from "../popoverpages/albumpop";
import { TrackPop } from "../popoverpages/trackpop";
import { MoviePop } from "../popoverpages/moviepop";
import { GamePop } from "../popoverpages/gamepop";

import { Http, Headers } from '@angular/http';



@Component({
  selector: 'page-search',
  templateUrl: 'search.html'
})
export class SearchPage
{

  public filterop: boolean = false;
  public searchmovies: boolean = true;
  public searchartists: boolean = true;
  public searchalbums: boolean = true;
  public searchtracks: boolean = true;
  public searchgames: boolean = true;

  public val: string = null;
  public everything: any;
  public tes: any = "jf";

  public searchingText: string = "Search";

  public searchedyet: boolean = false;


  constructor(public navCtrl: NavController, public apiservice: ApiService, public storage: Storage, private popoverCtrl: PopoverController, public http: Http)
  {

  }

  ionViewDidLoad()
  {
    this.storage.get('intro-done').then(done =>
    {
      if (!done)
      {
        this.storage.set('intro-done', true);
        this.navCtrl.setRoot(IntroPage);
      }
    });
  }

  getItems(ev)
  {
    // set val to the value of the ev target
    this.val = ev.target.value;
    this.everything = [];
    if (this.val != "")
    {
      this.searchingText = "Searching...";
      this.apiservice.generalsearch(this.val)
        .then(data =>
        {
          this.everything = data;
          this.searchingText = "Search";
        });
    } else
    {
      this.searchingText = "Search";
      this.everything = [];
    }
  }

  movieTapped(event, movie)
  {
    this.navCtrl.push(MoviePage, {
      movie: movie
    });
  }

  artistTapped(event, artist)
  {
    this.navCtrl.push(ArtistPage, {
      artist: artist
    });
  }

  trackTapped(event, track)
  {
    this.navCtrl.push(TrackPage, {
      track: track
    });
  }

  albumTapped(event, album)
  {
    this.navCtrl.push(AlbumPage, {
      album: album
    });
  }

  seeMoreMovies(event, movielist)
  {
    if (this.val != null)
      this.navCtrl.push(MovieSearchPage, {
        movielist: movielist,
        searchterm: this.val,
        pagenr: 1
      });
  }

  seeMoreArtists(event, artistlist)
  {
    if (this.val != null)
    {
      this.navCtrl.push(ArtistSearchPage, {
        artistlist: artistlist, searchterm: this.val
      });
    }
  }

  seeMoreAlbums(event, albumlist)
  {
    if (this.val != null)
      this.navCtrl.push(AlbumSearchPage, {
        albumlist: albumlist, searchterm: this.val
      });
  }

  seeMoreTracks(event, tracklist)
  {
    if (this.val != null)
      this.navCtrl.push(TrackSearchPage, {
        tracklist: tracklist, searchterm: this.val
      });
  }

  moviefilter()
  {
    if (this.searchmovies == true)
    {
      this.searchmovies = false;
    } else
    {
      this.searchmovies = true;
    }
  }

  artistfilter()
  {
    if (this.searchartists == true)
    {
      this.searchartists = false;
    } else
    {
      this.searchartists = true;
    }
  }

  albumfilter()
  {
    if (this.searchalbums == true)
    {
      this.searchalbums = false;
    } else
    {
      this.searchalbums = true;
    }
  }

  trackfilter()
  {
    if (this.searchtracks == true)
    {
      this.searchtracks = false;
    } else
    {
      this.searchtracks = true;
    }
  }

  gamefilter()
  {
    if (this.searchgames == true)
    {
      this.searchgames = false;
    } else
    {
      this.searchgames = true;
    }
  }

  togglefilter()
  {
    if (this.filterop == true)
    {
      this.filterop = false;
    } else
    {
      this.filterop = true;
    }
  }

  artistoptions(event, artist)
  {
    let popover = this.popoverCtrl.create(ArtistPop, {
      artist: artist
    });
    popover.present({
      ev: event
    });
  }

  albumoptions(event, album)
  {
    let popover = this.popoverCtrl.create(AlbumPop, {
      album: album
    });
    popover.present({
      ev: event
    });
  }

  trackoptions(event, track)
  {
    let popover = this.popoverCtrl.create(TrackPop, {
      track: track
    });
    popover.present({
      ev: event
    });
  }

  movieoptions(event, movie)
  {
    let popover = this.popoverCtrl.create(MoviePop, {
      movie: movie
    });
    popover.present({
      ev: event
    });
  }

  gameTapped(event, game)
  {
    this.navCtrl.push(GamePage, {
      game: game
    });
  }

  gameoptions(event, game)
  {
    let popover = this.popoverCtrl.create(GamePop, {
      game: game
    });
    popover.present({
      ev: event
    });
  }

  seeMoreGames(event, gamelist)
  {
    if (this.val != null)
      this.navCtrl.push(GameSearchPage, {
        gamelist: gamelist,
        searchterm: this.val,
        pagenr: 1
      });
  }

  //Denne funksjonen konverterer fra UNIX tidsformat til vanlig tidsregning og gir ut år
  timeConverter(UNIX_timestamp){
    var a = new Date(UNIX_timestamp);
    var months = ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'];
    var year = a.getFullYear();
    var month = months[a.getMonth()];
    var date = a.getDate();
    var hour = a.getHours();
    var min = a.getMinutes() < 10 ? '0' + a.getMinutes() : a.getMinutes(); var sec = a.getSeconds() < 10 ? '0' + a.getSeconds() : a.getSeconds();
    var time = year ;
    return time;
  }

  rating(ratingDouble){
    var rating = ratingDouble;
    var ratingRounded = Math.round(rating);
    if (ratingRounded != 0) return "Rated "+ratingRounded+"/100";
    else return null;
  }

}
