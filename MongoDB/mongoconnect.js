const mongoose = require("mongoose");

const mongoURI = 'mongodb://localhost:27017/mydatabase';

mongoose.connect(mongoURI)
.then(()=>console.log("mongoDB connected successfully"))
.cath((err)=>console.log("mongoDB connected successfully"));

const userSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    email: {
        type: String,
        required: true,
        unique: true,
      },
      age: {
        type: Number,
        required: false,
      },
});
const User = mongoose.model('User',userSchema);
module.exports = User;


// To make schema Dynamic we use 

const mongoose = require('mongoose');

// Create a dynamic schema
const dynamicSchema = new mongoose.Schema({}, { strict: false });

// Create a model
const DynamicModel = mongoose.model('Dynamic', dynamicSchema);

module.exports = DynamicModel;



