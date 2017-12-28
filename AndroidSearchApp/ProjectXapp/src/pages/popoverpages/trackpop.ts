import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { TrackPage } from "../itempages/track/track";
import { ArtistPage } from "../itempages/artist/artist";
import { AlbumPage } from "../itempages/album/album";

@Component({
  template: `
    <ion-list>
      <ion-item (click)="gotoartist()">Go to artist page</ion-item>
      <ion-item (click)="gotoalbum()">Go to album page</ion-item>
      <a href={{spotify}}>
        <ion-item>Listen on spotify</ion-item>
      </a>
    </ion-list>
  `
})
export class TrackPop {

    spotify: string;
    track: any;
  constructor(public navCtrl: NavController,public navParams: NavParams) {
      this.track = navParams.get("track");
      this.spotify = this.track.external_urls.spotify;
  }

  gotoartist(){
      this.navCtrl.push(ArtistPage, {
      artist: this.track.artists[0]
    });
  }

  gotoalbum(){
      this.navCtrl.push(AlbumPage, {
      album: this.track.album
    });
  }

}
