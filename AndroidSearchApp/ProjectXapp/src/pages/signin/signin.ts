import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { PeopleService } from "../../providers/people-service";
import { PersonPage } from "../itempages/person/person";

@Component({
  selector: 'page-signin',
  templateUrl: 'signin.html'
})
export class SignInPage {

public val:string;
public val2:any;
public name:string = "Idiot"
public people:any;

  constructor(public navCtrl: NavController, public peopleservice:PeopleService) {
    
  }

  getItems(ev) {
    // set val to the value of the ev target
    this.val = ev.target.value;
    this.people = [];
    if(this.val != ""){
      this.peopleservice.load(this.val)
      .then(data => {
        this.people = data;
    });
    }
  }

  itemTapped(event, person) {
    this.navCtrl.push(PersonPage, {
      person: person
    });
  }
  
}
