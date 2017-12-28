import { Component } from '@angular/core';
import { NavController, NavParams, PopoverController } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { GamePage } from "../../itempages/game/game";
import { GamePop } from "../../popoverpages/gamepop";

@Component({
  selector: 'page-gamesearch',
  templateUrl: 'gamesearch.html'
})
export class GameSearchPage {

  selectedItem: any;
  newsearch: any;
  searchterm: string;
  pagenr: number;
  

  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, private popoverCtrl: PopoverController) {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('gamelist');
    this.searchterm = this.navParams.get('searchterm');
    this.pagenr = this.navParams.get('pagenr');
  }

  gameTapped(event, game){
    this.navCtrl.push(GamePage, {
      game: game
    });
  }

  prevpage(){
    if(this.pagenr > 1){
      this.navCtrl.pop();
    }
  }

  nextpage(){
    if(this.pagenr < 100){
      this.apiservice.searchgames(this.searchterm, this.pagenr)
        .then(data =>
        {
          this.newsearch = data;
          this.newsearch = this.newsearch;
          this.navCtrl.push(GameSearchPage, {
            gamelist: this.newsearch,
            searchterm: this.searchterm,
            pagenr: this.pagenr + 1
      });
        });
    }
  }

  gameoptions(event, game){
    let popover = this.popoverCtrl.create(GamePop, {
      game: game
    });
    popover.present({
      ev: event
    });
  }

  //Denne funksjonen konverterer fra UNIX tidsformat til vanlig tidsregning og gir ut dag, måned, år
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
