import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";

@Component({
  selector: 'page-track',
  templateUrl: 'track.html'
})
export class TrackPage
{

  selectedItem: any;
  public tweets: any;


  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService)
  {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('track');
    this.apiservice.searchtweets(this.selectedItem.title)
      .then(data =>
      {
        this.tweets = data;
        console.log(this.tweets);
      });
  }
}
