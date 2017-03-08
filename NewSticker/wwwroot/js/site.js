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
        refresh: function() {
            this.$http.get('/api/sticker').then(function(response) {
                this.news = response.body.reverse();
                console.log(response);
            });
        }
    }
})