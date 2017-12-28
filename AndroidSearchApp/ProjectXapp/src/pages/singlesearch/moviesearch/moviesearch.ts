import { Component } from '@angular/core';
import { NavController, NavParams, PopoverController } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { MoviePage } from "../../itempages/movie/movie";
import { MoviePop } from "../../popoverpages/moviepop";

@Component({
  selector: 'page-moviesearch',
  templateUrl: 'moviesearch.html'
})
export class MovieSearchPage {

  selectedItem: any;
  newsearch: any;
  searchterm: string;
  offset: number;
  limit: number;
  pagenr: number;
  

  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, private popoverCtrl: PopoverController) {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('movielist');
    console.log(this.selectedItem);
    this.searchterm = this.navParams.get('searchterm');
    this.pagenr = this.navParams.get('pagenr');
  }

  movieTapped(event, movie) {
    this.navCtrl.push(MoviePage, {
      movie: movie
    });
  }

  prevpage(){
    if(this.pagenr > 1){
      this.navCtrl.pop();
    }
  }

  nextpage(){
    if(this.pagenr < 100){
      this.apiservice.searchmovies(this.searchterm, this.pagenr + 1)
        .then(data =>
        {
          this.newsearch = data;
          this.newsearch = this.newsearch;
          this.navCtrl.push(MovieSearchPage, {
            movielist: this.newsearch,
            searchterm: this.searchterm,
            pagenr: this.pagenr + 1
          });
        });
    }
  }

  movieoptions(event, movie){
    let popover = this.popoverCtrl.create(MoviePop, {
      movie: movie
    });
    popover.present({
      ev: event
    });
  }
  
}
