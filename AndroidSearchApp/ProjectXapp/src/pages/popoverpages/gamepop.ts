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
export class GamePop {
    
    game: any;
  constructor(public navCtrl: NavController,public navParams: NavParams) {
      this.game = navParams.get("game");
  }

}
