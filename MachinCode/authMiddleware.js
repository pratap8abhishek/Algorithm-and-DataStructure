


// authMiddleware.js

const jwt = require('jsonwebtoken');

const authenticateToken = (req, res, next) => {
    // Get token from header or query parameter
    const token = req.header('Authorization') || req.query.token;

    if (!token) {
        return res.status(403).send('Access Denied');
    }

    // Verify the token
    jwt.verify(token, 'yourSecretKey', (err, user) => {
        if (err) {
            return res.status(403).send('Invalid Token');
        }

        // Attach user data to the request object
        req.user = user;

        // Pass control to the next middleware
        next();
    });
};

module.exports = authenticateToken;





// app.js

const express = require('express');
const authenticateToken = require('./authMiddleware');

const app = express();

// Protected route
app.get('/protected', authenticateToken, (req, res) => {
    res.send(`Welcome, ${req.user.name}!`);
});

// Public route (no authentication needed)
app.get('/public', (req, res) => {
    res.send('This is a public route');
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});
