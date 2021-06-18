SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;


SELECT Email
FROM (SELECT Email, COUNT(Email) AS num FROM Person GROUP BY Email) AS statistics
WHERE num > 1;