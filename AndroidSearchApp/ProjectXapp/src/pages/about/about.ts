import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { SignInPage } from "../signin/signin";

@Component({
  selector: 'page-about',
  templateUrl: 'about.html'
})
export class AboutPage {

  signinPage = SignInPage;
  constructor(public navCtrl: NavController) {

  }

}
