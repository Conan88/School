import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { ArtistPage } from "../artist/artist";


@Component({
  selector: 'page-album',
  templateUrl: 'album.html'
})
export class AlbumPage
{

  selectedItem: any;
  tracklist: any;
  minutes: number;
  seconds: number;
  totalseconds: number;
  extraspace: string = "";
  public tweets: any;


  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService)
  {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('album');
    console.log(this.selectedItem);
    this.apiservice.getalbumtracklist(this.selectedItem.id)
      .then(data =>
      {
        this.tracklist = data;
        console.log(this.tracklist);
      });

    this.apiservice.searchtweets(this.selectedItem.title)
      .then(data =>
      {
        this.tweets = data;
        console.log(this.tweets);
      });
  }

  artistTapped(event, artist)
  {
    this.navCtrl.push(ArtistPage, {
      artist: artist
    });
  }

  toMinutes(ms)
  {
    this.totalseconds = (ms / 1000);
    this.totalseconds = Math.trunc(this.totalseconds);

    this.minutes = (this.totalseconds / 60);
    this.minutes = Math.trunc(this.minutes);

    this.seconds = this.totalseconds % 60;
    this.seconds = Math.trunc(this.seconds);

    if (this.seconds < 10)
    {
      this.extraspace = "0";
    } else
    {
      this.extraspace = "";
    }

    return ("" + this.minutes + ":" + this.extraspace + this.seconds);
  }
}
