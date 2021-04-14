
const express = require('express');
const getData = require('./getData');
const app = express();

app.use(express.json());

app.use(express.urlencoded({ extended : true})); //jey=value & key=value
app.use(express.static('public'));
app.use('/api/getData' , getData);





const port = process.env.PORT || 4000;
app.listen(port , () => console.log(`listening  ${port}...`));




