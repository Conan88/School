// Write your Javascript code.
new Vue({
    el: '#app',
    data: {
        news: [],
        inputHeader: '',
        inputText: '',
        inputUrl: '',

        articles: [],
        articlesCNN: [],
        url: 'https://www.google.com',
        headBBC: 'BBC News',
        headCNN: 'CNN News',
    },
    mounted: function() {
        setInterval(this.refresh, 1000);
        this.refresh();

        console.log('mounted workes');
        this.$http.get('/api/sticker').then(function(response) {
            this.news = response.body.reverse();
            console.log(response);
        });
        console.log('this is a second vue app');
        this.$http.get('https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=6508abdd35e74474aa46920aee671081').then(function(response) {
            this.articles = response.body.articles;
            console.log(response);
            console.log('inside bbc-api');
        });
        console.log('this is a third vue app');
        this.$http.get('https://newsapi.org/v1/articles?source=cnn&sortBy=top&apiKey=6508abdd35e74474aa46920aee671081').then(function(response) {
            this.articlesCNN = response.body.articles;
            console.log(response);
            console.log('inside CNN-api');
        });
    },
    methods: {
        addNews: function() {
            if (this.inputHeader.length === 0 || this.inputText.length === 0) return false;

            var data = {
                header: this.inputHeader,
                text: this.inputText,
                url: this.inputUrl
            };
            this.$http.post('/api/sticker', data).then(function(response) {
                this.news.push(response.body);
                this.news = '';
                this.inputHeader = '';
                this.inputText = '';
                this.inputUrl = '';
                this.$http.get('/api/sticker').then(function(response) {
                    this.news = response.body.reverse();
                    console.log(response);
                });
            });
        },
        updateNews: function(n) {
            console.log("Update news");
            var changedData = {
                header: this.inputHeader,
                id: n.id,
                text: this.inputText,
                url: this.inputUrl
            }
            console.log("ID is: " + n.id);
            this.$http.put('/api/sticker/' + n.id, changedData).then(function() {

            });
        },
        deleteNews: function(n) {

            var answer = confirm("Delete post?")
            if (answer) {
                console.log("Delete news" + " " + n.id);
                this.$http.delete('/api/sticker/' + n.id).then(function(response) {

                });
            } else {
                //some code
            }

        },
        refresh: function() {
            this.$http.get('/api/sticker').then(function(response) {
                this.news = response.body.reverse();
            });
        }
    }
})