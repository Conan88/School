import { Component } from '@angular/core';
import { NavController, NavParams, PopoverController } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { TrackPage } from "../../itempages/track/track";
import { TrackPop } from "../../popoverpages/trackpop";

@Component({
  selector: 'page-tracksearch',
  templateUrl: 'tracksearch.html'
})
export class TrackSearchPage {

  selectedItem: any;
  newsearch: any;
  searchterm: string;
  offset: number;
  limit: number;
  pagenr: number;
  prevactive: boolean = true;
  nextactive: boolean = true;


  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, private popoverCtrl: PopoverController) {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('tracklist');
    this.searchterm = this.navParams.get('searchterm');
    this.pagenr = (this.selectedItem.offset/this.selectedItem.limit) + 1;
    if(this.selectedItem.previous == null){
      this.prevactive = false;
    }
    if(this.selectedItem.next == null){
      this.nextactive = false;
    }
    
  }

  trackTapped(event, track) {
    this.navCtrl.push(TrackPage, {
      track: track
    });
  }

  prevpage(){
    if(this.selectedItem.previous == null){
      console.log("prev page does not exist");
    }else{
      this.navCtrl.pop();
    }
  }

  nextpage(){
    if(this.selectedItem.next == null){
      console.log("next page does not exist");
    }else{
      this.limit = this.selectedItem.limit;
      this.offset = this.selectedItem.offset + this.limit;
      this.apiservice.searchtrack(this.searchterm, ""+this.offset, ""+this.limit)
        .then(data =>
        {
          this.newsearch = data;
          this.navCtrl.push(TrackSearchPage, {
            tracklist: this.newsearch, searchterm: this.searchterm
          });
        });
      
    }
  }

  trackoptions(event, track){
    let popover = this.popoverCtrl.create(TrackPop, {
      track: track
    });
    popover.present({
      ev: event
    });
  }

}
