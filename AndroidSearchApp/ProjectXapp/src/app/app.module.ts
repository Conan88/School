import { NgModule, ErrorHandler } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { MyApp } from './app.component';
import { HttpModule, JsonpModule } from '@angular/http';
import { IonicStorageModule } from '@ionic/storage';


import { AboutPage } from '../pages/about/about';
import { ContactPage } from '../pages/contact/contact';
import { HomePage } from '../pages/home/home';
import { SignInPage } from '../pages/signin/signin';
import { TabsPage } from '../pages/tabs/tabs';

import { SearchPage } from "../pages/search/search";
import { MovieSearchPage } from "../pages/singlesearch/moviesearch/moviesearch";
import { ArtistSearchPage } from "../pages/singlesearch/artistsearch/artistsearch";
import { AlbumSearchPage } from "../pages/singlesearch/albumsearch/albumsearch";
import { TrackSearchPage } from "../pages/singlesearch/tracksearch/tracksearch";
import { GameSearchPage } from "../pages/singlesearch/gamesearch/gamesearch";

import { PersonPage } from "../pages/itempages/person/person";
import { MoviePage } from "../pages/itempages/movie/movie";
import { ArtistPage } from "../pages/itempages/artist/artist";
import { TrackPage } from "../pages/itempages/track/track";
import { AlbumPage } from "../pages/itempages/album/album";
import { IntroPage } from '../pages/intro/intro';
import { GamePage } from "../pages/itempages/game/game";

import { ArtistPop } from "../pages/popoverpages/artistpop/artistpop";
import { AlbumPop } from "../pages/popoverpages/albumpop";
import { TrackPop } from "../pages/popoverpages/trackpop";
import { MoviePop } from "../pages/popoverpages/moviepop";
import { GamePop } from "../pages/popoverpages/gamepop";

import { StatusBar } from '@ionic-native/status-bar';
import { SplashScreen } from '@ionic-native/splash-screen';
import { PeopleService } from "../providers/people-service";
import { ApiService } from "../providers/api-service";

@NgModule({
  declarations: [
    MyApp,
    AboutPage,
    ContactPage,
    HomePage,
    SignInPage,
    TabsPage,
    SearchPage,
    PersonPage,
    MoviePage,
    ArtistPage,
    AlbumPage,
    TrackPage,
    MovieSearchPage,
    ArtistSearchPage,
    AlbumSearchPage,
    TrackSearchPage,
    IntroPage,
    ArtistPop,
    AlbumPop,
    TrackPop,
    MoviePop,
    GamePop,
    GamePage,
    GameSearchPage
  ],
  imports: [
    BrowserModule,
    IonicModule.forRoot(MyApp),
    HttpModule,
    JsonpModule,
    IonicStorageModule.forRoot({ name: "databasenavn", driverOrder: ['indexeddb', 'sqlite', 'websql'] })
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    AboutPage,
    ContactPage,
    HomePage,
    SignInPage,
    TabsPage,
    SearchPage,
    PersonPage,
    MoviePage,
    ArtistPage,
    AlbumPage,
    TrackPage,
    MovieSearchPage,
    ArtistSearchPage,
    AlbumSearchPage,
    TrackSearchPage,
    IntroPage,
    ArtistPop,
    AlbumPop,
    TrackPop,
    MoviePop,
    GamePop,
    GamePage,
    GameSearchPage

  ],
  providers: [
    PeopleService,
    ApiService,
    StatusBar,
    SplashScreen,
    { provide: ErrorHandler, useClass: IonicErrorHandler }
  ]
})
export class AppModule { }
