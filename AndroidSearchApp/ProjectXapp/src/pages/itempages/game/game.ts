import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";

@Component({
  selector: 'page-game',
  templateUrl: 'game.html'
})
export class GamePage
{

  selectedItem: any;
  public game: any;
  public tweets: any;



  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService)
  {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('game');

    this.apiservice.searchtweets(this.selectedItem.title)
      .then(data =>
      {
        this.tweets = data;
        console.log(this.tweets);
      });
  }

  //Denne funksjonen konverterer fra UNIX tidsformat til vanlig tidsregning og gir ut dag, måned, år
  timeConverter(UNIX_timestamp){
    var a = new Date(UNIX_timestamp);
    var months = ['January','February','March','April','May','June','July','August','September','October','November','December'];
    var year = a.getFullYear();
    var month = months[a.getMonth()];
    var date = a.getDate();
    var hour = a.getHours();
    var min = a.getMinutes() < 10 ? '0' + a.getMinutes() : a.getMinutes(); var sec = a.getSeconds() < 10 ? '0' + a.getSeconds() : a.getSeconds();
    var time =  month + ' ' + date + ', ' + year ;
    return time;
  }

  rating(ratingDouble){
    var rating = ratingDouble;
    var ratingRounded = Math.round(rating);
    if (ratingRounded != 0) return "Rated "+ratingRounded+"/100";
    else return null;
  }

}
