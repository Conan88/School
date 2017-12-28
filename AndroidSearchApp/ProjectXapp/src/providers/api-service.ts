import { Injectable } from '@angular/core';
import { Http, RequestOptions } from '@angular/http';
import 'rxjs/add/operator/map';

/*
  Generated class for the MovieService provider.

  See https://angular.io/docs/ts/latest/guide/dependency-injection.html
  for more info on providers and Angular 2 DI.
*/
@Injectable()
export class ApiService
{

  private data: any;
  private data2: any;
  public base: string = "https://projectx2017.azurewebsites.net";
  public basea: string = "http://localhost:5000";


  constructor(public http: Http)
  {
    console.log('Hello MovieService Provider');
  }

  tokentest()
  {
    return new Promise(resolve =>
    {

      let headers = new Headers({ 'Authorization': 'YOUR KEY' });
      let options = new RequestOptions(headers);

      this.http.post('https://accounts.spotify.com/api/token',
        "grant_type=client_credentials",
        options)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  generalsearch(search: string)
  {
    /*
    // when using promise. Retains old data when recalling. Should switch to using 
    // observable but i dont get it.
  if (this.data) {
    // already loaded data
    return Promise.resolve(this.data);
  }
*/
    // don't have the data yet
    return new Promise(resolve =>
    {
      // We're using Angular HTTP provider to request the data,
      // then on the response, it'll map the JSON data to a parsed JS object.
      // Next, we process the data and resolve the promise with the new data.
      this.http.get(this.base + '/api/spider?input=' + search)
        //this.http.get('http://localhost:5000/api/spider?input=' + search)

        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data = data;
          resolve(this.data);
        });
    });
  }

  getmovie(imdbid: string)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/spider/' + imdbid)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  getalbumtracklist(albumid: string)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/music?albumid=' + albumid)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  gettoptracks(artistid: string)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/toptracks?artistid=' + artistid)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  getartistalbums(artistid: string, offset: string = "0", limit: string = "20")
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/artistalbum?id=' + artistid
        + "&offset=" + offset + "&limit=" + limit)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  searchartist(search: string, offset: string = "0", limit: string = "20")
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/artist?search=' + search
        + "&offset=" + offset + "&limit=" + limit)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  searchalbum(search: string, offset: string = "0", limit: string = "20")
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/album?search=' + search
        + "&offset=" + offset + "&limit=" + limit)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  searchtrack(search: string, offset: string = "0", limit: string = "20")
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/track?search=' + search
        + "&offset=" + offset + "&limit=" + limit)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  getartist(artistid: string)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + "/api/artistdetail/artistid=" + artistid)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

  searchmovies(searchterm: string, pagenr: number)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/movie/?search=' + searchterm + "&page=" + pagenr)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }


  searchtweets(searchterm: string)
  {
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/twitter?input=' + searchterm)
      .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }
  
  searchgames(searchterm: string, pagenr: number)
  {
    let offset = pagenr*20;
    return new Promise(resolve =>
    {
      this.http.get(this.base + '/api/game/?search=' + searchterm + "&offset=" + offset)
        .map(res => res.json())
        .subscribe(data =>
        {
          // we've got back the raw data, now generate the core schedule data
          // and save the data for later reference
          this.data2 = data;
          resolve(this.data2);
        });
    });
  }

}
