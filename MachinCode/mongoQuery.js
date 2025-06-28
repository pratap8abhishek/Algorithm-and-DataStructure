// 1. users


[
  { "_id": 1, "name": "Alice",   "age": 25, "gender": "female" },
  { "_id": 2, "name": "Bob",     "age": 30, "gender": "male" },
  { "_id": 3, "name": "Charlie", "age": 22, "gender": "male" },
  { "_id": 4, "name": "Diana",   "age": 35, "gender": "female" },
  { "_id": 5, "name": "Eve",     "age": 28, "gender": "female" }
]

// 2. orders
[
  { "_id": 101, "userId": 1, "amount": 1200, "status": "delivered" },
  { "_id": 102, "userId": 2, "amount": 800,  "status": "pending" },
  { "_id": 103, "userId": 1, "amount": 400,  "status": "cancelled" },
  { "_id": 104, "userId": 3, "amount": 300,  "status": "delivered" },
  { "_id": 105, "userId": 4, "amount": 2000, "status": "delivered" },
  { "_id": 106, "userId": 4, "amount": 500,  "status": "pending" },
  { "_id": 107, "userId": 2, "amount": 1000, "status": "delivered" },
  { "_id": 108, "userId": 5, "amount": 1500, "status": "cancelled" },
  { "_id": 109, "userId": 5, "amount": 100,  "status": "delivered" },
  { "_id": 110, "userId": 3, "amount": 700,  "status": "delivered" }
]


// 1 . Total order amount per user
db.orders.aggregate([
    {
        $group : { 
        _id : "$userId", 
        totalSpent : {$sum: "$amount"}
      }
    }
])

// 2 . Join users with their orders using $lookup
db.user.aggregate([
    {
        $lookup:{
            from:"orders",
            localField:"_id",
            foregineField:"userId",
            as:"orders"
        }
    }
])


// 3 . Find users with at least one delivered order

db.user.aggregate([
    {
        $lookup:{
            from:"orders",
            localField:"_id",
            foregineField:"userId",
            as:"orders"
        }
    },
    {
        $match: {"order.status" : "delivered"}
    }
])

// 4 . Average order amount by status

db.orders.aggregate([
    {
        $group :{
            _id: "$status",
            avgAmount : {$avg : "$amount"}
        }
    }
 ])

// 5 . Top 3 users by total order value  

db.orders.aggregate([
    {
        $group:{
            _id:"$userId",
            total : {$sum : "$amount"},
        }
    },
    {
        $sort:{total: -1}
        
    },
    {
        $limit : 3
    }    
  ])
  
//  6 . Get orders with user name (join + project)
 
 db.user.aggregate([
     {
         $lookup:{
             from: "user",
             localField: "userId",
             foregineField: "_id",
             as: " user"
         }
     },
     
     { $unwind : "$user" },
     
     {
         $project:{
             orderId: "$_id",
             amount: 1,
             userName: "$user.name",
             status:1
        }
    }
])

// 7 . Count of orders by each user

db.orders.aggregate([
    
    {
        $group:{
            _id: "$userId",
             orderCount : {$sum: 1}
        }
    }
])

// 8 . Users with no orders

db.user.aggregate([
  {
      $lookup:{
          from:"orders",
          localField: "-id",
          foregineField: "userId",
          as: "orders"
      }
  },
  {
      $maatch: {orders: {$eq:[]}}
  }
])

// 9. Gender-wise total spending

db.users.aggregate([
  {
    $lookup: {
      from: "orders",
      localField: "_id",
      foreignField: "userId",
      as: "orders"
    }
  },
  { $unwind: "$orders" },
  {
    $group: {
      _id: "$gender",
      totalSpent: { $sum: "$orders.amount" }
    }
  }
])

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    

