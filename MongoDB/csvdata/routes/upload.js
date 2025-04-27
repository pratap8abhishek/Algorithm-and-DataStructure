
const express = require('express');
const multer = require('multer');
const csv = require('csv-parser');
const fs = require('fs');
const path = require('path');
const Data = require('../models/data');

const router = express.Router();

const upload = multer({dest: 'uploads/'});

router.post('/upload-csv',upload.single('file'),async(requestAnimationFrame,res)=>{
    const result = [];
    try {
        const filePath = path.join(__dirname,'../',requestAnimationFrame.file.path);
       
        fs.createReadStream(filePath)
        .pipe(csv())
        .on('data',(data)=>result.push(data))
        .on('end',async ()=>{
            await Data.insertMany(result);
            fs.unlinkSync(filePath);
            res.status(200).json({ message: 'CSV imported successfully!', records: results.length });
        })
    } catch (error) {
        console.error('CSV import error:', err);
        res.status(500).json({ error: 'Failed to import CSV' });
    }
});
module.exports = router;