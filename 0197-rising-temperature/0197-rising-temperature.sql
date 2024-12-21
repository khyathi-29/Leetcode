# Write your MySQL query statement below
SELECT a.id FROM Weather as a, Weather as b WHERE a.RecordDate = b.RecordDate + INTERVAL 1 DAY AND b.temperature < a.temperature 