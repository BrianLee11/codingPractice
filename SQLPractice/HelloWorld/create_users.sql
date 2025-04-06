-- 1. Print a message
SELECT 'Hello World from SQLite' AS message;

-- 2. Drop the table if it exists
DROP TABLE IF EXISTS users;

-- 3. Recreate the table
CREATE TABLE users (
                       id INTEGER PRIMARY KEY,
                       name TEXT,
                       age INTEGER
);

-- 4. Insert data
INSERT INTO users (name, age) VALUES
                                  ('Alice', 28),
                                  ('Bob', 34),
                                  ('Charlie', 25);

-- 5. Query data
SELECT * FROM users;
