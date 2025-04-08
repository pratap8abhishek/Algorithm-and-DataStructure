const rateLimit = require('express-rate-limit');

const limiter = rateLimit({
  windowMs: 1 * 60 * 1000, // 1 minute
  max: 100, // limit each IP to 100 requests per windowMs
  message: 'Too many requests, please try again later.',
});

app.use('/api/', limiter);


// windowMs ---------------	Time window for the rate limit. 1 * 60 * 1000 = 1 minute in milliseconds.
// max      ---------------	Maximum number of allowed requests per IP in that window. Here, it's 100.
// message  ---------------	The response sent when the limit is exceeded. Can be a string or a full object.



// -----------What happens under the hood?--------------------
// Every time a request hits /api/*, it checks the IP.

// It counts how many requests that IP made in the current windowMs (1 min).

// If it's under max, it lets the request through.

// If it hits the limit, it blocks the request and returns a 429.

// 429 is an HTTP status code that stands for: 429 Too Many Requests




// --------pro tips-------
// This is in-memory, so it resets when the app restarts.

// For production with multiple servers, use a shared store like Redis (store: new RedisStore({ client })) for consistency across instances.

// You can also customize keys (by user ID, API token, etc.).
