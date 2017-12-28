import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { ApiService } from "../../../providers/api-service";
import { SafeResourceUrl, DomSanitizer } from '@angular/platform-browser';
@Component({
  selector: 'page-movie',
  templateUrl: 'movie.html'
})
export class MoviePage
{

  selectedItem: any;
  public movie: any;
  public tweets: any;
  public youtubeUrl: string = /*"https://www.youtube.com/embed?listType=search&list="*/"https://www.youtube.com/embed/XGSy3_Czz8k";


  constructor(public navCtrl: NavController, public navParams: NavParams, public apiservice: ApiService, public sanitizer: DomSanitizer)
  {
    // If we navigated to this page, we will have an item available as a nav param
    this.selectedItem = navParams.get('movie');
    this.apiservice.getmovie(this.selectedItem.imdbID)
      .then(data =>
      {
        this.movie = data;
        console.log(this.movie);
      });

    this.apiservice.searchtweets(this.selectedItem.title)
      .then(data =>
      {
        this.tweets = data;
        console.log(this.tweets);
      });
  }
  updateVideoUrl()
  {
    // Appending an ID to a YouTube URL is safe.
    // Always make sure to construct SafeValue objects as
    // close as possible to the input data, so
    // that it's easier to check if the value is safe.

    let dangerousVideoUrl = 'https://www.youtube.com/embed?listType=search&list=' + this.selectedItem.title + 'trailer';
    return this.sanitizer.bypassSecurityTrustResourceUrl(dangerousVideoUrl);
  }
}
