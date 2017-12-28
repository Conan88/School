import { Component } from '@angular/core';
import { NavController, NavParams, PopoverController } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { AlbumPage } from "../../itempages/album/album";
import { AlbumPop } from "../../popoverpages/albumpop";

@Component({
  selector: 'page-albumsearch',
  templateUrl: 'albumsearch.html'
})
export class AlbumSearchPage {

  selectedItem: any;
  newsearch: any;
  searchterm: string;
  offset: number;
  limit: number;
  pagenr: number;
  

  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, private popoverCtrl: PopoverController) {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('albumlist');
    this.searchterm = this.navParams.get('searchterm');
    this.pagenr = (this.selectedItem.offset/this.selectedItem.limit) + 1;
  }

  albumTapped(event, album) {
    this.navCtrl.push(AlbumPage, {
      album: album
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
      this.apiservice.searchalbum(this.searchterm, ""+this.offset, ""+this.limit)
        .then(data =>
        {
          this.newsearch = data;
          this.navCtrl.push(AlbumSearchPage, {
            albumlist: this.newsearch, searchterm: this.searchterm
          });
        });
      
    }
  }

  albumoptions(event, album){
    let popover = this.popoverCtrl.create(AlbumPop, {
      album: album
    });
    popover.present({
      ev: event
    });
  }

}
