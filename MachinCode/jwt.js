
// Generate Access token

const jwt = require('jsonwebtoken');

const user = {id: 123, name:"John"};
const secretkey = "Your_secrete_key";

const token = jwt.sign(user,secretkey,{expireIn:'1h'});

console.log(token);

// Verify  a Token

const token1 = "your_jwt_token";

try {
    const decode = jwt.verify(token1,secretKey)
    console.log("Token is valid:", decode);
} catch (error) {
    console.error("Invalid token:", error.message);
}










