import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ArtistPage } from "../itempages/artist/artist";

@Component({
  template: `
    <ion-list>
      <ion-item (click)="gotoartist()">Go to artist page</ion-item>
      <a href={{spotify}}>
        <ion-item>Open album in spotify</ion-item>
      </a>
    </ion-list>
  `
})
export class AlbumPop {

    spotify: string;
    album: any;
  constructor(public navCtrl: NavController,public navParams: NavParams) {
      this.album = navParams.get("album");
      this.spotify = this.album.external_urls.spotify;
  }

  gotoartist(){
      this.navCtrl.push(ArtistPage, {
      artist: this.album.artists[0]
    });
  }

}
