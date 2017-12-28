import { Component } from '@angular/core';
import { NavController, NavParams, PopoverController } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { ArtistPage } from "../../itempages/artist/artist";
import { ArtistPop } from "../../popoverpages/artistpop/artistpop";

@Component({
  selector: 'page-artistsearch',
  templateUrl: 'artistsearch.html'
})
export class ArtistSearchPage {

  selectedItem: any;
  newsearch: any;
  searchterm: string;
  offset: number;
  limit: number;
  pagenr: number;
  

  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, private popoverCtrl: PopoverController) {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('artistlist');
    this.searchterm = this.navParams.get('searchterm');
    this.pagenr = (this.selectedItem.offset/this.selectedItem.limit) + 1;
  }

  artistTapped(event, artist) {
    this.navCtrl.push(ArtistPage, {
      artist: artist
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
      this.apiservice.searchartist(this.searchterm, ""+this.offset, ""+this.limit)
        .then(data =>
        {
          this.newsearch = data;
          this.navCtrl.push(ArtistSearchPage, {
            artistlist: this.newsearch, searchterm: this.searchterm
          });
        });
      
    }
  }

  artistoptions(event, artist){
    let popover = this.popoverCtrl.create(ArtistPop, {
      artist: artist
    });
    popover.present({
      ev: event
    });
  }

}
