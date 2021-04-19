const express = require('express');
const  router = express.Router();
const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost/FarmDemo' , { useNewUrlParser: true , useUnifiedTopology: true })
.then(() => console.log('connected to mongodb...'))
.catch(err => console.error('could not connect to mongo db...' , err));

const dataShema =  new mongoose.Schema({
    MacAddress : String,
    SoilTemperature : Number,
    SoilHumidity : Number, //key : index , value : string
    AirTemperature : Number,
    AirHumidity : Number
});

const Data = mongoose.model('farm1' , dataShema);

router.post('/postdata' , async function(req , res){
    const input = req.body;
    console.log(typeof(input));
    if(input[1] == undefined){
        const newData = Data({
            MacAddress : input.MacAddress,
            SoilTemperature : input.SoilTemperature,
            SoilHumidity : input.SoilHumidity ,
            AirTemperature : input.AirTemperature,
            AirHumidity : input.AirHumidity
        });
        const assignedId = await newData.save(); //
        console.log(newData);
        res.send(newData);
    }
    // else{
    //     for(let i=0 ; input[i] ; i++){
    //         // console.log(input.length);
    //         const newData = Data({
    //             MacAddress : input[i].MacAddress,
    //             SoilTemperature : input[i].SoilTemperature,
    //             SoilHumidity : input[i].SoilTemperature ,
    //             AirTemperature : input[i].AirTemperature,
    //             AirHumidity : input[i].AirHumidity
    //         });
    //         //data.push(newData);
    //     }
        // const assignedId = await newData.save(); //
        // console.log(newData);
    //}
});

router.get('/getSoilTemp' , async function (req , res ){
    const data = await Data.find()
    .select({MacAddress : 1 , SoilTemperature : 1});
    console.log(data);
    res.send(data);
});

router.get('/getSoilHumidity' , async function (req , res ){
    const data = await Data.find()
    .select({MacAddress : 1 , SoilHumidity : 1});
    console.log(data);
    res.send(data);
});

router.get('/getAirTemp' , async function (req , res ){
    const data = await Data.find()
    .select({MacAddress : 1 , AirTemperature : 1});
    console.log(data);
    res.send(data);
});

router.get('/getAirHumidity' , async function (req , res ){
    const data = await Data.find()
    .select({MacAddress : 1 , AirHumidity : 1});
    console.log(data);
    res.send(data);
});

router.get('/getAllData' , async function (req , res ){
    const data = await Data.find();
    console.log(data);
    res.send(data);
});

module.exports= router;