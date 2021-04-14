const express = require('express');
const  router = express.Router();
const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost/farm demo' , { useNewUrlParser: true , useUnifiedTopology: true })
.then(() => console.log('connected to mongodb...'))
.catch(err => console.error('could not connect to mongo db...' , err));

const dataShema =  new mongoose.Schema({
    name : String,
    author : Number,
    tags : [String], //key : index , value : string
    date : {type : Date , default : Date.now},
    isPublished : Boolean
});

const Data = mongoose.model('Course' , dataShema);


// const data =[
//     {MacAddress:"1", SoilTemperature : 2, SoilHumidity :3 ,  AirTemperature : 4, AirHumidity : 5}
// ];

router.post('/postdata' , async function(req , res){
    const input = req.body;
    console.log(typeof(input));
    if(input[1] == undefined){
        const newData = Data({
            MacAddress : input.MacAddress,
            SoilTemperature : input.SoilTemperature,
            SoilHumidity : input.SoilTemperature ,
            AirTemperature : input.AirTemperature,
            AirHumidity : input.AirHumidity
        });
    }
    else{
        for(let i=0 ; input[i] ; i++){
            // console.log(input.length);
            const newData = Data({
                MacAddress : input[i].MacAddress,
                SoilTemperature : input[i].SoilTemperature,
                SoilHumidity : input[i].SoilTemperature ,
                AirTemperature : input[i].AirTemperature,
                AirHumidity : input[i].AirHumidity
            });
            //data.push(newData);
        }
    }
    const assignedId = await Data.save(); //
    console.log(assignedId);
    //res.send(data);
});

router.get('/getSoilTemp' , async function (req , res ){
    const data = await Course.find()
    .select({MacAddress : 1 , SoilTemperature : 1});
    console.log(data);
    res.send(data);
});

// router.get('/' , (req , res )=>{
//     console.log(data);
//     res.send(data);
// });

module.exports= router;