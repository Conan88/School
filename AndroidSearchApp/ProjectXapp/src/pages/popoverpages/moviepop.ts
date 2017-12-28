import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  template: `
    <ion-list>
      <a href="http://www.imdb.com/">
        <ion-item>Open IMDb page</ion-item>
      </a>
    </ion-list>
  `
})
export class MoviePop {

    imdb: string;
    movie: any;
  constructor(public navCtrl: NavController,public navParams: NavParams) {
      this.movie = navParams.get("movie");
      this.imdb = this.movie;
  }

}
