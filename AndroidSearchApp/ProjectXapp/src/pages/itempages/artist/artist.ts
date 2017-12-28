import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";

import { AlbumPage } from "../album/album";

@Component({
  selector: 'page-artist',
  templateUrl: 'artist.html'
})
export class ArtistPage
{

  selectedItem: any;
  toptracks: any;
  albums: any;
  show: boolean = false;
  public tweets: any;



  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService)
  {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('artist');
    console.log(this.selectedItem);

    if (this.selectedItem.images == null)
    {
      this.apiservice.getartist(this.selectedItem.id)
        .then(data =>
        {
          this.selectedItem = data;
          console.log(this.selectedItem);
        });
    }

    this.apiservice.gettoptracks(this.selectedItem.id)
      .then(data =>
      {
        this.toptracks = data;
        console.log(this.toptracks);
      });

    this.apiservice.getartistalbums(this.selectedItem.id)
      .then(data =>
      {
        this.albums = data;
        console.log(this.albums);
      });

    this.apiservice.searchtweets(this.selectedItem.title)
      .then(data =>
      {
        this.tweets = data;
        console.log(this.tweets);
      });

  }

  albumTapped(event, album)
  {
    this.navCtrl.push(AlbumPage, {
      album: album
    });
  }

  openspot(event, href)
  {
    window.open(href);
  }

}
