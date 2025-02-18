// upload a file

const express = require("express");
const multer = require("multer");
const path = require("path");

const app = express();
const PORT = 3000;

// Set storage engine
const storage = multer.diskStorage({
    destination: "./uploads/",
    filename: (req, file, cb) => {
        cb(null, file.fieldname + "-" + Date.now() + path.extname(file.originalname));
    },
});

// Init upload
const upload = multer({
    storage: storage,
    limits: { fileSize: 5 * 1024 * 1024 }, // 5MB limit
    fileFilter: (req, file, cb) => {
        const fileTypes = /jpeg|jpg|png|gif/;
        const extname = fileTypes.test(path.extname(file.originalname).toLowerCase());
        const mimeType = fileTypes.test(file.mimetype);

        if (mimeType && extname) {
            return cb(null, true);
        } else {
            return cb(new Error("Only images are allowed!"));
        }
    },
});

// Route to handle file upload
app.post("/upload", upload.single("file"), (req, res) => {
    if (!req.file) {
        return res.status(400).json({ message: "No file uploaded" });
    }
    res.json({ message: "File uploaded successfully", file: req.file });
});

// Serve static files
app.use(express.static("public"));

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});





// Upload a file whose min size is 8MB abd max size is 100MB

const express = require("express");
const multer = require("multer");
const path = require("path");

// const app = express();
// const PORT = 3000;

// Configure storage
const storage1 = multer.diskStorage({
    destination: "./uploads/",
    filename: (req, file, cb) => {
        cb(null, file.fieldname + "-" + Date.now() + path.extname(file.originalname));
    },
});

// File filter function
const fileFilter = (req, file, cb) => {
    const fileTypes = /jpeg|jpg|png|gif|pdf|mp4/;
    const extname = fileTypes.test(path.extname(file.originalname).toLowerCase());
    const mimeType = fileTypes.test(file.mimetype);

    if (mimeType && extname) {
        return cb(null, true);
    } else {
        return cb(new Error("Invalid file type! Only images, PDFs, and MP4 videos are allowed."));
    }
};

// Initialize multer upload settings
const upload1 = multer({
    storage: storage1,
    limits: { fileSize: 100 * 1024 * 1024 }, // Max size: 100MB
    fileFilter: (req, file, cb) => {
        if (file.size < 8 * 1024 * 1024) { // Min size: 8MB
            return cb(new Error("File size must be at least 8MB!"));
        }
        fileFilter(req, file, cb);
    },
});

// Route to handle multiple file uploads
app.post("/upload", upload1.array("files", 5), (req, res) => {
    if (!req.files || req.files.length === 0) {
        return res.status(400).json({ message: "No files uploaded or files did not meet the size requirement." });
    }
    res.json({ message: "Files uploaded successfully", files: req.files });
});

// Serve static files
app.use(express.static("public"));

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
