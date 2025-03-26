// 1/ How do you find the second highest salary from an employee table?

// SELECT DISTINCT salary 
// FROM Employee 
// ORDER BY salary DESC 
// LIMIT 1 OFFSET 1;

// ORDER BY salary DESC → Sorts salaries in descending order.
// DISTINCT → Ensures unique salary values.
// LIMIT 1 OFFSET 1 → Skips the highest salary (OFFSET 1) and fetches the second highest (LIMIT 1).


// 2/ Write a SQL query to fetch the top N highest salaries without using LIMIT or TOP.

// SELECT DISTINCT salary 
// FROM Employee e1 
// WHERE N-1 = (
//     SELECT COUNT(DISTINCT salary) 
//     FROM Employee e2 
//     WHERE e2.salary > e1.salary
// );

// COUNT(DISTINCT salary) WHERE e2.salary > e1.salary → Counts how many unique salaries are greater than e1.salary.
// If this count is N-1, then e1.salary is the Nth highest salary


// 3/ Explain the difference between INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN.

// Use INNER JOIN when you need only matching rows.------------------------------------------------(Common Data in Both Tables)
// Use LEFT JOIN when you need all records from the left table, even without matches.--------------(All Left Table + Matching Right Table)
// Use RIGHT JOIN when you need all records from the right table, even without matches.------------(All Right Table + Matching Left Table)
// Use FULL JOIN when you need all records from both tables.---------------------------------------(All Data from Both Tables)


// 4/ How do you remove duplicate rows from a table while keeping only one occurrence?
// 5/ Write a query to calculate the cumulative sum of transactions per user, ordered by date.

// ...............................Ans...................................
// SELECT 
//     user_id,
//     transaction_date,
//     amount,
//     SUM(amount) OVER (
//         PARTITION BY user_id 
//         ORDER BY transaction_date 
//         ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
//     ) AS cumulative_sum
// FROM transactions;

// ---------explanation-------------------

// PARTITION BY user_id: Calculates a separate cumulative sum for each user.
// ORDER BY transaction_date: Ensures transactions are summed in chronological order.
// ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW: Summation starts from the first row for each user and continues to the current row.


// 6/ What is the difference between GROUP BY and PARTITION BY?

// ...............................Ans...................................
// Both GROUP BY and PARTITION BY are used to segment data, but they serve different purposes:

// 1 - GROUP BY (Aggregates Data into Groups)
//     GROUP BY collapses rows into a single row per group.
//     It is used with aggregate functions (SUM(), COUNT(), AVG(), etc.).
//     The result has fewer rows than the original dataset.

// 2 - PARTITION BY (Divides Data into Windows)
//     PARTITION BY does NOT collapse rows but creates partitions to apply window functions (SUM() OVER(), ROW_NUMBER(), etc.).
//     It is used with window functions to provide aggregated values without reducing row count.

// 7/ Write a SQL query to find the moving average of sales for the past 7 days for each product.

// ............................Ans.............................
// SELECT 
//     product_id,
//     sale_date,
//     amount,
//     AVG(amount) OVER (
//         PARTITION BY product_id 
//         ORDER BY sale_date 
//         ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
//     ) AS moving_avg
// FROM sales;


// 8/ How do you rank transactions per user using ROW_NUMBER(), RANK(), and DENSE_RANK()?

// .................................Ans.............................
// To rank transactions per user, we use the ROW_NUMBER(), RANK(), and DENSE_RANK() window functions. 
// These functions assign rankings to rows based on an ORDER BY condition while keeping rankings separate for each user_id using PARTITION BY.

// ROW_NUMBER()	Assigns a unique number to each row without gaps. If there are duplicates, ranking is arbitrary.

// RANK()	Assigns the same rank to duplicates, but the next rank is skipped.

// DENSE_RANK()	Assigns the same rank to duplicates, but does not skip the next rank.

// 9/ Write a query to find the first and last transaction date for each user.
// ...............................Ans...........................
// SELECT 
//     user_id, 
//     MIN(transaction_date) AS first_transaction, 
//     MAX(transaction_date) AS last_transaction
// FROM transactions
// GROUP BY user_id;

// 10/ How do you calculate the percentage contribution of each transaction to the total sales?
// .................................Ans...................................
// SELECT 
//     user_id, 
//     transaction_date, 
//     amount, 
//     (amount / SUM(amount) OVER ()) * 100 AS percentage_contribution
// FROM transactions;

// 11/ What are CTEs (Common Table Expressions), and when should you use them?
// 12/ How do you optimize a slow-running SQL query?
// Ans : -    1. Analyze Query Execution Plan
            //   Use EXPLAIN (MySQL, PostgreSQL) or EXPLAIN ANALYZE to understand how the query is executed.
            //   Look for sequential scans (Seq Scan) and high-cost operations.
            //   Ensure indexes are used efficiently.

            // 2. Use Indexing Effectively
            //     Create indexes on columns used in WHERE, JOIN, and ORDER BY.
            //     Use composite indexes for filtering on multiple columns.
            //     Avoid too many indexes, as they slow down INSERT/UPDATE/DELETE operations.

            // 3.  Reduce Data Scanned
            //        Use SELECT only needed columns instead of SELECT *.
            //        Use WHERE conditions to limit rows.
            //        Partition large tables to speed up filtering.
            // 4.  Use Caching
            //        Store frequently accessed results in an in-memory cache (e.g., Redis).
            //        Use materialized views for complex aggregations.

// 13/ What is an index, and how does it impact query performance?
// Ans : - An index is a data structure that improves the speed of data retrieval operations on a database table. It works like a 
//         "table of contents" in a book, allowing the database to find rows faster without scanning the entire table.

//         Performance Benefits ---------------
//         Faster SELECT queries: Indexes reduce the number of rows scanned, improving query speed.
//         Efficient JOIN operations: Indexed columns make joins between tables faster.
//         Improved ORDER BY and GROUP BY performance: Sorting and grouping operations run faster with indexed columns.

//         Potential Drawbacks-----------------
//         Slower INSERT, UPDATE, and DELETE: Indexes must be updated when data changes, adding overhead.
//         Increased storage: Indexes consume additional disk space.
//         Too many indexes can degrade performance: The database has to manage them, increasing complexity.


// 14/ Explain the difference between clustered and non-clustered indexes.
// Ans : - 1. Clustered Index
//     ✅ Definition:
//          A clustered index determines the physical order of rows in a table.
//          Since the data is stored in the order of the indexed column, there 
//          can be only one clustered index per table.

//     ✅ Key Characteristics:
//         The table itself is the index (index and data are stored together).
//         Faster for range queries (BETWEEN, <, >, etc.) and sorting (ORDER BY).
//         Slows down INSERT, UPDATE, and DELETE if frequent changes occur in the indexed column.

//   2. Non-Clustered Index
//      ✅ Definition:
//                A non-clustered index creates a separate structure that stores 
//                a pointer to the actual table rows. The table itself remains 
//                unordered, and the index is used only for lookups.

//      ✅ Key Characteristics:
//             Does not affect row storage order (data remains in original order).
//             Faster for searches on non-primary key columns.
//             Slower than clustered indexes for range scans.
//             Multiple non-clustered indexes are allowed per table

//                                         Key Differences:

// Feature	                Clustered Index         	      Non-Clustered Index

// Storage	                Data is stored in index order	  Index stores pointers to data
// Row Order	            Physically sorted	              Original order maintained
// Number Allowed	        Only one per table	              Multiple per table
// Performance	            Faster for SELECT, ORDER BY	      Faster for lookups on non-key columns
// Best Use Case	        Primary key, range queries	      Searching/filtering non-primary columns
// Impact on DML	        Slows down INSERT/UPDATE/DELETE	  Less impact on data modifications

// 15/ How do you detect missing or incorrect data in a large dataset using SQL?
// 16/ How do you identify churned users using SQL from a transactions table?
// 17/ Write a query to find users who made their first transaction in the last 30 days.
// 18/ How do you find the top 3 most frequently purchased items per user?
// 19/ Write a SQL query to identify fraudulent transactions based on user behavior.
// 20/ Given a rideshare dataset, write a query to find the average ride distance per city.