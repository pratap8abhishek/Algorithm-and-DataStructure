
const express = require('express');
const mongoose = require("mongoose");
const uploadRouter = require('./routes/upload');
const app = express();

const port = 3000;


mongoose.connect('mongodb://localhost:27017/csvUpload')
.than(()=>console.log('MongoDb connected'))
.catch((err)=>console.error('MongoDB error :',err));

app.use('/api', uploadRouter);

app.listen(port,()=>{
    console.log(`server is Running at port ${port}`)
})







