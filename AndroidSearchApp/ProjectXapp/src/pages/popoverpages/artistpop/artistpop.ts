import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  template: `
    <ion-list>
      <a href={{spotify}}>
        <ion-item>Open artist in spotify</ion-item>
      </a>
    </ion-list>
  `
})
export class ArtistPop {

    spotify: string;
    artist: any;
  constructor(public navCtrl: NavController,public navParams: NavParams) {
      this.artist = navParams.get("artist");
      this.spotify = this.artist.external_urls.spotify;
  }

}
